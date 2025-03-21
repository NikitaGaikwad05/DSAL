/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
list to perform BFS. Use the map of the area around the college as the graph. Identify the 
prominent land marks as nodes and perform DFS and BFS on that.*/

#include <iostream>
#include <queue>
#include <set>

using namespace std;


void DFS_Matrix(int node, int adjMatrix[6][6], bool visited[6]) {
   
    cout << (char)('A' + node) << " ";
    visited[node] = true;

    
    for (int i = 0; i < 6; i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) {
            DFS_Matrix(i, adjMatrix, visited);
        }
    }
}


void BFS_List(int start, int adjList[6][6], int n) {
   
    bool visited[6] = {false};  
    queue<int> q;

    
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

      
        cout << (char)('A' + node) << " ";

        
        for (int i = 0; i < n; i++) {
            if (adjList[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    
    int n = 6;  
    int adjMatrix[6][6] = {0};
    
    
    adjMatrix[0][1] = adjMatrix[1][0] = 1;  // A-B
    adjMatrix[0][2] = adjMatrix[2][0] = 1;  // A-C
    adjMatrix[0][3] = adjMatrix[3][0] = 1;  // A-D
    adjMatrix[1][4] = adjMatrix[4][1] = 1;  // B-E
    adjMatrix[3][5] = adjMatrix[5][3] = 1;  // D-F

    
    int adjList[6][6] = {0};
    adjList[0][1] = adjList[0][2] = adjList[0][3] = 1;  // A connected to B, C, D
    adjList[1][0] = adjList[1][4] = 1;  // B connected to A, E
    adjList[2][0] = 1;  // C connected to A
    adjList[3][0] = adjList[3][5] = 1;  // D connected to A, F
    adjList[4][1] = 1;  // E connected to B
    adjList[5][3] = 1;  // F connected to D

    // DFS traversal using adjacency matrix
    cout << "DFS Traversal (using adjacency matrix):\n";
    bool visited[6] = {false};
    DFS_Matrix(0, adjMatrix, visited);  // Start from 'A' (node 0)
    cout << endl;

    // BFS traversal using adjacency list
    cout << "BFS Traversal (using adjacency list):\n";
    BFS_List(0, adjList, n);  // Start from 'A' (node 0)
    cout << endl;

    return 0;
}

