#include "Header.h"
#include <random>
#include <cmath>

// helper function to convert yearly interest to interest over periods (i.e. days)
double yearly_to_daily_interest(double rate, double period) {
	return 1 - pow(1.0 + rate / period, period);
}

Sector::Sector(double population, int max_population, double population_growth_yearly, 
	double immigration_pull) {
	population_ = population;
	max_population_ = max_population;
	set_population_growth_yearly(population_growth_yearly);
	immigration_pull_ = immigration_pull;
}

double Sector::get_population() const {
	return population_;
}

double Sector::modify_population(double population_change) {
	population_ += population_change;
}

double Sector::get_population_growth_daily() const {
	return population_growth_daily_;
}

double Sector::get_population_growth_yearly() const {
	return population_growth_yearly_;
}

void Sector::set_population_growth_yearly(double population_growth_yearly) {
	population_growth_yearly_ = population_growth_yearly;
	population_growth_daily_ = yearly_to_daily_interest(population_growth_yearly_, 365);
}

int Sector::get_max_population() const {
	return max_population_;
}

double Sector::get_immigration_pull() const {
	return immigration_pull_;
}

std::ostream& operator<<(std::ostream& out, const Sector* sector) {
	out << "population: " << sector->get_population() << "; ";
	out << "max population: " << sector->get_max_population() << "; ";
	out << "yearly population growth: " << sector->get_population_growth_yearly() << "; ";
	out << "immigration pull : " << sector->get_immigration_pull();
	return out;
}
