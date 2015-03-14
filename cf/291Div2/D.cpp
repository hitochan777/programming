#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M,K;
vector<vector<int> > cnt;

int calcRequiredShot(int start, int end){
	int sum = 0;
	for(int j = 0;j<M;++j){
		int maxval = 0;
		for(int i = start; i <= end; ++i){
			maxval = max(maxval,cnt[i][j]);	
		}	
		sum += maxval;
	}
	return sum;
}

int main(){
	int maxlen = 0;
	int begin, end;
	int fp=0, bp=0;
	cin>>N>>M>>K;
	cnt.resize(N);
	for(int i = 0;i < N;++i){
		cnt[i].resize(M);
		for(int j=0;j < M;++j){		
			cin>>cnt[i][j];
		}
	}
	while(bp < N){
		if(fp>bp){
			bp = fp;	
		}
		int rs = calcRequiredShot(fp,bp);
		if(rs < K){
			if(maxlen < bp - fp + 1){
				begin = fp;
				end = bp;
			}
			bp++;
		}
		else{
			fp++;
		}
	}
	for(int j = 0; j<M;++j){
		int maxval = 0;
		for(int i = begin; i <= end;++i){
			maxval = max(maxval, cnt[i][j]);		
		}
		cout<<maxval<<endl;
	}
	return 0;
}
