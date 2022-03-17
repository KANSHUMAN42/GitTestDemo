#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve()
{  
    int n ; cin >> n ; 
    vector<int>dp( n+1 , INT_MAX)  ; 
    dp[0] = 0 ; 
    int temp = n ; 
    for(int i = 1 ; i <= n ; i++){
            int c = i;
            while(c>0){
                int r = c%10 ; 
                if(i - r>=0){
                    dp[i] = min(dp[i] , dp[i-r] + 1) ; 
                }
                c = c/10 ; 
            } 
    }
    cout << dp[n] ;
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
