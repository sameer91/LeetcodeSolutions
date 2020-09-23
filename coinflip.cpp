#include<bits/stdc++.h>

using namespace std;

int main() {
    int T=0, G =0, I = 0, Q=0;
    long long N=0,nh, nt;

    cin >> T;
    while(T--){
        cin >> G;
        while(G--) {
            cin >> I >> N >> Q;
            nh = 0;
            nt = 0;
            if(I == 1) {
                if(N%2 == 0){
                    nh = N/2;
                    nt = N/2;
                }
                else{
                    nh = N/2;
                    nt = N/2 + 1;
                }
            }
            else {
                if(N%2 == 0){
                    nh = N/2;
                    nt = N/2;
                }
                else{
                    nh = N/2+1;
                    nt = N/2;
                }
            }
            if(Q == 1)
            cout<<nh<<endl;
            else
            cout<<nt<<endl;
        }
    }
}