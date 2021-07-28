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

// Kruskal's Algorithm for MST
// Greedy Algorithm
// Stores Graph as a Edge List
// DSU for Detecting Cycle
// Time : O(E log V)

// 1. Sort all edges based upon weight.
// 2. Pick the next smallest edge and add it to MST if it doesn't make a cycle. 

// DSU Data Structure (Path Compression + Union by Rank)
class DSU {
    int *parent;
    int *rank;
public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        // Init Parent : -1, Rank : 1
        for(int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    // Find Function
    int find(int i) {
        // Base Case
        if(parent[i] == -1) return i;
        // Recursive Case (Path Compression)
        return (parent[i] = find(parent[i]));
    }
    // Unite (Union) Function
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if(s1 != s2) {
            // Union By Rank
            if(rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    vector<vector<int> > edgeList;
    int V;
public:
    Graph(int V) {
        this->V = V;
    }
    void addEdge(int x, int y, int w) {
        edgeList.push_back({w, x, y});
    }
    int kruskal_MST() {
        // 1. Sort all the edges based upon weight
        sort(edgeList.begin(), edgeList.end());
        int ans = 0;
        // Init a DSU
        DSU s(V);
        for(auto edge : edgeList) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            // Take That Edge in MST if it Doesn't Form a Cycle
            if(s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main() {
    FIO;
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    cout << g.kruskal_MST() << nl;
    return 0;
}