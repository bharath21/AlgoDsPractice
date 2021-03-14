#include <iostream>
#include <algorithm>
using namespace std;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int knapsack(int w[], int v[], int n, int W, int val)
{
      if (n < 0 || W <= 0)
      {
            return val;
      }
      if (w[n] > W)
      {
            return knapsack(w, v, n - 1, W, val);
      }
      //MAX(item included and not included)
      return max(knapsack(w, v, n - 1, W - w[n], val + v[n]), knapsack(w, v, n - 1, W, val));
}

void knapsack_dp_bu(int n, int W, int w[], int v[])
{
      int table[n + 1][W + 1];
      for (int i = 0; i <= n; i++)
      {
            table[i][0] = 0;
      }
      LOOP(i, W + 1)
      {
            table[0][i] = 0;
      }
      for (int i = 1; i <= n; i++)
      {
            for (int j = 1; j <= W; j++)
            {
                  if (w[i - 1] > j)
                  {
                        table[i][j] = table[i - 1][j];
                  }
                  else
                  {
                        table[i][j] = max(v[i - 1] + ((j - w[i - 1] < 0) ? 0 : table[i - 1][j - w[i - 1]]), table[i - 1][j]);
                  }
            }
      }

      for (int i = 0; i <= n; i++)
      {
            for (int j = 0; j <= W; j++)
            {
                  cout << table[i][j] << " ";
            }
            cout << endl;
      }
      cout << table[n][W];
}
int main()
{
      int n, w[100] = {0}, v[100] = {0}, W;
      cin >> n;
      cin >> W;
      cout << "enter weights" << endl;
      LOOP(i, n)
      {
            cin >> w[i];
      }
      LOOP(i, n)
      {
            cin >> v[i];
      }
      cout << knapsack(w, v, n - 1, W, 0) << endl;

      knapsack_dp_bu(n, W, w, v);
      // cout << "dp " << table[n][W];
}