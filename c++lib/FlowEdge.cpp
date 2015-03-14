#include "FlowEdge.h"
	FlowEdge::FlowEdge(int v, int w, double capacity)
:v(v),w(w),capacity(capacity)
{}
int FlowEdge::from(){
	return v;
}
int FlowEdge::to(){
	return w;
}
int FlowEdge::other(int vertex){
	if(vertex == v){
		return w;	
	}
	else{
		return v;	
	}	
	return -1;
}
double FlowEdge::getCapacity(){
	return capacity;
}
double FlowEdge::getFlow(){
	return flow;
}
double FlowEdge::residualCapacityTo(int vertex){
	if(vertex == v){
		return flow;
	}
	else if(vertex == w){
		return capacity - flow;	
	}
	//TODO:throw exception
	return 0.0;
}
void FlowEdge::addResidualFlowTo(int vertex, double delta){
	if(vertex == v){
		flow -= delta;
	}
	else if(vertex == w){
		flow += delta;
	}
	//TODO:throw exception

}
std::string FlowEdge::toString(){
	std::stringstream ss;
	ss<<v<<"->"<<w<<" "<<flow<<"/"<<capacity;
	return ss.str();
}
