#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;

    pq.push(23);
    pq.push(49);
    pq.push(8);
    pq.push(17);
    pq.push(24);


    cout << "Size :- " << pq.size() << endl;
    cout << "Top :- " << pq.top() << endl;

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }

}