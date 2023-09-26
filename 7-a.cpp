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

    void DFS(int startVertex) {
        vector<bool> visited(V, false); 
        stack<int> stk; 

        stk.push(startVertex);
        visited[startVertex] = true;

        cout << "Depth First Search starting from vertex " << startVertex << ": ";

        while (!stk.empty()) {
            int currentVertex = stk.top();
            stk.pop();
            cout << currentVertex << " ";
            for (const int& adjacentVertex : adj[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    stk.push(adjacentVertex);
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
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    graph.DFS(startVertex);

    return 0;
}
