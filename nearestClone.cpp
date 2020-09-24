#include<iostream>
#include<list>
#include<map>
using namespace std;

map<long long,list<long long>> color;
map<long long,long long> col2;
class G{
  long long V;
  list<long long> *adj;
public:
  G(int v){
    this->V=v;

    adj= new list<long long>[v];
  }
  void addEdge(long long u,long long v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long bfs(int);
  void getColor(){
    for(long long i=0;i<V;i++){
      long long c;
      cin>>c;
      color[c].push_back(i);
      col2[i]=c;
    }
  }
  void getMin(long long);
};
void G::getMin(long long C){
  long long minLen=INT32_MAX;
  for(auto i=color[C].begin();i!=color[C].end();++i){
    long long depth=bfs(*i);
    if(depth > 0)
    minLen = min(minLen,depth);
  }
  if(minLen < INT32_MAX)
    cout<<minLen<<endl;
  else
    cout<<"-1"<<endl;
}
long long G::bfs(int v){
  list<long long> que;
  bool visited[V];
  for(auto i=0;i<V;++i){
    visited[i]=false;
  }
  que.push_back(v);
  visited[v]=true;
  long long depth=0;
  while(!que.empty()){
    list<long long> temp;
    while(!que.empty()){
      long long vertex = que.front();
      que.pop_front();
      if(depth>0 && col2[vertex]==col2[v]){
        return depth;
      }
      for(auto i = adj[vertex].begin();i!=adj[vertex].end();++i){
        if(!visited[*i]){
          visited[*i]=true;
          temp.push_back(*i);
        }
      }
    }
    depth++;
    que=temp;
  }
  return -1;
}
int main(){
  long long V,E;
  cin>>V>>E;
  G g(V);
  for(long long i=0;i<E;i++){
    long long u,v;
    cin>>u>>v;
    g.addEdge(u-1, v-1);
  }
  g.getColor();
  long long target=0;
  cin>>target;
  g.getMin(target);
  return 0;
}
