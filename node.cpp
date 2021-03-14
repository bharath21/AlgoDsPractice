#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
      int pos;
      int val;
};
bool comp(Node a, Node b)
{
      return a.val < b.val;
}
long long find_maximum_difference(vector<int> A, vector<Node> nodes)
{
      sort(nodes.begin(), nodes.end(), comp);
      int max = INT_MIN;
      for (int i = 0; i < A.size(); i++)
      {
            if (abs(i - nodes[i].pos) > max)
            {
                  max = abs(i - nodes[i].pos);
            }
      }
      return max;
}

int main()
{

      ios::sync_with_stdio(0);
      cin.tie(0);
      int n;
      cin >> n;
      vector<int> A(n);
      for (int i_A = 0; i_A < n; i_A++)
      {
            cin >> A[i_A];
      }

      long long out_;
      vector<Node> nodes(n);
      for (int i = 0; i < n; i++)
      {
            nodes[i].pos = i;
            nodes[i].val = A[i];
      }
      out_ = find_maximum_difference(A, nodes);
      cout << out_;
}