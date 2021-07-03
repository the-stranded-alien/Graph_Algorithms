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
#define vii vector< vector<int> >
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Cycle -> You have a way to visit a node more than once

class Graph {
    list<int> *l;
    int V;
public:
    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }
    // Undirected Graph
    void addEdge(int x, int y) {
        l[x].PB(y);
        l[y].PB(x);
    }

    bool dfs(int node, vector<bool> &visited, int parent) {
        // Mark that node visited
        visited[node] = true;
        for(auto nbr : l[node]) {
            if(!visited[nbr]) {
                bool nbrFoundACycle = dfs(nbr, visited, node);
                if(nbrFoundACycle) return true;
            } 
            // Nbr is visited and its not the parent of current node in the current dfs call
            else if(nbr != parent) return true; // Check for parent
        }
        return false;
    }

    bool containsCycle() {
        // Assuming Graph Is A Single Component !
        vector<bool> visited(V, false);
        return dfs(0, visited, -1);
    }

    // For Submission
    bool contains_cycle(int V, vector<pair<int, int> > edges) {
        Graph g(V);
        for(auto edge : edges) {
            g.addEdge(edge.F, edge.S);
        }
        return g.containsCycle();
    }
};

int main() {
    FIO;
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    cout << g.containsCycle() << endl;
    return 0;
}