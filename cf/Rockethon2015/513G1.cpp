#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

vector<int> p;
int N,K,norm=1,cases,total=0;

void invert(int i, int j){
	reverse(p.begin()+i,p.begin()+j+1);
	return ;
}

int getInversionNumber(){
	int sum = 0;
	for(int i =0;i<N;i++){
		for(int j=i+1;j<N;++j){
			if(p[i]>p[j]){
				++sum;	
			}
		}
	}
	return sum; 
}

void dfs(int depth){
	if(depth==K){
		total += getInversionNumber();	
	}
	else{
		for(int i = 0;i<N;++i){
			for(int j=i;j<N;++j){
				invert(i,j);
				dfs(depth+1);
				invert(i,j);
			}
		}				
	}
}

int main(){
	cin>>N>>K;
	cases = N*(N+1)/2;
	p.resize(N);
	for(int i = 0;i<N;++i){
		cin>>p[i];
	}
	for(int i = 0;i<K;++i){
		norm *= cases;
	}
	dfs(0);
	cout<<fixed<<setprecision(9)<<((double)total)/norm<<endl;
	return 0;
}
