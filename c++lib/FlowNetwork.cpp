#include "FlowNetwork.h"

FlowNetwork::FlowNetwork(int V){
	this->V = V;
	adj.resize(V);	
}

FlowNetwork::FlowNetwork(int V, int E):FlowNetwork(V) {
	srand(time(NULL));
	for (int i = 0; i < E; i++) {
		int v = rand()%V;
		int w = rand()%V;
		double capacity = (((double)rand())/RAND_MAX)*100.0;
		addEdge(*(new FlowEdge(v, w, capacity)));
	}
}

void FlowNetwork::addEdge(FlowEdge& e){
	int v = e.from();
	int w = e.to();	
	adj[v].push_back(e);
	adj[w].push_back(e);
}

std::vector<FlowEdge>* FlowNetwork::getAdj(int vertex){
	return &(adj[vertex]);
}

int FlowNetwork::getV(){
	return V;
}

std::string FlowNetwork::toString(){
	std::stringstream ss;
	for(int i = 0;i<adj.size();++i){
		for(int j = 0;j<adj[i].size();++j){
			FlowEdge &e = adj[i][j];
			ss<<e.from()<<"->"<<e.to()<<":"<<e.getFlow()<<"/"<<e.getCapacity()<<std::endl;	
		}
	}
	return ss.str();
}
