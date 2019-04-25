#include "Header.h"
#include <random>
#include <iostream>
#include <vector>

SectorGraph::SectorGraph(int num_sectors, int max_sector_population, int max_edges, double max_immigration_pull) {
	num_sectors_ = num_sectors;
	max_sector_population_ = max_sector_population;
	max_immigration_pull_ = max_immigration_pull;
	max_edges_ = max_edges;
}

void SectorGraph::generate_random_graph() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> random_population(0, max_sector_population_ - 1);
	std::uniform_real_distribution<double> random_immigration_pull((-1.0 * max_immigration_pull_), max_immigration_pull_);
	std::uniform_real_distribution<double> random_percentage(0, 1);
	std::uniform_real_distribution<double> random_percentage_yearly(-1, 1);

	int tmp_max_population;
	for (int i = 0; i < num_sectors_; i++) {
		tmp_max_population = random_population(mt);
		sector_vector.push_back(std::make_unique<Sector>(tmp_max_population * random_percentage(mt), tmp_max_population, 
			random_percentage_yearly(mt), random_immigration_pull(mt)));
	}
}
