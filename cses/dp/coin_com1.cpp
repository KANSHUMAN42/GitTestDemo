#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve()
{
    int n ; cin >> n ; 
    int sum  ; cin >> sum ; 
    vector<int> v(n);
        for(int i = 0 ; i < n ; i++ ){
            cin >> v[i] ;
        }
    vector<int>dp(sum+1, 0) ;
    dp[0] = 1 ; 
    for(int i = 1 ; i <= sum ; i++){
       for(auto it : v){
           if(i-it >= 0 ){
               dp[i]  = (dp[i] + dp[i-it]) % 1000000007 ; 
           }
       }
    }
    cout<<dp[sum] ; 
    
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
