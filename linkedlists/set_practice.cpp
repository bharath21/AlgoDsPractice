#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
      int pos;
      int value;
      Node(int a, int b)
      {
            pos = a;
            value = b;
      }
};
int main()
{
      unordered_set<int> keys;
      keys.insert(1);
      keys.insert(2);
      keys.insert(3);
      keys.insert(10);

      unordered_multiset<int> mKeys;
      mKeys.insert(keys.begin(), keys.end());
      mKeys.insert(10);
      Node *nodes[] = {new Node(1, 100),
                       new Node(2, 50)};

      unordered_map<string, int> map;
      map.insert(make_pair("a", 1));
      map["b"] = 1;
      // auto it = map.find("z");
      // if (it == map.end())
      // {
      //       cout << "not found" << endl;
      // }
      if (map.find("a") == map.end())
      {
            cout << "bad" << endl;
      }
      sort(nodes, nodes + 2, [](Node *a, Node *b) -> bool {
            return a->pos < b->pos;
      });
      for (auto i : map)
      {
            cout << i.first << " " << i.second << endl;
      }
}