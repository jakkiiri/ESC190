# Minimal implementation of a linked list for storing neighbors
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        # Insert new node at the beginning of the list.
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def remove(self, data):
        current = self.head
        prev = None
        while current:
            if current.data == data:
                if prev is None:
                    self.head = current.next
                else:
                    prev.next = current.next
                return True
            prev = current
            current = current.next
        return False

    def is_in(self, data):
        current = self.head
        while current:
            if current.data == data:
                return True
            current = current.next
        return False

# Graph2 class using an adjacency list represented as linked lists
class Graph2:
    def __init__(self, num_nodes=0):
        self.nodes = []             # List of LinkedList objects for each node's neighbors.
        self.node_names = {}        # Mapping from node name to index.
        self.node_names_rev = {}    # Mapping from index to node name.
        self.num_nodes = num_nodes
        for i in range(num_nodes):
            self.nodes.append(LinkedList())

    def add_node(self, name):
        index = len(self.nodes)
        self.node_names[name] = index
        self.node_names_rev[index] = name
        self.nodes.append(LinkedList())
        self.num_nodes += 1

    def is_edge(self, i, j):
        # Returns True if there's an edge from node i to node j.
        return self.nodes[i].is_in(j)

    def is_edge_name(self, name1, name2):
        return self.is_edge(self.node_names[name1], self.node_names[name2])

    def put_edge(self, i, j):
        # Inserts an edge from node i to node j.
        self.nodes[i].insert(j)

    def put_edge_name(self, name1, name2):
        i = self.node_names[name1]
        j = self.node_names[name2]
        self.put_edge(i, j)

    def remove_edge(self, i, j):
        self.nodes[i].remove(j)

# BFS
def breadth_first_traversal(g, start_name):
    start_i = g.node_names[start_name]
    visited = [False] * g.num_nodes
    queue = [start_i]
    while queue:
        cur = queue.pop(0)
        if not visited[cur]:
            print(g.node_names_rev[cur])
            visited[cur] = True
            neighbor = g.nodes[cur].head
            while neighbor:
                if not visited[neighbor.data]:
                    queue.append(neighbor.data)
                neighbor = neighbor.next


if __name__ == '__main__':
    airports = Graph2()
    
    # Adding nodes (airports):
    # YYZ: Toronto Pearson International Airport
    # YVR: Vancouver International Airport
    # YUL: Montréal–Trudeau International Airport
    # YYC: Calgary International Airport
    # YEG: Edmonton International Airport
    # YOW: Ottawa Macdonald–Cartier International Airport
    # YHZ: Halifax Stanfield International Airport
    # YQB: Québec City Jean Lesage International Airport
    airports.add_node("YYZ")
    airports.add_node("YVR")
    airports.add_node("YUL")
    airports.add_node("YYC")
    airports.add_node("YEG")
    airports.add_node("YOW")
    airports.add_node("YHZ")
    airports.add_node("YQB")
    
    # Adding edges to simulate flight connections:
    # From YYZ (Toronto)
    airports.put_edge_name("YYZ", "YVR")   # Toronto -> Vancouver
    airports.put_edge_name("YYZ", "YUL")   # Toronto -> Montréal
    airports.put_edge_name("YYZ", "YOW")   # Toronto -> Ottawa

    # From YVR (Vancouver)
    airports.put_edge_name("YVR", "YYZ")   # Vancouver -> Toronto
    airports.put_edge_name("YVR", "YYC")   # Vancouver -> Calgary
    airports.put_edge_name("YVR", "YHZ")   # Vancouver -> Halifax

    # From YUL (Montréal)
    airports.put_edge_name("YUL", "YQB")   # Montréal -> Québec City
    airports.put_edge_name("YUL", "YOW")   # Montréal -> Ottawa

    # From YYC (Calgary)
    airports.put_edge_name("YYC", "YEG")   # Calgary -> Edmonton

    # From YEG (Edmonton)
    airports.put_edge_name("YEG", "YYZ")   # Edmonton -> Toronto

    # From YOW (Ottawa)
    airports.put_edge_name("YOW", "YYZ")   # Ottawa -> Toronto

    # From YHZ (Halifax)
    airports.put_edge_name("YHZ", "YUL")   # Halifax -> Montréal

    print("BFS Traversal starting from YYZ:")
    breadth_first_traversal(airports, "YYZ")

'''
            YVR
           / | \
          /  |  \
       YYZ   |   YYC
      /  \   |    |
    YOW  YUL-+    YEG
         |  \
         YQB YHZ

'''