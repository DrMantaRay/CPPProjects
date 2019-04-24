#include "Header.h"
#include <random>
#include <iostream>
#include <vector>

SectorGraph::SectorGraph(int num_sectors, int max_sector_population, double max_immigration_pull) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> random_population(0, max_sector_population - 1);
	std::uniform_real_distribution<double> random_immigration_pull((-1.0 * max_immigration_pull), max_immigration_pull);
	std::uniform_real_distribution<double> random_percentage(0, 1);
	std::uniform_real_distribution<double> random_percentage_yearly(-1, 1);

	int tmp_max_population;
	Sector* tmp_sector_ptr;
	for (int i = 0; i < num_sectors; i++) {
		tmp_max_population = random_population(mt);
		tmp_sector_ptr = new Sector(tmp_max_population * random_percentage(mt), tmp_max_population, 
			random_percentage_yearly(mt), random_immigration_pull(mt));
		sector_vector.push_back(tmp_sector_ptr);
	}
}
