// Input Header and structure borrowed from b0guslaw

#include <chrono>
#include <tuple>

#include "utils/Input-V4.h"
#include "solutions/Day1.cpp"

const std::string dir{"input/"};

auto print = [](const std::string &name, const uint64_t part1, double elapsed1, const uint64_t part2, double elapsed2)
{
	std::cout << "\t~~ " << name << " ~~"
			  << "\nPart 1: " << part1 << " || elapsed time: " << elapsed1 << "ms"
			  << "\nPart 2: " << part2 << " || elapsed time: " << elapsed2 << "ms\n\n";
};

template <typename F, typename I>
std::tuple<uint64_t, double> SolutionRunner(F func, std::vector<I> input)
{
	auto start = std::chrono::high_resolution_clock::now();
	uint64_t result = func(input);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	return std::make_tuple(result, elapsed);
}

void Day1(std::vector<int> data)
{
	auto [result1, elapsed1] = SolutionRunner(aoc::Day1::Part1, data);
	auto [result2, elapsed2] = SolutionRunner(aoc::Day1::Part2, data);

	print(__func__, result1, elapsed1, result2, elapsed2);
}

int main(int argc, char **argv)
{
	Day1(Input::GetNumberData<int>(dir + "01Input.txt", '\n'));
}