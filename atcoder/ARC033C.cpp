#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

#define MAX_LEAF_NUM 200000

using namespace std;

class SegmentTree{
	private:
		vector<int> node;
		int N;
		void printTree(int index,int depth){
			if(index>=(int)node.size()){
				return ;
			}
			printf("%*s%d\n", depth, "", node[index]);
			printTree(index*2+1,depth+1);
			printTree(index*2+2,depth+1);
			return ;
		}

		void printArray(){
			for(int i = 0; i<(int)node.size();++i){
				cout<<node[i]<<" ";
				if(!(i%10)){
					cout<<endl;	
				}
			}
		}

		int sum(int l, int r,int index,int a, int b){
			if(b<=l || r<=a){
				return 0;	
			}
			if(l<=a && b<=r){
				return node[index];
			}
			else{
				return sum(l,r,index*2+1,a,(a+b)/2)+sum(l,r,index*2+2,(a+b)/2,b);
			}
		}

	public:
		enum PrintType {TREE, ARRAY};
		SegmentTree(int n){
			N = pow(2,ceil(log(n)/log(2)));
			int size = 2*N - 1;
			node.resize(size,0);
		}

		int getLeafNumber(){
			return N;	
		}

		void add(int index,int x){
			index += N - 1;	
			node[index] += x;
			// cout<<"index="<<index<<endl;
			while(index>0){
				index = (index - 1)/2;
				node[index] = node[index*2+1] + node[index*2+2];
			}
		}

		int sum(int l, int r){
			return sum(l,r,0,0,N);
		}

		void print(const PrintType type){
			switch(type){
				case TREE:
					printTree(0,0);
					break;
				case ARRAY:
					printArray();
					break;
				default:
					throw "Unknown Output Type in print function";
					break;
			}
			return ;
		}
};

int main(){
	int Q;
	SegmentTree st(MAX_LEAF_NUM);
	cin>>Q;
	for(int i = 0,T,X;i<Q;++i){
		cin>>T>>X;
		if(T==1){
			st.add(X-1,1);	
		}
		else{//T==2
			int l = 0, r = st.getLeafNumber();
			int mid;
			while(l<r){
				mid = (l + r)/2;
				int sum = st.sum(0,mid);
				 // printf("(l,r)=(%d,%d),mid=%d, sum=%d\n",l,r,mid,sum);
				if(sum >= X){
					r = mid;
				}
				else{
					l = mid+1;
				}
			}	
			st.add(l-1,-1);
			cout<<l<<endl;	
		}
		// st.print(SegmentTree::TREE);
	}
	return 0;
}
