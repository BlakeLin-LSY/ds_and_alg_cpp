#include <iostream>

using namespace std;

class Node{
private:
    int data;       // data in the node
    Node *next;     // pointer to the next node

public:
    Node(int _data){
        data = _data;       // Initialized value;
        next = NULL;        // Initialize with NULL pointer;
    }

    int getData(){
        return data;
    }

    Node *getNext(){
        return next;
    }

    void setData(int _val){
        data = _val;
    }

    void setNext(Node *_next){
        next = _next;
    }

};

class UnorderedList{
public:
    Node *head;

    UnorderedList(){
        head = NULL;
    }

    bool isEmpty(){
        return head == NULL;
    }

    // add -> T(n) == O(1)
    void add(int _val){
        Node *temp = new Node(_val);
        temp->setNext(head);
        head = temp;
    }

    // size -> T(n) == O(n)
    int size(){
        Node *current = head;
        int count = 0;
        while (current != NULL){
            current = current->getNext();
            // current = current.next;  
            /* 
                Cannot be reached if the "variable" is private; 
                And "current" should be Node instead of Node*
            */
            ++count;
        }
        return count;
    }

    // search -> T(n) == O(n)
    bool find(int _target){
        Node *current = head;
        while (current != NULL){
            if (current->getData() == _target){
                return true;
            }
            else
            {
                current = current->getNext();
            }
        }
        return false;
    }

    // remove -> T(n) == O(n)
    void remove(int _target){
        Node *current = head;
        Node *prev = NULL;
        bool found = false;
        while (!found){
            if (current->getData() == _target){
                found = true;
            }
            else{
                prev = current;
                current = current->getNext();
            }
        }
        if (prev == NULL){
            head = current->getNext();
        }
        else{
            prev->setNext(current->getNext());
        }

    }

    // ==== Un-implemented methods ====

    // append

    // insert

    // index

    // pop
};


ostream& operator<<(ostream& os, const UnorderedList& ol){
    Node *current = ol.head;
    while (current != NULL){
        os<<current->getData()<<endl;
        current = current->getNext();
    }
}


int main(){
    UnorderedList myList;
    myList.add(31);
    myList.add(77);
    myList.add(17);
    myList.add(93);
    myList.add(26);
    myList.add(54);

    cout<<"SIZE: "<<myList.size()<<endl;
    cout<<"contain 93?\t"<<myList.find(93)<<endl;
    cout<<"contain 100?\t"<<myList.find(100)<<endl;

    myList.add(100);
    cout<<"contain 100?\t"<<myList.find(100)<<endl;
    cout<<"SIZE: "<<myList.size()<<endl;

    myList.remove(54);
    cout<<"SIZE: "<<myList.size()<<endl;
    myList.remove(93);
    cout<<"SIZE: "<<myList.size()<<endl;
    myList.remove(31);
    cout<<"SIZE: "<<myList.size()<<endl;

    myList.find(93);

    cout<<"MY LIST: "<<endl<<myList;

    return 0;
}


/*
    Linked-list data structures

*/