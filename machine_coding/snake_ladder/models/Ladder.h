#include <iostream>
using namespace std;

class Ladder
{
private:
      int mStartPosition, mEndPosition;

public:
      Ladder(int startPosition, int endPosition);
      int getStartPosition();
      int getEndPosition();
};

Ladder::Ladder(int startPosition, int endPosition)
{
      mStartPosition = startPosition;
      mEndPosition = endPosition;
}
int Ladder::getStartPosition()
{
      return mStartPosition;
}

int Ladder::getEndPosition()
{
      return mEndPosition;
}