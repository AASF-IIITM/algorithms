import heapq


def dijkstra(graph, start, end):
    """Return the cost of the shortest path between vertices start and end.
    >>> dijkstra(G, "E", "C")
    6
    >>> dijkstra(G2, "E", "F")
    3
    >>> dijkstra(G3, "E", "F")
    3
    """

    heap = [(0, start)]  # cost from start node,end node
    visited = set()
    while heap:
        (cost, u) = heapq.heappop(heap)
        if u in visited:
            continue
        visited.add(u)
        if u == end:
            return cost
        for v, c in graph[u]:
            if v in visited:
                continue
            next = cost + c
            heapq.heappush(heap, (next, v))
    return -1


G = {
    "A": [["B", 2], ["C", 5]],
    "B": [["A", 2], ["D", 3], ["E", 1], ["F", 1]],
    "C": [["A", 5], ["F", 3]],
    "D": [["B", 3]],
    "E": [["B", 4], ["F", 3]],
    "F": [["C", 3], ["E", 3]],
}

r"""
Layout of G2:
E -- 1 --> B -- 1 --> C -- 1 --> D -- 1 --> F
 \                                         /\
  \                                        ||
    ----------------- 3 --------------------
"""
G2 = {
    "B": [["C", 1]],
    "C": [["D", 1]],
    "D": [["F", 1]],
    "E": [["B", 1], ["F", 3]],
    "F": [],
}

r"""
Layout of G3:
E -- 1 --> B -- 1 --> C -- 1 --> D -- 1 --> F
 \                                         /\
  \                                        ||
    -------- 2 ---------> G ------- 1 ------
"""
G3 = {
    "B": [["C", 1]],
    "C": [["D", 1]],
    "D": [["F", 1]],
    "E": [["B", 1], ["G", 2]],
    "F": [],
    "G": [["F", 1]],
}

shortDistance = dijkstra(G, "E", "C")
print(shortDistance)  # E -- 3 --> F -- 3 --> C == 6

shortDistance = dijkstra(G2, "E", "F")
print(shortDistance)  # E -- 3 --> F == 3

shortDistance = dijkstra(G3, "E", "F")
print(shortDistance)  # E -- 2 --> G -- 1 --> F == 3

if __name__ == "__main__":
    import doctest

    doctest.testmod()
