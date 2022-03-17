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

   int n ; 
   cin >> n ; 
   vector<int>v(n) ; 
   int sum = 0 ; 
   for(auto &i : v){
       cin >> i;
       sum += i ; 
   }
  
   vector<vector<int>>dp(n, vector<int>(n,0))  ;
  
       for(int i = n-1 ; i >= 0 ; i--){
           for(int j = i ; j < n ; j++){
              if(i == j){
                  dp[i][j] = v[i] ;
              }else{
                  dp[i][j] = max( v[i] - dp[i+1][j] ,v[j] - dp[i][j-1] ) ;
              }
           }
       }
   
   cout << (sum + dp[0][n-1]) /2 <<endl ; 

    return 0;
}
