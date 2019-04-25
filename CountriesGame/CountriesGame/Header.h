#ifndef HEADER
#define HEADER
#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <set>

class Sector {
	public:
		Sector(double population, int max_population, double population_growth_yearly, double immigration_pull);
		Sector() : Sector(0, 0, 0, 0) {};
		double get_population() const;
		double get_population_growth_daily() const;
		double get_population_growth_yearly() const;
		void set_population_growth_yearly(double yearly_interest);
		int get_max_population() const;
		double get_immigration_pull() const;

	private:
		std::string name;
		double population_;
		double population_growth_yearly_;
		double population_growth_daily_;
		int max_population_;
		double immigration_pull_;

};

class SectorGraph {
	public:
		SectorGraph(int num_sectors, int max_sector_population, int max_edges, double max_immigration_pull);
		SectorGraph() : SectorGraph(10, 100, 3, 0.2) {};
		void generate_random_graph();
		std::vector<std::unique_ptr<Sector>> sector_vector;
		std::vector<std::set<int>> edge_vector;

	private:
		int max_sector_population_;
		int num_sectors_;
		int max_edges_;
		double max_immigration_pull_;
		


};

std::ostream& operator<< (std::ostream &out, const Sector* sector);

#endif