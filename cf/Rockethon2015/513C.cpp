#include <iostream>

using namespace std;

int main(){
	int n;
	int l[5],r[5];
	int minL=10000, maxR=1;
	cin>>n;
	for(int i = 0;i<n;++i){
		cin>>l[i]>>r[i];
		minL = min(minL,l[i]);
		maxR = max(maxR,r[i]);
	}
	for(int b = minL;b <= maxR; ++b){
		for(int A = 1; A <= (1<<n);A<<1){	
			for(int B = 1; B <= (1<<n);++B){
				int BminusA = A^B;
				if(!BminusA){
					continue;	
				}
				
			}	
		}	
	}
	return 0;
}
