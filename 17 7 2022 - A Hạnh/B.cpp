#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll t;
ll n,m;
ii a[MAX],b[MAX];

signed main(){
	
	cin>>y>>n>>m;
	
	for(ll i = 1;i <= n;i++){
		
		cin>>a[i].X;
		
		if(a[i].X < 0)a[i].Y = 0;
		else a[i].Y = 1;
		a[i].X = abs(a[i].X);
		
	}
	
	
	
	
}