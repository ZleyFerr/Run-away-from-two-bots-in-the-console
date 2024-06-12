#include <iostream>
const int mapWidth = 29, mapHeight = 29;
char map[mapHeight][mapWidth]
{
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};
void botMovement(int &bot1X, int &bot1Y, int &bot2X, int &bot2Y)
{
	srand(time(NULL));
	int bot1Move = (rand() % 4) + 1, bot2Move = (rand() % 4) + 1;
	switch (bot1Move)
	{
	case 1:
		if (map[bot1Y + 1][bot1X] != '#')
		{
			map[bot1Y][bot1X] = ' ';
			bot1Y++;
		}break;
	case 2:
		if (map[bot1Y - 1][bot1X] != '#')
		{
			map[bot1Y][bot1X] = ' ';
			bot1Y--;
		}break;
	case 3:
		if (map[bot1Y][bot1X + 1] != '#')
		{
			map[bot1Y][bot1X] = ' ';
			bot1X++;
		}break;
	case 4:
		if (map[bot1Y][bot1X - 1] != '#')
		{
			map[bot1Y][bot1X] = ' ';
			bot1X--;
		}break;
	default:
		break;
	}
	switch (bot2Move)
	{
	case 1:
		if (map[bot2Y + 1][bot2X] != '#')
		{
			map[bot2Y][bot2X] = ' ';
			bot2Y++;
		}break;
	case 2:
		if (map[bot2Y - 1][bot2X] != '#')
		{
			map[bot2Y][bot2X] = ' ';
			bot2Y--;
		}break;
	case 3:
		if (map[bot2Y][bot2X + 1] != '#')
		{
			map[bot2Y][bot2X] = ' ';
			bot2X++;
		}break;
	case 4:
		if (map[bot2Y][bot2X - 1] != '#')
		{
			map[bot2Y][bot2X] = ' ';
			bot2X--;
		}break;
	default:
		break;
	}
}
int main()
{
	srand(time(NULL));
	int bot1X = (rand() % 25) + 1, bot1Y = (rand() % 25) + 1;
	int bot2X = (rand() % 25) + 1, bot2Y = (rand() % 25) + 1;
	int personX = (rand() % 25) + 1, personY = (rand() % 25) + 1;
	while ((personX == bot1X and personY == bot1Y) or (personX == bot2X and personY == bot2Y) or (bot2X == bot1X and bot2Y == bot2X))
	{
		int personX = rand() % 25, personY = rand() % 25;
		int bot1X = rand() % 25, bot1Y = rand() % 25;
		int bot2X = rand() % 25, bot2Y = rand() % 25;
	}
	bool gameStarted = 1;
	char movePerson = ' ';
	while (gameStarted)
	{
		map[personY][personX] = 'Z';
		map[bot1Y][bot1X] = '@';
		map[bot2Y][bot2X] = '@';
		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				std::cout << " " << map[i][j];
			}
			std::cout << std::endl;
		}

		std::cin >> movePerson;

		if (movePerson == 'W' or movePerson == 'w')
		{
			if (map[personY - 1][personX] != '#')
			{
				map[personY][personX] = ' ';
				personY--;
				botMovement(bot1X, bot1Y, bot2X, bot2Y);
				if ((personX == bot1X and personY == bot1Y) or (personX == bot2X and personY == bot2Y))
				{
					std::cout << "DEATH";
					break;
				}
			}
			else
			{
				std::cin >> movePerson;
			}
		}
		else if (movePerson == 'S' or movePerson == 's')
		{
			if (map[personY + 1][personX] != '#')
			{
				map[personY][personX] = ' ';
				personY++;
				botMovement(bot1X, bot1Y, bot2X, bot2Y);
				if ((personX == bot1X and personY == bot1Y) or (personX == bot2X and personY == bot2Y))
				{
					std::cout << "DEATH";
					break;
				}
			}
			else
			{
				std::cin >> movePerson;
			}
		}
		else if (movePerson == 'D' or movePerson == 'd')
		{
			if (map[personY][personX + 1] != '#')
			{
				map[personY][personX] = ' ';
				personX++;
				botMovement(bot1X, bot1Y, bot2X, bot2Y);
				if ((personX == bot1X and personY == bot1Y) or (personX == bot2X and personY == bot2Y))
				{
					std::cout << "DEATH";
					break;
				}
			}
			else
			{
				std::cin >> movePerson;
			}
		}
		else if (movePerson == 'a' or movePerson == 'A')
		{
			if (map[personY][personX - 1] != '#')
			{
				map[personY][personX] = ' ';
				personX--;
				botMovement(bot1X, bot1Y, bot2X, bot2Y);
				if ((personX == bot1X and personY == bot1Y) or (personX == bot2X and personY == bot2Y))
				{
					std::cout << "DEATH";
					break;
				}
			}
			else
			{
				std::cin >> movePerson;
			}
		}
	}
}
