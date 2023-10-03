#include <bits/stdc++.h>

using namespace std;

int main(){
	for(int i=0;i<100;++i){
		int fail;
		for(int j = 0, fail = 0; j<100 && !fail; ++j){
			cout<<j<<endl;
			if(j % 10 == 0) {
				fail=1;
			}
		}
		if(!fail){
			cout<<"not fail"<<endl;
		}
	}
	return 0;
}
