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

// DFS => Recursion / Stack
// O(V+E) Time

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int i, int j, bool undir = true) {
        l[i].PB(j);
        if(undir) l[j].PB(i);
    }

    void dfsHelper(int node, bool *visited) {
        visited[node] = true;
        cout << node << ", ";
        // Make a dfs call on all its unvisited neighbours
        for(int nbr : l[node]) {
            if(!visited[nbr]) {
                dfsHelper(nbr, visited);
            }
        }
        return;
    }

    void dfs(int source) {
        bool *visited = new bool[V]{0};
        dfsHelper(source, visited);
    }
 
};

int main() {
    FIO;
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.dfs(1);
    return 0;
}