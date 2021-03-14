#include <bits/stdc++.h>
using namespace std;

int main()
{
      // your code goes here
      int test_cases, num_lds, num_kds;
      cin >> test_cases;
      vector<int> ld_sizes;
      while (test_cases--)
      {
            cin >> num_lds >> num_kds;
            ld_sizes.clear();
            for (int i = 0; i < num_lds; i++)
            {
                  int size;
                  cin >> size;
                  ld_sizes.push_back(size);
            }
            sort(ld_sizes.begin(), ld_sizes.end());
            int num_sub_sizes = num_lds - num_kds + 1;
            int result = INT_MAX;
            for (int i = 0; i < num_sub_sizes; i++)
            {
                  int min = ld_sizes[i];

                  int max = ld_sizes[i + num_kds - 1];
                  // for (int j = i; j <= i + num_kds - 1; j++)
                  // {
                  // max=ld_sizes[j];
                  // cout << "m " << max << " " << min << endl;

                  if (result > (max - min))
                  {
                        result = (max - min);
                  }
            }
            cout << result << endl;
      }
      return 0;
}
