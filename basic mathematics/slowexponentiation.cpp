#include<bits/stdc++.h>
using namespace std;
int slowexpo(int a,int b){
    int ans=1;
    for(int i=1;i<=b;i++){
        ans*=a;
    }
    return ans;
}
int main(){
    int a=5,b=5;
    cout<<slowexpo(a,b);
return 0;
}