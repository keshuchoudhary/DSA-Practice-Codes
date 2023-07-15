#include<iostream>
using namespace std;

template <typename T>
class queue{
    private:
        int firstIndex;
        int nextIndex;
        int capacity;
        T *data;
        int size;

    public:
        queue(){
            firstIndex=-1;
            nextIndex=0;
            size=0;
            capacity=4;
            data=new T[capacity];
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size==0;
        }

        T front(){
            if(firstIndex==-1){
                cout << "QUEUE IS EMPTY!\n";
                return 0;
            }
            return data[firstIndex];
        }

        void enqueue(int element){
            if(size==capacity){
                T *newData= new T[2*capacity];
                int j=0;
                for(int i=firstIndex; i<capacity; i++){
                    newData[j]=data[i];
                    j++;
                }
                for(int i=0; i<firstIndex; i++){
                    newData[j]=data[i];
                    j++;
                }
                delete []data;
                data=newData;
                firstIndex=0;
                nextIndex=capacity;
                capacity*=2;
            }
            data[nextIndex]=element;
            nextIndex=(nextIndex+1)%capacity;
            if(firstIndex==-1){
                firstIndex=0;
            }
            size++;
        }

        T dequeue(){
            if(size==0){
                cout << "QUEUE IS EMPTY!\n";
                return 0;
            }
            T ans=data[firstIndex];
            firstIndex=(firstIndex+1)%capacity;
            size--;
            if(size==0){
                firstIndex=-1;
                nextIndex=0;
            }
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