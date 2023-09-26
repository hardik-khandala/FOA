#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
vector<pair<int, int>> adj[MAX];
bool visited[MAX];

long long prim()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int x;
    long long minimumCost = 0;
    pair<int, int> p;
    pq.push(make_pair(0, 0));

    while (!pq.empty())
    {
        p = pq.top();
        pq.pop();
        x = p.second;

        if (visited[x])
            continue;

        minimumCost += p.first;
        visited[x] = true;

        for (int i = 0; i < adj[x].size(); ++i)
        {
            int y = adj[x][i].second;
            if (!visited[y])
                pq.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y, weight;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    for (int i = 0; i < edges; ++i)
    {
        cout << "Enter edge " << i + 1 << " (x, y, weight): ";
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }

    long long minimumCost = prim();
    cout << "Minimum cost is " << minimumCost << endl;

    return 0;
}
