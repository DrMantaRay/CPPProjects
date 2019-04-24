#include "Header.h"
#include <iostream>
class Simulation {

};


int main() {
	SectorGraph* sectorgraph = new SectorGraph(2, 1000, 0.2);
	for (int i = 0; i < 2; i++) {
		std::cout << sectorgraph->sector_vector[i] << std::endl;
	} 
	Sector* sector = new Sector();
	std::cout << sector;
	std::getchar();
}