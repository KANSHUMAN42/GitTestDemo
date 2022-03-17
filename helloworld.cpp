#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve()
{
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    vector<int> v(n) ; 
    for(auto &i : v){
        cin >> i ; 
    }
    vector<vector<int>> dp(n , vector<int>(m+1, 0 )) ; 
    if(v[0] == 0 ){
        for(int i = 1 ; i <= m ; i++ ){
            dp[0][i] = 1; 
        }
    }else{
        dp[0][v[0]] = 1  ; 
    }
    for(int i = 1 ; i < n; i++){
         if(v[i] == 0){
             for(int j = 1 ; j <= m ; j++){
                 if(dp[i-1][j]  > 0){
                  dp[i][j] += dp[i-1][j] ; 
                  if(j - 1 > 0) dp[i][j]+= dp[i][j-1] ;
                  if(j+1 <=m ) dp[i][j] += dp[i][j+1] ; 
                   dp[i][j] = dp[i][j]%(1000000007)  ; 
                 }
             }
         }else{
             int j = v[i] ; 
            dp[i][j] += dp[i-1][j] ; 
            if(j-1 > 0) dp[i][j]+= dp[i-1][j-1] ; 
            if(j+1 <= m ) dp[i][j+1] += dp[i-1][j+1] ; 
            dp[i][j] = dp[i][j]%(1000000007) ; 
         }

    }
    int ans = 0 ; 
    for(int j = 1 ; j <= m ; j++){
          ans += dp[n-1][j] ; 
          ans = ans % (1000000007) ; 
    }
    cout << ans << endl ;     
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
