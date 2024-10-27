#include <iostream>
#include <windows.h>
#include <random>
//random creation
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(0, 4);
std::uniform_int_distribution<int> dist1(0, 25);
//map creation
const int mapWidth = 29, mapHeight = 29;
char map[mapHeight][mapWidth]
{
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', '#',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', '#',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', '#','#','#', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ','#', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ','#', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ','#','#', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ','#', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ','#', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#', '#','#','#', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ','#', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ','#', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ','#', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ','#', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', '#',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', '#',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ','#', '#','#',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ',' ', ' ',' ',' ', ' ',' ', ' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};
//bot random move
void botMovement(int& bot1X, int& bot1Y, int& bot2X, int& bot2Y)
{
	int bot1Move = dist(gen), bot2Move = dist(gen);
	//bot 1 movement
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
	//bot 2 movement
	if (bot2Y != 0 and bot2X != 0)
	{
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
}
int main()
{
	int score = 0;
	int bot1X = 0, bot1Y = 0, bot2X = 0, bot2Y = 0;
	//selection level
	int level = 3;
	while (level > 2)
	{
		std::cout << "Select bot amounts [1-2]: ";
		std::cin >> level;
		if (level < 1) std::cout << "ahahahha, 2 bots!!!!!!!)\n";
		else if (level == 1) std::cout << "1 bot selected\n";
		else if (level == 2) std::cout << "2 bots secelted\n";
	}
	//instruiction 
	bool instruction_sent = 0;
	//start positions
	bot1X = dist1(rd), bot1Y = dist1(rd);
	if (level < 1 or level == 2) bot2X = dist1(rd), bot2Y = dist1(rd);
	else int bot2X = 1, bot2Y = 0;
	int personX = dist1(rd), personY = dist1(rd);
	//not x,y doubled check
	while ((personX == bot1X and personY == bot1Y) or (personX == bot2X and personY == bot2Y) or (bot2X == bot1X and bot2Y == bot2X))
	{
		int personX = dist1(rd), personY = dist1(rd);
		int bot1X = dist1(rd), bot1Y = dist1(rd);
		if (level < 1 or level == 2) int bot2X = dist1(rd), bot2Y = dist1(rd);
		else int bot2X = 0, bot2Y = 0;
	}
	//moveperson
	bool gameStarted = 1;
	char movePerson = ' ';

	while (gameStarted)
	{
		map[personY][personX] = 'Z';
		map[bot1Y][bot1X] = '@';
		//2 bot
		if (level < 1 or level == 2)
			map[bot2Y][bot2X] = '@';
		if (instruction_sent != 0) system("cls");

		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				std::cout << " " << map[i][j];
			}
			std::cout << std::endl;
		}

		if (instruction_sent == 0)
		{
			std::cout << "Player: Z\n" << "Bots: @\n";
			Sleep(500);
		}
		instruction_sent = 1;

		//Up movement
		if (GetAsyncKeyState(VK_UP) & 0X8000)
		{
			if (map[personY - 1][personX] != '#') //not barrier check
			{
				map[personY][personX] = ' ';
				personY--;
				score++;
				botMovement(bot1X, bot1Y, bot2X, bot2Y);
				if ((personX == bot1X and personY == bot1Y) or (personX == bot2X and personY == bot2Y)) //death check
				{
					std::cout << "DEATH\n";
					std::cout << "your score: " << score << "\n";
					if (score < 50) std::cout << "lol, noob xD";
					Sleep(10000);
					break;
				}
			}
		}
		//Down movement
		if (GetAsyncKeyState(VK_DOWN) & 0X8000)
		{
			if (map[personY + 1][personX] != '#')
			{
				map[personY][personX] = ' ';
				personY++;
				score++;
				botMovement(bot1X, bot1Y, bot2X, bot2Y);
				if ((personX == bot1X and personY == bot1Y) or (personX == bot2X and personY == bot2Y))
				{
					std::cout << "DEATH\n";
					std::cout << "your score: " << score << "\n";
					if (score < 50) std::cout << "lol, noob xD";
					Sleep(10000);
					break;
				}
			}
		}
		//right movement
		if (GetAsyncKeyState(VK_RIGHT) & 0X8000)
		{
			if (map[personY][personX + 1] != '#')
			{
				map[personY][personX] = ' ';
				personX++;
				score++;
				botMovement(bot1X, bot1Y, bot2X, bot2Y);
				if ((personX == bot1X and personY == bot1Y) or (personX == bot2X and personY == bot2Y))
				{
					std::cout << "DEATH\n";
					std::cout << "your score: " << score << "\n";
					if (score < 50) std::cout << "lol, noob xD";
					Sleep(10000);
					break;
				}
			}
		}
		//left movement
		if (GetAsyncKeyState(VK_LEFT) & 0X8000)
		{
			if (map[personY][personX - 1] != '#')
			{
				map[personY][personX] = ' ';
				personX--;
				score++;
				botMovement(bot1X, bot1Y, bot2X, bot2Y);
				if ((personX == bot1X and personY == bot1Y) or (personX == bot2X and personY == bot2Y))
				{
					std::cout << "DEATH\n";
					std::cout << "your score: " << score << "\n";
					if (score < 50) std::cout << "lol, noob xD";
					Sleep(10000);
					break;
				}
			}
		}
	}
}
