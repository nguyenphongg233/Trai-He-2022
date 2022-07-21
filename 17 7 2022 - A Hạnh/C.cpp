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

map<char,ll> mp;
ll cntw[MAX];
signed main(){
	
	if(ifstream("balastr.inp")){
		freopen("balastr.inp","r",stdin);
		freopen("balastr.out","w",stdout);
	}
	
	string s;
	cin>>s;
	
	for(ll i = 'A';i <= 'Z';i++){
		mp[char(i)] = min({abs(i - 'A'),abs(i - 'E'),abs(i - 'O'),abs(i - 'I'),abs(i - 'U')});
	}
	
	ll cnt = 0;
	ll cnt1 = 0;
	
	string op = "";
	string up = "";
	for(ll i = 0;i < s.size();i++){
		
		if(s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U')cnt++;
		else cnt--,cntw[s[i]]++;
		
		
	}
	
	
	
	if(cnt > 0)return cout<<cnt / 2,0;
	
	
	vector<pair<ll,char>> less;
	
	ll cntu = -cnt / 2;
	for(auto e : mp){
		less.push_back({e.Y,e.X});
		
	}
	ll sum = 0;
	
	
	sort(less.begin(),less.end());
	ll chiphi = 0;
	for(auto v : less){
		
		if(cntw[v.Y] >= cntu)return cout<<sum + cntu * v.X,0;
		else sum += cntw[v.Y] * v.X,cntu -= cntw[v.Y];
		
	}
	
	
	
	
	
}