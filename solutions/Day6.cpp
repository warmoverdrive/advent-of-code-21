#ifndef DAY_6_CPP
#define DAY_6_CPP

#include <vector>
#include <array>
#include <string>
#include <algorithm>

const int newFishTimer = 8;
const int fishRespawnTimer = 6;
const int daysToCheckA = 80;
const int daysToCheckB = 256;

namespace aoc
{
	namespace Day6
	{
		uint64_t Part1(std::vector<int> &data)
		{
			for (auto day = 0; day < daysToCheckA; day++)
			{
				for (int fish{}; fish < data.size(); fish++)
				{
					if (data[fish] == 0)
					{
						data[fish] = fishRespawnTimer;
						data.emplace_back(newFishTimer + 1);
					}
					else
						data[fish]--;
				}
			}

			return data.size();
		}

		uint64_t Part2(std::vector<int> &data)
		{
			std::array<uint64_t, 9> timers{0};
			for (auto fish : data)
				timers[fish]++;

			for (auto day = 0; day < daysToCheckB; day++)
			{
				uint64_t spawningFish = timers[0];
				std::rotate(timers.begin(), timers.begin() + 1, timers.end());
				timers[6] += spawningFish;
			}

			auto sum = [&]()
			{
				uint64_t sum = 0;
				for (auto fish : timers)
					sum += fish;
				return sum;
			};

			return sum();
		}
	}
}

#endif