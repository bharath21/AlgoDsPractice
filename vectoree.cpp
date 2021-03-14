// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void add_pair(vector<pair<string, pair<int, int>>> &A, string str, int x, int y);
int get_size(vector<pair<string, pair<int, int>>> &A);
void print_values(vector<pair<string, pair<int, int>>> &A);
void sort_pair(vector<pair<string, pair<int, int>>> &A);

int main()
{
      // your code goes here
      int t;
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);

      cin >> t;
      while (t--)
      {
            vector<pair<string, pair<int, int>>> A;
            int q;
            cin >> q;
            string ss;
            while (q--)
            {
                  char c;
                  cin >> c;
                  if (c == 'a')
                  {
                        string name;
                        cin >> ss;
                        // int x, y;
                        // cin >> x >> y;
                        //add_pair(A, name, x, y);
                  }
                  if (c == 'b')
                  {
                        cout << ss << " ";
                  }
                  if (c == 'c')
                  {
                        print_values(A);
                  }
                  if (c == 'd')
                  {
                        sort_pair(A);
                  }
            }
            cout << endl;
      }
      return 0;
} // } Driver Code Ends

/* Inserts a pair  <string,   pair<x, y> > >    into the vector A */
void add_pair(vector<pair<string, pair<int, int>>> &A, string str, int x, int y)
{
      // Your code here
      pair<int, int> p(x, y);
      pair<string, pair<int, int>> q(str, p);
      A.push_back(q);
}

/* Returns the size of the vector A */
int get_size(vector<pair<string, pair<int, int>>> &A)
{
      // Your code here
      return A.size();
}

/* Prints space separated values of vector A */
void print_values(vector<pair<string, pair<int, int>>> &A)
{
      // Your code here

      for (auto it = A.begin(); it != A.end(); it++)
      {
            cout << it->first << " " << it->second.first << " " << it->second.second << endl;
      }
}

bool comp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
      return (a.second.first == b.second.first) ? (a.second.second < b.second.second) : (a.second.first < b.second.first);
}
/* Sorts the vector A based on value x and y*/
void sort_pair(vector<pair<string, pair<int, int>>> &A)
{
      // Your code here
      sort(A.begin(), A.end(), comp);
}
