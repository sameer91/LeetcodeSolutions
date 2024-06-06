#include<bits/stdc++.h>
using namespace std;

int main() {
  int lena,lenb,lenc;
  cin >>lena>>lenb>>lenc;

  int a[lena],b[lenb],c[lenc];
  map<int,int> freqa,freqb,freqc;
  set<int> ua,ub,uc;
  for(int i = 0;i<lena;i++){
    cin>>a[i];
    if(freqa[a[i]] == 0)
      ua.insert(a[i]);
    freqa[a[i]]++;
  }
  for(int i = 0;i<lenb;i++){
    cin>>b[i];
    if(freqb[b[i]] == 0)
      ub.insert(b[i]);
    freqb[b[i]]++;
  }
  for(int i = 0;i<lenc;i++){
    cin>>c[i];
    if(freqc[c[i]] == 0)
      uc.insert(c[i]);

    freqc[c[i]]++;
  }
  // sort(ua.begin(),ua.end());
  // sort(ub.begin(),ub.end());
  // sort(uc.begin(),uc.end());
  auto pa = ua.begin();
  auto pb = ub.begin();
  auto pc = uc.begin();
  long count=0,ca=0,cc=0;
  for(;pb!=ub.end();pb++){
    while(pa != ua.end() && *pa<=*pb){
      pa++;
      ca++;
    }
    while(pc != uc.end() && *pc<=*pb){
      pc++;
      cc++;
    }
    count += ca * cc;
    //cout<<pa*pc<<endl;
  }

  cout<<count<<endl;

  return 0;
}
