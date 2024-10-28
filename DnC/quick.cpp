#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int s,int e){
    int pivotIndex=s;
    int pivotElement=arr[s];
    //check karo kitne elements es pivotelement se chhote hai
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivotElement){
            cnt++;
        }
    }
    // pivotElement ki correcct position mil gyi
    int correctPos=s+cnt;
    swap(arr[pivotIndex],arr[correctPos]);
    pivotIndex=correctPos;
    //ab baaki elements ko bhi adjust kardo
    int i=s,j=e;
    // while(i<pivotIndex && j>pivotIndex){
    //     while(arr[i]<pivotElement){
    //         i++;
    //     }
    //     while(arr[j]>pivotElement){
    //         j--;
    //     }
    //     if(i<pivotIndex && j>pivotIndex){
    //         swap(arr[i],arr[j]);
    //     }
    // }
    return pivotIndex;
}
void quicksort(int arr[],int s,int e){
    if(s>e){
        return;
    }
    //ye pth element ko uski correct position pe pahucha dega
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1,0};
    int e=sizeof(arr)/sizeof(int);
    int s=0;
    quicksort(arr,s,e-1);
    for(auto v:arr){
        cout<<v<<" ";
    }
return 0;
}