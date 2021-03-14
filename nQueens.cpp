
#include <bits/stdc++.h>
using namespace std;
int N;
bool isSafe(int board[10][10], int row, int col)
{

      for (int i = 0; i < col; i++)
      {
            if (board[row][i])
            {
                  return false;
            }
      }
      /* Check upper diagonal on left side */
      int i, j;
      for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                  return false;

      /* Check lower diagonal on left side */
      for (i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j])
                  return false;
      return true;
}
bool placeQueens(int board[10][10], int n, int col)
{
      if (col >= n)
      {
            return true;
      }
      for (int row = 0; row < n; row++)
      {
            if (isSafe(board, row, col))
            {
                  board[row][col] = 1;
                  if (placeQueens(board, n, col + 1))
                  {
                        return true;
                  }
                  // else
                  // {
                  board[row][col] = 0;
                  // }
            }
      }
      return false;
}
int main()
{
      int n;
      cin >> n;
      N = n;
      int board[10][10];
      // board = new *board[10];
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  board[i][j] = 0;
            }
      }
      if (placeQueens(board, n, 0))
            for (int i = 0; i < n; i++)
            {
                  for (int j = 0; j < n; j++)
                  {
                        cout << board[i][j] << " ";
                  }
                  cout << endl;
            }
      else
            cout << "Not possible" << endl;
      return 0;
}