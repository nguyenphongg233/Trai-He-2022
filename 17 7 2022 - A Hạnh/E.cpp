#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 5e18;

using namespace std;

ll n,m,x,y,a[MAX];
ll dp[MAX];
ll st[MAX << 2];
ll lazy[MAX << 2];
ll pref[MAX];
ll minx[MAX];


void lazyupdate(ll id,ll l,ll r){
	
	if(lazy[id] == 0)return;
	
	
	
	st[id] += lazy[id];
	
	
	//if(st[id << 1] == st[id] - lazy[id])
	if(l != r){
		lazy[id << 1] += lazy[id];
	//else 
		lazy[id << 1 | 1] += lazy[id];
	}
	lazy[id] = 0; 
	
}

void update(ll id,ll l,ll r,ll u,ll v,ll val){

    
	lazyupdate(id,l,r);
	
	if(u > v)return;
	if(u > r || v < l)return;
	
	if(u <= l && r <= v){
		
		lazy[id] += val;
		lazyupdate(id,l,r);
		
		return;
		
		
	}
	
	ll m = l + r >> 1;
	
	
	int mid = (l + r) >> 1;
	if(u <= mid) update(id << 1, l, mid, u, v, val);
	if(mid + 1 <= v) update(id << 1|1, mid + 1, r, u, v, val);
	st[id] = min(st[id << 1],st[id << 1 | 1]);
	
}

ll get(ll id,ll l,ll r,ll u,ll v){
	
	
	lazyupdate(id,l,r);
	
	if(u > v)return INF;
	if(u > r || v < l)return INF;
	
	if(u <= l && r <= v)return st[id];
	
	//ll m = l + r >> 1;
	
	int mid = (l + r) >> 1;
	long long res = INF;
	if(u <= mid) res = min(res, get(id << 1, l, mid, u, v));
	if(mid + 1 <= v) res = min(res, get(id << 1|1, mid + 1, r, u, v));
	
	return res;
}

signed main(){
	
	if(ifstream("candy.inp")){
		freopen("candy.inp","r",stdin);
		freopen("candy.out","w",stdout);
	}
	
	
	cin>>n >> m >> x >> y;
	for(ll i = 1;i <= n;i++)cin>>a[i],pref[i] = pref[i - 1] + a[i];
	
	//for(ll i = 1;i < MAX;i++)st[i] = INF;

	
	minx[n + 1] = pref[n] * x;
	ll i_ = n;
	
	for(ll i = n;i >= 1;i--){
		dp[i] = INF;
		
		while(pref[i_] - pref[i - 1] > m)i_--;
		i_++;
		
		i_ = min(i_,n);
		
		if(pref[i_] - pref[i - 1] > m){
			dp[i] = min(dp[i],minx[i_ + 1] - x * pref[i - 1] - m * x);
			ll z = get(1,1,n,i + 1,i_) + y * m - a[i] * y ;
		    dp[i] = min(dp[i],z);
		}
		if(pref[i_] - pref[i - 1] <= m)
			dp[i] = y * (m - (pref[i_] - pref[i - 1]));
        	


	
		update(1,1,n,i + 1,n,-a[i] * y); 
		update(1,1,n,i,i,dp[i]);
		minx[i] = min(minx[i + 1],dp[i] + pref[i - 1] * x);
	}
	
	cout<<dp[1];
	
}