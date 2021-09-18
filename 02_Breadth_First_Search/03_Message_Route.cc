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

// There is a network of N computers, each computer is numbered 1 to N.
// The computer network is given as an array of edges where edges[i] = [ui, vi] is a
// bidirectional edge that connects computer ui and computer vi.
// Your task is to find if Alice can send a message to Bob, if it possible, return
// minimum number of computers on such a route and if it is not possible than return -1.
// Alice's computer is 1 and Bob's Computer is N.

class Graph {
private:
    int V;
    list<int> *l;
public:
    Graph(int v) {
        this->V = v;
        this->l = new list<int>[V];
    }
    void addEdge(int u, int v, bool bidir = true) {
        l[u].push_back(v);
        if(bidir) l[v].push_back(u);
    }
    void printGraph() {
        for(int i = 0; i < V; i++) {
            cout << (i + 1) << " -> ";
            for(auto ele : l[i]) cout << (ele + 1) << " ";
            cout << endl;
        }
    }
    void bfs(int src) {
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(src);
        visited[src] = true;
        while(!q.empty()) {
            int cur = q.front();
            cout << cur << " ";
            q.pop();
            for(auto nbr : l[cur]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    int bfsShortestPath(int src, int dest) {
        queue<int> q;
        bool *visited = new bool[V]{0};
        // int *parent = new int[V];
        int *dist = new int[V]{0};
        // for(int i = 0; i < V; i++) parent[i] = -1;
        visited[src] = true;
        // parent[src] = src;
        dist[src] = 0;
        q.push(src);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto nbr : l[cur]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    // parent[nbr] = cur;
                    dist[nbr] = dist[cur] + 1;
                }
            }
        }
        if(dist[dest] == 0) return -1;
        else return (dist[dest] + 1);
    }
};

int messageRoute(int n, vector<vector<int> > edges) {
    Graph g(n);
    for(auto edge : edges) {
        g.addEdge((edge[0] - 1), (edge[1] - 1));
    }
    int res = g.bfsShortestPath(0, n - 1);
    return res;
}

int main() {
    FIO;
    int n = 3;
    vii edges = {{1, 3}, {1, 2}, {2, 3}};
    messageRoute(n, edges);
    return 0;
}