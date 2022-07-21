#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 5000 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

int n,m,W,B;
vi adj[MAX][2];
// 0 : nguoc
// 1 : xuoi
int dp[MAX][MAX];
int f[MAX][MAX];

bool dfs(int w,int b){
	
	if(f[w][b] != -1)return f[w][b];
	
	bool ok = 0;
	int mx = 0,minx = INF;
	for(auto v : adj[w][1]){
		
		if(!dfs(v,b)){
			
			ok = 1;
			minx = min(minx,dp[v][b] + 1);
			
		}else mx = max(mx,dp[v][b] + 1);
		
		
	}
	
	
	for(auto v : adj[b][0]){
		
		if(!dfs(w,v)){
			ok = 1;
			minx = min(minx,dp[w][v] + 1);
		}else mx = max(mx,dp[w][v] + 1);
	}
	
	f[w][b] = ok;
	dp[w][b] = (f[w][b] == 1 ? minx : mx);
	
	
	
	
	
	
	return ok;
}
signed main(){
	
	cin>>n>>m>>W>>B;
	
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		adj[u][1].push_back(v);
		adj[v][0].push_back(u);
	}
	
	memset(f,-1,sizeof f);
	dfs(W,B);
	
	cout<<dp[W][B];
	
	
	
}