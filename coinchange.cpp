#include <bits/stdc++.h>
using namespace std;

int ways;
int calcChange(int coins[], int size, int amount)
{
      if (amount == 0)
      {
            return 1;
      }
      if (amount < 0)
      {
            return 0;
      }
      if (size <= 0 && amount >= 1)
      {
            return 0;
      }
      {
            return (calcChange(coins, size, amount - coins[size - 1]) + calcChange(coins, size - 1, amount));
      }
}
int main()
{
      int n;
      cin >> n;
      int coins[n];
      for (int i = 0; i < n; i++)
      {
            cin >> coins[i];
      }
      int amount;
      cin >> amount;
      ways = 0;

      cout << calcChange(coins, n, amount);
}