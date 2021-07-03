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

class Node {
public:
    string name;
    list<string> nbrs;

    Node(string name) {
        this->name = name;
    }
};

class Graph {
    // All Nodes
    // Hashmap (String, Node *)
    unordered_map<string, Node*> map;
public:
    Graph(vector<string> cities) {
        for(auto city : cities) map[city] = new Node(city);
    }
    void addEdge(string x, string y, bool undir = true) {
        map[x]->nbrs.PB(y);
        if(undir) map[y]->nbrs.PB(x);
    }
    void printAdjList() {
        for(auto cityPair : map) {
            auto cityName = cityPair.F;
            Node *node = cityPair.S;
            cout << cityName << " --> ";
            for(auto nbr : node->nbrs) {
                cout << nbr << ", ";
            }
            cout << nl;
        }
    }
};

int main() {
    FIO;
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");
    g.printAdjList();
    return 0;
}