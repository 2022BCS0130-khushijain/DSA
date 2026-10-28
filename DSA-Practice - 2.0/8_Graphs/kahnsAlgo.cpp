// Kahns ---- DAG (assume in this form)
// bfs approach
#include <iostream>
#include <queue>
#include <vector> 

using namespace std;

void Kahns(vector<vector<int>> &adj, vector<int> &inDegree, vector<int> &vis){
    queue<int> q;
    int n = adj.size();
    for(int i=0; i<n; i++){
        if(inDegree[i]==0){
            q.push(i);
            vis[i] = 1;
            cout<<i<<" ";
        }
    }
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto neigh : adj[node]){
            inDegree[neigh]--;
            if(!vis[neigh]){
                if(inDegree[neigh] == 0){
                    vis[neigh] = 1;
                    q.push(neigh);
                    cout<<neigh<<" ";
                }
            }
        }
    }
}

int main(){
    int V = 7;
    vector<vector<int>> adj = {
        {6}, {2}, {0}, {6}, {1,2}, {4,3}, {}
    };

    vector<int> vis(V, 0);
    vector<int> inDegree = {1,1,2,1,1,0,2};

    Kahns(adj, inDegree, vis);

    return 0;
}