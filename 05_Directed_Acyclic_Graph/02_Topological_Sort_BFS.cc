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

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int v) {
        this->V = v;
        this->l = new list<int>[V]; 
    }
    void addEdge(int x, int y) {
        l[x].PB(y); // Directed Graph
    }
    void topologicalSort() {
        vi indegree(V, 0);
        // Iterate Over All the Edges to Find the Right Indegree
        for(int i = 0; i < V; i++) {
            for(auto nbr : l[i]) indegree[nbr]++;
        }
        // BFS
        queue<int> q;
        // Init the Queue with nodes having 0 indegree
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        // Start Popping
        while(!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop();
            // Iterate Over The Nbrs of this Node and Reduce their Indegree by 1
            for(auto nbr : l[node]) {
                indegree[nbr]--;
                // If Indegree of Any Nbr Becomes 0 Push it Into the Queue
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
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
    g.topologicalSort();
    return 0;
}