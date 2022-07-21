#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e17;

using namespace std;

struct node{
	ll a,b,id;
};

node poil[MAX];
ll n,k;
ll subtask;
node tv[MAX][MAX];
ll dp[MAX][MAX];
ll a[MAX];

signed main(){
	
	
	if(ifstream("credit.inp")){
		freopen("credit.inp","r",stdin);
		freopen("credit.out","w",stdout);
	}
	
	cin>>subtask;
	cin>>n>>k;
	
	
	for(ll i = 1,u,v;i <= n;i++){
		cin>>u>>v;
		poil[i] = {u,v,i};
		
	}
	
	for(ll i = 0;i <= n;i++){
		for(ll j = 0;j <= k;j++)dp[i][j] = INF;
	}
	
	dp[0][0] = 0;
	
	
	for(ll i = 1;i <= n;i++){
		dp[i][0] = 0;
		for(ll j = 1;j <= k;j++){
			//cout<<i<<" "<<j<<"\n";
		
			if(j >= 1 && dp[i][j] > dp[i - 1][j - 1] + poil[i].a){
				
				//cout<<dp[i - 1][j - 1] + poil[i].a<<" ";
				dp[i][j] = dp[i - 1][j - 1] + poil[i].a;
				tv[i][j] = {i - 1,j - 1,1};
				
			}
			if(j >= 2 && dp[i][j] > dp[i - 1][j - 2] + poil[i].b){
				
				//cout<<dp[i - 1][j - 2] + poil[i].b<<" ";
				dp[i][j] = dp[i - 1][j - 2] + poil[i].b;
				tv[i][j] = {i - 1,j - 2,2};
			}
			
			if(dp[i][j] > dp[i - 1][j]){
				//cout<<dp[i - 1][j]<<" ";
				dp[i][j] = dp[i - 1][j];
				tv[i][j] = {i - 1,j,0};
			}
			
			//cout<<poil[i].a <<" "<<poil[i].b<<"\n";
			
			//cout<<dp[i][j]<<"\n";
		}
		//cout<<"\n";
	}
	
	
	cout<<dp[n][k]<<"\n";
	
	ll x = n,y = k;
	
	vi o;
	
	while(1){
		
		if(x == 0)break;
		
		
		o.push_back(tv[x][y].id);
		//cout<<tv[x][y].id<<" ";
		ll se = tv[x][y].a;
		ll z = tv[x][y].b;
		
		x = se;
		y = z;
		
		
		
		
	}
	
	for(ll i = o.size() - 1;i >= 0;i--)cout<<o[i];
	//cout<<ste;
}