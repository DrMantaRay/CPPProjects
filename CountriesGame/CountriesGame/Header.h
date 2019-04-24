#ifndef HEADER
#define HEADER
#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

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
		double population_;
		double population_growth_yearly_;
		double population_growth_daily_;
		int max_population_;
		double immigration_pull_;

};

class SectorGraph {
	public:
		SectorGraph(int num_sectors, int max_sector_population, double max_immigration_pull);
		std::vector<Sector*> sector_vector;
	private:
		int max_sector_population;


};
std::ostream& operator<< (std::ostream &out, const Sector* sector);

#endif