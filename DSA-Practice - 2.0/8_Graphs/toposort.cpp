// Toposort ---- DAG (assume in this form) [u->v] u come before v
// DFS approach
#include <iostream>
#include <vector> 
#include <stack>

using namespace std;

void topoDFS(int node, vector<vector<int>> &adj, stack<int> &s, vector<int> &vis){
    vis[node] = 1;

    for(auto neigh : adj[node]){
        if(!vis[neigh]){
            topoDFS(neigh, adj, s, vis);
        }
    }
    s.push(node);
}

int main(){
    int V = 7;
    vector<vector<int>> adj = {
        {6}, {2}, {0}, {6}, {1,2}, {4,3}, {}
    };

    stack<int> st;
    vector<int> vis(V, 0);

    for(int i=0; i<V; i++){
        if(!vis[i]){
            topoDFS(i, adj, st, vis);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}