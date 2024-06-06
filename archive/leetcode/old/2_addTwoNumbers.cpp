#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x){
		val=x;
		next=NULL;
	}
};

void addNode(ListNode** head_ref, int x){
	ListNode *newNode = new ListNode(x), *itr = *head_ref;
	if(*head_ref == NULL){
		*head_ref = newNode;
		return;
	}
	while (itr->next != NULL) {
		itr = itr->next;
	}
	itr->next = newNode;
	return;
}

ListNode *addTwoNumber(ListNode *l1, ListNode *l2){
	ListNode *res=NULL;
	int sum=0,carry=0;
	while(l1||l2){
		if(l1&&l2){
			sum = carry + l1->val + l2->val;
			l1=l1->next;
			l2=l2->next;
		}
		else if(l1!=NULL){
			sum = carry + l1->val;
			l1=l1->next;
		}
		else {
			sum = carry + l2->val;
			l2=l2->next;
		}
		carry = sum/10;
		sum = sum%10;
		addNode(&res, sum);
	}
	if(carry !=0)
		addNode(&res,carry);
	return res;
}

int main(){
	int n1,n2;
	cin>>n1>>n2;
	ListNode *l1=NULL, *l2=NULL;
	for(int i=0;i<n1;++i){
		int x;
		cin>>x;
		addNode(&l1,x);
	}
	for(int i=0;i<n2;++i){
		int x;
		cin>>x;
		addNode(&l2,x);
	}
	ListNode *res = addTwoNumber(l1, l2);
	while(res){
		cout<<res->val<<' ';
		res=res->next;
	}
	cout<<endl;
	return 0;
}
