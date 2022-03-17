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
    int n ; cin >> n;
    int val = n*(n+1)/2 ;  
    if(val%2 == 1){
      cout<<0<<endl  ;
      return 0 ;
    } 
    val = val / 2; 
    vector<vector<int>>dp(val+1 , vector<int>(n + 1)); 
    dp[0][0] = 1  ;
     for(int i = 1 ; i <= val ; i++){
         for(int j = 1 ; j <= n ; j++ ){
             dp[i][j] = dp[i][j-1] ; 
             int p = i - j ;
             if(p >= 0){
                 dp[i][j] += dp[p][j-1] % mod  ; 
             } 
         }
     }
     cout << dp[val][n] % mod <<endl ;  
  
    return 0;
}
