#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve(){
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    vector<vector<int>>mp(n) ; 
    for(int i = 0 ; i < m ; i++){
        int a , b ; 
        cin >> a >> b ; 
        mp[a-1].push_back(b - 1) ; 
        mp[b-1].push_back(a - 1) ; 
    }
    vector<int>prev(n,-1) ; 
    queue<int>  q ; 
    vector<bool>vis(n,false) ; 
    q.push(0) ; 
    vis[0] = true ; 
    bool found = false ; 
    int ans = 0 ; 
    while(!q.empty()){
        int sz = q.size() ; 
       
        auto f = q.front() ; 
        q.pop() ; 
         if(f == n-1){
            found = true ; 
         }
         if( found ){
           continue ; 
         }
         for(auto nbr : mp[f]){
             if( !vis[nbr] ){
                 vis[nbr] = true ; 
                 q.push(nbr) ; 
                 prev[nbr] = f ; 
             }
         } 
         
      
    }
    if( prev[n-1] == -1 ){
        cout << "IMPOSSIBLE" << endl ;
    }else{
        int cnt = 0 ; 
        vector<int> v_ans ; 
        int temp = n-1 ;
        while( prev[temp] != -1){
            v_ans.push_back(temp+1) ; 
            temp = prev[temp] ;
        }
        v_ans.push_back(1) ;
        cout<<v_ans.size()  <<endl ; 
        reverse(v_ans.begin(), v_ans.end()) ; 
        for(auto it : v_ans){
            cout<<it<<" " ;
        }
        cout<<endl ; 

    }


    
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

    int test=1;

    while(test--)
    {
        solve();
    }
    return 0;
}
