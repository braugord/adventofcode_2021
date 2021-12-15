#include "Puzzle.h"
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

struct BingoNumber
{
	unsigned int number;
	bool marked;
};
class BingoBoard
{
public:
	static const unsigned int width = 5;
	static const unsigned int height = 5;
	BingoNumber numbers[width * height];

	void MarkNumber(int number)
	{
		int size = width * height;
		for (int i = 0; i < size; i++)
		{
			if (numbers[i].number == number)
			{
				numbers[i].marked = true;
				return;
			}
		}
	}

	
	bool HasBingo()
	{
		int size = width * height;
		
		for (int i = 0; i < width; i++)
		{
			int horizontalMarked = 0;
			int verticalMarked = 0;
			for (int j = 0; j<width; j++)
			{
				// horizontal bingo
				int horizontalIndex = j + i * width;
				horizontalMarked += (int)numbers[horizontalIndex].marked;

				// vertical bingo
				int verticalIndex = i + (j * width);
				verticalMarked += (int)numbers[verticalIndex].marked;
			}
			if (horizontalMarked == width || verticalMarked == width)
				return true;
		}
		return false;
	}
	/*
	* index in array
	[ 0][ 1][ 2][ 3][ 4]
	[ 5][ 6][ 7][ 8][ 9]
	[10][11][12][13][14]
	[15][16][17][18][19]
	[20][21][22][23][24]
	*/

	int GetUnmarkedTotal()
	{
		int size = width * height;
		int total = 0;
		for (int i = 0; i < size; i++)
		{
			if (!numbers[i].marked)
				total += numbers[i].number;
		}
		return total;
	}
};

std::vector<BingoBoard*> bingoBoards;
std::vector<int> numbersDrawn;

void Dec04::LoadInputInternal()
{
	std::string line = "";
	std::ifstream file("Dec04.txt");
	BingoBoard* board = nullptr;
	if (file.is_open())
	{
		std::getline(file, line);

		while (line.length() > 0)
		{
			size_t delim = line.find(',');
			std::string val = line.substr(0, delim);
			line.erase(0, delim + (delim == std::string::npos ? 0 : 1));
			
			int value = std::stoi(val);
			numbersDrawn.push_back(value);
		}

		unsigned int index = 0;
		while (std::getline(file, line))
		{
			if (line.size() == 0)
			{
				board = new BingoBoard();
				bingoBoards.push_back(board);
				index = 0;
			}
			while (line.length() > 0)
			{
				size_t delim = line.find(' ');
				std::string val = line.substr(0, delim);
				if (val.length() == 0)
				{
					line.erase(0, 1);
					continue;
				}
				line.erase(0, delim + (delim == std::string::npos ? 0 : 1));
				int value = std::stoi(val);
				if (board == nullptr)
					return;
				board->numbers[index].number = value;
				index++;
			}
		}
	}
}

void Dec04::SolvePart1()
{
	for (int i = 0; i < numbersDrawn.size(); i++)
	{
		int number = numbersDrawn[i];
		for (int j = 0; j < bingoBoards.size(); j++)
		{
			bingoBoards[j]->MarkNumber(number);
		}
		for (int j = 0; j < bingoBoards.size(); j++)
		{
			if (bingoBoards[j]->HasBingo())
			{
				int unmarkedTotal = bingoBoards[j]->GetUnmarkedTotal();
				int answer = unmarkedTotal * number;
				std::cout << "Dec04 - Solution1 : " << answer << std::endl;
				return;
			}
		}
	}
	/*
	At this point, the third board wins because it has at least one complete row or 
	column of marked numbers (in this case, the entire top row is marked: 14 21 17 24 4).

	The score of the winning board can now be calculated. Start by finding the sum of all 
	unmarked numbers on that board; in this case, the sum is 188. Then, multiply that sum 
	by the number that was just called when the board won, 24, to get the final score, 188 * 24 = 4512.*/

}

void Dec04::SolvePart2()
{
	BingoBoard* winningBoard = nullptr;
	int lastNumber = 0;
	for (int i = 0; i < numbersDrawn.size(); i++)
	{
		int number = numbersDrawn[i];
		for (int j = 0; j < bingoBoards.size(); j++)
		{
			bingoBoards[j]->MarkNumber(number);
		}
		for (int j = 0; j < bingoBoards.size(); j++)
		{
			if (bingoBoards[j]->HasBingo())
			{
				winningBoard = bingoBoards[j];
				lastNumber = number;
				bingoBoards.erase(bingoBoards.begin() + j);
			}
		}
	}
	int unmarkedTotal = winningBoard->GetUnmarkedTotal();
	int answer = unmarkedTotal * lastNumber;
	std::cout << "Dec04 - Solution2 : " << answer << std::endl;
}