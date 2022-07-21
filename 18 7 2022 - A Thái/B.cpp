#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e4 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int dp[MAX][2][2][12][17];
string l,r;
int n;

int calc(int id,bool lower,bool upper,int last,int du){
	
	if(id == n){
		if(du == 0)return dp[id][lower][upper][last][du] = 1;
		else return dp[id][lower][upper][last][du] = 0;
	}
	
	
	if(dp[id][lower][upper][last][du] != -1)return dp[id][lower][upper][last][du];
	int &res = dp[id][lower][upper][last][du] = 0;
	
	for(int i = 0;i < 10;i++){
		
		if(i == last)continue;
		if((!lower && i > r[id] - '0') || (!upper && i < l[id] - '0'))continue;
		
		res += calc(id + 1,lower || (i < r[id] - '0'),upper || (i > l[id] - '0'),(i == 0 && last == 10) ? 10 : i,(du * 10 + i) % 17);
		res %= mod;
		
	}
	
	
	return res %= mod ;
	
}


signed main(){
	
	cin>>l>>r;
	
	while(l.size() < r.size())l = '0' + l;
	
	n = r.size();
	memset(dp,-1,sizeof dp);
	
	cout<<calc(0,0,0,10,0) % mod;
	
	
}
