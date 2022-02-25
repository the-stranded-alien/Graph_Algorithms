#include<bits/stdc++.h>
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

const int N = 1e5;

vector<int> gr[N];

int vis[N];
int disc[N];
int low[N];
int time = 1;

vector<pair<int, int> > bridges;
set<int> articulationPoints;

void dfs(int cur, int par) {
    vis[cur] = 1;
    disc[cur] = low[cur] = time++;
    int child = 0;
    for(auto x : gr[cur]) {
        if(!vis[x]) {
            dfs(x, cur);
            child++;
            // We know low and disc of x
            low[cur] = min(low[cur], low[x]);
            // Bridges
            if(low[x] > disc[cur]) bridges.push_back({cur, x});
            // Articulation Points
            if(par != 0 && low[x] >= disc[cur]) {
                articulationPoints.insert(cur);
            }
        } else if(x != par) { // Backedge
            low[cur] = min(low[cur], disc[x]);
        }
    }
    // Root is an articulation point or not
    if(par == 0 && child > 1) {
        articulationPoints.insert(cur);
    }
    return;

}

int main() {
    FIO;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }    
    dfs(1, 0);
    return 0;
}