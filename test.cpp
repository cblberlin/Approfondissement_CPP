#include <vector>

const int N = 9; // size of the Sudoku puzzle (9x9)

// Each vertex in the graph represents a cell in the Sudoku puzzle
struct Vertex {
  int value; // the value of the cell (0 if unassigned)
  std::vector<int> neighbors; // adjacency list of neighboring vertices
};

std::vector<Vertex> graph(N*N); // create the graph with N*N vertices

int main(){

// Add edges to connect vertices that share a row, column, or region
for (int i = 0; i < N; i++) {
  for (int j = 0; j < N; j++) {
    int u = i*N + j; // index of the vertex at cell (i, j)

    // Connect to vertices in the same row
    for (int k = 0; k < N; k++) {
      if (k == j) continue; // skip self-loop
      int v = i*N + k; // index of the vertex at cell (i, k)
      graph[u].neighbors.push_back(v);
    }

    // Connect to vertices in the same column
    for (int k = 0; k < N; k++) {
      if (k == i) continue; // skip self-loop
      int v = k*N + j; // index of the vertex at cell (k, j)
      graph[u].neighbors.push_back(v);
    }

    // Connect to vertices in the same region
    int region_row = i / 3;
    int region_col = j / 3;
    for (int k = 0; k < 3; k++) {
      for (int l = 0; l < 3; l++) {
        int x = region_row * 3 + k;
        int y = region_col * 3 + l;
        if (x == i && y == j) continue; // skip self-loop
        int v = x*N + y; // index of the vertex at cell (x, y)
        graph[u].neighbors.push_back(v);
      }
    }
  }
}
return 0;
}