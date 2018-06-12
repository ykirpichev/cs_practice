
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
using Graph = vector<vector<int>>;


void doDfs(const Graph& g, int u, vector<bool>& visited, vector<int>& result)
{
    visited[u] = true;
    result.push_back(u);

    for (auto v: g[u]) {
        if (!visited[v]) {
            doDfs(g, v, visited, result);
        }
    }
}

vector<int> dfs(const Graph& g, int s)
{
    vector<int> result;
    vector<bool> visited(g.size());

    doDfs(g, s, visited, result);
    return result;
}


int main(int argc, char* argv[])
{
    auto result = dfs({{1}, {0}}, 0);

    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
