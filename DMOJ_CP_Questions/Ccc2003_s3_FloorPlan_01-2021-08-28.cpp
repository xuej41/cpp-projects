/*
CCC 2003 S3 Floor Plan
Ccc2003_s3_FloorPlan_01-*
2021-08-28 Sat,
Python/C++ CCC Sr, HS
Sat, 6 - 7:30 pm, Jul 10 - Sept 4
*/
#include <bits/stdc++.h>
using namespace std;

class BFS_matrix {
public:
   BFS_matrix(int R, int C); // constructor
   int rows;
   int cols;

   int **grid;
   bool **vis;  // visited
   int **level; // depth, step
   int reached; // how many grids are reached == visited

   // Direction vectors
   int dRow[4];
   int dCol[4];

   bool isValid(int row, int col);
   void BFS(int row, int col);
};

BFS_matrix::BFS_matrix(int R, int C) { // constructor
   rows = R; cols = C;

   grid = new int *[rows];
   vis = new bool *[rows];
   level = new int *[rows];

   for (int i = 0; i < rows; i++) {
      grid[i] = new int [cols];
      vis[i] = new bool [cols];
      level[i] = new int [cols];
   }

   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        vis[i][j] = false;
        level[i][j] = -1; // not visited, or unreachable,
      }
   }
   // Direction vectors
   dRow[0] = -1; dRow[1] = 0; dRow[2] = 1; dRow[3] =  0; // top, right, bottom,left
   dCol[0] =  0; dCol[1] = 1; dCol[2] = 0; dCol[3] = -1;

}


// Function to check if a cell
// is be visited or not
bool BFS_matrix::isValid(int r, int c)
{
    // If cell lies out of bounds
    if (r < 0 || c < 0
        || r >= rows || c >= cols)
        return false;

    // If cell is already visited
    if (vis[r][c])
        return false;

    // Otherwise
    return true;
}

// Function to perform the BFS traversal
void BFS_matrix::BFS(int row, int col)
{
    // Stores indices of the matrix cells
    queue<pair<int, int> > q;

    // Mark the starting cell (grid) as visited
    // and push it into the queue
    q.push({ row, col });
    vis[row][col] = true;
    level[row][col] = 0;
    reached = 0;
    if (grid[row][col] == 0)
      reached = 1;

    // Iterate while the queue
    // is not empty
    while (!q.empty()) {

        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;

        //cout << grid[x][y] << " ";

        q.pop();

        // Go to the adjacent cells
        for (int i = 0; i < 4; i++) {

            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (isValid(adjx, adjy)) {
               if(grid[adjx][adjy] == 0) { //is floor?
                  q.push({ adjx, adjy });
                  vis[adjx][adjy] = true;
                  level[adjx][adjy] = level[x][y] + 1;
                  reached++;
               }
            }
        }
    }
}

// Driver Code
int main()
{
   int A; // area, square meters of hardwood flooring
   int R; // rows of grid
   int C; // columns of grid

   cin >> A >> R >> C;

   char mat[R][C];

   for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        cin >> mat[i][j];

   BFS_matrix bm(R, C);
   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         if(mat[i][j] == 'I')
            bm.grid[i][j] = -1;
         else // '.' // floor
            bm.grid[i][j] = 0;
      }
   }

   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++)
         cout << mat[i][j] << ' ';
      cout << endl;
   }

   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++)
         cout << bm.grid[i][j] << ' ';
      cout << endl;
   }

   //
   vector<int> floors;
   bm.BFS(1, 1);
   cout << bm.reached << endl;
   floors.push_back(bm.reached);

   bm.BFS(6, 1);
   cout << bm.reached << endl;
   floors.push_back(bm.reached);

   sort(floors.begin(), floors.end(), greater <>());

   return 0;
}

/*
Sample Input 1
105
14
16
IIIIIIIIIIIIIIII
I......I.......I
I......III.....I
I........I.....I
I........IIIIIII
IIIIIIIIII.....I
I.I......I.....I
III..III.I.....I
I....I.IIIII...I
I....I.....III.I
I....I.......I.I
I....I.....III.I
I....I.....I...I
IIIIIIIIIIIIIIII

Output for Sample Input 1
4 rooms, 1 square metre(s) left over
=====================================
Sample Input 2
13
2
3
.I.
.I.

Output for Sample Input 2
2 rooms, 9 square metre(s) left over
*/
