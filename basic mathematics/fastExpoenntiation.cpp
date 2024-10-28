#include<bits/stdc++.h>
using namespace std;
int exponentiation(int a,int b){
    int ANS=1;
    while(b>0){
        if(b&1){
            ANS*=a;
        }
        a*=a;
        b>>=1;
    }
    return ANS;
}

int main(){
    int a=5,b=5;
    cout<<exponentiation(a,b);
return 0;
}