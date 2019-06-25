#include <bits/stdc++.h>

using namespace std;
int tree[2000005];
int a[100005];
void build(int node ,int l,int r){
    if(l==r){
        int tmp=a[l];int ftr=0;
        while(tmp){
            if(tmp%2!=0)ftr++;
            tmp=tmp/2;
        }
        tree[node]=ftr;
    }
    else{
        int mid=(l+r)/2;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        tree[node]=tree[node*2]+tree[2*node+1];
    }
}

void update1(int node,int l,int r,int index){
    if(l==r){a[index]=a[l]*2+1;tree[node]=tree[node]+1;}
    else{
     int mid=(l+r)/2;
    if(index>=l&&index<=mid){
        update1(node*2,l,mid,index);
    }
    else update1(node*2+1,mid+1,r,index);
    
    tree[node]=tree[node*2]+tree[node*2+1];
    }
}
void update2(int node,int l,int r,int index){
    if(l==r){
        if(a[l]==0)return;
        if(a[l]%2!=0){
            a[index]=a[l]/2-1;
            tree[node]=tree[node]-1;
        }
        else{
            a[index]=a[l]/2;
        }
    }
    else{
     int mid=(l+r)/2;
    if(index>=l&&index<=mid){
        update2(node*2,l,mid,index);
    }
    else update2(node*2+1,mid+1,r,index);
    
    tree[node]=tree[node*2]+tree[node*2+1];
    }
}
int q(int node,int start,int end,int l,int r){
    if(start>r||end<l)return 0;
    if(start>=l&&end<=r)return tree[node];
    int mid=(start+end)/2;
    int p=q(2*node,start,mid,l,r);
    int p1=q(2*node+1,mid+1,end,l,r);
    return p+p1;
}
int main() {
    int n,q1;cin>>n>>q1;for(int i=0;i<n;i++){a[i]=0;}
    build(1,0,n-1);
    while(q1--){
        int a,b,c;cin>>a;
        if(a==1){
            cin>>b;
            update1(1,0,n-1,b-1);
        }
        if(a==2){
            cin>>b;
            update2(1,0,n-1,b-1);
        }
        if(a==3){
            cin>>b>>c;
            int d=q(1,0,n-1,b-1,c-1);cout<<d<<endl;
        }
    }
	return 0;
	
}
