#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> adj;
class Graph {
    
public:
    Graph(int v) {
        ll V = v;
        adj.resize(V);
    }
    
    // Function to add an undirected edge between two vertices
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

void printGraph(vector<vector<int>>& graph) {
    for(int i=0; i<graph.size(); i++) {
        cout << i << " -> ";
        for(int j=0; j<graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ll buildings, tunnels,temp1,temp2;
    cin >> buildings >> tunnels;
    Graph g(buildings);
    for(ll i=0;i<tunnels;i++){
        cin >> temp1 >> temp2;
       g.addEdge(temp1,temp2);
       cout<<"hello\n";
    }

    printGraph(adj);
}