#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,cnt = 0;

int f(vector<int>& v){
	int val = 0;
	for(int i = 0;i< n;++i){
		for(int j = i;j<n;++j){
			int minval = 100;
			for(int k = i;k<=j;++k){
				if(minval>v[k]){
					minval = v[k];
				}
			}	
			val += minval;
		}
	}
	return val;
}

int main(){
	int maxval = 0;
	cin>>n>>m;
	vector<int> v(n),ans(n);
	for(int i =0 ;i<n;++i){
		v[i] = i+1; 
	}
	do {
		int fp = f(v);
		// cout<<fp<<endl;
		if(fp > maxval){
			cnt = 1;
			maxval = fp;
			ans = v;
		}
		else if(fp==maxval){
			if(cnt<m){
				cnt++;
				ans = v;
			}
		}
	} while(next_permutation(v.begin(), v.end()));	
	for(int i = 0;i<n;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}
