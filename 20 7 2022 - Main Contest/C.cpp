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
	
	int t;
	cin>>t;
	
	
	while(t--){
		int l,r;
		cin>>l>>r;
		
		
		if(r <= 1000){
			int cnt = 0,res = 0;
		    for(int i = l;i <= r;i++){
			    string s = to_string(i);
			    
			    if(s.size() == 2){
			    	if(res == 2){
			    		
			    		if(s[0] < s[1])cnt++; 
			    		
			    		
			    	}else{
			    		if(s[0] < s[1])cnt = 1,res = 2;
			    	}
			    }else if(s.size() == 3){
			    	
			    	if(res == 3){
			    		
			    		if(s[0] < s[1] && s[1] < s[2])cnt++;
			    		
			    		
			    	}else{
			    		
			    		if(res == 2){
			    			if(s[1] < s[2])cnt++;
			    			if(s[0] < s[1])cnt++;
			    			if(s[0] < s[2])cnt++;
			    		}else{
			    			res = 2;
			    			cnt = 0;
			    			if(s[1] < s[2])cnt++;
			    			if(s[0] < s[1])cnt++;
			    			if(s[0] < s[2])cnt++;
			    		}
			    		
			    		
			    	}
			    	
			    	
			    }
			    
			    
		    }
		    
		    cout<<res<<" "<<cnt<<"\n";
		}
	}	
	
	
	
	
}