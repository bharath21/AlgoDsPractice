#include <iostream>
using namespace std;
int l, n;
int max_jumps(int *arr, int idx, int step)
{
      if (idx + step >= n - 1)
      {
            return 1;
      }
      int k = INT_MAX;
      for (int i = 1; i <= step; i++)
      {
            if (max_jumps(arr, idx + i, arr[idx + i]) < k)
            {
                  k = 1 + max_jumps(arr, idx + i, arr[idx + i]);
            }
      }
      return k;
}
int main()
{
      int arr[] = {1, 3, 6, 3, 2,
                   3, 6, 8, 9, 5};
      // cin >> n;
      // for (int i = 0; i < n; i++)
      // {
      //       cin >> arr[i];
      // }
      l = sizeof(arr) / sizeof(int);
      n = l;
      // cout << "l " << l << endl;
      cout << max_jumps(arr, 0, arr[0]);
}