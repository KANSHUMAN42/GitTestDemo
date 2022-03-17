#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

void dfs(vector<vector<int>>&v , int src , vector<bool>&vis ){
    
    vis[src] = true ; 
    for(auto nbr : v[src]){
        if(!vis[nbr]){
        dfs(v,  nbr , vis ) ;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif
    int n , m ; 
    cin >> n >> m ; 
    vector<int>ans ; 
    vector<vector<int>>v(n) ; 
    for(int i = 0 ; i < m ; i++){
        int a, b ; 
        cin >> a >> b ; 
        v[a-1].push_back(b-1) ;
        v[b-1].push_back(a-1) ; 
    }
     vector<bool>vis(n) ; 
     for(int i = 0 ; i < n ; i++){
         if(!vis[i]){
             ans.push_back(i) ; 
             dfs(v, i, vis) ;
         }
     }
     sort(ans.begin(),ans.end()) ;
     if(ans.size() > 1){
         cout<<ans.size()-1<<endl  ;
         for(int i= 1 ; i<ans.size() ; i++){
             cout<<ans[i]+1<<" "<<ans[i-1]+1 <<endl ; 
         }
     }else{
         cout<<0<<endl ;
     }


   
    return 0;
}
