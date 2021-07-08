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

// Connected Trio is a set of three nodes where there is an edge between 
// every pair of them. The degree of a connected trio is the number of
// edges where one endpoint is in the trio and other is not.

int minTrioDegree(int n, vector<vector<int>> edges) {
    bool mat[400][400] = {0};
    for(auto edge : edges) {
        mat[edge[0] - 1][edge[1] - 1] = 1;
        mat[edge[1] - 1][edge[0] - 1] = 1;
    }
    int min_degree = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = (i + 1); j < n; j++) {
            for(int k = (j + 1); k < n; k++) {
                // Check if it is a Trio
                if(mat[i][j] == 1 && mat[j][k] == 1 && mat[k][i] == 1) {
                    // Find Degree of the Trio
                    int degree = -6;
                    for(int x = 0; x < n; x++) {
                        if(mat[i][x] == 1) degree++;
                        if(mat[j][x] == 1) degree++;
                        if(mat[k][x] == 1) degree++;
                    }
                    if(min_degree > degree) {
                        min_degree = degree;  
                    }                  
                } 
            }
        }
    }
    if(min_degree == INT_MAX) return -1;
    else return min_degree;
}

int main() {
    FIO;
    int n = 6;
    vector< vector<int> > edges;
    edges.PB({1,2});
    edges.PB({1,3});
    edges.PB({3,2});
    edges.PB({4,1});
    edges.PB({5,2});
    edges.PB({3,6});
    cout << minTrioDegree(n, edges);   
    return 0;
}