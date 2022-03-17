#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve()
{
    
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

    int n ; cin >> n ; 
    vector<int> v(n) ; 
    for( auto &it : v){
        cin >> it ; 
    }
    vector<int>ans ; 
    ans.push_back(v[0]) ; 
    for(int i = 1 ; i < n; i++){
        int idx = lower_bound(ans.begin(), ans.end() , v[i] ) - ans.begin() ; 
        if(idx < ans.size()){
           ans[idx] = v[i] ;
        }else{
            ans.push_back(v[i]) ; 
        }
    }
    cout<<ans.size() ; 
    return 0;
}
