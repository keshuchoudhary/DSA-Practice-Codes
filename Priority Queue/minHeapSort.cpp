#include <iostream>
using namespace std;

void upHeapify(int pq[], int childIndex){

    while(childIndex>0){

        int parentIndex=(childIndex-1)/2;

        if(pq[childIndex]<pq[parentIndex]){
            swap(pq[childIndex],pq[parentIndex]);
        }
        else{
            break;
        }

        childIndex=parentIndex;
    }
}

void downHeapify(int pq[], int size){

    int parentIndex=0;
    int leftChildIndex=(2*parentIndex)+1;
    int rightChildIndex=(2*parentIndex)+2;

    while(leftChildIndex<size){
        int minIndex=parentIndex;
        if(pq[leftChildIndex]<pq[minIndex]){
            minIndex=leftChildIndex;
        }
        if(rightChildIndex<size && pq[rightChildIndex]<pq[minIndex]){
            minIndex=rightChildIndex;
        }

        if(parentIndex==minIndex){
            break;
        }

        swap(pq[parentIndex],pq[minIndex]);

        parentIndex=minIndex;
        leftChildIndex=(2*parentIndex)+1;
        rightChildIndex=(2*parentIndex)+2;
    }

}

void inplaceHeapSort(int pq[], int n){

    // inserting in heap
    for(int i=1; i<n; i++){
        upHeapify(pq, i);
    }

    // removing elements in heap and keeping them at the end
    int size=n;
    while(size>1){

        swap(pq[0],pq[size-1]);
        size--;

        downHeapify(pq, size);
    }
}


int main(){


    int arr[]={2,5,1,8,0};
    int size=5;
    inplaceHeapSort(arr,size);

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}