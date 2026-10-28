#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


// NOTE : we considered nodes are 0-n no duplicates, 
//        connected component , undir

/*
Dijkstra - shortest path - positive edge only (works for cycles)

dis : inf inf inf inf inf 
bfs traverse each 
*/


void dijkstra(vector<vector<pair<int,int>>> &adj, vector<int> &dist){

    dist[0] = 0;

    // {distance, node}; smallest distance comes first
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0,0});

    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        for(auto neigh : adj[u]){
            int v = neigh.first, wt = neigh.second;
            if(dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
}


int main(){
    // Edge List
    vector<vector<pair<int,int>>> adj = {
        // u->{v, wt}
        {{1,3},{2,2}},{{0,3},{6,4}},{{0,2},{3,1}},{{2,1},{4,4},{5,2}},{{3,4}},{{3,2}},{{1,4}}
    };
    int n = 7;
    vector<int> dist(n, INT_MAX);

    /*
    0 - 1 - 6
    |
    2 - 3 - 4
        |
        5

    bfs : 0 1 2 6 3 4 5
    dfs : 0 1 6 2 3 4 5
    dist: 0 3 2 3 7 5 7

    0 - 1,2
    1 - 0,6
    2 - 0,3
    3 - 2,4,5
    4 - 3
    5 - 3
    6 - 1
    */

    dijkstra(adj, dist);

    for(int i=0; i<dist.size(); i++){
        cout<<dist[i]<<" ";
    }
    
    return 0;
}