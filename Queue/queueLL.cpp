#include<iostream>
using namespace std;

template <typename T>
class node{
    public:
        T data;
        node<T>* next;

        node(T element){
            data=element;
            next=NULL;
        }
};

template <typename T>
class queue{
    private:
        node<T> *head, *tail;
        int size;

    public:
        queue(){
            head=NULL;
            tail=NULL;
            size=0;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size==0;
        }

        T front(){
            if(head==NULL){
                cout << "QUEUE IS EMPTY\n";
                return 0;
            }
            return head->data;
        }

        void enqueue(T element){
            node<T>* newNode=new node<T>(element);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
            size++;
        }

        T dequeue(){
            if(size==0){
                cout << "QUEUE IS EMPTY!\n";
                return 0;
            }
            T ans=head->data;
            node<T> *temp=head;
            head=head->next;
            delete temp;
            size--;
            return ans;
        }

};

int main(){

    queue<int> q;

    cout << q.isEmpty() << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << q.getSize() << endl;
    cout << q.dequeue() << endl;
    cout << q.getSize() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(60);
    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;


    // queue<int> q;
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(40);
    // q.dequeue();
    // q.dequeue();
    // q.enqueue(100);
    // q.enqueue(200);
    // q.enqueue(300);
    // q.enqueue(400);
    // q.enqueue(500);
    // q.enqueue(600);
    // q.enqueue(700);
    // q.enqueue(800);

    // cout << q.getSize() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.isEmpty() << endl;


}