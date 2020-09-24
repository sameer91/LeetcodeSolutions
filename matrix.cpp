#include<iostream>
#include<list>
#include<map>
#include<set>
using namespace std;

map<long long,list<pair<long long, long long>>,greater<long long>> edges;
list<long long> *adj;
long long V,*parent;
bool *machine;
long long *count;

long long getParent(long long x){
  while(parent[x] != x){
    x = parent[x];
  }
  return x;
}

long long unify(long long u, long long v){
  long long s1=getParent(u);
  long long s2=getParent(v);

  if(s1!=s2 && machine[s1]==1 && machine[s2]==1){
    return 1;
  }
  if(count[s1]>count[s2]){
    parent[s2]=s1;
    count[s2]+=count[s1];
    if(machine[s1]|| machine[s2]){
      machine[s1]=true;
    }
  }
  else {
    parent[s1]=s2;
    count[s1]+=count[s2];
    if(machine[s1]||machine[s2]){
      machine[s2]=true;
    }
  }
  return 0;
}

int main() {
  int N,K;
  cin>>N>>K;
  V=N;
  adj= new  list<long long>[V];
  parent= new long long[V];
  machine=new bool[V];
  count=new long long[V];
  for(int i=0;i<N-1;++i){
    long long u,v,w;
    cin>>u>>v>>w;
    edges[w].push_back(make_pair(u, v));
    adj[u].push_back(v);
    adj[v].push_back(u);
    machine[i]=false;
    parent[i]=i;
    count[i]=1;
  }
  machine[N-1]=false;
  parent[N-1]=N-1;
  count[N-1]=1;
  for(int j=0;j<K;j++){
    int x;
    cin>>x;
    machine[x]=true;
  }
  long long cost=0;
  for(auto i=edges.begin();i!=edges.end();++i){
    //add edge to
    for(auto j=i->second.begin();j!=i->second.end();++j){
      long long u = j->first;
      long long v=j->second;
      long long w=i->first;
      int x=unify(u,v) ;
      cost+=x*w;
    }

  }
  cout << cost<<endl;

  return 0;
}
