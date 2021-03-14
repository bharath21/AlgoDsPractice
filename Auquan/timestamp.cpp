#include <bits/stdc++.h>
using namespace std;
int charToInt(char i)
{
      return i - '0';
}
int *stringToInt(string givenString)
{
      int *arr = new int[3];
      arr[0] = charToInt(givenString[0]) * 10 + charToInt(givenString[1]);
      arr[1] = charToInt(givenString[3]) * 10 + charToInt(givenString[4]);
      arr[2] = charToInt(givenString[6]) * 10 + charToInt(givenString[7]);
      return arr;
};

int main()
{
      string givenString = "11:23:10";
      vector<string> timestamps;
      timestamps.push_back("10:23:10");
      timestamps.push_back("10:01:00");
      timestamps.push_back("10:59:50");
      int *givenTimestamp = stringToInt(givenString);
      cout << givenTimestamp[0] << " " << givenTimestamp[1] << " " << givenTimestamp[2];
      int inputSeconds = givenTimestamp[0] * 3600 + givenTimestamp[1] * 60 + givenTimestamp[2];
      vector<string> result;
      for (int i = 0; i < timestamps.size(); i++)
      {
            // cout << timestamps[i] << endl;
      }
      for (int i = 0; i < timestamps.size(); i++)
      {
            string time = timestamps[i];
            // cout << time << endl;
            int *timeStamp = stringToInt(time);
            // cout << timeStamp[0] << " " << timeStamp[1] << " " << timeStamp[2];

            int seconds = timeStamp[0] * 3600 + timeStamp[1] * 60 + timeStamp[2];
            int diff = inputSeconds - seconds;
            string res = "";
            cout << diff << endl;
            if (diff / 3600 > 0)
            {
                  res += to_string(diff / 3600);
                  if (diff / 3600 == 1)
                  {
                        res += " hour ago";
                        result.push_back(res);
                  }
                  else
                  {
                        res += " hours ago";
                        result.push_back(res);
                  }
            }
            else if (diff / 60 > 0)
            {
                  res += to_string(diff / 60);

                  if (diff / 60 == 1)
                  {
                        res += " minute ago";
                        result.push_back(res);
                  }
                  else
                  {
                        res += " minutes ago";
                        result.push_back(res);
                  }
            }
            else if (0 < diff && diff < 60)
            {
                  res += to_string(diff);

                  if (diff == 1)
                  {
                        res += " second ago";
                        result.push_back(res);
                  }
                  else
                  {
                        res += " seconds ago";
                        result.push_back(res);
                  }
            }
            else
            {
                  result.push_back("now");
            }
      }
      cout << endl;
      for (auto s : result)
      {
            cout << s << endl;
      }
}