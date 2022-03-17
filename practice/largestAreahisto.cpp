#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve(){
    int n ; cin >> n; 
    vector<int>v(n) ; 
    for(auto &it : v){
        cin >>  it ; 
    }
    stack<int>stk ; 
    
    vector<int>nextS_left(n, -1 ) , nextS_right(n,n) ; 
    for(int i = 0; i <  n; i++){
         if( !stk.empty() && v[stk.top()] >= v[i] ){
             stk.pop() ; 
         }
         if(stk.empty()){
             nextS_left[i] = -1 ; 
         }else{
         nextS_left[i] = stk.top() ;
         }
         stk.push(i) ; 
    }
     stack<int>s; 
     stk = s ; 
    for(int i = n-1 ; i >= 0 ; i--){
        if( !stk.empty() && v[stk.top()] >= v[i] ){
             stk.pop() ; 
         }
         if( stk.empty() ){
             nextS_right[i] = n ; 
         }else{
         nextS_right[i] = stk.top() ;
         }
         stk.push(i) ; 
    }

    for(auto it : nextS_left){
        cout<< it<<" " ;
    }
    cout<<endl ; 
    for(auto it : nextS_right){
        cout<< it <<" " ; 
    }
    cout<<endl ;
    
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
