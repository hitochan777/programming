#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
	long long n,m,tmp;
	int p1=0,p2;
	cin>>n>>m;
	p2 = n-1;
	vector<int> p(n);
	for(int i = 1;i <= n;++i){
		tmp = 1LL<<(n-1-i);
		if(tmp<m){
			m-=tmp;	
			p[p2--]=i;
		}
		else{
			p[p1++]=i;
		}
	}	
	for(int i = 0;i<n;++i){
		cout<<p[i]<<" ";
	}
	return 0;
}
