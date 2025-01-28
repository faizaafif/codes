#include <iostream>
using namespace std;

class graph{
    int cost[10][10];
    int tcities;
    public:
        graph();
        void create();
        void display();
        void prims();

        graph(){
        tcities = 0;
        cout<<"\nEnter no. of cities:";
        cin>>tcities;
        for(int i=0; i<tcities; i++){
            for(int j=0; j<tcities; j++){
                cost[i][j]=999;
                }
            }
        }

        void create(){
            char ch;
            //for(int i=0; i <)
        }

        void display(){}

        void prims(){
            
        }
};

#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

// Function to find the vertex with the minimum key value that is not yet included in the MST
int findMinKeyVertex(int key[], bool included[], int n) {
    int minKey = INT_MAX;
    int minIndex;

    for (int i = 0; i < n; i++) {
        if (!included[i] && key[i] < minKey) {
            minKey = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to implement Prim's Algorithm
void primsAlgorithm(int graph[100][100], int n) {
    int parent[100];   // To store the constructed MST
    int key[100];      // To store the minimum weight edge for each vertex
    bool included[100]; // To keep track of vertices included in MST

    // Initialize all keys to infinity and included array to false
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        included[i] = false;
    }

    key[0] = 0;      // Start from the first vertex
    parent[0] = -1;  // First vertex is the root of the MST

    for (int i = 0; i < n - 1; i++) {
        int u = findMinKeyVertex(key, included, n); // Find the minimum key vertex
        included[u] = true; // Include the vertex in the MST

        // Update the key and parent of the adjacent vertices of the chosen vertex
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !included[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Display the resulting MST
    cout << "Edge\tWeight" << endl;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int n; // Number of vertices (offices)
    int graph[100][100]; // Adjacency matrix to store graph

    cout << "Enter the number of offices: ";
    cin >> n;

    cout << "Enter the cost adjacency matrix (enter 0 if no direct connection exists):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "\nMinimum Cost Spanning Tree using Prim's Algorithm:" << endl;
    primsAlgorithm(graph, n);

    return 0;
}

