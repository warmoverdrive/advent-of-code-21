#ifndef DAY_8_CPP
#define DAY_8_CPP

#include <vector>
#include <tuple>
#include <array>
#include <string>

namespace aoc
{
	namespace Day8
	{
		uint64_t Part1(std::vector<std::string> &data)
		{
			// segment key:: 1 = 2seg || 4 = 4seg || 7 = 3seg || 8 = 7seg

			// organize into a vector of tuples, of arrays of strings (first (10): input, second (5): output)
			// seperate function to parse input, will probably be used in part 2

			// for each tuple, check each element in second array for size of 2, 4, 3, 7 and add to tally result

			// return tally

			return 0;
		}

		uint64_t Part2(std::vector<std::string> &data)
		{

			return 0;
		}
	}
}

#endif