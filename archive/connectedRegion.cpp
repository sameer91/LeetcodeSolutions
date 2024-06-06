#include<iostream>
#include<list>
#include<map>
using namespace std;

int matrix[10][10],V=0;
map<pair<int,int>,list<pair<int,int>>> adj;
map<pair<int,int>,bool> visited;
list<pair<int,int>> g;

int bfs(pair<int,int> p){
  visited[p]=true;
  list<pair<int,int>> que;
  que.push_back(p);
  int count=1;
  while(!que.empty()){
    list<pair<int,int>> temp;
    while(!que.empty()){
      pair<int,int> f=que.front();
      que.pop_front();
      for(auto i=adj[f].begin();i!=adj[f].end();++i){
        if(!visited[*i]){
          count++;
          visited[*i]=true;
          temp.push_back(*i);
        }
      }
    }
    que=temp;
  }
  return count;
}

int main(){
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N;++i){
    for(int j=0;j<M;++j){
      cin>>matrix[i][j];
      if(matrix[i][j]==1)
        V++;
    }
  }
  for (int i=0; i<N; ++i) {
    for (int j=0; j<M; ++j) {
      if(matrix[i][j]==1){
        visited[make_pair(i,j)]=false;
        g.push_back(make_pair(i,j));
        int u=i-1,d=i+1,l=j-1,r=j+1;
        if(u>=0 && matrix[u][j]==1){ adj[make_pair(i,j)].push_back(make_pair(u,j)); }
        if(d<N && matrix[d][j]==1) { adj[make_pair(i,j)].push_back(make_pair(d,j)); }
        if(l>=0 && matrix[i][l]==1){ adj[make_pair(i,j)].push_back(make_pair(i,l)); }
        if(r<M && matrix[i][r]==1) { adj[make_pair(i,j)].push_back(make_pair(i,r)); }

        if(u>=0 && l>=0 && matrix[u][l]==1){ adj[make_pair(i,j)].push_back(make_pair(u,l)); }
        if(d<N && l>=0 && matrix[d][l]==1) { adj[make_pair(i,j)].push_back(make_pair(d,l)); }
        if(u>=0 && r<M && matrix[u][r]==1) { adj[make_pair(i,j)].push_back(make_pair(u,r)); }
        if(d<N && r<M  && matrix[d][r]==1) { adj[make_pair(i,j)].push_back(make_pair(d,r)); }
      }
    }
  }
  int maxCount=1;
  for(auto i=g.begin();i!=g.end();++i){
    if(!visited[*i]){
      int count=bfs(*i);
      maxCount = max(maxCount,count);
    }
  }
  cout<<maxCount<<endl;
  return 0;
}
