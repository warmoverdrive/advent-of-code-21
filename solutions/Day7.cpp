#ifndef DAY_7_CPP
#define DAY_7_CPP

#include <vector>
#include <algorithm>

namespace aoc
{
	namespace Day7
	{
		uint64_t Part1(std::vector<int> &data)
		{
			std::sort(data.begin(), data.end());

			int lastCrab{INT_MIN};	 //store last crab checked to avoid running on duplicates. init to INT_MIN to avoid missing the first crab
			int lowestFuel{INT_MAX}; // store lowest fuel value, initialized to highest possible value

			for (auto crab : data)
			{
				if (crab == lastCrab) // skip repeated horizontal crab positions
					continue;

				int fuelUsed = {};

				for (auto testCrab : data)
				{
					if (testCrab == crab) // ignore testing on itself and duplicates
						continue;

					fuelUsed += testCrab < crab ? crab - testCrab : testCrab - crab; // check fuel used to equalize pos
				}

				if (fuelUsed <= lowestFuel)
					lowestFuel = fuelUsed;
				lastCrab = crab;
			}

			return lowestFuel;
		}

		uint64_t CalcFuelCost(const uint64_t &crab1, const uint64_t &crab2)
		{
			uint64_t cost = crab1 - crab2;
			uint64_t costCounter = cost;

			while (costCounter > 0)
			{
				cost += --costCounter;
			}
			return cost;
		}

		uint64_t Part2(std::vector<int> &data)
		{
			std::sort(data.begin(), data.end());

			uint64_t lastCrab{LLONG_MAX};	//store last crab checked to avoid running on duplicates. init to LLONG_MAX to avoid missing first crab
			uint64_t lowestFuel{LLONG_MAX}; // store lowest fuel value, initialized to highest possible value

			for (uint64_t i = 0; i < data.back(); i++)
			{
				uint64_t fuelCost{};
				for (auto crab : data)
				{
					if (crab == i)
						continue;

					fuelCost += crab < i ? CalcFuelCost(i, crab) : CalcFuelCost(crab, i);
				}
				if (fuelCost < lowestFuel)
					lowestFuel = fuelCost;
			}

			return lowestFuel;
		}
	}
}

#endif