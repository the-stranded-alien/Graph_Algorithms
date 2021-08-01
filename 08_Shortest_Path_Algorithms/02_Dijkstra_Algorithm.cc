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

// Dijkstra's Algorithm 
// -> Weighted Graphs
// -> Single Source Shortest Paths (SSSP)

class Graph {
    int V;
    list<pair<int, int> > *l;
public:
    Graph(int v) {
        V = v;
        l = new list<pair<int, int> >[V];
    }
    void addEdge(int u, int v, int wt, bool undir = true) {
        l[u].push_back({wt, v});
        if(undir) l[v].push_back({wt, u});
    }
    int dijkstra(int src, int dest) {
        // Data Structures
        vector<int> dist(V, INT_MAX);
        set<pair<int, int> > s;
        // 1. Initialize
        dist[src] = 0;
        s.insert({0, src});
        // 2. Pop Out One Pair At A Time & Do Some Work
        while(!s.empty()) {
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it); // Pop
            // Iterate Over The Neighbours of Node
            for(auto nbrPair : l[node]) {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;
                if(distTillNow + currentEdge < dist[nbr]) {
                    // Remove If Neighbour Already Exists in Set
                    auto f = s.find({dist[nbr], nbr});
                    if(f != s.end()) s.erase(f);
                    // Insert the Updated Value With the New Dist
                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }        
        // Single Source Shortest Distance to All Other Nodes
        for(int i = 0; i < V; i++) cout << "Source : "  << src << " & Dest : " << i << " => Dist : " << dist[i] << nl;
        return dist[dest];
    }
};

int main() {
    FIO;
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);  
    g.addEdge(0, 2, 4);  
    g.addEdge(0, 3, 7);  
    g.addEdge(3, 2, 2);  
    g.addEdge(3, 4, 3);  
    cout << g.dijkstra(0, 4) << nl;
    return 0;
}