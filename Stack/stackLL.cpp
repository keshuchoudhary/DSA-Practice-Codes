#include<iostream>
using namespace std;

template <typename T>
class node{

    public:
        T data;
        node<T> *next;

        node(T data){
            this->data=data;
            next=NULL;
            // cout << "chala\n";
        }
};



template<typename T>
class stack{

    private:
        node<T> *head;
        int size;

    public:
        stack(){
            head=NULL;
            size=0;
            // cout << "chala\n";

        }

        void push(T element){
            node<T>* newNode=new node<T>(element);
            newNode->data=element;
            
            if(head==NULL){
                head=newNode;
            }
            else{
                newNode->next=head;
                head=newNode;
            }

            size++;
        }

        T pop(){
            if(head==NULL){
                cout << "STACK IS EMPTY!\n";
                return 0;
            }
            else{
                int ans=head->data;
                node<T> *temp=head;
                head=head->next;
                delete temp;
                size--;
                return ans;

            }
        }

        T top(){
            if(head==NULL){
                return 0;
            }
            else{
                return head->data;
            }
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size==0;
        }


};

int main(){
    stack<int> s;
    cout << s.isEmpty() << endl;
    s.push(3);
    s.push(2);
    s.push(1);
    cout << s.getSize() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.push(10);
    cout << s.getSize() << endl;
}