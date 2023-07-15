#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;


// printDFS and printBFS function prints the connected graphs only
void printDFS(int* *edges, int n, int startingVertex, bool *visited){
    cout << startingVertex << " ";
    visited[startingVertex]=true;
    for(int i=0; i<n; i++){
        if(i==startingVertex){
            continue;
        }

        if(edges[i][startingVertex]==1){
            if(visited[i]){
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int* *edges, int n, int startingVertex, bool visited[]){
    queue<int> pendingVertices;

    pendingVertices.push(startingVertex);
    visited[startingVertex]=true;
    while(!pendingVertices.empty()){
        int front=pendingVertices.front();
        pendingVertices.pop();

        cout << front << " ";

        for(int i=0; i<n; i++){
            if(i==front){
                continue;
            }
            if(edges[i][front]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
    // cout << endl;
}

// DFS and BFS function prints the graph for disconnected graphs also
void DFS(int* *edges, int n){
    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }

    for(int i=0; i<n; i++){
        if(visited[i]==false){
            printDFS(edges, n, i, visited);
        }
    }
}

void BFS(int* *edges, int n){
    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }

    for(int i=0; i<n; i++){
        if(visited[i]==false){
            printBFS(edges, n, i, visited);
        }
    }
}

bool hasPath(int* *edges, int n, int start, int end, bool visited[]){
    int ans=0;
    for(int i=0; i<n; i++){
        if(i==end && edges[start][i]==1){
            return true;
        }

        if(edges[start][i]==1 && start!=i && visited[i]==false){
            visited[start]=true;
            bool x=hasPath(edges, n, i, end, visited);
            if(x){
                ans++;
            }
        }
    }
    if(ans){
        return true;
    }
    else{
        return false;
    }

}

bool hasPath(int* *edges, int n, int start, int end){
    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    return hasPath(edges, n, start, end, visited);
}

vector<int> getPathDFS(int* *edges, int n, int start, int end, vector<int>& pathDFS, bool visited[]){
    if(start==end){
        visited[end]=true;
        pathDFS.push_back(end);
        return pathDFS;
    }
    for(int i=0; i<n; i++){
        // cout << i << "\t" << edges[start][i] << "\t" << start << "\t" << i << "\t" << visited[i] << endl;
        if(edges[start][i]==1 && start!=i && visited[i]==false){
            visited[start]=true;
            getPathDFS(edges, n, i, end, pathDFS, visited);
            if(pathDFS.size()!=0){
                pathDFS.push_back(start);
                return pathDFS;
            }
        }
    }
    return pathDFS;
}

vector<int> getPathDFS(int* *edges, int n, int start, int end, vector<int>& pathDFS){
    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    return getPathDFS(edges, n, start, end, pathDFS, visited);
}


vector<int> getPathBFS(int* *edges, int n, int start, int end, vector<int>& pathBFS, bool visited[]){
    queue<int> pendingVertices;
    unordered_map<int, int> mapu;

    mapu[end]=-1;

    pendingVertices.push(start);
    visited[start]=true;
    while(!pendingVertices.empty()){
        int front=pendingVertices.front();
        pendingVertices.pop();

        
        for(int i=0; i<n; i++){
            if(i==front){
                continue;
            }
            if(edges[i][front]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
                mapu[i]=front;
                if(i==end){
                    break;
                }
            }
        }
        if(mapu[end]>=0){
            break;
        }
    }
    
    if(mapu[end]<0){
        return pathBFS;
    }
    
    int x=end;
    while(x!=start){
        pathBFS.push_back(x);
        x=mapu[x];
    }
    pathBFS.push_back(start);
    return pathBFS;

}

vector<int> getPathBFS(int* *edges, int n, int start, int end, vector<int>& pathBFS){
    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    return getPathBFS(edges, n, start, end, pathBFS, visited);
}

void isConnectedMarker(int* *edges, int n, int startingVertex, bool visited[]){

    visited[startingVertex]=true;
    for(int i=0; i<n; i++){
        if(edges[startingVertex][i]==1 && startingVertex!=i && visited[i]==false){
            isConnectedMarker(edges, n, i, visited);
        }
    }

}


bool isConnected(int* *edges, int n){

    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }

    isConnectedMarker(edges, n, 0, visited);

    for(int i=0; i<n; i++){
        if(visited[i]==false){
            return false;
        }
    }
    return true;

}

void allConnectedComponentsMarker(int* *edges, int n, int startingVertex, bool visited[], vector<int>& x){

    visited[startingVertex]=true;
    x.push_back(startingVertex);
    for(int i=0; i<n; i++){
        if(edges[startingVertex][i]==1 && startingVertex!=i && visited[i]==false){
            allConnectedComponentsMarker(edges, n, i, visited, x);
        }
    }

}


void allConnectedComponents(int* *edges,int n, vector<vector<int>>& ans){

    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }

    vector<int> x;


    for(int i=0; i<n; i++){
        if(visited[i]==false){
            allConnectedComponentsMarker(edges, n, i, visited, x);
            ans.push_back(x);
            x.clear();
        }
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
        int start, end;
        cin >> start >> end;
        edges[start][end]=1;
        edges[end][start]=1;
    }

/*
    // Below visited array is just for printDFS and printBFS function
    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }

    cout << "DFS :- " << endl;
    printDFS(edges, n, 0, visited);

    cout << endl;
    
    for(int i=0; i<n; i++){
        visited[i]=false;
    }

    cout << "BFS :- " << endl;
    printBFS(edges, n, 0, visited);

    cout << endl;
*/
    cout << "DFS(for disconnected graphs also):- " << endl;
    DFS(edges, n);
    cout << endl;

    cout << "BFS(for disconnected graphs also):- " << endl;
    BFS(edges, n);
    cout << endl;


    // CODE FOR "HAS PATH"
    cout << endl;
    cout << "To find whether a path exists, enter source and destination vertex :- ";
    int start, end;
    cin >> start >> end;
    cout << "Path from vertex " << start << " to " << end << " ";
    if(hasPath(edges, n, start, end)){
        cout << "exists!\n";
    }
    else{
        cout << "does not exists!\n";
    }


    // Code for "GET PATH DFS"
    vector<int> pathDFS;
    getPathDFS(edges, n, start, end, pathDFS);
    cout << endl;
    cout << "DFS path from vertex " << start << " to " << end << " :- ";
    if(pathDFS.size()!=0){
        for(int i=pathDFS.size()-1; i>=0; i--){
            cout << pathDFS[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << " does not exists!\n";
    }


    // Code for "GET PATH BFS"
    vector<int> pathBFS;
    getPathBFS(edges, n, start, end, pathBFS);
    cout << endl;
    cout << "BFS path from vertex " << start << " to " << end << " :- ";
    if(pathBFS.size()!=0){
        for(int i=pathBFS.size()-1; i>=0; i--){
            cout << pathBFS[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << " does not exists!\n";
    }

    // Code for "IS CONNECTED"
    if(isConnected(edges, n)){
        cout << "Graph is connected!\n";
    }
    else{
        cout << "Graph is not connected!\n";
    }

    // Code for "ALL CONNECTED COMPONENTS"
    vector<vector<int>> ans;
    allConnectedComponents(edges, n, ans);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i].at(j) << " ";
        }
        cout << endl;
    }


    for(int i=0; i<n; i++){
        delete[] edges[i];
    }
    delete[] edges;

}