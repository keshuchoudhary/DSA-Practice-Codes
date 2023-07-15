#include <iostream>
#include <climits>
using namespace std;

int findMinWeightVertex(int* weight, bool* visited, int n){

    int minWeightVertex=-1;
    for(int i=0; i<n; i++){
        if(visited[i]==false && (minWeightVertex==-1 || weight[i]<weight[minWeightVertex]) ){
            minWeightVertex=i;
        }
    }

    return minWeightVertex;

}

void printMST(int* parent, int* weight, int size){
    for(int i=1; i<size; i++){
        cout << i << " " << parent[i] << " " << weight[i] << endl;
    }
}

void prims(int* *edges, int n){

    int* parent=new int[n];
    int* weight=new int[n];

    bool* visited=new bool[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
        weight[i]=INT_MAX;
    }

    weight[0]=0;
    parent[0]=-1;
    for(int i=0; i<n; i++){
        int minWeightVertex=findMinWeightVertex(weight, visited, n);
        visited[minWeightVertex]=true;
        for(int j=0; j<n; j++){
            if(visited[j]==false && edges[minWeightVertex][j]!=0){
                if(weight[j]>edges[minWeightVertex][j]){
                    weight[j]=edges[minWeightVertex][j];
                    parent[j]=minWeightVertex;
                }
            }
        }


    }

    printMST(parent, weight, n);


}

int main(){

    int n, e;
    cin >> n >> e;

    int* *edges=new int*[n];
    for(int i=0; i<n; i++){
        edges[i]=new int[n];
        for(int j=0; j<n; j++){
            edges[i][j]=0;
        }
    }

    for(int i=0; i<e; i++){
        int s, d, w;
        cin >> s >> d >> w;
        edges[s][d]=w;
        edges[d][s]=w;
    }

    cout << endl;

    prims(edges, n);

    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;


}