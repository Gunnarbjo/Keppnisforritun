from collections import defaultdict

def kruskal(n, edges):
    parent = list(range(n))
    rank = [0] * n
    tree_edges = []

    def find(u):
        if parent[u] != u:
            parent[u] = find(parent[u])
        return parent[u]

    def union(u, v):
        pu, pv = find(u), find(v)
        if rank[pu] > rank[pv]:
            parent[pv] = pu
        else:
            parent[pu] = pv
            if rank[pu] == rank[pv]:
                rank[pv] += 1

    for w, u, v in sorted(edges):
        if find(u) != find(v):
            union(u, v)
            tree_edges.append((w, u, v))

    return tree_edges

def main():
    buildings, tunnels = map(int, input().split())
    edges = []
    for i in range(tunnels):
        a, b = map(int, input().split())
        edges.append((1, a-1, b-1)) # All edges have weight 1

    tree_edges = kruskal(buildings, edges)

    if len(tree_edges) == buildings - 1:
        print(0)
    else:
        num_additional_tunnels = buildings - 1 - len(tree_edges)
        print(num_additional_tunnels)

if __name__ == '__main__':
    main()
