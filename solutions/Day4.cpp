#ifndef DAY_4_CPP
#define DAY_4_CPP

#include <vector>
#include <string>
#include <queue>
#include <sstream>

namespace aoc
{
	namespace Day4
	{
		struct Board
		{
			std::vector<std::vector<std::pair<int, bool>>> board;
			Board()
			{
				board =
					std::vector<std::vector<std::pair<int, bool>>>(5, std::vector<std::pair<int, bool>>(5, std::make_pair(0, false)));
			}
		};

		void ParseData(std::vector<std::string> &data, std::vector<Board> &boards, std::queue<int> &numbers)
		{
			std::stringstream sstream;
			std::string temp{};

			sstream << data[0];
			std::cout << data[0] << '\n';
			do
			{
				std::getline(sstream, temp, ',');
				if (temp.empty())
					break;
				numbers.push(std::stoi(temp));
				sstream.clear();
			} while (!sstream.eof());

			for (auto ind = 1, row = 0, board = -1; ind < data.size(); ind++)
			{
				if (data[ind].size() == 0)
				{
					std::cout << "EMPTY\n";
					row = 0;
					boards.emplace_back(Board());
					board++;
				}
				else
				{
					for (auto i = 0; i < 5; i++)
						boards[board].board[row][i].first = std::stoi(data[ind].substr(i * 3, 3));
					row++;
				}
			}
		}

		uint64_t Part1(std::vector<std::string> &data)
		{
			// I'm at a point where I'm able to sort and process the input into a usable state
			// but it's getting late and I'm too tired to deal with finishing the problem rn.

			std::vector<Board> boards{};
			std::queue<int> numbers{};

			ParseData(data, boards, numbers);

			while (numbers.size() > 0)
			{
				std::cout << numbers.front() << " ";
				numbers.pop();
			}
			std::cout << "\n\n";
			for (auto board : boards)
			{
				for (auto row : board.board)
				{
					for (auto col : row)
						std::cout << col.first << " ";
					std::cout << '\n';
				}
				std::cout << '\n';
			}

			return 0;
		}

		uint64_t Part2(std::vector<std::string> &data)
		{
			return 0;
		}
	}
}

#endif