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

int n,dp[MAX][13];

int calc(int id,int du){
	
	if(id == n){
		//cout<<id<<" "<<n<<"\n";
		if(du == 0)return dp[id][du] = 1;
		else return dp[id][du] = 0;
	}
	

	if(dp[id][du] != -1)return dp[id][du];
	
	int &res = dp[id][du] = 0 ;
	
	for(int i = 0;i < 10;i++){
		if(id == 0 && i == 0)continue;
		if(i == 3 || i == 1)continue;
		res += calc(id + 1,(du * 10 + i) % 13);
		res %= mod;
	}
	
	
	
	return res;	
}

signed main(){
	
	

	cin>>n;
	memset(dp,-1,sizeof dp);
	cout<<calc(0,0) % mod;
	
	
	
}