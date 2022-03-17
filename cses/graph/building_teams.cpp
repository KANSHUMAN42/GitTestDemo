#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
bool notpos = false ;
void bfs(vector<vector<int>>&mp, vector<int>&color, int src){
    int n = mp.size() ;
    int flag = 0 ; 
    queue<int>q ; 
    color[src] = flag ; 
    q.push(src) ;
   
    while( !q.empty() ){
        auto f = q.front() ; 
        q.pop() ; 
        if(notpos)continue ; 
        for(auto nbr : mp[f]){
            if(color[nbr] == -1){
               color[nbr] = 1 - color[f] ;
               q.push(nbr) ;
            }else{
                if(color[nbr] == color[f]){
                    notpos = true ; 
                    break ; 
                }
            }
        }

    }

}


void solve(){
    int n , m ; 
    cin >> n >> m ; 
    vector<vector<int>>mp(n) ; 
    for(int i = 0 ; i < m ; i++){
        int a, b ; 
        cin >> a >> b ; 
        mp[a-1].push_back(b-1) ; 
        mp[b-1].push_back(a-1) ; 
    } 
    vector<int>color(n,-1) ; 
    for(int i = 0 ; i < n; i++ ){
         if(color[i] == -1 && !notpos){
             bfs(mp,color,i) ;
         }
    }
    if(notpos){
        cout<<"IMPOSSIBLE"<<endl ; 
        return ;
    }
    for(auto it : color){
        cout<<it+1<<" " ; 
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
