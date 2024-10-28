#include <iostream>
using namespace std;
void permu(string s,int i){
  if(i>=s.length()){
    cout<<s<<" ";
    return;
  }

  for(int j=i;j<s.length();j++){
    swap(s[i],s[j]);
    permu(s,i+1);
  }
}


int main() {
  string s;
  cin>>s;
  int i=0;
  permu(s,i);
  return 0;
}