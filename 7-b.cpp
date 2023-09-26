#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adj; 

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void BFS(int startVertex) {
        vector<bool> visited(V, false); 
        queue<int> q; 
        q.push(startVertex);
        visited[startVertex] = true;

        cout << "Breadth First Search starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            for (const int& adjacentVertex : adj[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    q.push(adjacentVertex);
                    visited[adjacentVertex] = true;
                }
            }
        }

        cout << endl;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter edges (format: u v):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    graph.BFS(startVertex);

    return 0;
}
