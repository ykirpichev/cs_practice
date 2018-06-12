
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
using Graph = vector<vector<int>>;


vector<int> bfs(const Graph& g, int s)
{
    vector<int> result;
    vector<bool> visited(g.size());
    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        auto v = q.front();
        result.push_back(v);
        q.pop();

        for (auto u: g[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    return result;
}


int main(int argc, char* argv[])
{
    auto result = bfs({{1}, {0}}, 0);

    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
