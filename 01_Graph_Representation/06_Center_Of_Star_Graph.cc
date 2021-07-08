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

// Find the central node in a star network

int findCenter(vector< vector<int> > edges) {
    int node1 = edges[0][0];
    int node2 = edges[0][1];
    int c1 = edges[1][0];
    int c2 = edges[1][1];
    if(c1 == node1 || c1 == node2) return c1;
    else return c2;
}

int main() {
    FIO;
    vector< vector<int> > edges;
    edges.PB({1,2});
    edges.PB({2,3});
    edges.PB({4,2});
    cout << findCenter(edges);
    return 0;
}