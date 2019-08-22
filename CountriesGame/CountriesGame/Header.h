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
		double modify_population(double population_change);

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
		int get_num_sectors();
		std::vector<std::unique_ptr<Sector>> sector_vector;
		std::vector<std::unique_ptr<Edge>> edge_vector;

	private:
		int max_sector_population_;
		int num_sectors_;
		int num_edges_;
		int max_edges_;
		double max_immigration_pull_;
};

class Edge {
	public:
		Edge(Sector sec_a, Sector sec_b);
	protected:
		Sector sec_a;
		Sector sec_b;
};

class SharedEdge : public Edge {
	public:
		double get_immigration_constant();
	private:
		double immigration_constant;
};

class SingleEdge : public Edge {
	public:
		double get_immigration_constant() const;
		void update();
	private:
		double immigration_constant_;
};

std::ostream& operator<< (std::ostream &out, const Sector* sector);

#endif