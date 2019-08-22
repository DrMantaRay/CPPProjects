#include "Header.h" 
#include <string>

Edge::Edge(Sector sec_a, Sector sec_b) {
	sec_a = sec_a;
	sec_b = sec_b;
}
double SingleEdge::get_immigration_constant() const { return immigration_constant_; }
void SingleEdge::update() {
	sec_a.modify_population(sec_a.get_immigration_pull() - sec_b.get_immigration_pull);
}
