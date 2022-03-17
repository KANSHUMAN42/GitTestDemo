
//based on tracing back by keeping the vis track ; 
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

 vector<vector<int>>mp ; 
 vector<bool>vis ; 
 vector<int>prnt ; 

 void dfs(int src , int p){
         prnt[src] = p ; 
         vis[src] = true ; 
         for(auto nbr : mp[src]){
             if(!vis[nbr]){
                 dfs(nbr, src) ; 
             }else if(nbr != p){
                 vector<int>cyc ; 
                 cyc.push_back(nbr)  ; 
                 int x = src ; 
                 while(prnt[x] != nbr){
                     
                   cyc.push_back(x) ; 
                    x = prnt[x] ;
                   
                 }
                 cyc.push_back(x) ;
                 cyc.push_back(nbr) ; 
                 cout<<cyc.size()<<endl ; 
                 for(auto it : cyc){
                     cout<<it+1<<" " ;
                 }
               exit(0) ;
             }
         }

 }
void solve(){

    int n , m ; 
    cin >> n >> m ; 
    mp.resize(n) ; 
    vis.resize(n,false) ;
    prnt.resize(n,-1) ;
    for(int i = 0 ; i < m ; i++){
        int a, b ; 
        cin >>  a >> b ; 
        mp[a-1].push_back(b-1) ; 
        mp[b-1 ].push_back(a-1) ; 
    }
    for(int i = 0 ; i < n; i++){
       if(!vis[i]) dfs(i,-1) ; 
    }
    cout<<"IMPOSSIBLE\n" ;
     
    
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















/*#include <bits/stdc++.h>// based on dsf and cycle detection
using namespace std;
#define int long long 
#define mod 1000000007
vector<bool>vis;
bool findcycle(int src , vector<vector<int>>&mp , int p , int baap,vector<int>&stk){
    vis[src] = true ; 
    stk.push_back(src) ;
    for(auto nbr : mp[src]){
        if(!vis[nbr]){
          bool cycle =  findcycle(nbr, mp, src, baap, stk );
          if(cycle)return true ; 
        }else if(nbr != p  && nbr == baap){
           return true ;
        }
    }
    stk.pop_back() ;
    vis[src] = false ; 
    return false ; 
}

void solve(){
    int n , m ; 
    cin >> n >> m ; 
    vector<vector<int>>mp(n) ; 
    vis = vector<bool>(n,false) ;
    for(int i = 0 ; i < m ; i++){
        int a, b ; 
        cin >> a >> b; 
        mp[a-1].push_back(b-1) ; 
        mp[b-1].push_back(a-1) ; 
    }
    bool found = false ;
    for(int i = 0 ; i < n ; i++){
        if(!found){
            vector<int>stk ;
        bool temp = findcycle(i, mp,-1,i, stk) ; 
        if(temp) {cout<<stk.size()+1<<endl ;
        for(auto it : stk){
            cout<<it+1<<" " ;
        }
        cout<<i+1;
        found = true ; 
        } 
    }

    }

}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

    int test=1;
    while(test--){
        solve();
    }
    return 0;
}
*/