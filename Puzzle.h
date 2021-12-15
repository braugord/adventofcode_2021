#pragma once

#include <string>

class Puzzle
{
protected:
	bool inputLoaded;
	std::string name;
	virtual void LoadInputInternal() = 0;
public:
	Puzzle() { inputLoaded = false; }
	void LoadInput()
	{
		if (inputLoaded) return;
		LoadInputInternal();
		inputLoaded = true;
	}
	std::string GetName() { return name; };
	virtual void SolvePart1() = 0;
	virtual void SolvePart2() = 0;
};

class Dec01 : public Puzzle
{
protected:
	void LoadInputInternal() override;
public:
	Dec01() { name = "--- Day 1: Sonar Sweep ---"; };
	void SolvePart1() override;
	void SolvePart2() override;
};

class Dec02 : public Puzzle
{
protected:
	void LoadInputInternal() override;
public:
	Dec02() { name = "--- Day 2: Dive! ---"; };
	void SolvePart1() override;
	void SolvePart2() override;
};

class Dec03 : public Puzzle
{
protected:
	void LoadInputInternal() override;
public:
	Dec03() { name = "--- Day 3: Binary Diagnostic ---"; };
	void SolvePart1() override;
	void SolvePart2() override;
};

class Dec04 : public Puzzle
{
protected:
	void LoadInputInternal() override;
public:
	Dec04() { name = "--- Day 4: Giant Squid ---"; };
	void SolvePart1() override;
	void SolvePart2() override;
};

class Dec05 : public Puzzle
{
protected:
	void LoadInputInternal() override;
public:
	Dec05() { name = "--- Day 5: Hydrothermal Venture ---"; };
	void SolvePart1() override;
	void SolvePart2() override;
};