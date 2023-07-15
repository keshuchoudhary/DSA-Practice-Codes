#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
    public:
        int source;
        int dest;
        int weight;
};

bool compare(Edge e1, Edge e2){
    // By below statement, the edge array will be sorted on the increasing weight basis
    return e1.weight<e2.weight;
}

int findParent(int v, int* parent){
    if(v==parent[v]){
        return v;
    }
    return findParent(parent[v], parent);
}

void printMST(Edge* arr, int size){
    
    for(int i=0; i<size; i++){
        cout << arr[i].source << " " << arr[i].dest << " " << arr[i].weight << endl;
    }

}

void kruskal(Edge* input, int n, int E){
    
    sort(input, input+E, compare);

    Edge output[n-1];

    int* parent=new int[n];
    for(int i=0; i<n; i++){
        parent[i]=i;
    }

    int count=0;
    int i=0;

    while(count!=n-1){

        Edge currentEdge=input[i];

        int sourceParent=findParent(currentEdge.source, parent);
        int destParent=findParent(currentEdge.dest, parent);

        if(sourceParent!=destParent){
            output[count]=currentEdge;
            count++;

            parent[sourceParent]=destParent;
        }
        i++;
    }

    printMST(output, n-1);

}

int main(){

    int n, E;
    cin >> n >> E;

    Edge* input=new Edge[E];

    for(int i=0; i<E; i++){
        cin >> input[i].source;
        cin >> input[i].dest;
        cin >> input[i].weight;
    }

    cout << "Minimum Spanning Tree using Kruskal's Algorithm :- \n";
    kruskal(input, n, E);

}