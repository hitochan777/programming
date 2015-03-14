#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include "FlowEdge.h"

class FlowNetwork{
	private:
		int V;
		std::vector<std::vector<FlowEdge> > adj;

	public:
		FlowNetwork(int V);
		FlowNetwork(int V, int E);
		void addEdge(FlowEdge& e);
		std::vector<FlowEdge>* getAdj(int vertex);
		int getV();
		std::string toString();
 };
