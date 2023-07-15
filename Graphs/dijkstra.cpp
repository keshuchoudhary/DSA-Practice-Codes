#include<iostream>
#include<climits>
using namespace std;


int findMinDistanceVertex(int distance[], bool visited[], int n){

    int minDistanceVertex=-1;
    for(int i=0; i<n; i++){
        if(visited[i]==false && ( minDistanceVertex==-1 || distance[minDistanceVertex]>distance[i] ) ){
            minDistanceVertex=i;
        }
    }
    return minDistanceVertex;
}

void dijkstra(int* *edges, int n, int sourceVertex){

    bool visited[n];
    int distance[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[sourceVertex]=0;

    for(int i=0; i<n; i++){

        int minDistanceVertex=findMinDistanceVertex(distance, visited, n);
        visited[minDistanceVertex]=true;
        for(int j=0; j<n; j++){
            if(visited[j]==false && edges[minDistanceVertex][j]!=0){
                int dist=distance[minDistanceVertex]+edges[minDistanceVertex][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }


    }

    // Printing result
    for(int i=0; i<n; i++){
        cout << i << " " << distance[i] << endl;
    }

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
    dijkstra(edges, n, 0);


    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;




}