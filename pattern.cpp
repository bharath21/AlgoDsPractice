#include <bits/stdc++.h>
using namespace std;
bool isPattern(int n)
{
      int prev = -1;
      int next;
      int curr;
      while (n)
      {
            curr = n % 2;
            // if (prev == -1)
            // {
            //       n /= 2;
            //       prev = curr;
            //       continue;
            // }
            if (prev != -1 && curr != prev)
            {
                  n /= 2;
                  prev = curr;
                  continue;
            }
            else
            {
                  int temp = n / 2;
                  if (temp)
                  {
                        next = temp % 2;
                        if (next != curr)
                        {
                              n /= 2;
                              prev = curr;
                              continue;
                        }
                        else
                        {
                              return false;
                        }
                  }
                  else
                  {
                        if (curr != 0)
                        {
                              return true;
                        }
                        return false;
                  }
            }
      }
      return true;
}
bool isPattern2(int n)
{
      if (n == 0)
            return 0;
      while (n)
      {
            int first = n % 2;
            n >>= 1;
            int second = n % 2;
            n >>= 1;
            if (first == second)
            {
                  return 0;
            }
      }
      return 1;
}
int main()
{
      int t, n;
      cin >> t;
      while (t--)
      {
            cin >> n;
            cout << isPattern(n);
            // cout << isPattern2(n);
      }
}