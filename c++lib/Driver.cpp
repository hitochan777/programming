#include "FordFulkerson.h"

using namespace std;

int main(){
	int V,E, s = 0, t;
	FlowNetwork* fn;
	FordFulkerson* ff;
	cin>>V>>E;
	t = V-1;
	fn = new FlowNetwork(V,E);
	cout<<fn->toString()<<endl;
	ff = new FordFulkerson(*fn, s, t);
	cout<<"Max flow from "<<s<<" to "<<t<<endl;
	for (int v = 0; v < fn->getV(); v++) {
		vector<FlowEdge>* vfe = fn->getAdj(v);
		for (int i = 0;(int)i<vfe->size();++i) {
			if ((v == vfe->at(i).from()) && vfe->at(i).getFlow() > 0)
				cout<<"   "<<vfe->at(i).toString()<<endl;
		}
	}

	cout<<"Min cut: ";
	for (int v = 0; v < fn->getV(); v++) {
		if (ff->inCut(v)){
			cout<<v<<" ";
		}
	}
	cout<<endl;
	cout<<"Max flow value = "<<ff->getValue()<<endl;
	return 0;
}
