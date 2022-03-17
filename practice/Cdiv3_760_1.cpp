#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

string replace_str(string str, int a , int b ){
	string c ;
        char ch = str[a] ; 
		for(int i = 0 ; i < str.size() ; i++ ){
			if(str[i] == ch){
                 str[i] = b +'a' ; 
			}
		}
		c= str ; 
		return c ;
}

void solve()
{
 vector<string>sarr ; 
 string istr ; 
 cin >> istr ; 
 stringstream s(istr ) ; 
 string word ; 
 while(s>> word){
	 sarr.push_back(word) ; 
 }

 int m ; 
 cin >> m  ;
 vector<vector<int>>varr( m  ,vector<int>(2,0)) ; 
 for(int i =0 ; i < m ; i++){
   int a, b ; 
   cin >> a>>b ; 
   varr[i][0] = a ; 
   varr[i][1] = b  ; 
   string ch = replace_str(sarr[i], a, b) ; 
   sarr[i]= ch ; 
 } 
 string ans ; 
 map<char,int>mp  ; 
 mp['a']++ ;
 mp['e']++ ; 
 mp['i']++ ; 
 mp['o']++ ; 
 mp['u']++ ;
 map<int,int>mp2 ; 
 int ansidx = m+1  ; 
 int mxcnt = INT_MAX ;
 for(int i = 0 ; i < m ; i++){
	 int cnt  = 0 ; 
    for(int j = 0 ; j < sarr[i].size() ; j++){
		if(!mp.count(sarr[i][j])){
			cnt ++ ; 
		}

	}
	if(cnt < mxcnt){
		ansidx= i ; 
		mxcnt = cnt ; 
	}
 }
 cout<<sarr[ansidx]<<endl  ; 


 
	
}
int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
	freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

	int test=1;
//cin>>test;
	while(test--)
	{
		solve();
	}
	return 0;
}
