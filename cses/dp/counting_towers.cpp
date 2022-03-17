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
int t ; cin >> t ; 
while(t--){
    int n ; cin >> n ; 
    vector<vector<int>>dp(n+1,vector<int>(3,0)) ; 
    dp[1][1] = dp[1][2] = 1  ;
    for(int i = 2 ; i <= n ; i++){
          dp[i][1] = (dp[i-1][1]*4 + dp[i-1][2]) % mod ; 
          dp[i][2] =  (dp[i-1][1] + dp[i-1][2]*2) % mod ; 

    }
    cout<<  dp[n][1] + dp[n][2]% mod  <<endl ; 
}

return 0;
}
