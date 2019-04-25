#include "Header.h"
#include <iostream>
class Simulation {

};


int main() {
	SectorGraph sectorgraph(2, 1000, 1, 0.2);
	sectorgraph.generate_random_graph();
	for (int i = 0; i < 2; i++) {
		std::cout << sectorgraph.sector_vector[i] << std::endl;
	} 
	std::getchar();

}
