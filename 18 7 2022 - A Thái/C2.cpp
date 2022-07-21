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

string r;
int n;
int dp[MAX][2][2][11];


int calc(int id,bool ok1,bool ok2,int last){
	if(id == n){
		
		if(ok1 && ok2)return dp[id][ok1][ok2][last] = 1;
		else return dp[id][ok1][ok2][last] = 0;
	}
	
	
	if(dp[id][ok1][ok2][last] != -1)return dp[id][ok1][ok2][last];
	
	int &res = dp[id][ok1][ok2][last];
	
	for(int i = 0;i < 10;i++){
		
		if ((abs(j-p) >= 5 || p == 10) && (ok1 || j <= (r[i] - '0'))) {
			fn += cac(i+1, ok1 || j < (r[i] - '0'), ok2 || j > (r[n-i-1] - '0'), (p == 10 && j == 0) ? 10 : j);
			fn %= MOD;
		}
	}
	
	return dp[i][ok1][ok2][p] = fn;
}
signed main(){
	
	cin>>r;
	n = r.size();
	memset(dp,-1,sizeof dp);
	cout<<calc(0,0,0,10) % mod;
	
	
	
	
	
	
}