#include "Header.h" 
#include <string>

class Edge {
	public:
		Edge(Sector sec_a, Sector sec_b);
	private:
		std::string type;
};

class SharedEdge: public Edge {
	private:
	public:
};

class SingleEdge : public Edge {
	private:
	public:
};
