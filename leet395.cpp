#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
      int f;
      bool isResult(int count[26])
      {
            for (int i = 0; i < 26; i++)
            {
                  if (count[i] > 0)
                  {
                        if (count[i] < f)
                        {
                              return false;
                        }
                  }
            }
            return true;
      }
      int longestSubstring(string s, int k)
      {
            int l = s.length();
            f = k;
            int count[26] = {0};
            int result = -1;
            int i, j;

            for (i = 0; i < l; i++)
            {
                  // count[26] = {0};
                  for (int p = 0; p < 26; p++)
                  {
                        count[p] = 0;
                  }
                  for (j = i; j < l; j++)
                  {
                        count[s[j] - 'a']++;
                        if (isResult(count))
                        {
                              if (result < (j - i + 1))
                              {
                                    result = j - i + 1;
                              }
                        }
                        // for (int p = 0; p < 26; p++)
                        // {
                        //       cout << char('a' + p) << " " << count[p];
                        //       cout << endl;
                        // }
                  }
            }
            return result;
      }
};

int main(int argc, char *argv[])
{
      // cout << argc << endl;
      Solution s;
      string ip;
      int k;
      cin >> ip >> k;
      cout << s.longestSubstring(ip, k) << endl;
      return 0;
}