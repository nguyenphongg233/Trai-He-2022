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

ll n,x,y;
ll a[MAX];
ll pref[MAX];
vii vach;
signed main(){
	
	cin>>n>>x>>y;
	for(ll i = 1;i <= n;i++)cin>>a[i],pref[i] = pref[i - 1] + a[i];
	
	bool ok = 0;
	
	for(ll i = 1;i <= n;i++){
		
		if(a[i - 1] < x){
			if(a[i] < x)continue;
			else vach.push_back({i,0});
		}
		if(a[i + 1] < x){
			if(a[i] < x)continue;
			else vach.push_back({i,1});
		}
		
		
	}
	
	
	sort(vach.begin(),vach.end());
	
	vach.erase(unique(vach.begin(),vach.end()),vach.end());
	for(ll i = 1;i < vach.size() - 1;i++){
		
		
		ll l = vach[i - 1].X;
		ll r = vach[i].X;
		
		cout<<l<<" "<<r<<"\n";
		
	}
	
	
	
}