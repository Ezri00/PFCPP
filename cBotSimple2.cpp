#include "bots.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

void cBotSimple2::ChooseNextGridPosition() {


	bool done = false;
	while (!done)
	{
		int currentX = PositionX();
		int currentY = PositionY();
		int targetX = gTarget.PositionX();
		int targetY = gTarget.PositionY();

		if (currentX > targetX && gLevel.isValid(PositionX() - 1, PositionY()))
		{
			cout << "1" << endl;
			done = SetNext((PositionX() - 1), (PositionY()), gLevel);
		}
		else if (currentX < targetX && gLevel.isValid(PositionX() + 1, PositionY()))
		{
			cout << "2" << endl;
			done = SetNext((PositionX() + 1), (PositionY()), gLevel);
		}
		else if (currentY > targetY && gLevel.isValid(PositionX(), PositionY() - 1))
		{
			cout << "3" << endl;
			done = SetNext((PositionX()), (PositionY() - 1), gLevel);
		}
		else if (currentY < targetY && gLevel.isValid(PositionX(), PositionY() + 1))
		{
			cout << "4" << endl;
			done = SetNext((PositionX()), (PositionY() + 1), gLevel);
		}
		else if (gLevel.isValid(PositionX(), PositionY() - 1))
		{
			cout << "Move Up" << endl;
			done = SetNext((PositionX()), (PositionY() - 1), gLevel);
		}
		else if (gLevel.isValid(PositionX() - 1, PositionY()))
		{
			cout << "Move Left" << endl;
			done = SetNext((PositionX() - 1), (PositionY()), gLevel);
		}
	}

}