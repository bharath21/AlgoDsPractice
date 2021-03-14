#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
      int V;
      list<int> *g;
      bool *visited;
      bool *isInStack;
      Graph(int v)
      {
            V = v;
            g = new list<int>[v];
            visited = new bool[v];
            isInStack = new bool[v];
            for (int i = 0; i < v; i++)
            {
                  visited[i] = isInStack[i] = false;
            }
      }

      void addEdge(int u, int v)
      {
            g[u].push_back(v);
      }

      bool util(list<int> &s, int idx)
      {
            cout << idx << "<< ";
            if (visited[idx] == true)
            {
                  return true;
            }
            visited[idx] = true;
            list<int>::iterator it;
            for (it = g[idx].begin(); it != g[idx].end(); it++)
            {
                  if (!visited[*it])
                  {
                        util(s, *it);
                  }
                  else
                  {
                        if (!isInStack[*it])
                        {
                              return false;
                        }
                  }
            }
            isInStack[idx] = true;
            s.push_back(idx);
            return true;
      }

      vector<int> getOrder()
      {
            list<int> s;
            int i;
            for (i = 0; i < V; i++)
            {
                  if (!util(s, i))
                  {
                        break;
                  }
            }
            vector<int> arr;
            list<int>::iterator it;
            if (i == V)
            {
                  int size = s.size();
                  while (size--)
                  {
                        int val = s.back();
                        s.pop_back();
                        arr.push_back(val);
                  }
            }
            return arr;
      }
};

class Solution
{

public:
      vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
      {
            Graph g(numCourses);
            for (int i = 0; i < prerequisites.size(); i++)
            {
                  g.addEdge(prerequisites[i][1], prerequisites[i][0]);
            }

            vector<int> a = g.getOrder();
            for (int i = 0; i < a.size(); i++)
            {
                  cout << a[i] << endl;
            }
            return a;
      }
};

int main()
{
      return 0;
}