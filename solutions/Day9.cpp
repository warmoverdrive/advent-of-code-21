#ifndef DAY_9_CPP
#define DAY_9_CPP

#include <vector>
#include <string>
#include <iostream>

namespace aoc
{
	namespace Day9
	{
		std::vector<std::vector<int>> ParseInput(std::vector<std::string> &data)
		{
			std::vector<std::vector<int>> inputGrid{};
			for (auto line : data)
			{
				std::vector<int> row{};
				for (auto digit : line)
					row.emplace_back(digit - '0'); // subtract the ASCII value for '0' from the digit to quick convert char to digit

				inputGrid.emplace_back(row);
			}

			return inputGrid;
		}

		uint64_t Part1(std::vector<std::string> &data)
		{
			auto inputGrid = ParseInput(data);
			std::vector<int> lowPoints{};

			for (int y = 0; y < inputGrid.size(); y++)
				for (int x = 0; x < inputGrid[y].size(); x++)
				{
					bool isGreater = false;
					for (int deltaY = -1; deltaY <= 1; deltaY++)
					{
						for (int deltaX = -1; deltaX <= 1; deltaX++)
						{
							if (y + deltaY < 0 || y + deltaY >= inputGrid.size())
								continue;
							if (x + deltaX < 0 || x + deltaX >= inputGrid[y].size())
								continue;
							if (deltaX == 0 && deltaY == 0)
								continue;
							if (inputGrid[y][x] >= inputGrid[y + deltaY][x + deltaX])
							{
								isGreater = true;
								break;
							}
						}
						if (isGreater == true)
							break;
					}
					if (isGreater == false)
						lowPoints.emplace_back(inputGrid[y][x]);
				}
			uint64_t sum{};
			for (auto point : lowPoints)
				sum += point + 1;
			return sum;
		}

		uint64_t Part2(std::vector<std::string> &data)
		{
			return 0;
		}
	}
}

#endif