#ifndef DAY_8_CPP
#define DAY_8_CPP

#include <vector>
#include <utility>
#include <array>
#include <string>
#include <sstream>
#include <numeric>
#include <unordered_map>
#include <bitset>

namespace aoc
{
	namespace Day8
	{
		const int inputStrings = 10;
		const int outputStrings = 4;

		const std::unordered_map<std::bitset<7>, int> numberDefinitions = {
			{std::bitset<7>("1110111"), 0},
			{std::bitset<7>("0010010"), 1},
			{std::bitset<7>("1011101"), 2},
			{std::bitset<7>("1011011"), 3},
			{std::bitset<7>("0111010"), 4},
			{std::bitset<7>("1101011"), 5},
			{std::bitset<7>("1101111"), 6},
			{std::bitset<7>("1010010"), 7},
			{std::bitset<7>("1111111"), 8},
			{std::bitset<7>("1111011"), 9}};

		std::vector<std::pair<std::array<std::string, 10>, std::array<std::string, 4>>> ParseInput(std::vector<std::string> &data)
		{
			std::vector<std::pair<std::array<std::string, 10>, std::array<std::string, 4>>> parsedInput{};
			std::stringstream sstream{};
			std::string dump{};

			for (auto line : data)
			{
				std::pair<std::array<std::string, 10>, std::array<std::string, 4>> newLine{};
				sstream << line;

				for (int i = 0; i < inputStrings; i++)
					std::getline(sstream, newLine.first[i], ' ');

				std::getline(sstream, dump, ' '); // dump the '|'

				for (int i = 0; i < outputStrings; i++)
					std::getline(sstream, newLine.second[i], ' ');

				sstream.clear();

				parsedInput.push_back(newLine);
			}

			return parsedInput;
		}

		void PrintParsedInput(std::vector<std::pair<std::array<std::string, 10>, std::array<std::string, 4>>> &parsedInput)
		{
			for (auto line : parsedInput)
			{
				std::cout << "< ";
				for (auto e : line.first)
					std::cout << e << ' ';
				std::cout << "> :: < ";
				for (auto e : line.second)
					std::cout << e << ' ';
				std::cout << ">\n";
			}
		}

		uint64_t Part1(std::vector<std::string> &data)
		{
			// segment key:: 1 = 2seg || 4 = 4seg || 7 = 3seg || 8 = 7seg
			uint64_t tally{};

			// organize into a vector of tuples, of arrays of strings (first (10): input, second (4): output)
			// seperate function to parse input, will probably be used in part 2
			auto parsedInput = ParseInput(data);

			// for each tuple, check each element in second array for size of 2, 4, 3, 7 and add to tally result
			for (auto line : parsedInput)
				for (auto e : line.second)
					if (e.length() == 2 || e.length() == 3 || e.length() == 4 || e.length() == 7)
						tally++;

			// return tally
			return tally;
		}

		std::unordered_map<char, std::bitset<7>> DeduceKey(
			std::vector<std::pair<std::array<std::string, 10>, std::array<std::string, 4>>> &parsedInput)
		{
			std::unordered_map<char, std::bitset<7>> key{};

			// idk man this is complicated as hell...
			// but i think these are the steps and im not sure how to
			// code it:
			// 		deduce 1 and 7 to get a
			// 		determine whats missing from 8 and 4 to get e (9), c (6), d (0)
			// 		determine whats missing from 8 and 1 to get
			// 		compare 6 to 1 to get f
			// 		check for acdf in length key to get g(3)
			// 		implicitly get 2
			// 		remaining string is 5, determining b

			// I'd create bitset<7> for each char determining its place and return that as an unordered map

			return key;
		}

		uint64_t Part2(std::vector<std::string> &data)
		{
			// remove this when Deduce Key is implemented
			return 0;

			// not fully implemented
			std::vector<int> outputs{};
			auto parsedInput = ParseInput(data);
			auto key = DeduceKey(parsedInput);

			// get key from Deduce Key outlined above
			// for each parsedInput
			for (auto input : parsedInput)
			{
				// for each string in second
				for (auto s : input.second)
				{
					// create a bitset<7> and temp string
					std::bitset<7> tempBitset{};
					std::string tempString{};
					// for each char in second
					for (auto c : s)
						// bitwise OR onto the bitset for this string
						tempBitset | key.at(c);
					// pull the int from the numberDefinitions map using the bitset Key
					// and push back int onto temp string
					tempString.push_back(numberDefinitions.at(tempBitset));
					// convert temp string to int and push back into outputs vector
					outputs.emplace_back(std::stoi(tempString));
				}
			}
			// accumulate all values in outputs vector and return
			return std::accumulate(outputs.begin(), outputs.end(), 0);
		}
	}
}

#endif