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

class OrderedList{
public:
    Node* head;

    bool search(int item){
        Node *current = head;
        bool found = false;
        bool stop = false;
        while (current != NULL && !found && !stop){
            if(current->getData() == item){
                found = true;
            }
            else{
                if (current->getData() > item){
                    stop = true;
                }
                else{
                    current = current->getNext();
                }
            }
        }
        return found;
    }

    void add(int item){
        if (head == NULL){
            Node *tmp = new Node(item);
            head = tmp;
        }
        else{
            Node *current = head;
            Node *prev = NULL;
            bool stop = false;
            while (current != NULL && !stop){
                if (current->getData() > item){
                    stop = true;
                }
                else{
                    prev = current;
                    head = current->getNext();
                }
            }
            Node *tmp = new Node(item);
            if (prev == NULL){
                tmp->setNext(head);
                head = tmp;
            }
            else{
                tmp->setNext(current);
                prev->setNext(tmp);
            }
        }
    }

    bool isEmpty(){
        return head == NULL;
    }

    int size(){
        Node *current = head;
        int count = 0;
        while (current != NULL){
            ++count;
            current = current->getNext();
        }
        return count;
    }

    friend ostream& operator<<(ostream& os, const OrderedList& ol);
    
};

ostream& operator<<(ostream& os, const OrderedList& ol){
    Node *current = ol.head;
    while (current!=NULL){
        os<<current->getData()<<", ";
        current = current->getNext();
    }
    os<<endl;
    return os;
}



int main(){
    OrderedList mylist;
    mylist.add(31);
    mylist.add(77);
    mylist.add(17);
    mylist.add(93);
    mylist.add(26);
    mylist.add(54);

    cout<<"SIZE: "<<mylist.size()<<endl;
    cout<<"contains 93?\t"<<mylist.search(93)<<endl;
    cout<<"contains 100?\t"<<mylist.search(100)<<endl<<endl;
    cout<<"MY LIST: "<<endl<<mylist;

    return 0;
}