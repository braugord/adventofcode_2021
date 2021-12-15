#include "Puzzle.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

enum class Direction
{
	Forward,
	Up,
	Down
};

std::vector<std::pair<Direction, int>> input;

void Dec02::LoadInputInternal()
{
	std::string line = "";
	std::ifstream file("Dec02.txt");
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			std::string dir = line.substr(0, line.find(' '));
			line.erase(0, line.find(' '));
			int value = std::stoi(line);
			Direction direction;
			if (dir == "forward") direction = Direction::Forward;
			else if (dir == "up") direction = Direction::Up;
			else if (dir == "down") direction = Direction::Down;
			input.push_back({ direction, value });
		}
	}
}

void Dec02::SolvePart1()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < input.size(); i++)
	{
		switch (input[i].first)
		{
		case Direction::Forward: x += input[i].second; break;
		case Direction::Up: y -= input[i].second; break;
		case Direction::Down: y += input[i].second; break;
		}
	}
	int result = x * y;
	std::cout << "Dec01 - Solution1 : " << result << std::endl;
}

void Dec02::SolvePart2()
{
	int x = 0;
	int y = 0;
	int aim = 0;
	for (int i = 0; i < input.size(); i++)
	{
		switch (input[i].first)
		{
		case Direction::Forward: x += input[i].second; 
								 y += aim * input[i].second; break;
		case Direction::Up: aim -= input[i].second; break;
		case Direction::Down: aim += input[i].second; break;
		}
	}
	int result = x * y;
	std::cout << "Dec01 - Solution2 : " << result << std::endl;
}