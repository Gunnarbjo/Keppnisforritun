#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
int Graph(int v) {
    ll V = v;
    adj.resize(V);
}

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    ll n, m;
    cin>>n>>m;
    ll arr[(n*m)-1];
    Graph g(n*m);
    
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin>>arr[i];            
        }
    }
}