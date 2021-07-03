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

// BFS Shortest Path Undirected Graph !
// Single Source Shortest Path Algorithm for Undirected Graph

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
    void bfsShortestPath(int source, int dest = -1) {
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *dist = new int[V]{0};
        int *parent = new int[V];
        for(int i = 0; i < V; i++) {
            parent[i] = -1;
        }

        q.push(source);
        visited[source] = true;
        parent[source] = source;
        dist[source] = 0;

        while(!q.empty()) {
            // Do some work for every node
            int f = q.front();
            q.pop();
            // Push the nbrs of current node inside the queue 
            // if they are not already visited.
            for(auto nbr : l[f]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    // Parent & Distance
                    parent[nbr] = f;
                    dist[nbr] = dist[f] + 1;
                    visited[nbr] = true;
                }
            }
        }
        // Print the shortest distance
        for(int i = 0; i < V; i++) {
            cout << "Shortest Distance To " << i << " is " << dist[i] << nl;
        }
        // Print the path from a source to any dest
        if(dest != -1) {
            int temp = dest;
            while(temp != source) {
                cout << temp << " -- ";
                temp = parent[temp];
            }
            cout << source << nl;
        }
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
    g.bfsShortestPath(1, 6); 
    return 0;
}