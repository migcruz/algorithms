#!/usr/bin/python
# -*- coding: utf-8 -*-

import gtk, gobject, os, dbus, dbus.service, logging

class Phonebook_Phone:

   bus = None
   session_p = None
   session = None
   pbap_object = None
   transfer_path = None
   transfer_file = None
   phone_book = []
   cb_done = None

   def __init__(self, phone, done_cb):
      self.cb_done = done_cb
      self.bus = dbus.SessionBus()
      client = dbus.Interface(self.bus.get_object("org.bluez.obex", "/org/bluez/obex"), "org.bluez.obex.Client1")
      self.session_p = client.CreateSession(phone, { "Target": "PBAP" })
      obj = self.bus.get_object("org.bluez.obex", self.session_p)
      self.session = dbus.Interface(obj, "org.bluez.obex.Session1")
      self.pbap_object = dbus.Interface(obj, "org.bluez.obex.PhonebookAccess1")
      self.bus.add_signal_receiver(self.properties_changed,
               dbus_interface="org.freedesktop.DBus.Properties",
               signal_name="PropertiesChanged",
               path_keyword="path")
      self.pbap_object.Select("int", "PB")
      self.get_book()

   def properties_changed(self, interface, properties, invalidated, path):
      if self.transfer_file == None:
         return
      if "Transferred" in properties:
         return
      if properties['Status'] == 'complete':
         self.transfer_complete(path)
         return
      if properties['Status'] == 'error':
         self.error(path)
         return

   def get_book(self):
      params = dbus.Dictionary({ "Format" : "vcard30",
                               "Fields" : ["PHOTO"] })
      self.pbap_object.PullAll("", params,
              reply_handler=self.register,
              error_handler=self.error)

   def register(self, path, properties):
      self.transfer_path = path
      self.transfer_file = properties["Filename"]

   def error(self, err):
       logging.error("Error while retrieving the Phonebook: %s", err)

   def transfer_complete(self, path):
       if self.transfer_file == None:
          return
       try:
          f = open(self.transfer_file, "r")
          lines = f.readlines()
          f.close()
          os.remove(self.transfer_file)
          self.result_cb(lines)
       except:
          pass
 
   def result_cb(self, lines):
       for line in lines:
           line = line.strip()
           if line[:3] == "FN:":
              my_name = line[3:]
              my_numbers = []
           elif line[:4] == "TEL;":
              my_numbers.append(line[line.find(":") + 1:])
           elif line == "END:VCARD" and len(my_numbers) != 0:
              for i in range(0, len(my_numbers)):
                 my_name_1 = my_name
                 if i != 0:
                    my_name_1 = my_name_1 + " " + str(i)
                 self.phone_book.append([my_name_1, my_numbers[i]])
       if self.cb_done:
          self.cb_done()

