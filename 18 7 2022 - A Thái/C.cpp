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


// t * 2 * 2 * N * 3 * 9 * (0 - 0) | (2 - 3 )(1 / 2) | (1 - 4)/ ( 1 / 2));
string a,b;
int dp[MAX][2][2][2][3][3][3][9];
int n;
// f(id, >= a, <= b,(0  0),(1 4) / (1 , 2),(2 - 3) / (1,2),% 3, % 9);


int calc(int id,bool ga,bool lb,bool z0,int z1,int z2,int du3,int du9){
	
	
	if(id == n){
		if(du3 == 0 && du9 != 0)return dp[id][ga][lb][z0][z1][z2][du3][du9] = 1;
		else return dp[id][ga][lb][z0][z1][z2][du3][du9] = 0;
	}
	
	if(dp[id][ga][lb][z0][z1][z2][du3][du9] != -1)return dp[id][ga][lb][z0][z1][z2][du3][du9] % mod;
	
	int &res = dp[id][ga][lb][z0][z1][z2][du3][du9] = 0;
	
	for(int i = 0;i < 10;i++){
		
		
		if((ga == 0 && i < a[id] - '0') || (lb == 0 && i > b[id] - '0')) continue;
		bool nextga = ga || (i > a[id] - '0');
		bool nextlb = lb || (i < b[id] - '0');
		
		int nextdu3 = (du3 * 10 + i ) % 3;
		int nextdu9 = (du9 * 10 + i ) % 9;
		
		
		int j = i % 5;
	
		
		
		if(z0 && j == 0)continue;
		if(z1 == 1 && j == 4)continue;
		if(z1 == 2 && j == 1)continue;
		if(z2 == 1 && j == 3)continue;
		if(z2 == 2 && j == 2)continue;
		int nextz0 = (z0 || j == 0);
		int nextz1;
		int nextz2;
		
		
		if(j == 1){
			nextz1 = 1;
			
		}else if(j == 4)nextz1 = 2;
		else nextz1 = 0;
		
		if(j == 2)nextz2 = 1;
		else if(j == 3)nextz2 = 2;
		else nextz2 = 0;
		
		
		if(z1 > 0)nextz1 = z1;
		if(z2 > 0)nextz2 = z2;
		
		
		res += calc(id + 1,nextga,nextlb,nextz0,nextz1,nextz2,nextdu3,nextdu9);
		res %= mod;
		
	}
	
	//cout<<id<<" "<<ga<<" "<<lb<<" "<<z0<<" "<<z1<<" "<<z2<<" "<<du3<<" "<<du9<<" : ";
	//cout<<res<<'\n';
	return res;
	
	
}


void solve(){
	
	cin>>a>>b;
	
	while(a.size() < b.size())a = "0"  + a ;
	n = b.size();
	
	memset(dp,-1,sizeof dp);
	
	cout<<calc(0,0,0,0,0,0,0,0)<<"\n";
	
	
	
}
signed main(){
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
	}
	
	
	
	
	
}