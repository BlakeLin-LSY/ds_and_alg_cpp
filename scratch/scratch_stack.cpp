#include<iostream>
using namespace std;

struct Node{
    public:
        int val;
        Node *next;
};

class Stack{
    public:
        Stack(){
            cur = new Node();
            count = 0;
        };

        void push(int n){
            Node *new_node = new Node();
            new_node->val = n;
            new_node->next = cur;

            cur = new_node;
            count++;
        };

        void pop(){
            Node *tmp = new Node();
            if (cur->next == NULL){
                cout << "all elements in stack are popped out!" << endl;
                count = 0;
            }
            else{
                tmp = cur;
                cur = cur->next;
                free(tmp);  
                count--;
            }
        }

        const int size(){
            return count;
        }

        int top(){
            return cur->val;
        }
    private:
        Node *cur;
        int count;
};

int main()
{
    int a[5] = {3, 5, 7, 8, 2};
    Stack stk;
    cout << "size() = " << stk.size() << endl;

    for (auto x : a){
        stk.push(x);
        cout << x << ", ";
    }
    cout << endl;
    cout << "size() = " << stk.size() << endl;
    cout << "top() = " << stk.top() << endl;
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    cout << "pop() twice" << endl;
    cout << "top() = " << stk.top() << endl;
    cout << "size() = " << stk.size() << endl;


    return 0;
}