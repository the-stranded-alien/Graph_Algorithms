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

// DSU Optimisations
// 1. Union By Rank (Union Function)
// 2. Path Compression Optimisation in DSU (Find Function)


// 1. Union By Rank : Store the Rank (No of Nodes) of Each Set. 
// And Attach The Smaller Tree With The Bigger Tree

// After these Two Optimisations The Complexity of Both Operations and DSU becomes O(1).


class Graph {
    int V;
    list<pair<int, int> > l;
public:
    Graph(int V) {
        this->V = V;
    }
    int addEdge(int u, int v) {
        l.push_back(make_pair(u, v));
    }
    // Find (Path Compression)
    int findSetOptimized(int i, int parent[]) {
        // Base Case
        if(parent[i] == -1) return i;
        // Recursive Case
        // Path Compression Optimization
        return (parent[i] = findSetOptimized(parent[i], parent));
    }

    // Union By Rank
    void unionSetOptimized(int x, int y, int parent[], int rank[]) {
        int s1 = findSetOptimized(x, parent);
        int s2 = findSetOptimized(y, parent);
        if(s1 != s2) {
            if(s1 != s2) {
                if(rank[s1] < rank[s2]) {
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                } else {
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }
            } 
        }
    }
    
    // Cycle Detection using DSU Logic
    bool containsCycleOptimized() {
        // DSU Logic to Check if Graph Contains Cycle or Not
        int *parent = new int[V+1];
        int *rank = new int[V+1];
        for(int i = 0; i < V; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
        // Iterate Over The Edge List
        for(auto edge : l) {
            int i = edge.first;
            int j = edge.second;
            int s1 = findSetOptimized(i, parent);
            int s2 = findSetOptimized(j, parent);
            if(s1 != s2) unionSetOptimized(s1, s2, parent, rank);
            else {
                // cout << "Same Parents : " << s1 << " and " << s2 << nl;
                return true;
            }
        }
        delete [] parent;
        return false;
    }
};  


int main() {
    FIO;
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    cout << g.containsCycleOptimized() << nl;
    return 0;
}