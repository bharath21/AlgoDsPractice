#include <bits/stdc++.h>
using namespace std;

int main()
{
      int n, data;
      cin >> n;
      int first;
      priority_queue<int> pq;
      for (int i = 0; i < n; i++)
      {
            cin >> data;
            if (i == 0)
            {
                  first = data;
                  continue;
            }
            pq.push(data);
      }
      int result = 0;
      while (!pq.empty())
      {
            auto iData = pq.top();
            while (first <= iData)
            {
                  iData = pq.top();
                  first++;
                  iData--;
                  result++;
                  pq.pop();
                  pq.push(iData);
            }
            cout << result * 1000 << endl;
            break;
      }
}