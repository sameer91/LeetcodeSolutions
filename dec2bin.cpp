#include <iostream>
#include<cmath>
using namespace std;

int main(){
	int number;
	cin>>number;
	//code
	unsigned long long int res=0, c=0;
	int count=0;
	while(number>0){
		int rem = number%2;
		c = pow(10,count);
		res += rem*c;
		number/=2;
		count++;
	}
	cout<<res<<endl;
}
