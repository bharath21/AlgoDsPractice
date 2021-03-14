#include <bits/stdc++.h>
using namespace std;
vector<int> w1_arr, w2_arr;
int findDistance(string s, string w1, string w2)
{
      bool isStart = false;
      int w_count = 0;
      for (int i = 0; i < s.length(); i++)
      {
            if (i == 0)
            {
                  w_count = 1;
                  if (s.substr(i, w1.length() + 1) == w1 + " ")
                  {
                        w1_arr.push_back(w_count);
                  }
                  if (s.substr(i, w2.length() + 1) == w2 + " ")
                  {
                        w2_arr.push_back(w_count);
                  }
            }
            else if (s[i] == ' ')
            {
                  w_count++;
                  if (s.substr(i + 1, w1.length() + 1) == w1 + " ")
                  {
                        w1_arr.push_back(w_count);
                  }
                  if (s.substr(i + 1, w2.length() + 1) == w2 + " ")
                  {
                        w2_arr.push_back(w_count);
                  }
            }
      }
      for (int i = 0; i < w1_arr.size(); i++)
      {
            cout << w1_arr[i] << " , ";
      }
      cout << endl;
      for (int i = 0; i < w2_arr.size(); i++)
      {
            cout << w2_arr[i] << " , ";
      }
      int res = INT_MAX;

      int w1_ptr, w2_ptr;
      w1_ptr = w2_ptr = 0;
      while (w1_ptr != w1_arr.size() && w2_ptr != w2_arr.size())
      {
            if (abs(w1_arr[w1_ptr] - w2_arr[w2_ptr]) < res)
            {
                  res = min(res, abs(w1_arr[w1_ptr] - w2_arr[w2_ptr]));
            }
            if (w1_arr[w1_ptr] < w2_arr[w2_ptr])
            {
                  w1_ptr++;
            }
            if (w1_arr[w1_ptr] > w2_arr[w2_ptr])
            {
                  w2_ptr++;
            }
      }
      return res;
}
int main()
{
      string s = "the boy lived in a town and boy is a hero ";
      s.append("heros ");
      s.push_back('a');
      // char c_ar[] = {'a', 'b'};
      // s.assign(c_ar);
      for (auto i = s.rbegin(); i != s.rend(); i++)
      {
            cout << *i << " ";
      }

      s.s.replace(0, 3, "there was");

      cout << s << endl;

      cout << endl
           << findDistance(s, "boy", "a");
}