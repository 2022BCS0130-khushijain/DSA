#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// NOTE : we considered nodes are 0-n no duplicates, 
//        connected component 
void bfs(vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> vis(n, 0); // 0 - unvisited
    queue<int> q;

    q.push(0);
    vis[0] = 1;

    while(!q.empty()){
        int node = q.front(); q.pop();
        cout<<node<<" ";
        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                vis[neigh]= 1;
                q.push(neigh);
            }
        }
    }
}


int main(){
    vector<vector<int>> adj = {
        {1,2}, {0,6}, {0,3}, {2,4,5}, {3}, {3}, {1}
    };
    
    /*
    0 - 1 - 6
    |
    2 - 3 - 4
        |
        5

    bfs : 0 1 2 6 3 4 5

    0 - 1,2
    1 - 0,6
    2 - 0,3
    3 - 2,4,5
    4 - 3
    5 - 3
    6 - 1
    */

    bfs(adj);
    
    return 0;
}