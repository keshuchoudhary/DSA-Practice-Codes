#include<iostream>
#include "MinPriorityQueue.h"
using namespace std;

int main(){
    MinPriorityQueue<int> p;

    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << "Size :- " << p.getSize() << endl;
    cout << "Minimum Value :- " << p.getMin() << endl;

    while(!p.isEmpty()){
        cout << "Removed element :- " << p.removeMin() << endl;
    }

}