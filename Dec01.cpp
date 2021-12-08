#include "Puzzle.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<int> numbers;

void Dec01::LoadInputInternal()
{
	std::string line = "";
	std::ifstream file("Dec01.txt");
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			numbers.push_back(std::stoi(line));
		}
	}
}

void Dec01::SolvePart1()
{
	int depthIncrease = 0;
	for (size_t i = 0; i < numbers.size()-1; i++)
	{
		if (numbers[i] < numbers[i + 1])
			depthIncrease++;
	}
	std::cout << "Dec01 - Solution1 : " << depthIncrease << std::endl;
}

void Dec01::SolvePart2()
{
	int depthIncrease = 0;
	for (size_t i = 0; i < numbers.size() - 3; i++)
	{
		int current = numbers[i] + numbers[i + 1] + numbers[i + 2];
		int next = numbers[i+1] + numbers[i + 2] + numbers[i + 3];
		if (current < next)
			depthIncrease++;
	}
	std::cout << "Dec01 - Solution2 : " << depthIncrease << std::endl;
}