#include<iostream>
using namespace std;

template <typename T>
class stack{

    private:    
        T* data=new T[4];
        int nextIndex;
        int capacity;

    public:
        stack(){
            nextIndex=0;
            capacity=4;
        }

        int getSize(){
            return nextIndex;
        }

        bool isEmpty(){
            return nextIndex==0;
        }

        void push(T element){
            if(nextIndex==capacity){
                T *newData=new T[capacity*2];
                for(int i=0; i<capacity; i++){
                    newData[i]=data[i];
                }
                delete []data;
                data=newData;
                data[nextIndex]=element;
                nextIndex++;
            }
            else{
                data[nextIndex]=element;
                nextIndex++;
            }
        }

        T pop(){
            if(nextIndex==0){
                cout << "STACK IS EMPTY!\n";
                return 0;
            }
            else{
                nextIndex--;
                return data[nextIndex];
            }
        }

        T top(){
            if(nextIndex==0){
                return 0;
            }
            else{
                return data[nextIndex];
            }
        }

};

int main(){
    stack<int> s;
    cout << s.getSize() << endl;
    for(int i=1; i<=10; i++){
        s.push(i);
    }
    cout << s.getSize() << endl;
    for(int i=1; i<=11; i++){
        cout << s.pop() << endl;
    }
    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;
    cout << s.top() << endl;
}