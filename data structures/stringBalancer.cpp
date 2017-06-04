#include <iostream>
#include <string>
using namespace std;


class stack{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        char x;
        Node *next;
    };

// public member
public:
    // constructor
    stack(){
        head = NULL; // set head to NULL
        tail = NULL;
    }
    
    bool empty(){
        if (head == NULL){
            return true;
        }
        return false;
    }

    void pushFront(char val){
        Node *n = new Node(); //using new makes n available until it is deleted and is stored in the heap (if not deleted you can get a memory leak)
        n->x = val;
        n->next = head;
        head = n;
        if (tail == NULL){ //empty LinkedList
            tail = n;
        }
    }

    // returns the first element in the list and deletes the Node.
    char popFront(){ 
        
        if (head == NULL){//LinkedList is empty case
            return NULL;
        }
        Node *n = head;
        char ret = n->x;


        head = head->next;
        if (head == NULL){ //LinkedList is now empty
            tail = NULL;
        }
        delete n;
        return ret;
    }

// private member
private:
    Node *head; // this is the private member variable. It is just a pointer to the first Node
    Node *tail; //pointer to the last node
};

int main() {
    stack stringBalancer;
    string test = "[{}][";

    for (string::iterator it = test.begin(); it != test.end(); ++it){
        if (*it == '[' || *it == '(' || *it == '{'){
            cout << "ENQUEUE " << *it << endl;
            stringBalancer.pushFront(*it);
        }
        else {
            if (stringBalancer.empty()){
                cout << "FAILED" << endl; //End bracket is first thing
                return -1;
            }
            char bracket = stringBalancer.popFront();
            if ((*it == ')' && bracket != '(') || (*it == ']' && bracket != '[') || (*it == '}' && bracket != '{')){
                cout << "FAILED " << bracket << *it <<endl;
                return -1;
            }
             cout << "DEQUEUE " << bracket << endl;
        }
    }

    //Stack should be empty
    if (!stringBalancer.empty()){
         cout << "FAILED " << endl;
         return -1;
    }

    cout << "SUCCESS" << endl;

    return 0;
}