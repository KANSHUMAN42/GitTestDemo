/*
This is a n2 solution 

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
    vector<tuple<int,int,int>> v(n) ; 
    for(int i = 0 ; i < n ; i++){
        int a, b, c ; 
        cin >> a >> b >> c ; 
        v[i] = {a , b, c} ; 
    }
    sort(v.begin(), v.end(), [&](tuple<int,int,int> &a , tuple<int,int,int> &b ){
     if(get<0>(a) == get<0>(b)){

         if(get<1>(a) == get<1>(b)){
             return get<2>(a) > get<2>(b) ; 
         }
         return  get<1>(a) < get<1>(b) ;  
     }
     return get<0>(a) < get<0>(b) ; 
    }) ; 

    vector<int>dp(n) ;
    int ans = 0  ;
    for(int i = 0 ; i< n ; i++){
         dp[i] = get<2>(v[i]) ; 
         ans = max(ans, dp[i]) ; 
    } 
    for(int i = 1 ; i < n; i++){
         for(int j = 0 ; j < i ; j++){
           if(get<1>(v[j]) < get<0>(v[i]) && dp[j]+ get<2>(v[i]) >dp[i] ){
                dp[i] = dp[j]+ get<2>(v[i])  ; 
                ans = max(ans, dp[i]) ; 
           }
         }
    }
    cout<<ans<<endl ; 


    return 0;
}
*/
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
    int  n ; 
    cin >> n ; 
    vector<tuple<int,int,int>> v(n) ; 
    for(int i = 0 ; i < n ; i++){
        int a, b, c ; 
        cin >> a >> b >> c ; 
        v[i] = {a , b, c} ; 
    }
    sort(v.begin(), v.end(), [&](tuple<int,int,int> &a , tuple<int,int,int> &b ){
     if(get<0>(a) == get<0>(b)){

         if(get<1>(a) == get<1>(b)){
             return get<2>(a) > get<2>(b) ; 
         }
         return  get<1>(a) < get<1>(b) ;  
     }
     return get<0>(a) < get<0>(b) ; 
    }) ; 
    vector<int>ans; 
    
 
    return 0;
}
