#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// NOTE : we considered nodes are 0-n no duplicates, 
//        connected component ,  undirected


void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
    vis[node] = 1;
    cout<<node<<" ";

    for(int i=0; i<adj[node].size(); i++){
        if(!vis[adj[node][i]]){
            dfs(adj[node][i], adj, vis);
        }
    }
}


int main(){
    vector<vector<int>> adj = {
        {1,2}, {0,6}, {0,3}, {2,4,5}, {3}, {3}, {1}
    };
    vector<int> vis(adj.size(), 0);
    /*
    0 - 1 - 6
    |
    2 - 3 - 4
        |
        5

    bfs : 0 1 2 6 3 4 5
    dfs : 0 1 6 2 3 4 5

    0 - 1,2
    1 - 0,6
    2 - 0,3
    3 - 2,4,5
    4 - 3
    5 - 3
    6 - 1
    */

    dfs(0, adj, vis);
    
    return 0;
}