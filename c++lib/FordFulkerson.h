#include <vector>
#include <limits>
#include <queue>
#include "FlowNetwork.h"

class FordFulkerson{
	private:
		std::vector<bool> marked;
		std::vector<FlowEdge*> edgeTo;
		double value;
		bool hasAugmentingPath(FlowNetwork& G, int s, int t);
	public:
		FordFulkerson(FlowNetwork& G, int s, int t);
		double getValue();
		bool inCut(int vertex);
};
