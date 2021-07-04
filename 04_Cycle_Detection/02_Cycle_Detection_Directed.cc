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

// Cycle Detection in Directed Graphs
// Whether the graph contains a BACKEDGE or not.

// O(V+E) Time

class Graph {
    list<int> *l;
    int V;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y) {
        l[x].PB(y);
    }
    bool dfs(int node, vector<bool> &visited, vector<bool> &stack) {
        // Return True if BACKEDGE is Found, Else False
        // Arrive at a node
        visited[node] = true;
        stack[node] = true;
        // Do Some work at node, return true if backedge is found here itself
        for(int nbr : l[node]) {
            if(stack[nbr] == true) return true; // Node immediately leads to backedge
            else if(visited[nbr] == false) { // Nbr rescursively leads to backedge
                bool nbrFoundACycle = dfs(nbr, visited, stack);
                if(nbrFoundACycle) return true;
            }
        }
        // Going Back
        stack[node] = false;
        return false;
    }

    // Wrapper function over main dfs function as we
    // want to create these data structures only once !
    bool containsCycle() { 
        vector<bool> visited(V, false);
        vector<bool> stack(V, false);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, visited, stack)) return true;
            }
        }
        return false;
    }
};

// For submission
bool contains_cycle(int V, vector<pair<int, int> > edges) {
    Graph g(V);
    for(auto edge : edges) g.addEdge(edge.first, edge.second);
    return g.containsCycle();
}

int main() {
    FIO;
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    cout << g.containsCycle() << nl;
    return 0;
}