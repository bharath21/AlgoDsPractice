#include <iostream>
#include <algorithm>
using namespace std;
int path[100][100];
int mincost(int i, int j, int m, int n)
{
      if (i > m || j > n)
      {
            return 88888;
      }
      if (i == m && j == n)
      {
            return path[m][n];
      }
      return path[i][j] + min(mincost(i + 1, j, m, n), min(mincost(i, j + 1, m, n), mincost(i + 1, j + 1, m, n)));
}

int main()
{
      int m, n;
      cin >> m >> n;
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  cin >> path[i][j];
            }
      }
      cin >> m >> n;
      cout << mincost(0, 0, m, n);
}