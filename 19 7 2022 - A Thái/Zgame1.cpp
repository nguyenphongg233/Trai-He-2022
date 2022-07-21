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
int x = 0;
int cnt[2];
signed main(){
	
	cin>>n>>s;
	
	int id = 0;
	
	for(int i = 0;i < s.size();i++){
		
		cnt[i % 2] += (s[i] == '1');
		
	}
	
	 
	if(cnt[0] % 2 == 0 && cnt[1] % 2 == 0){
		cout<<"0"<<endl;
		int x;
		cin>>x;
		x--;
		
		if(x < 0){
			
			cnt[abs(x + 1) % 2] += (s[-x-1] == '1' ? -1 : 1);
			s[-x] = (s[-x] == '1' ? '0' : '1');
			s[-x - 1] = (s[-x - 1] == '1' ? '0' : '1');
				
			
			
				
		}else{
				
			s[x] = '0';
				
		}
		
		cnt[abs(x) % 2]--;
		
		
	}else cout<<1<<endl;
	
	while(cnt[0] > 0 || cnt[1] > 0){
		
		
		if(cnt[0] + cnt[1] == 3){
			
			bool ok = 0;
			for(int i = 1;i < s.size() - 1;i++){
				if(s[i] == '1' && s[i - 1] == '1' &&s[i + 1] == '1'){
					
					s[i] = '0';
					cnt[i % 2]--;
					cout<<i + 1 <<endl;
					
					ok = 1;
					break;
				}
			}
			
			if(!ok){
				
				for(int i = 0;i < s.size();i++){
					
					if(s[i] == '1'){
						s[i] = '0';
						cnt[i % 2] --;
						cout<<i + 1<<endl;
						break;
					}
					
			    }
				
			}
			
			
	    }else if(cnt[0 + cnt[1] == 2]){
	    	
	    	
	    	
			bool ok = 0;
			for(int i = 1;i < s.size();i++){
				if(s[i] == '1' && s[i - 1] == '1'){
					
					s[i] = '0';
					cnt[i % 2]--;
					cout<<-(i + 1) <<endl;
					
					return 0;
				
				}
			}
			
			if(!ok){
				
				for(int i = 0;i < s.size();i++){
					
					if(s[i] == '1'){
						s[i] = '0';
						cnt[i % 2] --;
						cout<< - abs(i + 1)<<endl;
						
						
						cnt[(i + 1) % 2]--;
						
						
						if(s[i - 1] == '0')cnt[(i + 1) % 2]+=2;
						
						break;
					}
					
			    }
				
			}
			
			
	    	
	    	
	    	
	    
	    
	    }
		if(cnt[0] & 1 && cnt[1] & 1){
			
			for(int i = 1;i < s.size();i++){
				if(s[i] == '1' && s[i - 1] == '1'){
					
					s[i] = '0';
					s[i - 1] = '0';
					
					cnt[0]--;
					cnt[1]--;
					
					cout<<-(i + 1)<<endl;
					break;
				}
			}
			
		}
		else if(cnt[0] & 1 && !(cnt[1] & 1)){
			
			
			for(int i = 0;i < s.size();i++){
				
				if(i % 2 == 0 && s[i] == '1'){
					s[i] = '0';
					cnt[0]--;
					cout<<i + 1<<endl;
					break;
				}
				
			}
			
			
		}else if(cnt[0] % 2 == 0 && cnt[1] % 2 == 1){
			
			for(int i = 0;i < s.size();i++){
				
				if(i % 2 == 1 && s[i] == '1'){
					s[i] = '0';
					cnt[1]--;
					cout<<i<<endl;
					break;
				}
				
			}
			
		}
		
		
		
		
		
		
		
		
		
		
		
		
		cin>>x;
			
		if(x < 0){
			
			cnt[abs(x + 1) % 2] -= (s[-x-1] == '1');
			s[-x] = (s[-x] == '1' ? '0' : '1');
			s[-x - 1] = (s[-x - 1] == '1' ? '0' : '1');
				
			
			
				
		}else{
				
			s[x] = '0';
				
		}
		
		cnt[abs(x) % 2]--;
		
		
	}
	
	
	
}