#include "Puzzle.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

void swap(int& lhs, int& rhs)
{
	int tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}
struct Vector2
{
	int x;
	int y;
};
struct VentLine
{
	Vector2 from;
	Vector2 to;
};

class Grid
{
	int* cells;
	unsigned int width;
	unsigned int height;
public:
	Grid(std::vector<VentLine>& ventLines)
	{
		int maxX = 0;
		int maxY = 0;
		for (int i = 0; i < ventLines.size(); i++)
		{
			if (ventLines[i].from.x > maxX)
				maxX = ventLines[i].from.x;
			if (ventLines[i].to.x > maxX)
				maxX = ventLines[i].to.x;
			if (ventLines[i].from.y > maxY)
				maxY = ventLines[i].from.x;
			if (ventLines[i].to.y > maxY)
				maxY = ventLines[i].to.x;
		}
		width = maxX+1;
		height = maxY+1;
		cells = new int[width * height]{};
	}
	~Grid()
	{
		delete[] cells;
	}
	void CalculatePart1(std::vector<VentLine>& ventLines)
	{
		for (int i = 0; i < ventLines.size(); i++)
		{
			Vector2 from = ventLines[i].from;
			Vector2 to = ventLines[i].to;

			if (from.x != to.x && from.y != to.y)
				continue;

			if (from.x > to.x)
				swap(from.x, to.x);
			if (from.y > to.y)
				swap(from.y, to.y);

			if (from.x != to.x)
			{
				for (int x = from.x; x <= to.x; x++)
				{
					int cellindex = x + from.y * width;
					cells[cellindex]++;
				}
			}

			if (from.y != to.y)
			{
				for (int y = from.y; y <= to.y; y++)
				{
					int cellindex = from.x + y * width;
					cells[cellindex]++;
				}
			}
		}
	}

	void CalculatePart2(std::vector<VentLine>& ventLines)
	{

		for (int i = 0; i < ventLines.size(); i++)
		{
			Vector2 from = ventLines[i].from;
			Vector2 to = ventLines[i].to;

			if (from.x != to.x && from.y != to.y)
			{
				int deltaX = abs(from.x - to.x);
				int deltaY = abs(from.y - to.y);
				if (deltaX != deltaY)
					continue;

				int dirX = (to.x > from.x ? 1 : -1);
				int dirY = (to.y > from.y ? 1 : -1);
				for (int i = 0; i <= deltaX; i++)
				{
					int x = from.x + (dirX * i);
					int y = from.y + (dirY * i);
					int cellindex = x + y * width;
					cells[cellindex]++;
				}

			}
			else
			{
				if (from.x > to.x)
					swap(from.x, to.x);
				if (from.y > to.y)
					swap(from.y, to.y);

				if (from.x != to.x)
				{
					for (int x = from.x; x <= to.x; x++)
					{
						int cellindex = x + from.y * width;
						cells[cellindex]++;
					}
				}

				if (from.y != to.y)
				{
					for (int y = from.y; y <= to.y; y++)
					{
						int cellindex = from.x + y * width;
						cells[cellindex]++;
					}
				}
			}
		}
	}

	int GetOverlappingPoints(int atLeast)
	{
		int sum = 0;
		int size = width * height;
		for (int i = 0; i < size; i++)
		{
			if (cells[i] >= atLeast)
				sum++;
		}
		return sum;
	}
	void Print()
	{
		int size = width * height;
		for (int i = 0; i < size; i++)
		{
			
			if (i % width == 0)
				std::cout << std::endl;

			std::cout << "[" << cells[i] << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
};

std::vector<VentLine> input;

void Dec05::LoadInputInternal()
{
	std::string line = "";
	std::ifstream file("Dec05.txt");
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			while (line.length() > 0)
			{
				std::string from = line.substr(0, line.find(' '));
				line.erase(0, line.find('>') + 2);
				std::string to = line;
				std::string fromX = from.substr(0, from.find(','));
				std::string fromY = from.substr(from.find(',') + 1, from.length());
				std::string toX = to.substr(0, to.find(','));
				std::string toY = to.substr(to.find(',') + 1, to.length());
				line = "";
				VentLine ventLine;
				ventLine.from.x = std::stoi(fromX);
				ventLine.from.y = std::stoi(fromY);
				ventLine.to.x = std::stoi(toX);
				ventLine.to.y = std::stoi(toY);
				input.push_back(ventLine);
			}
		}
	}
}

void Dec05::SolvePart1()
{
	Grid grid(input);
	grid.CalculatePart1(input);
	int result = grid.GetOverlappingPoints(2);
	std::cout << "Dec05 - Solution1 : " << result << std::endl;
}


void Dec05::SolvePart2()
{
	Grid grid(input);
	grid.CalculatePart2(input);
	int result = grid.GetOverlappingPoints(2);
	std::cout << "Dec05 - Solution2 : " << result << std::endl;
}