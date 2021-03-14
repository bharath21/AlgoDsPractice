#include "Game.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
      fstream ifs("D:\\dev\\coding_practice\\trees\\machine_coding\\snake_ladder\\input.txt", ios_base::in);
      srand(time(NULL)); 
      int ns, nl, np, m, n;
      string s;
      vector<pair<int, int>> snakes;
      vector<pair<int, int>> ladders;
      vector<string> players;
      ifs >> ns;

      while (ns--)
      {
            ifs >> m >> n;
            snakes.push_back(make_pair(m, n));
      }
      ifs >> nl;
      while (nl--)
      {
            ifs >> m >> n;
            ladders.push_back(make_pair(m, n));
      }
      ifs >> np;
      while (np--)
      {
            ifs >> s;
            players.push_back(s);
      }
      Game game(snakes, ladders, players);
      game.startGame();
}