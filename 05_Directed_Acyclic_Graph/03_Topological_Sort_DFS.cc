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

// O(V+E) Time

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V) {
        this->V = V;
        this->l = new list<int>[V];
    }
    void addEdge(int x, int y) {
        l[x].PB(y);
    }
    void dfs(int node, vb &visited, list<int> &ordering) {
        visited[node] = true;
        for(int nbr : l[node]) {
            if(!visited[nbr]) {
                dfs(nbr, visited, ordering);
            }
        }
        // At this point, we are backtracking
        ordering.push_front(node);
        return;
    }
    void dfs_topologicalSort() {
        vb visited(V, false);
        list<int> ordering;
        // We call dfs from every node if it is not visited
        for(int i = 0; i < V; i++) {
            if(!visited[i]) dfs(i, visited, ordering);
        }
        // Finally print the ordering
        for(auto node : ordering) cout << node << " ";
        cout << nl;
    }
};

int main() {
    FIO;
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(1, 4);
    g.addEdge(1, 2);
    g.dfs_topologicalSort();
    return 0;
}