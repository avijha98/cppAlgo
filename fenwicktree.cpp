#include<bits/stdc++.h>
using namespace std;

int sum(int bt[],int st,int end){
    st++;end++;int s=0;
    while(end>=st){
        s+=bt[end];
        end-=end&(-end);
    }
    return s;
}
void update(int bt[],int val,int ind,int n){
    ind++;
    while(ind<=n){
        bt[ind]+=val;
        ind+=ind&(-ind);
    }
}
int *Bit(int a[],int n){
    int *bit=new int[n+1];
    for(int i=1;i<=n;i++){
        bit[i]=0;
    }
    for(int i=0;i<=n;i++){
        update(bit,a[i],i,n);
    }
    return bit;
}
int main(){
    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int *bit=Bit(a,n);
    int x=sum(bit,0,2);
    cout<<x<<endl;
    return 0;
}