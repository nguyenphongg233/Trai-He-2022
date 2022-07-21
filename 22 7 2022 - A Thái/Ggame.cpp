#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int n,m,a[MAX];
int dp[MAX];
vi adj[MAX];

int dfs(int u){
	
	
	if(dp[u] != -1)return dp[u];
	dp[u] = 1;
	
	for(auto v : adj[u]){
		
		dp[u] = max(dp[u],dfs(v) + 1);
		
		
	}
	
	return dp[u];
	
	
	
	
	
}
signed main(){
	
	cin>>n>>m;
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	memset(dp,-1,sizeof dp);
	
	int nim = 0;
	for(int i = 1;i <= n;i++){
		dfs(i);
		nim ^= dp[i] * a[i];
	}
	
	cout<<((nim > 0) ? "YES" : "NO");
	
	
	
	
	
	
	
}