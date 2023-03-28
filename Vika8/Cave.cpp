#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<vector<LL>> Graph;
typedef pair<LL, LL> Edge;
typedef vector<bool> BoolVec;
typedef vector<LL> IntVec;

LL dfs_time = 0;

void find_bridges(Graph& adj, vector<Edge>& bridges, BoolVec& vis, IntVec& parent, IntVec& high, IntVec& low, LL curr) {
    vis[curr] = true;
    high[curr] = low[curr] = ++dfs_time;
    for (auto next : adj[curr]) {
        if (!vis[next]) {
            parent[next] = curr;
            find_bridges(adj, bridges, vis, parent, high, low, next);
            low[curr] = min(low[curr], low[next]);
            if (low[next] > high[curr]) {
                bridges.push_back({next, curr});
            }
        }
        else if (next != parent[curr]) {
            low[curr] = min(low[curr], high[next]);
        }
    }
}

LL dfs(Graph& adj, BoolVec& vis, set<Edge>& skip, LL curr) {
    vis[curr] = true;
    LL total = 1;
    for (auto next : adj[curr]) {
        if (vis[next]) {
            continue;
        }
        if (skip.count({curr, next}) || skip.count({next, curr})) {
            continue;
        }
        total += dfs(adj, vis, skip, next);
    }
    return total;
}

int main() {
    LL num_vertices, num_edges;
    cin >> num_vertices >> num_edges;
    Graph adj(num_vertices);
    for (int i = 0; i < num_edges; i++) {
        LL v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    vector<Edge> bridges;
    BoolVec vis(num_vertices, false);
    IntVec parent(num_vertices, -1);
    IntVec high(num_vertices, -1);
    IntVec low(num_vertices, -1);
    find_bridges(adj, bridges, vis, parent, high, low, 0);
    set<Edge> skip;
    for (auto i : bridges) {
        skip.insert(i);
    }
    for (int i = 0; i < num_vertices; i++) {
        vis[i] = false;
    }
    cout << dfs(adj, vis, skip, 0) << '\n';
    return 0;
}
