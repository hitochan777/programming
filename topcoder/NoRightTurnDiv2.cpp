#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

class NoRightTurnDiv2{
	private:
		bool isEqual(double x, double y){
			return isZero(abs(x-y));
		}
		bool isZero(double x){
			return (x <  numeric_limits<double>::epsilon() && 
					x > -numeric_limits<double>::epsilon());

		}
		bool valid(vector<int>& route, vector<int>& x, vector<int>& y){
			for(unsigned int i = 0;i<route.size();++i){
				cout<<route[i]<<" ";
			}
			cout<<endl;
			int N = route.size();
			for(int i = 0;i<N-1;++i){
				double A1 = (double)y[route[i+1]] - y[route[i]];
				double B1 = (double)x[route[i]] - x[route[i+1]];
				double C1 = A1*x[route[i]] + B1*y[route[i]];
				for(int j = 0; j<i;++j){
					double A2 = (double)y[route[j+1]] - y[route[j]];
					double B2 = (double)x[route[j]] - x[route[j+1]];
					double C2 = A2*x[route[j]] + B2*y[route[j]];
					double det = A1*B2 - A2*B1;
					//if(route[i]==1 && route[j]==3){
					//	cout<<det<<endl;
					//}
					if(!isZero(det)){
						double X = (B2*C1 - B1*C2)/det;
						double Y = (A1*C2 - A2*C1)/det;
						if(
							       max(min(x[route[i]],x[route[i+1]]),min(x[route[j]],x[route[j+1]]))<X &&
							       min(max(x[route[i]],x[route[i+1]]),max(x[route[j]],x[route[j+1]]))>X &&
							       max(min(y[route[i]],y[route[i+1]]),min(y[route[j]],y[route[j+1]]))<Y && 
							       min(max(y[route[i]],y[route[i+1]]),max(y[route[j]],y[route[j+1]]))>Y){
							return false;	
						}
					}
				}

			}
			return true;
		}

	public:
		vector<int> findPath(vector<int> x, vector<int> y){
			int N = x.size();
			for(int i = 0; i < N;++i){
				for(int j = 0;j<N;++j){
					if(i==j){
						continue;
					}
					int p = i, q = j;	
					vector<bool> used(N,false);
					vector<int> route;
					used[i] = used[j] = true;
					route.push_back(i);
					route.push_back(j);
					while(route.size()<N){
						double theta1 = atan2(y[q]-y[p],x[q]-x[p]);
						double minval = M_PI;
						int index = -1;
						for(int k = 0; k<N;++k){
							if(!used[k]){
								double theta2 = atan2(y[k]-y[q],x[k]-x[q]);		
								double ang = theta2 - theta1;
								while(ang<0){
									ang += 2.0*M_PI;
								}
								if(ang<minval){
									index = k;
									minval = ang;
								}
							}

						}
						if(index==-1){
							break;
						}
						route.push_back(index);
						used[index] = true;
						p = q;
						q = index;
					}
					if(route.size()==N){
						if(valid(route,x,y)){
							return route;
						}
					}
					/*if(route.size()==N && valid(route,x,y)){
						return route;	
					}*/
				}
			}	
			return vector<int>();
		}
};

int main(){
	NoRightTurnDiv2 nrtd2;
	vector<int> x = {0, 2,-2, 4,-4, 2,-2, 0};
	vector<int> y = {1, 2, 2, 4, 4, 6, 6, 5};
	vector<int> ans = nrtd2.findPath(x,y);
	cout<<"ans.size()=="<<ans.size()<<endl;
	for(unsigned int i = 0;i<ans.size();++i){
		cout<<ans[i]<<" ";
	}

	return 0;
}
