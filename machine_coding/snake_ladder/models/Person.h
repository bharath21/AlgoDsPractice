#include <iostream>
using namespace std;

class Player
{
private:
      string mName;
      int mCurrentPosition, mPreviousPosition;

public:
      Player(string name);
      Player();

      string getName();
      int getCurrentPosition() { return mCurrentPosition; }
      int getPreviousPosition() { return mPreviousPosition; }
      void setCurrentPosition(int currentPosition) { mCurrentPosition = currentPosition; }
      void setPreviousPosition(int previousPosition) { mPreviousPosition = previousPosition; }
};

Player::Player(string name)
{
      mName = name;
      mCurrentPosition = 0;
      mPreviousPosition = 0;
}

Player::Player()
{
}

string Player::getName()
{
      return mName;
}
