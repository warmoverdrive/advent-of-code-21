// Input Header and structure borrowed from b0guslaw

#include <chrono>

#include "utils/Input-V4.h"
#include "solutions/Day1.cpp"

const std::string dir{"input/"};

auto print = [](const std::string &name, const std::string &part1, const std::string &part2)
{
	std::cout << "\t~~ " << name << " ~~"
			  << "\nPart 1: " << part1 << "\nPart 2: " << part2 << "\n\n";
};

void Day1(std::vector<int> data)
{
	int part1, part2;
	{
		auto start = std::chrono::high_resolution_clock::now();
		part1 = aoc::Day1::Part1(data);
		auto end = std::chrono::high_resolution_clock::now();
		auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << __func__ << ".A Elapsed Time: " << t << "ms\n";
	}
	{
		auto start = std::chrono::high_resolution_clock::now();
		part2 = aoc::Day1::Part2(data);
		auto end = std::chrono::high_resolution_clock::now();
		auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << __func__ << ".B Elapsed Time: " << t << "ms\n";
	}
	print(__func__, std::to_string(part1), std::to_string(part2));
}

int main(int argc, char **argv)
{
	Day1(Input::GetNumberData<int>(dir + "01Input.txt", '\n'));
}