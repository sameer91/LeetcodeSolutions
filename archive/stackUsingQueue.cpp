#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Stack{
  queue<int> q1;
public:
  void push(int);
  void pop();
  int top();
};
void Stack::push(int x){
  queue<int> q2;
  q2.push(x);
  while(!q1.empty()){
    q2.push(q1.front());
    q1.pop();
  }
  q1=q2;
}
void Stack::pop(){
  q1.pop();
}
int Stack::top(){
  return q1.front();
}
int main(){
  Stack s;
  s.push(10);
  s.push(9);
  s.push(1);
  cout<<s.top()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  return 0;
}
