#include <string>
#include <iostream>
#include <sstream>

class FlowEdge{
	private:
		int v,w;
		double capacity;
		double flow;
	public:
		FlowEdge(int v, int w, double capacity);
		int from();
		int to();
		int other(int vertex);
		double getCapacity();
		double getFlow();
		double residualCapacityTo(int vertex);
		void addResidualFlowTo(int vertex, double delta);
		std::string toString();
};
