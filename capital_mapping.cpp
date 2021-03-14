#include <bits/stdc++.h>
using namespace std;
class Item
{
public:
      long long pos;
      long long value;
};
int myComp(Item a, Item b)
{
      return a.value > b.value;
}
int main()
{
      long long T, N;
      cin >> T;
      Item arr[50001];
      list<long long> graph[50001];
      long long result[50001];
      long long u, v;
      long long count = 0;
      while (T--)
      {
            cin >> N;
            count = 0;

            for (long long i = 1; i <= N; i++)
            {
                  cin >> arr[i].value;
                  arr[i].pos = i;
            }
            sort(arr + 1, arr + N + 1, myComp);

            for (long long i = 1; i <= N; i++)
            {
                  result[i] = 0;
                  graph[i].clear();
            }

            for (long long i = 1; i <= N - 1; i++)
            {
                  cin >> u >> v;
                  graph[u].push_back(v);
                  graph[v].push_back(u);
            }

            for (int i = 1; i <= N; i++)
            {
                  int vortex = arr[i].pos;
                  int j;
                  for (j = 1; j <= N; j++)
                  {
                        if (j != vortex && result[j] == 0)
                        {
                              if (find(graph[vortex].begin(), graph[vortex].end(), j) == graph[vortex].end())
                              {
                                    result[j] = vortex;
                                    count++;
                                    if (count == N)
                                    {
                                          break;
                                    }
                              }
                        }
                  }
                  if (count == N)
                  {
                        break;
                  }
            }
            for (long long k = 1; k <= N; k++)
            {
                  cout << result[k] << " ";
            }
      }

      return 0;
}