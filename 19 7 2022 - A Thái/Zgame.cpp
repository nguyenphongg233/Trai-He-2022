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

signed main(){
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	s = " " + s;
	
	cout<<1<<endl;
	int cnt = 0;
	int cnt2 = 0;
	
	for(int i = 0;i < s.size();i++){
		
		cnt += s[i] == '1';
		if(i > 0 && s[i] == '1' && s[i - 1] == '1')cnt2++;
		
		
	}
	
	if(cnt2 == 1){
		
		for(int i = 1;i < s.size();i++){
			if(s[i] == s[i - 1] && s[i] == '1'){
				
			   cout<<-i<<endl;
			   s[i] = '0';
			   s[i - 1] = '0';
			}
		}
		
		
		
	}else if(cnt == 2){
		for(int i = 1;i < s.size();i++){
			if(s[i] == '1'){
				cout<<-i<<endl;
				s[i] = '0';
				if(s[i - 1] == '1')s[i - 1] = '0';
				else s[i - 1] = '1';
			}
		}
		
	}else if(cnt == 1){
	
	
	   for(int i = 1;i < s.size();i++){
			if(s[i] == '1'){
				cout<<i<<endl;
				s[i] = '0';
			}
		}
	
	
	
	}else if(cnt & 1){
		for(int i = 1;i < s.size();i++){
			if(s[i] == '1'){
				cout<<-i<<endl;
				s[i] = '0';
				if(s[i - 1] == '1')s[i - 1] = '0';
				else s[i - 1] = '1';
			}
		}
	}else{
		
		for(int i = 1;i < s.size();i++){
			if(s[i] == '1'){
				cout<<i<<endl;
				s[i] = '0';
			}
		}
		
		
		
	}
	
	int x;
	while(cin>>x){
		
		if(x < 0){
				s[-x] = (s[-x] == '1' ? '0' : '1');
				s[-x - 1] = (s[-x - 1] == '1' ? '0' : '1');
			}else{
				
				s[x] = (s[x] == '0' ? '1' : '0');
				
		}
		
		 cnt = 0;
		 cnt2 = 0;
		
		for(int i = 0;i < s.size();i++){
			
			cnt += s[i] == '1';
			if(i > 0 && s[i] == '1' && s[i - 1] == '1')cnt2++;
			
			
		}
		
		if(cnt2 == 1){
			
			for(int i = 1;i < s.size();i++){
				if(s[i] == s[i - 1] && s[i] == '1'){
					
				   cout<<-i<<endl;
				   s[i] = '0';
				   s[i - 1] = '0';
				}
			}
			
			
			
		}else if(cnt == 2){
			for(int i = 1;i < s.size();i++){
				if(s[i] == '1'){
					cout<<-i<<endl;
					s[i] = '0';
					if(s[i - 1] == '1')s[i - 1] = '0';
					else s[i - 1] = '1';
				}
			}
			
		}else if(cnt == 1){
		
		
		   for(int i = 1;i < s.size();i++){
				if(s[i] == '1'){
					cout<<i<<endl;
					s[i] = '0';
				}
			}
		
		
		
		}else if(cnt & 1){
			for(int i = 1;i < s.size();i++){
				if(s[i] == '1'){
					cout<<-i<<endl;
					s[i] = '0';
					if(s[i - 1] == '1')s[i - 1] = '0';
					else s[i - 1] = '1';
				}
			}
		}else{
			
			for(int i = 1;i < s.size();i++){
				if(s[i] == '1'){
					cout<<i<<endl;
					s[i] = '0';
				}
			}
			
			
			
		}
		
		
	}
	
	
	
}