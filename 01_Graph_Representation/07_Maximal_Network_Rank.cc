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

// The network rank of two different cities is defined as the total number of directly
// connected roads to either city. If a road is directly connected to both cities, it is
// counted once. Maximal network rank of the infrastructure is the maximum network rank of
// all pairs of different cities.

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
        l[y].PB(x);
    }
    bool areTwoVerticesConnected(int x, int y) {
        for(int cnt : l[x]) {
            if(cnt == y) return true;    
        }
        return false;
    }
    int numberOfConnections(int x) {
        return (l[x].size());
    }
};

int maximalNetworkRank(int n, vector<vector<int>> roads) {
    Graph cities(n);
    for(auto road : roads) cities.addEdge(road[0], road[1]);
    int maxNetworkRank = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = (i + 1); j < n; j++) {
            int curNetworkRank = 0;
            int c1 = cities.numberOfConnections(i);
            int c2 = cities.numberOfConnections(j);
            bool twoCncted = cities.areTwoVerticesConnected(i, j);
            if(twoCncted) curNetworkRank = c1 + c2 - 1;
            else curNetworkRank = c1 + c2;
            if(maxNetworkRank < curNetworkRank) maxNetworkRank = curNetworkRank;
        }
    }
    return maxNetworkRank;
}

int main() {
    FIO;
    vector< vector<int> > roads;
    roads.PB({0,1});
    roads.PB({0,3});
    roads.PB({1,2});
    roads.PB({1,3});
    int n = 4;
    cout << maximalNetworkRank(n, roads);
    return 0;
}