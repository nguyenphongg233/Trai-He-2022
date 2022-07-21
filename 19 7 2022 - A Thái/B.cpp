#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int pref[MAX][MAX];
int dp[MAX][MAX];
int get(int x,int y,int u,int v){
	return (pref[u][v] - pref[x - 1][v] - pref[u][y - 1] + pref[x - 1][y - 1] + 3 * 3 * 3 * 3 ) % 3;
}
bool dx[MAX][3];
bool dy[MAX][3];

signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	int n,m;
	
	while(cin>>n>>m){
	    	
	
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				int x;
				cin>>x;
				x %= 3;
				pref[i][j] = (pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + x + 3 * 3) % 3;
			}
		}
		
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				dp[i][j] = -1;
			}
			for(int j = 0;j < 3;j++)dx[i][j] = 0;
		}
		
		for(int j = 1;j <= m;j++){
			for(int z = 0;z < 3;z++)dy[j][z] = 0;
		}
		// dp[i][j] : thg dang xet trang thai (i,j) la thang : 1 thua : 0
		
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				
				if(i == 1 && j == 1){
					
					if(pref[i][j] % 3 == 1)dp[i][j] = 1;
					else dp[i][j] = 0;
					
					
					if(dp[i][j] == 0){
						dx[i][pref[i][j] % 3] = 1;
						dy[j][pref[i][j] % 3] = 1;
					}
					
					//cout<<dp[i][j]<<" ";
					continue;
					
				}
				
				
				if(pref[i][j] % 3 == 1){
					dp[i][j] = 1;
					//cout<<dp[i][j]<<" ";
					continue;
				}
				
				int du = ( pref[i][j] + 2 + 3 * 3) % 3;
				
				if(dx[i][du] || dy[j][du])dp[i][j] = 1;
				else dp[i][j] = 0;
				
				
				
				
				if(dp[i][j] == 0){
				   
				   dx[i][pref[i][j] % 3] = 1;
				   dy[j][pref[i][j] % 3] = 1;
				}
				
				//cout<<dp[i][j]<<" ";
			}
			//cout<<"\n";
		}
		
		
		cout<<dp[n][m]<<"\n";
		
	}
	
	
}