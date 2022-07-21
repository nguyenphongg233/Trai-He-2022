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
vi adj[MAX];
int dp[MAX];

signed main(){
	
	cin>>n>>m;
	
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	memset(dp,-1,sizeof dp);
	int nim = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] & 1){
			
			if(adj[i].size() > 0)nim ^= 1;
			
		}
		
	}
	
	cout<<(nim > 0 ? "YES" : "NO")<<"\n";
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}