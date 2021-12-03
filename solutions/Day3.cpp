#ifndef DAY_3_CPP
#define DAY_3_CPP

#include <vector>
#include <iostream>
#include <string>

namespace aoc
{
	namespace Day3
	{
		void CullData(std::vector<std::string> &data, int iterator, bool isOxy)
		{
			auto tempData(data);										 // temp data copy to reference from
			int tally{};												 // tally of 1's to test against
			char key{};													 // the key we're culling against
			int size = tempData.size() / 2 + (tempData.size() % 2 != 0); // the size threshold rounded to the ceiling

			for (auto line : tempData)
				if (line[iterator] == '1')
					tally++;

			if (tally > size)
				key = isOxy ? '1' : '0';
			else if (tally < size)
				key = isOxy ? '0' : '1';
			else if (tally == size)
				key = isOxy ? '1' : '0';

			data.clear();
			for (auto line : tempData)
				if (line[iterator] == key)
					data.push_back(line);
		}

		uint64_t Part1(std::vector<std::string> &data)
		{
			std::string strResultGamma{};				 // most common bits
			std::string strResultEpsilon{};				 // least common bits
			std::vector<int> tally(data.at(0).length()); // init vector of ints the size of input strings to tally 1's, to be compared after processing

			for (auto &line : data)
			{
				for (int c{}; c < line.length(); c++)
				{
					if (line[c] == '1')
						tally[c]++;
				}
			}

			for (auto c : tally)
			{
				if (c > data.size() / 2)
				{
					strResultGamma.push_back('1');
					strResultEpsilon.push_back('0');
				}
				else
				{
					strResultGamma.push_back('0');
					strResultEpsilon.push_back('1');
				}
			}

			return std::stoi(strResultGamma, nullptr, 2) * std::stoi(strResultEpsilon, nullptr, 2);
		}

		uint64_t Part2(std::vector<std::string> &data)
		{
			auto oxygenData(data);
			auto scrubberData(data);

			int iterator = 0;

			while (iterator < data[0].length())
			{
				if (oxygenData.size() == 1 && scrubberData.size() == 1)
					break;
				if (oxygenData.size() > 1)
					aoc::Day3::CullData(oxygenData, iterator, true);
				if (scrubberData.size() > 1)
					aoc::Day3::CullData(scrubberData, iterator, false);

				iterator++;
			}

			return std::stoi(oxygenData[0], nullptr, 2) * std::stoi(scrubberData[0], nullptr, 2);
		}
	}
}

#endif