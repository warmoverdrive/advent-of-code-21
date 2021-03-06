// Input Header and structure borrowed from b0guslaw

#include <chrono>
#include <tuple>

#include "utils/Input-V4.h"
#include "solutions/Day1.cpp"
#include "solutions/Day2.cpp"
#include "solutions/Day3.cpp"
#include "solutions/Day4.cpp"
#include "solutions/Day5.cpp"
#include "solutions/Day6.cpp"
#include "solutions/Day7.cpp"
#include "solutions/Day8.cpp"
#include "solutions/Day9.cpp"

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
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	return std::make_tuple(result, elapsed);
}

void Day1(std::vector<int> data)
{
	auto [result1, elapsed1] = SolutionRunner(aoc::Day1::Part1, data);
	auto [result2, elapsed2] = SolutionRunner(aoc::Day1::Part2, data);

	print(__func__, result1, elapsed1, result2, elapsed2);
}
void Day2(std::vector<std::string> data)
{
	auto [result1, elapsed1] = SolutionRunner(aoc::Day2::Part1, data);
	auto [result2, elapsed2] = SolutionRunner(aoc::Day2::Part2, data);

	print(__func__, result1, elapsed1, result2, elapsed2);
}
void Day3(std::vector<std::string> data)
{
	auto [result1, elapsed1] = SolutionRunner(aoc::Day3::Part1, data);
	auto [result2, elapsed2] = SolutionRunner(aoc::Day3::Part2, data);

	print(__func__, result1, elapsed1, result2, elapsed2);
}
void Day4(std::vector<std::string> data)
{
	auto [result1, elapsed1] = SolutionRunner(aoc::Day4::Part1, data);
	auto [result2, elapsed2] = SolutionRunner(aoc::Day4::Part2, data);

	print(__func__, result1, elapsed1, result2, elapsed2);
}
void Day5(std::vector<std::string> data)
{
	auto [result1, elapsed1] = SolutionRunner(aoc::Day5::Part1, data);
	auto [result2, elapsed2] = SolutionRunner(aoc::Day5::Part2, data);

	print(__func__, result1, elapsed1, result2, elapsed2);
}
void Day6(std::vector<int> data)
{
	auto [result1, elapsed1] = SolutionRunner(aoc::Day6::Part1, data);
	auto [result2, elapsed2] = SolutionRunner(aoc::Day6::Part2, data);

	print(__func__, result1, elapsed1, result2, elapsed2);
}
void Day7(std::vector<int> data)
{
	auto [result1, elapsed1] = SolutionRunner(aoc::Day7::Part1, data);
	auto [result2, elapsed2] = SolutionRunner(aoc::Day7::Part2, data);

	print(__func__, result1, elapsed1, result2, elapsed2);
}
void Day8(std::vector<std::string> data)
{
	auto [result1, elapsed1] = SolutionRunner(aoc::Day8::Part1, data);
	auto [result2, elapsed2] = SolutionRunner(aoc::Day8::Part2, data);

	print(__func__, result1, elapsed1, result2, elapsed2);
}
void Day9(std::vector<std::string> data)
{
	auto [result1, elapsed1] = SolutionRunner(aoc::Day9::Part1, data);
	auto [result2, elapsed2] = SolutionRunner(aoc::Day9::Part2, data);

	print(__func__, result1, elapsed1, result2, elapsed2);
}

int main(int argc, char **argv)
{
	Day1(Input::GetNumberData<int>(dir + "01Input.txt", '\n'));
	Day2(Input::GetData<std::string>(dir + "02Input.txt", '\n'));
	Day3(Input::GetData<std::string>(dir + "03Input.txt", '\n'));
	Day4(Input::GetData<std::string>(dir + "04Test.txt", '\n'));
	Day5(Input::GetData<std::string>(dir + "05Input.txt", '\n'));
	Day6(Input::GetNumberData<int>(dir + "06Input.txt", ','));
	Day7(Input::GetNumberData<int>(dir + "07Test.txt", ',')); // keep as test to speed up execution
	Day8(Input::GetData<std::string>(dir + "08Input.txt", '\n'));
	Day9(Input::GetData<std::string>(dir + "09Input.txt", '\n'));
}