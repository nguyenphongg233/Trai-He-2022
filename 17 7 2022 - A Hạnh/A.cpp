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

ii a[MAX];

signed main(){
	
	if(ifstream("cetvrta.inp")){
		freopen("cetvrta.inp","r",stdin);
		freopen("cetvrta.out","w",stdout);
	}
	
	vi dx,dy;
	for(ll i = 1,x,y;i <= 3;i++){
		cin>>x>>y;
		dx.push_back(x);
		dy.push_back(y);
		
		
	}
	
    sort(dx.begin(),dx.end());
    sort(dy.begin(),dy.end());
    
    if(dx[0] == dx[1])cout<<dx[2]<<" ";
    else cout<<dx[0]<<" ";
    
    if(dy[0] == dy[1])cout<<dy[2]<<" ";
    else cout<<dy[0]<<" ";
	
	
	
	
	
	
	
	
}