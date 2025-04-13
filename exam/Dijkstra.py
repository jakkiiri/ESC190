# Shortest Path Algorithm

# Weighted Graph
class Node:
    def __init__(self, name):
        self.name = name
        self.connections = []
        self.visited = False

def connect (node1, node2, weight):
    node1.connections.append({"node": node2, "weight": weight})
    node2.connections.append({"node": node1, "weight": weight})

A = Node("A")
B = Node("B")
C = Node("C")
D = Node("D")
E = Node("E")
F = Node("F")

connect(A, B, 3)
connect(E, F, 8)
connect(B, E, 7)
connect(E, D, 5)
connect(B, D, 1)
connect(B, C, 2)
connect(D, C, 4)

def get_all_nodes(node):
    connections = []
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop(0)
        connections.append(cur)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"])
                con["node"].visited = True
    return connections

def dijsktra(node):

    S = [node]
    d = {node.name: 0}
    prev = {}

    unexplored = get_all_nodes(node)

    for n in unexplored:
        if n.name not in d:
            d[n.name] = 999999

    while len(unexplored) > 0:
        cur = unexplored.pop(0)
        for con in cur.connections:
            if con["node"] not in S:
                if con["weight"] + d[cur.name] < d[con["node"].name]:
                    d[con["node"].name] = con["weight"] + d[cur.name]
                    prev[con["node"].name] = cur.name

        S.append(cur)

    print(prev)
    return d, prev


def recover_path(prev, start, end):
    path = []
    current = end
    while current != start:
        path.append(current)
        current = prev.get(current)
        if current is None:
            return None  # No path exists
    path.append(start)
    return path[::-1]


distances, predecessors = dijsktra(C)
print("Distances:", distances)
print("Path from C to F:", recover_path(predecessors, "C", "F"))