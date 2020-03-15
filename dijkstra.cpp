#include "bots.h"
#include <exception>
#include <iostream>


void cDijkstra::Build(cBotBase& bot) {

	for (int x = 0; x < GRIDWIDTH; x++)
	{
		for (int y = 0; y < GRIDHEIGHT; y++)
		{
			closed[x][y] = false;
			cost[x][y] = 1000000000000000.0f;
			linkX[x][y] = -1;
			linkY[x][y] = -1;
			inPath[x][y] = -1;
		}
	}

	cost[bot.PositionX()][bot.PositionY()] = 0;

	while (!closed[gTarget.PositionX()][gTarget.PositionY()])
	{
		int lowestCost = 10000000;
		int lowCostX = -1;
		int lowCostY = -1;

		for (int x = 0; x < GRIDWIDTH; x++)
		{
			for (int y = 0; y < GRIDHEIGHT; y++)
			{
				if (lowestCost > cost[x][y])
				{
					lowestCost = cost[x][y];
					lowCostX = x;
					lowCostY = y;
				}
			}
		}

		closed[lowCostX][lowCostY] = true;

		if (gLevel.isValid(lowCostX - 1, lowCostY - 1) && closed[lowCostX - 1][lowCostY - 1])
		{
			float newCost = cost[lowCostX][lowCostY] + 1.4f;
			float currentCost = cost[lowCostX - 1][lowCostY - 1];
			if (newCost < currentCost)
			{
				cost[lowCostX - 1][lowCostY - 1] = newCost;
				linkX[lowCostX - 1][lowCostY - 1] = lowCostX;
				linkY[lowCostX - 1][lowCostY - 1] = lowCostY;
			}
		}

		if (gLevel.isValid(lowCostX, lowCostY - 1) && closed[lowCostX][lowCostY - 1])
		{
			float newCost = cost[lowCostX][lowCostY] + 1.0f;
			float currentCost = cost[lowCostX][lowCostY - 1];
			if (newCost < currentCost)
			{
				cost[lowCostX][lowCostY - 1] = newCost;
				linkX[lowCostX][lowCostY - 1] = lowCostX;
				linkY[lowCostX][lowCostY - 1] = lowCostY;
			}
		}

		if (gLevel.isValid(lowCostX + 1, lowCostY - 1) && closed[lowCostX + 1][lowCostY - 1])
		{
			float newCost = cost[lowCostX][lowCostY] + 1.4f;
			float currentCost = cost[lowCostX + 1][lowCostY - 1];
			if (newCost < currentCost)
			{
				cost[lowCostX + 1][lowCostY - 1] = newCost;
				linkX[lowCostX + 1][lowCostY - 1] = lowCostX;
				linkY[lowCostX + 1][lowCostY - 1] = lowCostY;
			}
		}

		if (gLevel.isValid(lowCostX - 1, lowCostY) && closed[lowCostX - 1][lowCostY])
		{
			float newCost = cost[lowCostX][lowCostY] + 1.0f;
			float currentCost = cost[lowCostX - 1][lowCostY];
			if (newCost < currentCost)
			{
				cost[lowCostX - 1][lowCostY] = newCost;
				linkX[lowCostX - 1][lowCostY] = lowCostX;
				linkY[lowCostX - 1][lowCostY] = lowCostY;
			}
		}

		if (gLevel.isValid(lowCostX + 1, lowCostY) && closed[lowCostX + 1][lowCostY])
		{
			float newCost = cost[lowCostX][lowCostY] + 1.0f;
			float currentCost = cost[lowCostX + 1][lowCostY];
			if (newCost < currentCost)
			{
				cost[lowCostX + 1][lowCostY] = newCost;
				linkX[lowCostX + 1][lowCostY] = lowCostX;
				linkY[lowCostX + 1][lowCostY] = lowCostY;
			}
		}

		if (gLevel.isValid(lowCostX - 1, lowCostY + 1) && closed[lowCostX - 1][lowCostY + 1])
		{
			float newCost = cost[lowCostX][lowCostY] + 1.4f;
			float currentCost = cost[lowCostX - 1][lowCostY + 1];
			if (newCost < currentCost)
			{
				cost[lowCostX - 1][lowCostY + 1] = newCost;
				linkX[lowCostX - 1][lowCostY + 1] = lowCostX;
				linkY[lowCostX - 1][lowCostY + 1] = lowCostY;
			}
		}

		if (gLevel.isValid(lowCostX, lowCostY + 1) && closed[lowCostX][lowCostY + 1])
		{
			float newCost = cost[lowCostX][lowCostY] + 1.0f;
			float currentCost = cost[lowCostX][lowCostY + 1];
			if (newCost < currentCost)
			{
				cost[lowCostX][lowCostY + 1] = newCost;
				linkX[lowCostX][lowCostY + 1] = lowCostX;
				linkY[lowCostX][lowCostY + 1] = lowCostY;
			}
		}

		if (gLevel.isValid(lowCostX + 1, lowCostY + 1) && closed[lowCostX + 1][lowCostY + 1])
		{
			float newCost = cost[lowCostX][lowCostY] + 1.4f;
			float currentCost = cost[lowCostX + 1][lowCostY + 1];
			if (newCost < currentCost)
			{
				cost[lowCostX + 1][lowCostY + 1] = newCost;
				linkX[lowCostX + 1][lowCostY + 1] = lowCostX;
				linkY[lowCostX + 1][lowCostY + 1] = lowCostY;
			}
		}
		bool done = false; //set to true when we are back at the bot position
		int nextClosedX = gTarget.PositionX(); //start of path
		int nextClosedY = gTarget.PositionY(); //start of path
		while (!done)
		{
			inPath[nextClosedX][nextClosedY] = true;
			int tmpX = nextClosedX;
			int tmpY = nextClosedY;
			nextClosedX = linkX[tmpX][tmpY];
			nextClosedY = linkY[tmpX][tmpY];
			if ((nextClosedX == bot.PositionX()) && (nextClosedY ==
				bot.PositionY())) done = true;
		}

	}
	completed = true;
}

cDijkstra gDijkstra;