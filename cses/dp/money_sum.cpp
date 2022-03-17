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
  
  int n ; cin >> n ; 
  vector<int>v(n) ; 
  for(auto &it : v){
      cin >> it ; 
  }
  int mxsum = n * 1000 ; 
  vector<vector<bool>>dp( n+1 , vector<bool>( mxsum+1 , 0)) ;
  dp[0][0] = true ; 
  for(int i = 1 ; i <= n; i++){
      for(int j = 0 ; j <= mxsum ; j++ ){
          dp[i][j] = dp[i-1][j] ; 
          int k = j- v[i-1] ; 
          if(k >= 0 && dp[i-1][k] ){
              dp[i][j] = true   ; 
           }
      }
  }
    vector<int>poss ; 
    for(int j= 1 ; j <= mxsum ; j++){
        if(dp[n][j] == true ){
            poss.push_back(j) ; 
        }
    }
    cout<<poss.size() << endl ; 
    for(auto it : poss){
        cout<< it<< " " ; 
    }

    return 0;
}
