#include <iostream>
using namespace std;


class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        int x;
        Node *next;
        Node *prev;
    };

// public member
public:
    // constructor
    LinkedList(){
        head = NULL; // set head to NULL
        tail = NULL;
    }

    void pushFront(int val){
        Node *n = new Node(); //using new makes n available until it is deleted and is stored in the heap (if not deleted you can get a memory leak)
        n->x = val;
        n->next = head;
        head = n;
        if (tail == NULL){ //empty LinkedList
            tail = n;
        }
    }

    int topFront(){// return the front item
        Node *n = head;
        int ret = n->x;
        return ret;
    }

    int topBack(){
        Node *n = tail;
        int ret = n->x;
        return ret;
    }

    // returns the first element in the list and deletes the Node.
    int popFront(){ 
        
        if (head == NULL){//LinkedList is empty case
            return -1;
        }
        Node *n = head;
        int ret = n->x;


        head = head->next;
        if (head == NULL){ //LinkedList is now empty
            tail = NULL;
        }
        delete n;
        return ret;
    }

    void pushBack(int val){
        Node *n = new Node();
        n->x = val;
        n->next = NULL; //end of list
        if (tail == NULL){ //LinkedList was empty
            head = n;
            tail = n;
            n->prev = NULL;
        }
        else {
            tail->next = n;
            n->prev = tail
            tail = n;
        }
    }

    int popBack(){
        if (head == NULL){
            return -1;
        }
        if (head == tail){ //only 1 item
            Node* n = head;
            int ret = n->x;
            head = NULL;
            tail = NULL;
            delete n;
            return ret;
        }
        else {
            Node *p = tail;
            int ret = p->x;
            tail = p->prev;
            tail->next = NULL;
            delete p;
            return ret;
        }
    }

    void addAfter(Node *n, int val){
        Node *n2 = new Node();
        n2->x = val;
        n2->next = n->next;
        n->next = n2;
        if (tail == n){
            tail = n2;
        }
    }

    void addBefore(Node *n, int val){
        Node *n2 = new Node();
        n2->x = val;
        n2->next = n;

        //find the node before
        Node *p = head;
        while (p->next != n){
            p = p->next;
        }
        //p is now at the node before n
        p->next = n2;

    }



// private member
private:
    Node *head; // this is the private member variable. It is just a pointer to the first Node
    Node *tail; //pointer to the last node
};

int main() {
    LinkedList list;

    list.pushFront(5);
    list.pushFront(10);
    list.pushFront(20);

    cout << list.topFront() << endl;
    cout << list.topBack() << endl;

    list.popBack();
    
    cout << list.topBack() << endl;
    // because there is no error checking in popValue(), the following
    // is undefined behavior. Probably the program will crash, because
    // there are no more values in the list.
    // cout << list.popValue() << endl;
    return 0;
}