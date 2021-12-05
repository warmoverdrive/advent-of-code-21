#ifndef DAY_5_CPP
#define DAY_5_CPP

#include <vector>
#include <string>

namespace aoc
{
	namespace Day5
	{
		struct Line
		{
			int x1, x2, y1, y2{};
			Line(int x1, int x2, int y1, int y2) : x1(x1), x2(x2), y1(y1), y2(y2){};
		};

		void ParseLineData(std::vector<std::string> &data, std::vector<Line> &lines)
		{
			std::stringstream sstream;
			for (auto line : data)
			{
				int x1, x2, y1, y2{};
				std::string temp{};
				sstream << line;

				std::getline(sstream, temp, ',');
				x1 = std::stoi(temp);
				std::getline(sstream, temp, ' ');
				y1 = std::stoi(temp);
				std::getline(sstream, temp, ' '); // extract and discard the '->'
				std::getline(sstream, temp, ',');
				x2 = std::stoi(temp);
				std::getline(sstream, temp, '\n');
				y2 = std::stoi(temp);
				sstream.clear();
				Line newLine(x1, x2, y1, y2);
				lines.push_back(newLine);
			}
		}

		uint64_t Part1(std::vector<std::string> &data)
		{
			std::vector<Line> lines{};
			ParseLineData(data, lines);

			std::vector<std::vector<int>> graph(1000, std::vector<int>(1000, 0)); // create a 1000:1000 diagram

			for (auto line : lines)
			{
				if (line.x1 == line.x2)
				{
					int y1 = line.y1 < line.y2 ? line.y1 : line.y2;
					int y2 = line.y2 < line.y1 ? line.y1 : line.y2;
					for (auto y = y1; y <= y2; y++)
					{
						graph[y][line.x1]++;
					}
				}
				else if (line.y1 == line.y2)
				{
					int x1 = line.x1 < line.x2 ? line.x1 : line.x2;
					int x2 = line.x2 < line.x1 ? line.x1 : line.x2;
					for (auto x = x1; x <= x2; x++)
					{
						graph[line.y1][x]++;
					}
				}
			}

			int tally{};

			for (auto row : graph)
				for (auto space : row)
					if (space > 1)
						tally++;

			return tally;
		}

		uint64_t Part2(std::vector<std::string> &data)
		{
			std::vector<Line> lines{};
			ParseLineData(data, lines);

			std::vector<std::vector<int>> graph(10, std::vector<int>(10, 0)); // create a 1000:1000 diagram

			for (auto line : lines)
			{
				if (line.x1 == line.x2)
				{
					int y1 = line.y1 < line.y2 ? line.y1 : line.y2;
					int y2 = line.y2 < line.y1 ? line.y1 : line.y2;
					for (auto y = y1; y <= y2; y++)
					{
						graph[y][line.x1]++;
					}
				}
				else if (line.y1 == line.y2)
				{
					int x1 = line.x1 < line.x2 ? line.x1 : line.x2;
					int x2 = line.x2 < line.x1 ? line.x1 : line.x2;
					for (auto x = x1; x <= x2; x++)
					{
						graph[line.y1][x]++;
					}
				}
				else
				{
					bool xDeltaPositive = line.x1 < line.x2;
					bool yDetlaPositive = line.y1 < line.y2;

					for (auto x = line.x1, y = line.y1;
						 xDeltaPositive ? x <= line.x2 : x >= line.x2;
						 xDeltaPositive ? x++ : x--, yDetlaPositive ? y++ : y--)
					{
						graph[x][y]++;
					}
				}
			}

			int tally{};

			for (auto row : graph)
			{
				for (auto space : row)
				{
					if (space > 1)
						tally++;
					if (space == 0)
						std::cout << ". ";
					else
						std::cout << space << " ";
				}
				std::cout << '\n';
			}

			return tally;
		}
	}
}

#endif