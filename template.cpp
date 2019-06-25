#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mod1 1000000007
#define bg begin()
#define ed end()
#define sc second
#define fr first
using namespace std;
void fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
ll mod(ll a){return a%mod1;}
ll myPow(ll a,ll b){ if(b==0)return 1; ll temp=myPow(a,b/2);temp=mod(temp);if(b%2!=0)return mod(mod(mod(temp)*mod(temp))*a);else return mod(mod(temp)*mod(temp));}
ll mult(ll a,ll b){return mod(mod(a)*mod(b));}
ll add(ll a,ll b){return mod(mod(a)+mod(b));}
ll gcd(ll a,ll b){if(!b) return a;else return gcd(b,a%b);}
//////////////////////////////////////////////////////////////////////////////////^ ^////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void solve(){
   ll x=myPow(2,10);cout<<x;
}

int main(){
    fast();solve();
}

