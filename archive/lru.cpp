#include <bits/stdc++.h>
#include <utility>
using namespace std;

int cacheMisses(vector<int> inputNum, int size){
	map<int,int> cachelru, cache;
	int N=inputNum.size(), miss=0;
	for(int i=0;i<N;++i){
		//cache found
		if(cache.find(inputNum[i])!= cache.end()){
			int j=cache[inputNum[i]];
			cache[inputNum[i]]=i;
			cachelru.erase(cachelru.find(j));
			cachelru.insert(make_pair(i, inputNum[i]));
		}
		//cache miss
		else {
			miss++;
			if(cache.size()<size){
				cachelru.insert(make_pair(i,inputNum[i]));
				cache.insert(make_pair(inputNum[i], i));
			}
			else {
				pair<int,int> remove=*cachelru.begin();
				cachelru.erase(remove.first);
				cache.erase(remove.second);

				cachelru.insert(make_pair(i,inputNum[i]));
				cache.insert(make_pair(inputNum[i], i));
			}
		}
	}
	return miss;
}

int main(){
	int N;
	cin>>N;
	vector<int> num(N,0);
	for(int i=0;i<N;++i)
		cin>>num[i];

	int size=0;
	cin>>size;
	cout<<"\n"<<cacheMisses(num, size)<<endl;
	return 0;
}
