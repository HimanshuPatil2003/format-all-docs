#include <iostream>
using namespace std;

int partition(int arr[],int s,int e){
  int pvtidx=s;
  int pvtele=arr[s];
  int cnt=0;
  for(int i=s+1;i<=e;i++){
    if(arr[i]<=pvtele)cnt++;
  }
  int rightidx=s+cnt;
  swap(arr[rightidx],arr[pvtidx]);
  pvtidx=rightidx;

  int i=s,j=e;
  while(i<pvtidx && j>pvtidx){
    if(arr[i]<=pvtele){
      i++;
    }
    if(arr[j]>pvtele){
      j--;
    }

    if(i<pvtidx && j>pvtidx){
      swap(arr[i],arr[j]);
    }
  }

  return pvtidx;
}

void quicksort(int arr[],int s,int e){
  if(s>=e)return ;

  int p=partition(arr,s,e);
  quicksort(arr,s,p-1);
  quicksort(arr,p+1,e);
}
int main() {
  int arr[]={8,1,20,30,6,5,60,5};
  int n=sizeof(arr)/sizeof(int);

  quicksort(arr,0,n-1);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}