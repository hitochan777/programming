#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

map<int,bool> have;

int main(){
	int Na,Nb,intersection = 0;
	cin>>Na>>Nb;
	for(int i = 0,input;i<Na;++i){
		cin>>input;
		have[input] = true;	
	}
	for(int i = 0,input;i<Nb;++i){
		cin>>input;	
		if(have[input]){
			intersection++;
		}
	}
	cout<<fixed<<setprecision(6)<<((double)intersection)/(Na+Nb-intersection)<<endl;
	return 0;
}
