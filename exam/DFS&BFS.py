# Transversing Graphs
class Node:
    def __init__(self, name):
        self.name = name
        self.connections = []
        self.visited = False

def connect(node1, node2):
    node1.connections.append(node2)
    node2.connections.append(node1)

A = Node("A")
B = Node("B")
C = Node("C")
D = Node("D")
E = Node("E")
F = Node("F")

connect (A, B)
connect (E, F)
connect (B, E)
connect (E, D)
connect (B, D)
connect (B, C)
connect (D, C)

# BFS (Breadth First Search)
def BFS(node):
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop(0)
        print(cur.name)
        for con in cur.connections:
            if not con.visited:
                q.append(con)
                con.visited = True

BFS(E)

A.visited = False
B.visited = False
C.visited = False
D.visited = False
E.visited = False
F.visited = False

print()

# DFS (Depth First Search)
def DFS(node):
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop()
        print (cur.name)
        for con in cur.connections:
            if not con.visited:
                q.append(con)
                con.visited = True
DFS(E)

A.visited = False
B.visited = False
C.visited = False
D.visited = False
E.visited = False
F.visited = False

print()

def DFS_rec(node):
    print(node.name)
    node.visited = True
    for con in node.connections:
        if not con.visited:
            DFS_rec(con)
DFS_rec(E)

