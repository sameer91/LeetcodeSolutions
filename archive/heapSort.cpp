#include<iostream>
using namespace std;
class Heap{
  int N;
  int len;
  int *heap;
public:
  Heap(int N);
  void heapify(int i);
  void insert(int x);
  int removeMin();
  bool empty();
};

bool Heap::empty(){
  return len==-1;
}
Heap::Heap(int N){
  this->N=N;
  this->len=-1;
  heap= new int[N];
}

void Heap::insert(int x){
  len++;
  heap[len]=x;
  int p=len/2,c=len;
  while(p>=0 &&  heap[p]>heap[c]){
    swap(heap[p],heap[c]);
    c=p;
    p=(p-1)/2;
  }
}
int Heap::removeMin() {
  int e=heap[0];
  heap[0]=heap[len];
  len--;
  if(len>=0)
    heapify(0);
  return e;
}
void Heap::heapify(int i){
  int min=i;
  int l=2*i+1;
  int r=l+1;
  if(l<=len && heap[min]>heap[l]){
    min=l;
  }
  if(r<=len && heap[min] > heap[r]){
    min=r;
  }

  if(min != i){
    swap(heap[i],heap[min]);
    heapify(min);
  }
}

int main(){
  int arr[]={4,10,3,5,1,1,6,31,3,123,3,1,23,12312,421,3,3,4,2};
  int n=sizeof(arr)/sizeof(int);
  Heap h(n+1);
  for(int i=0;i<n;++i){
    h.insert(arr[i]);
  }
  while(!h.empty()){
    cout<<h.removeMin()<<" ";
  }
  cout<<endl;
  return 0;
}
