#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007


int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

   string s , t ; 
   cin >> s >> t ; 
   int n = s.length() ; 
   int m = t.length() ;
   vector<vector<int>>dp(n+1,vector<int>(m+1, 0) ) ; 

   for(int i = 0 ; i <= n ; i++){
        dp[i][0] = i ; 
   }
   for(int i = 0 ; i <= m ; i++){
        dp[0][i] = i ; 
   }

   for(int i = 1 ; i <= n ; i++){
       for(int j = 1 ; j <= m ; j++){
           if(s[i-1] == t[j-1]){
              dp[i][j] = dp[i-1][j-1] ; 
           }else{
               int k = min(dp[i][j-1] , min(dp[i-1][j] , dp[i-1][j-1])) ;
               dp[i][j] = k + 1 ; 
           }
       }
   }
   cout << dp[n][m] << endl ; 
    return 0;
}
