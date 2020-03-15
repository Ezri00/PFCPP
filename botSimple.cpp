#include "bots.h"
#include "stdlib.h"

void cBotSimple::ChooseNextGridPosition() {

	bool done = false;
	while (!done)
	{
		int currentX = PositionX();
		int currentY = PositionY();
		int targetX = gTarget.PositionX();
		int targetY = gTarget.PositionY();

		if (currentX > targetX)
		{
			done = SetNext((PositionX() - 1), (PositionY()), gLevel);
		}
		else if (currentX < targetX)
		{
			done = SetNext((PositionX() + 1), (PositionY()), gLevel);
		}
		else if (currentY > targetY)
		{
			done = SetNext((PositionX()), (PositionY() - 1), gLevel);
		}
		else if (currentY < targetY)
		{
			done = SetNext((PositionX()), (PositionY() + 1), gLevel);
		}
	}

}