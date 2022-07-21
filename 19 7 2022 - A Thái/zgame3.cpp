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


int n;
string s;
set<int> c[2];

signed main(){
	
	cin>>n>>s;
	
	for(int i = 0;i < s.size();i++){
		
		if(s[i] == '1'){
			if(i & 1)c[1].insert(i);
			else c[0].insert(i);
		}
		
	}
	
	
	if(c[0].size() % 2 == 0 && c[1].size() % 2 == 0){
		
		cout<<"0"<<endl;
		
		int x;
		cin>>x;
		
		if(x < 0){
			
			x = abs(x) - 1;
			
			c[x % 2].erase(x);
			s[x] = '0';
			
			if(s[x - 1] == '0'){
				s[x - 1] = '1';
				c[(x + 1) % 2].insert(x - 1);
			}else{
				s[x - 1] = '0';
				c[(x + 1) % 2].erase(x - 1);
			}
			
			
		}else{
			
			x--;
			
			c[x % 2].erase(x);
			s[x] = '0';
			
		}
		
		
		
		
		
		
	}else cout<<"1"<<endl;
	
	
	while(c[0].size() > 0 || c[1].size() > 0){
		
		
		
		if(c[0].size() % 2 == 1 && c[1].size() % 2 == 1){
			
			int id = max(*c[0].rbegin(),*c[1].rbegin());
			
			s[id] = '0';
			c[id % 2].erase(id);
			
			
			if(s[id - 1] == '0'){
				s[id - 1] = '1';
				c[(id + 1) % 2].insert(id - 1);
			}else{
				s[id - 1] = '0';
				c[(id + 1) % 2].erase(id - 1);
			}
			
			
			cout<<-(id + 1)<<endl;
			
			
		}else if(c[0].size() % 2 == 1 && c[1].size() % 2 == 0){
			
			
			int id = *c[0].rbegin();
			
			s[id] = '0';
			c[id % 2].erase(id);
			cout<<id + 1<<endl;
			
		}else if(c[0].size() % 2 == 0 && c[1].size() % 2 == 1){
			
			int id = *c[1].rbegin();
			
			s[id] = '0';
			c[id % 2].erase(id);
			cout<<id + 1<<endl;
		}
		
		
		
		
		
		
		
		
		int x;
		cin>>x;
		
		if(x < 0){
			
			x = abs(x) - 1;
			
			c[x % 2].erase(x);
			s[x] = '0';
			
			if(s[x - 1] == '0'){
				s[x - 1] = '1';
				c[(x + 1) % 2].insert(x - 1);
			}else{
				s[x - 1] = '0';
				c[(x + 1) % 2].erase(x - 1);
			}
			
			
		}else{
			
			x--;
			
			c[x % 2].erase(x);
			s[x] = '0';
			
		}
		
	}
	
}