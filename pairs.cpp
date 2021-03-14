#include <bits/stdc++.h>
using namespace std;

void generatePairs(vector<string> &pairs)
{
      char a[26];

      for (int i = 0; i < 26; i++)
      {
            a[i] = 'a' + i;
      }

      for (int i = 0; i < 26; i++)
      {
            for (int j = 0; j < 26; j++)
            {
                  if (i == j)
                  {
                        continue;
                  }
                  string temp1, temp2, temp;
                  stringstream ss;
                  ss << a[i];
                  ss >> temp1;
                  ss.clear();
                  ss << a[j];
                  ss >> temp2;
                  ss.clear();
                  string pair = temp1 + temp2;
                  pairs.push_back(pair);
            }
      }
}
void calculateFrequencies(string input, vector<int> &freqs)
{
      for (auto i : input)
      {
            freqs[i - 'a']++;
      }
}
int calculateMaxSub(string input, vector<string> pairs, vector<int> freqs)
{

      int maxChar = INT_MIN;
      int result = 0;

      for (int i = 0; i < 26; i++)
      {
            if (freqs[i] > maxChar)
            {
                  maxChar = freqs[i];
            }
      }
      // maxChar = *max(freqs.begin(), freqs.end());
      cout << "max " << maxChar << endl;
      result = maxChar;
      for (auto pair : pairs)
      {
            bool firstFound = false;
            int count = 0;
            if (freqs[pair[0]] == 0 || freqs[pair[1]] == 0)
            {
                  continue;
            }
            for (auto character : input)
            {
                  if (!firstFound && character == pair[0])
                  {
                        firstFound = true;
                  }
                  else if (firstFound && character == pair[1])
                  {
                        firstFound = false;
                        count += 2;
                  }
            }
            if (count > result)
            {
                  result = count;
            }
      }
      return result;
}
int main()
{
      string input;
      cin >> input;
      vector<string> pairs;
      vector<int> freqs(26, 0);
      generatePairs(pairs);
      calculateFrequencies(input, freqs);
      for (auto i : input)
      {
            cout << freqs[i - 'a'] << endl;
      }
      cout << endl
           << calculateMaxSub(input, pairs, freqs);
      return 0;
}