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

// You can divide all vertices of a graph in 2 sets
// such that all edges of the graph are from set1 to set2.
// Odd Length Cycle -> Not a Bipartite Graph

bool dfs_helper(vi graph[], int node, int *visited, int parent, int color) {
    // Come to node
    visited[node] = color; // 1 or 2, both mean visited
    for(auto nbr : graph[node]) {
        if(visited[nbr] == 0) {
            int subprob = dfs_helper(graph, nbr, visited, node, (3 - color));
            if(subprob == false) return false;
        }
        else if(nbr != parent && color == visited[nbr]) return false;
    }
    return true;
}

bool dfs(vector<int> graph[], int N) {
    int visited[N] = {0}; // 0 : Not visited, 1 : Visited & Color 1, 2 : Visited & Color 2
    int color = 1;
    bool ans = dfs_helper(graph, 0, visited, -1, color);
    // Colors
    for(int i = 0; i < N; i++) cout << i << " - Color " << visited[i] << nl;
    return ans;
}

int main() {
    FIO;
    int N, M;
    cin >> N >> M;
    vector<int> graph[N];
    while(M--) {
        int x, y;
        cin >> x >> y;
        graph[x].PB(y);
        graph[y].PB(x);
    }
    // BFS or DFS, by Coloring the nodes at each step
    // (Current node has color 1, nbr should have a color 2)
    // Odd length cycle means that graph is not Bipartite
    if(dfs(graph, N)) cout << "Yes, it's Bipartite";
    else cout << "It's Not Bipartite";
    return 0;
}