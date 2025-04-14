import heapq

class Node:
    def __init__(self, name):
        self.name = name
        self.connections = []
        self.visited = False
        self.distance = 999999

    # Comparison function for the priority queue
    def __lt__(self, other):
        return self.distance < other.distance

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

# The number of times a node is pushed is 2|E|, and given that heapify has a time complexity of log|V|
# Time complexity is O(|E|log|V|)

def dijsktra_pq(node):
    node.distance = 0

    S = []
    pq = [node]
    heapq.heapify(pq)

    d = {node.name: 0}

    while len(pq) > 0:
        cur = heapq.heappop(pq)

        if cur in S: 
            continue

        d[cur.name] = cur.distance

        for con in cur.connections:
            con["node"].distance = cur.distance + con["weight"]
            heapq.heappush(pq, con["node"])

        S.append(cur)

    return d

print(dijsktra_pq(C))
