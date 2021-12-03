#ifndef DAY_2_CPP
#define DAY_2_CPP

#include <vector>
#include <iostream>

const std::string forward{"forward"}, down{"down"}, up{"up"};

namespace aoc
{
	namespace Day2
	{
		uint64_t Part1(std::vector<std::string> data)
		{
			uint64_t horizontalPos{}, depth{};

			for (auto &line : data)
			{
				if (line[0] == 'f') // forward
					horizontalPos += std::stoi(line.substr(forward.length()));
				else if (line[0] == 'd') // down
					depth += std::stoi(line.substr(down.length()));
				else if (line[0] == 'u') // up
					depth -= std::stoi(line.substr(up.length()));
				else
				{
					std::cout << "Day2.A - ERROR - Data invalid\n\n";
					return 0;
				}
			}

			return horizontalPos * depth;
		}

		uint64_t Part2(std::vector<std::string> data)
		{
			uint64_t horizontalPos{}, depth{}, aim{};

			for (auto &line : data)
			{
				if (line[0] == 'f')
				{
					auto delta = std::stoi(line.substr(forward.length()));
					horizontalPos += delta;
					depth += delta * aim;
				}
				else if (line[0] == 'd') // down
					aim += std::stoi(line.substr(down.length()));
				else if (line[0] == 'u') // up
					aim -= std::stoi(line.substr(up.length()));
				else
				{
					std::cout << "Day2.B - ERROR - Data invalid\n\n";
					return 0;
				}
			}

			return horizontalPos * depth;
		}
	}
}

#endif