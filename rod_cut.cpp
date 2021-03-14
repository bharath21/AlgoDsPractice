#include <bits/stdc++.h>
using namespace std;
int rod_cut(int l, int *arr, int n)
{
      if (l <= 0)
      {
            return 0;
      }
      int result = INT_MIN;
      for (int j = 0; j < l; j++)
      {
            result = max(result, arr[j] + rod_cut(l - j - 1, arr, n));
      }
      return result;
}
int rod_cut_dp(int l, int *arr, int n)
{
      int rod_dp[l + 1];
      for (int j = 0; j < l + 1; j++)
      {
            rod_dp[j] = 0;
      }
      rod_dp[0] = 0;
      for (int i = 1; i <= l; i++)
      {
            for (int j = 1; j <= i; j++)
            {
                  rod_dp[i] = max(rod_dp[i], arr[j - 1] + rod_dp[i - j]);
            }
      }
      return rod_dp[l];
}
int main()
{
      int n, *arr, l;
      cin >> n;
      arr = new int[n];
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }
      //cout << rod_cut(l, arr, n) << endl;

      cout << rod_cut_dp(l, arr, n) << endl;
      return 0;
}