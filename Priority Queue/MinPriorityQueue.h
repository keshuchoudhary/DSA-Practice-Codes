#include<vector>
#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

template<typename T>
class MinPriorityQueue{
    private:
        vector<T> pq;
    
    public:
        MinPriorityQueue(){

        }

        bool isEmpty(){
            return (pq.size()==0);
        }

        int getSize(){
            return pq.size();
        }

        T getMin(){
            if(isEmpty()){
                cout << "Min-Priority Queue is empty!\n";
                return 0;
            }
            return pq[0];
        }

    private:

        void upHeapify(){

            int childIndex=pq.size()-1;

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

    public:

        void insert(T element){
            pq.push_back(element);

            upHeapify();
        }

    private:

        void downHeapify(){

            int parentIndex=0;
            int leftChildIndex=(2*parentIndex)+1;
            int rightChildIndex=(2*parentIndex)+2;

            while(leftChildIndex<pq.size()){
                int minIndex=parentIndex;
                if(pq[leftChildIndex]<pq[minIndex]){
                    minIndex=leftChildIndex;
                }
                if(rightChildIndex<pq.size() && pq[rightChildIndex]<pq[minIndex]){
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

    public:

        T removeMin(){
            if(isEmpty()){
                cout << "Nothing to remove! Size of Min-Priority Queue is 0\n";
                return 0;
            }

            int ans=pq[0];

            pq[0]=pq[pq.size()-1];
            pq.pop_back();

            downHeapify();
            return ans;
        }
    
};