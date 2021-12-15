#include "Puzzle.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> inputValues;
std::vector<std::pair<int, int>> gamma;
void Dec03::LoadInputInternal()
{
	std::string line = "";
	std::ifstream file("Dec03.txt");
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			inputValues.push_back(line);
			int index = 0;
			while (line.length() > 0)
			{
				if (gamma.size() <= index)
					gamma.push_back({ 0,0 });
				std::string val = line.substr(0, 1);
				line.erase(0, 1);
				int value = std::stoi(val);
				if (value == 1)
					gamma[index].first++;
				else
					gamma[index].second++;
				index++;
			}
		}
	}
}

void Dec03::SolvePart1()
{
	unsigned int gammeResult = 0;
	unsigned int epsilonResult = 0;
	for (int i = 0; i < gamma.size(); i++)
	{
		gammeResult = gammeResult << 1;
		if (gamma[i].first > gamma[i].second)
		{
			gammeResult += 1;
		}
	}
	int bitDiff = (sizeof(gammeResult) * 8) - (int)gamma.size();
	epsilonResult = ~gammeResult;
	epsilonResult = epsilonResult << bitDiff;
	epsilonResult = epsilonResult >> bitDiff;
	int powerConsumption = gammeResult * epsilonResult;
	std::cout << "Dec03 - Solution1 : " << powerConsumption << std::endl;
}
std::string GetOxygen(std::vector<std::string> input)
{
	for (int i = 0; i < input[0].length(); i++)
	{
		if (input.size() == 1)
			return input[0];

		std::vector<std::string> zero;
		std::vector<std::string> one;

		for (int j = 0; j < input.size(); j++)
		{
			if (input[j][i] == '0')
				zero.push_back(input[j]);
			else if (input[j][i] == '1')
				one.push_back(input[j]);
		}
		if (zero.size() == one.size())
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[j][i] == '0')
				{
					input.erase(input.begin() + j);
					j--;
				}
			}
		}
		else if (zero.size() > one.size())
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[j][i] == '1')
				{
					input.erase(input.begin() + j);
					j--;
				}
			}
		}
		else if (one.size() > zero.size())
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[j][i] == '0')
				{
					input.erase(input.begin() + j);
					j--;
				}
			}
		}
	}
	return input[0];
}

std::string GetScrubber(std::vector<std::string> input)
{
	for (int i = 0; i < input[0].length(); i++)
	{
		if (input.size() == 1)
			return input[0];

		std::vector<std::string> zero;
		std::vector<std::string> one;

		for (int j = 0; j < input.size(); j++)
		{
			if (input[j][i] == '0')
				zero.push_back(input[j]);
			else if (input[j][i] == '1')
				one.push_back(input[j]);
		}
		if (zero.size() == one.size())
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[j][i] == '1')
				{
					input.erase(input.begin() + j);
					j--;
				}
			}
		}
		else if (zero.size() > one.size())
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[j][i] == '0')
				{
					input.erase(input.begin() + j);
					j--;
				}
			}
		}
		else if (one.size() > zero.size())
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[j][i] == '1')
				{
					input.erase(input.begin() + j);
					j--;
				}
			}
		}
	}
	return input[0];
}

std::string ParseInput(std::vector<std::string> input, char prio)
{
	for (int i = 0; i < input[0].length(); i++)
	{
		if (input.size() == 1)
			return input[0];

		std::vector<std::string> zero;
		std::vector<std::string> one;

		for (int j = 0; j < input.size(); j++)
		{
			if (input[j][i] == '0')
				zero.push_back(input[j]);
			else if (input[j][i] == '1')
				one.push_back(input[j]);
		}
		if (zero.size() == one.size())
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[j][i] == prio)
				{
					input.erase(input.begin() + j);
					j--;
				}
			}
		}
		else if (zero.size() > one.size())
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[j][i] != prio)
				{
					input.erase(input.begin() + j);
					j--;
				}
			}
		}
		else if (one.size() > zero.size())
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[j][i] == prio)
				{
					input.erase(input.begin() + j);
					j--;
				}
			}
		}
	}
	return input[0];
}

unsigned int StrBinToInt(std::string input)
{
	unsigned int result = 0;
	for (int i = 0; i < input.size(); i++)
	{
		result = result << 1;
		result += (input[i] == '1' ? 1 : 0);
	}
	return result;
}
void Dec03::SolvePart2()
{
	unsigned int oxygenGenLevel = 0;
	std::string oxygen = ParseInput(inputValues, '0');
	std::string scrubber = ParseInput(inputValues, '1');

	unsigned int oxygenValue = StrBinToInt(oxygen);
	unsigned int scrubberValue = StrBinToInt(scrubber);
	
	int lifesupport = oxygenValue * scrubberValue;
	std::cout << "Dec03 - Solution2 : " << lifesupport << std::endl;

	return;
}