#include <iostream>

using namespace std;

int main(){
	long long l,r;
	cin>>l>>r;
	if(!(l%2)){
		if(r-l>=2){
			cout<<l<<" "<<l+1<<" "<<l+2<<endl;	
		}
		else{
			cout<<-1<<endl;	
		}
	}
	else{
		if(r-l-1>=2){
			cout<<l+1<<" "<<l+2<<" "<<l+3<<endl;
		}	
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
