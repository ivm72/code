
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class LinkStateRouter {
public:
    int n; // Number of routers (nodes)
    vector<vector<int>> dist; // Matrix to store distance between routers
    vector<bool> visited; // Keeps track of visited routers

    LinkStateRouter(int routers) {
        n = routers;
        dist.resize(n, vector<int>(n, INT_MAX)); // Initialize distances with infinity
        visited.resize(n, false); // Initialize visited routers as false
    }

    // Function to add a link between two routers (u, v) with a given cost (weight)
    void addLink(int u, int v, int cost) {
        dist[u][v] = cost;
        dist[v][u] = cost; // For undirected links
    }

    // Dijkstra's algorithm to find the shortest path from source
    void dijkstra(int source) {
        vector<int> distance(n, INT_MAX); // Initialize distances with infinity
        distance[source] = 0; // Distance to source is 0

        for (int i = 0; i < n; i++) {
            int u = -1;

            // Find the router with the minimum distance
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }

            visited[u] = true; // Mark the router as visited

            // Update the distances to the neighbors of the selected router
            for (int v = 0; v < n; v++) {
                if (dist[u][v] != INT_MAX && !visited[v] &&
                    distance[u] + dist[u][v] < distance[v]) {
                    distance[v] = distance[u] + dist[u][v];
                }
            }
        }

        // Print the shortest distances from the source router
        cout << "Shortest paths from Router " << source << ":\n";
        for (int i = 0; i < n; i++) {
            if (distance[i] == INT_MAX) {
                cout << "Router " << i << " is unreachable from Router " << source << endl;
            } else {
                cout << "Distance to Router " << i << ": " << distance[i] << endl;
            }
        }
    }
};

int main() {
    // Create a network of 5 routers
    LinkStateRouter network(5);

    // Add links between routers (router1, router2, cost)
    network.addLink(0, 1, 10);
    network.addLink(0, 2, 20);
    network.addLink(1, 2, 30);
    network.addLink(1, 3, 50);
    network.addLink(2, 3, 10);
    network.addLink(3, 4, 20);

    // Run Dijkstra's algorithm starting from Router 0
    network.dijkstra(0);

    return 0;
}
