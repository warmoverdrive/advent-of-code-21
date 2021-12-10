#ifndef DAY_1_CPP
#define DAY_1_CPP

#include <vector>
#include <iostream>

namespace aoc
{
	namespace Day1
	{
		uint64_t Part1(std::vector<int> &data)
		{
			int previous{};
			int current{};
			int increasedMeasurements{};

			for (auto &depth : data)
			{
				current = depth;
				if (previous == 0 || previous >= current)
				{
					previous = current;
					continue;
				}
				else
				{
					previous = current;
					increasedMeasurements++;
				}
			}

			return increasedMeasurements;
		}

		uint64_t Part2(std::vector<int> &data)
		{
			return 0;
		}
	}
}

#endif