#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve()
{
  string s ; cin >> s ; 
  int n = s.length() ; 
  int cnt = 1 ; 
  int ans = 1 ; 
  for( int i = 1 ; i < n ; i++){
      if(s[i] == s[i-1]){
          cnt++  ;
           
      }else{
          cnt = 1 ; 
      }
       ans = max( ans, cnt ) ;
  }  
  cout<<ans ; 
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
