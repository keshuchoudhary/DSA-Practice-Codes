#include <iostream>
#include <queue>
using namespace std;

int main(){

    int arr[]={5, 6, 9, 12, 3, 13, 2};
    int k=3, size=7;

    // k smallest elements
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    for(int i=k; i<size; i++){
        if(pq.top()>arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    for(int i=0; i<k; i++){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;


}