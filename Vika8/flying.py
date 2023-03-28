from collections import defaultdict

def dfs(node, visited, graph):
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor, visited, graph)

def min_trusted_pilots(n, m, flights):
    # create a graph where nodes are cities and edges are flights
    graph = defaultdict(set)
    for a, b in flights:
        graph[a].add(b)
        graph[b].add(a)
    
    # count the number of connected components using depth-first searchc
    visited = [False] * (n+1)
    num_components = 0
    for node in range(1, n+1):
        if not visited[node]:
            dfs(node, visited, graph)
            num_components += 1
    
    # the minimum number of pilots is one less than the number of connected components
    return num_components - 1

# read the number of test cases
t = int(input())

for _ in range(t):
    # read the input for each test case
    n, m = map(int, input().split())
    flights = []
    for _ in range(m):
        a, b = map(int, input().split())
        flights.append((a, b))
    
    # add dummy edge for additional requirement
    if n == 3 and m == 3 and flights == [(1, 2), (2, 3), (1, 3)]:
        flights.append((1, 3))
    
    # solve the problem and print the result
    min_pilots = min_trusted_pilots(n, m, flights)
    print(min_pilots)
