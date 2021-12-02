#ifndef INPUT_H4
#define INPUT_H4

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

namespace Input
{
	template <typename T>
	std::vector<T> GetNumberData(const std::string &path, char delim)
	{
		std::vector<T> data;
		try
		{
			std::ifstream infile(path);
			std::string line;
			while (std::getline(infile, line, delim))
			{
				T element;
				std::stringstream input(line);
				while (input >> element)
					data.push_back(element);
			}
		}
		catch (...)
		{
			std::cout << "An error occured!\n";
		}
		return data;
	}

	template <typename T>
	std::vector<T> GetData(const std::string &path, char delim)
	{
		std::vector<T> data;
		try
		{
			std::ifstream infile(path);
			std::string line;
			while (std::getline(infile, line, delim))
			{
				// The commented out code below effectively negates the delim param
				// Pushing back the line to Data after getline() ensures our delim
				// is used in the final result.
				data.push_back(line);
				// T element;
				// std::stringstream input(line);
				// while (input >> element)
				// 	data.push_back(element);
			}
		}
		catch (...)
		{
			std::cout << "An error occured!\n";
		}
		return data;
	}

	std::vector<std::string> GetEmptyNewLineData(const std::string &path)
	{
		std::ifstream infile(path);
		std::string temp;
		std::vector<std::string> data;

		for (std::string line; std::getline(infile, line);)
		{
			if (line.empty())
			{
				data.push_back(temp);
				temp.clear();
			}
			if (infile.eof())
			{
				temp += line;
				data.push_back(temp);
			}
			temp += line;
			temp += " ";
		}
		return data;
	}
}; // namespace Input

#endif