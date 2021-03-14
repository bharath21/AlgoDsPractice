#include <bits/stdc++.h>
using namespace std;

int main()
{
      int n;
      cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }
      int k;
      cin >> k;
      unordered_map<int, int> s;
      int count = 0;
      for (int i = 0; i < k - 1; i++)
      {
            if (s.find(arr[i]) != s.end())
            {
                  s[arr[i]]++;
            }
            else
            {
                  s[arr[i]] = 1;
                  count++;
            }
      }
      for (int i = k - 1; i < n; i++)
      {
            if (s.find(arr[i]) != s.end())
            {
                  cout << "1st " << arr[i] << endl;
                  s[arr[i]]++;
            }
            else
            {
                  cout << "2nd " << arr[i] << endl;

                  cout << arr[i] << " ";
                  s[arr[i]] = 1;
                  count++;
            }
            cout << "element " << arr[i] << " " << count << endl;
            if (s[arr[i - k + 1]] <= 1)
            {
                  cout << "3rd " << arr[i - k + 1] << endl;

                  s.erase(arr[i - k + 1]);
                  count--;
            }
            else
            {
                  cout << "4th " << arr[i - k + 1] << endl;
                  s[arr[i - k + 1]]--;
            }
      }
}