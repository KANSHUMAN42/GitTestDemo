#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve(){
    int n ; 
    cin >> n ; 
    vector<int>v(n) ; 
    for(auto &it : v){
        cin>>it ; 
    }
    int k ; cin >> k ; 
   //yha tk input hai 


// yha se ans 
 reverse(v.begin(), v.end()) ;
    int op = 0 ; 
    for(int i = 0 ; i <= k ; i++){
        cout<<i<<"-->";
        
        for(int j = i ; j < n-k ; j+=k){
           if(v[j] < v[j+k]){
               v[j+k] = v[j] ;
               cout<<j<<" -- "<< j+k <<endl ;
               op++ ; 
           }else{
               cout<<"here";
               continue ;
           }
        }
    }
    cout<<op <<endl ;
    // yha tk hai

}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

    int test;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
