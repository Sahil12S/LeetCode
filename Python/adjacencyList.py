# Implement Graph using Adjacency List

class AdjNode:
    def __init__(self, data):
        self.vertex = data
        self.next = None


class Graph:
    def __init__(self, numVertices):
        self.numVertices = numVertices
        self.graph = [None] * self.numVertices

    def add_edge(self, src, dest):
        node = AdjNode(dest)
        node.next = self.graph[src]
        self.graph[src] = node

        # For undirected graph
        node = AdjNode(src)
        node.next = self.graph[dest]
        self.graph[dest] = node

    def print_graph(self):
        for i in range(self.numVertices):
            print("Adjacency list of vertex {} \nhead".format(i), end="")
            temp = self.graph[i]
            while temp:
                print(" -> {}".format(temp.vertex), end="")
                temp = temp.next
            print("\n")
            

if __name__ == "__main__":
    g = Graph(5)
    g.add_edge(0, 1) 
    g.add_edge(0, 4) 
    g.add_edge(1, 2) 
    g.add_edge(1, 3) 
    g.add_edge(1, 4) 
    g.add_edge(2, 3) 
    g.add_edge(3, 4) 
  
    g.print_graph() 