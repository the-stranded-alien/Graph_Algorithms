#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
#include<array>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<deque>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#define ll long long int
#define ld long long double
#define PB push_back
#define POB pop_back
#define MP make_pair
#define F first
#define S second
#define nl '\n'
#define tab '\t'
#define pi pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define vii vector< vector<int> >
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Bellman Ford
// -> Weighted Graphs
// -> Single Source Shortest Path (SSSP)
// -> Bellman Ford Works for Graphs with Negative Weight Edges

// 1. Initialize dist[vertices] = INT_MAX, dist[src] = 0
// 2. Relax all edges V-1 times / iterations [Most Important]
// 3. Negative Weight Cycle Detection

// Like Bottom Up DP

// Bellman-Ford Algorithm Function
vector<int> bellman_ford(int V, int src, vector<vector<int> > edges) {
    // Create a Vector
    vector<int> dist((V + 1), INT_MAX);
    dist[src] = 0;
    // Relax All Edges (V - 1) Times
    for(int i = 0; i < (V - 1); i++) {
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if((dist[u] != INT_MAX) && ((dist[u] + wt) < dist[v])) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Negative Weight Cycle
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if((dist[u] != INT_MAX) && ((dist[u] + wt) < dist[v])) {
            cout << "Negative Weight Cycle Found !\n";
            exit(0);
        }
    }
    return dist;
}


int main() {
    FIO;
    int n, m;
    cin >> n >> m;
    // Edge List
    vector<vector<int> > edges;
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    } 
    vector<int> distances = bellman_ford(n, 1, edges);
    for(int i = 1; i <= n; i++) {
        cout << "Node " << i << " Is At Distance : " << distances[i] << nl;
    }
    return 0;
}