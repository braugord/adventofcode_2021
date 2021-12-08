#include <iostream>
#include "Puzzle.h"
#include <vector>

enum class State
{
	PuzzleSelection,
	PartSelection,
	Solving
};


int main()
{
	std::vector<Puzzle*> puzzles;
	puzzles.push_back(new Dec01());
	puzzles.push_back(new Dec02());
	bool running = true;
	int index = 0;
	int part = 0;
	State state = State::PuzzleSelection;

	{
		index = 2;
		part = 1;
		state = State::Solving;
	}

	while (running)
	{
		if (state == State::PuzzleSelection)
		{
			std::cout << "[0] --- Exit Program --- " << std::endl;
			for (int i = 0; i < puzzles.size(); i++)
			{
				std::cout << "[" << i+1 << "] - " << puzzles[i]->GetName() << std::endl;
			}
			
			std::cout << "Please select which puzzle to run: \n\n";
			std::cin >> index;
			if (index < 0 || index > puzzles.size())
			{
				std::cout << "Invalid puzzle selected. \n\n";
			}
			if (index == 0)
				running = false;
			else
				state = State::PartSelection;
		}
		else if (state == State::PartSelection)
		{
			std::cout << "[0] --- BACK --- \n";
			std::cout << "[1] - Part 1 \n";
			std::cout << "[2] - Part 2 \n";
			std::cout << "[3] - Both \n";
			std::cout << "Please select which part to run: \n\n";
			std::cin >> part;
			if (part < 0 || part > 3)
			{
				std::cout << "Invalid part selected. \n";
			}
			else if (part == 0)
				state = State::PuzzleSelection;
			else
				state = State::Solving;
		}
		else if(state == State::Solving)
		{
			auto puzzle = puzzles.at((size_t)(index)-1);

			puzzle->LoadInput();
			if(part == 1)
				puzzle->SolvePart1();
			else if(part == 2)
				puzzle->SolvePart2();
			else if (part == 3)
			{
				puzzle->SolvePart1();
				puzzle->SolvePart2();
			}
			std::cout << std::endl;
			state = State::PartSelection;
		}
	}
	

	return 0;
}
