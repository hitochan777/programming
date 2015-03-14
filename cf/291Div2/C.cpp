#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	int n,m;
	string s;
	set<int> v;
	cin>>n>>m;
	hash<string> string_hash;
	for(int i =0;i<n;++i){
		cin>>s;
		v.insert(string_hash(s));
	}
	for(int i =0;i<m;++i){
		cin>>s;
		unsigned int j = 0;
		for(; j<s.length();++j){
			string tmp(s);
			if(s[j]=='a'){
				tmp.replace(j,1,"b");
				if(v.find(string_hash(tmp))!=v.end()){
					break;
				}
				tmp.replace(j,1,"c");
				if(v.find(string_hash(tmp))!=v.end()){
					break;
				}
			}
			else if(s[j]=='b'){
				tmp.replace(j,1,"a");
				if(v.find(string_hash(tmp))!=v.end()){
					break;
				}
				tmp.replace(j,1,"c");
				if(v.find(string_hash(tmp))!=v.end()){
					break;
				}
			}	
			else{//s[j]=='c'
				tmp.replace(j,1,"a");
				if(v.find(string_hash(tmp))!=v.end()){
					break;
				}
				tmp.replace(j,1,"b");
				if(v.find(string_hash(tmp))!=v.end()){
					break;
				}
			}
		}
		if(j>=s.length()){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}

