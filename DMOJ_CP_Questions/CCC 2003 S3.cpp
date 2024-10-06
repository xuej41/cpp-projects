/*
Breadth First Traversal ( BFS ) on a 2D array
https://www.geeksforgeeks.org/breadth-first-traversal-bfs-on-a-2d-array/
*/
#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 4

class BFS_matrix {
public:
    BFS_matrix(int R, int C): //constructor
    int rows;
    int cols;

    int **grid;
    bool **vis; //visited
    int **level; //depth, step
    int reached; //how many grids are reached  == visited

    // Direction vectors
    int dRow[4];
    int dCol[4];

    bool isValid(int row, int col);
    void BFS(int row, int col)
};

BFS_matrix::BFS_matrix(int R, int C) { //constructor
    rows = R; cols = C;

    grid = new int*[rows];
    vis = new int*[rows];
    level = new int*[rows];

    for (int i = 0; i < rows; i++) {
        grid[i] = new int [cols];
        vis[i] = new int [cols];
        level[i] = new int [cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            vis[i][j] = false;
            level[i][j] = -1; //not visited, or unreachable
        }
    }



// Direction vectors
    dRow[0] = -1; dRow[1] = 0; dRow[2] = 1; dRow[3] =  0; // top, right, back, bottom
    dCol[0] =  0; dCol[1] = 1; dCol[2] = 0; dCol[3] = -1;

}

// Function to check if a cell
// is be visited or not
bool isValid(bool vis[][COL],
             int row, int col)
{
    // If cell lies out of bounds
    if (row < 0 || col < 0
        || row >= ROW || col >= COL)
        return false;

    // If cell is already visited
    if (vis[row][col])
        return false;

    // Otherwise
    return true;
}

// Function to perform the BFS traversal
void BFS(int grid[][COL], bool vis[][COL],
         int row, int col)
{
    // Stores indices of the matrix cells
    queue<pair<int, int> > q;

    // Mark the starting cell as visited
    // and push it into the queue
    q.push({ row, col });
    vis[row][col] = true;

    // Iterate while the queue
    // is not empty
    while (!q.empty()) {

        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;

        cout << grid[x][y] << " ";

        q.pop();

        // Go to the adjacent cells
        for (int i = 0; i < 4; i++) {

            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (isValid(vis, adjx, adjy)) {
                q.push({ adjx, adjy });
                vis[adjx][adjy] = true;
            }
        }
    }
}

// Driver Code
int main()
{
    // Given input matrix
    int grid[ROW][COL] = { { 1, 2, 3, 4 },
                           { 5, 6, 7, 8 },
                           { 9, 10, 11, 12 },
                           { 13, 14, 15, 16 } };

    // Declare the visited array
    bool vis[ROW][COL];
    memset(vis, false, sizeof vis);

    BFS(grid, vis, 0, 0);

    return 0;
}

/*
Output:
1 2 5 3 6 9 4 7 10 13 8 11 14 12 15 16
*/
