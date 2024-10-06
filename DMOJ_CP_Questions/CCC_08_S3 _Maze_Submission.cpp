#include <bits/stdc++.h>
using namespace std;

class BFS_matrix {
public:
   BFS_matrix(int R, int C);
   int rows;
   int cols;

   char **grid;
   bool **vis;
   int **level;
   int reached;

   int dRow[4];
   int dCol[4];

   bool isValid(int row, int col);
   int BFS(int row, int col, int tr, int tc);
};

BFS_matrix::BFS_matrix(int R, int C) {
   rows = R; cols = C;

   grid = new char *[rows];
   vis = new bool *[rows];
   level = new int *[rows];

   for (int i = 0; i < rows; i++) {
      grid[i] = new char [cols];
      vis[i] = new bool [cols];
      level[i] = new int [cols];
   }

   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        vis[i][j] = false;
        level[i][j] = -1;
      }
   }

   dRow[0] = -1; dRow[1] = 0; dRow[2] = 1; dRow[3] =  0;
   dCol[0] =  0; dCol[1] = 1; dCol[2] = 0; dCol[3] = -1;

}

bool BFS_matrix::isValid(int r, int c)
{
    if (r < 0 || c < 0
        || r >= rows || c >= cols)
        return false;

    if (vis[r][c])
        return false;

    return true;
}

int BFS_matrix::BFS(int row, int col, int tr, int tc)
{
    int crosses = 1;

    queue<pair<int, int> > q;

    q.push({ row, col });
    vis[row][col] = true;
    level[row][col] = 0;
    reached = 0;
    if (grid[row][col] == 0)
      reached = 1;

    while (!q.empty()) {

        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            if(grid[x][y] == '-' && (i == 0 || i == 2))
                continue;
            else if(grid[x][y] == '|' && (i == 1 || i == 3))
                continue;

            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (isValid(adjx, adjy)) {
               if(grid[adjx][adjy] != '*') {
                  q.push({ adjx, adjy });
                  vis[adjx][adjy] = true;
                  level[adjx][adjy] = level[x][y] + 1;
                  reached++;
                  if(adjx == tr && adjy == tc) {
                    crosses = level[adjx][adjy] + 1;
                    return crosses;
                  }
               }
            }
        }
    }
return crosses;
}

int main()
{
   int t;
   int R;
   int C;

   cin >> t;

   for(int i = 0; i < t; i++){
        cin >> R >> C;


   BFS_matrix bm(R, C);

   for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        cin >> bm.grid[i][j];

   int crosses = bm.BFS(0, 0, R - 1, C - 1);

   if(crosses == 1 && (R > 1 || C > 1))
    crosses = -1;
   cout << crosses << endl;
   }
   return 0;
}
