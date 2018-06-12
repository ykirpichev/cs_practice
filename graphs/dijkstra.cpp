#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits> // for numeric_limits
#include <utility> // for pair
#include <set>

using namespace std;

using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;

void dijkstra(const Graph& g, int s)
{
    set<pair<int, int>> q;
    vector<int> d(g.size(), numeric_limits<int>::max());

    d[s] = 0;
    q.insert(make_pair(d[s], s));

    while (!q.empty()) {
        auto iter = q.begin();
        auto u = iter->second;
        // TODO: push result here or remember visiting order
        cout << "distance to " << u << " is " << iter->first << endl;
        q.erase(iter);

        for (auto edge: g[u]) {
            auto v = edge.first;
            auto w = edge.second;
            auto dv = d[u] + w;
            if (dv < d[v]) {
                q.erase(make_pair(d[v], v));
                d[v] = dv;
                q.insert(make_pair(d[v], v));
            }
        } 
    }
}

int main(int argc, char* argv[])
{
    Graph g(3);

    g[0].push_back({1, 2});
    g[0].push_back({2, 3});
    g[1].push_back({0, 2});
    g[1].push_back({2, 0});
    g[2].push_back({0, 2});
    g[2].push_back({1, 3});

    dijkstra(g, 0);

    return 0;
}
