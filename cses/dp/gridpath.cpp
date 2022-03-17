#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve()
{
    int n ; cin >> n ; 
    vector<vector<char>>v(n) ; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c ; cin >> c ; 
            v[i].push_back(c) ;
        }
    }
    if(v[0][0] == '*'){
        cout<<0;
        return; 
    }
    vector<vector<int>>dp(n+1, vector<int>(n+1)) ; 
    for( int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0 ; 
            }else{
                if(i ==1 && j==1){
                    dp[i][j] =1  ; 
                    continue ; 
    
                }
                if(v[i-1][j-1] == '.'){
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1] )% (1000000007);
                }else{
                    dp[i][j] = 0 ;
                }
            }
        }
    } 
    cout<<dp[n][n] ; 
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
