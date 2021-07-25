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

// Minimum Spanning Tree 
// Given a Connected, Undirected and Weighted Graph 'G', Select a Subset of Edges E'
// Such That Graph G is Connected and Total Weight of Selected Edges E' is Minimum.
// (V - 1) Edges to From a Tree and Keep the Graph Connected.

// Prim's Algorithm for MST
// Weighted Undirected Graph
// Greedy Algorithm
// Uses a Priority Queue
// Terms -> 
// 1. MST Set 
// 2. Active Edge : Edge from a Vertex in MST Set to V.
// 3. MST Edge : An Edge that has been Included in MST So Far.
// Algorithm ->
// 1. Start from Any Source Vertex
// 2. Out of All Active Edges, Pick the One with Smallest Weight.
//     - Select in Y in MST.
//     - Add Edges Starting from Y in the Active Edge List.

class Graph {
    // Adjacency List
    vector<pair<int, int> > *l;
    int V;
public:
    Graph(int n) {
        V = n;
        l = new vector<pair<int, int> >[n];
    }
    void addEdge(int x, int y, int w) {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }
    int prim_mst() {
        // Initialize a Min Heap
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
        // Visited Array That Denotes Whether a Node Has Been Included in MST or Not.
        bool *visited = new bool[V]{0};
        int ans = 0;
        // Begin
        Q.push({0, 0}); // Weight Node
        while(!Q.empty()) {
            // Pick Out the Edge with Minimum Weight
            auto best = Q.top();
            Q.pop();
            int to = best.second;
            int weight = best.first;
            if(visited[to]) {
                // Discard The Edge And Continue
                continue;
            }
            // Otherwise Take The Current Edge
            ans += weight;
            visited[to] = true;
            // Add the New Edges in the Queue
            for(auto x : l[to]) {
                if(visited[x.first] == false) {
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};

int main() {
    FIO;
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 3);
    cout << g.prim_mst() << nl;
    return 0;
}