#include <bits/stdc++.h>
using namespace std;

int main()
{
      // your code goes here
      int M, N;
      cin >> M;
      list<int> l;
      int t;
      for (int i = 0; i < M; i++)
      {
            cin >> t;
            l.push_back(t);
      }
      cin >> N;
      int pos;
      for (int i = 0; i < N; i++)
      {
            cin >> pos;
            auto itr = l.begin();
            int j = 0;
            for (j = 1; j < pos; j++)
            {
                  advance(itr, 1);
            }
            cout << *itr << endl;
            l.erase(itr);
      }
      return 0;
}
