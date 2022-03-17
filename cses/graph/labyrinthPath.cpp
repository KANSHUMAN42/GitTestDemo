#include <bits/stdc++.h>
using namespace std;
#define int long long 
  int dxy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}} ;
  string dir ="URDL" ;
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

    int n ; cin >> n ; 
    int m ; cin >> m ; 
    vector<string>v(n) ; 
    for(auto &it : v){
        cin >> it ; 
    }
    vector<vector<int>>prev(n,vector<int>(m,-1)) ; 
    int cnt = 0 ; 
    pair<int,int>strt ,end ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ;j++){
            if(v[i][j] == 'A'){
              strt ={i,j} ;
             }
             else if(v[i][j] == 'B'){
                end = {i,j} ;
             }
        }
    }
    vector<vector<bool>>vis(n , vector<bool>(m,false)) ;
    
    //bfs
    queue<pair<int,int>>q ; 
    vis[strt.first][strt.second] = true ;
    q.push(strt) ; 
    while(!q.empty()){
        pair<int,int> f = q.front() ; 
        int a = f.first ; 
        int b = f.second ; 
        q.pop() ; 
      
       for(int i = 0 ; i < 4 ; i++){
           int x = dxy[i][0] + a ; 
           int y = dxy[i][1] + b ; 
           if( x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || v[x][y] == '#' ) continue ;
        
          q.push({x,y}) ; 
           vis[x][y] = true ; 
           prev[x][y] = i ; 
       }
    }

    if(vis[end.first][end.second] ){
        cout<< "YES" ;
        string ans ; 
        int x = end.first , y = end.second  ;
        int a = strt.first , b = strt.second ;
       // cout<<a <<" "<< b <<x<<" "<<y<<endl ;

         while(prev[x][y] !=-1 ){
             int i = prev[x][y] ;
             ans += dir[i] ;
             //cout<<prev[x][y] <<"->" ;
             x = x - dxy[i][0] ; 
             y = y - dxy[i][1] ;
             
           
         }
         cout<<endl ;
          reverse(ans.begin(),ans.end()) ;
         cout<<ans.size() <<endl << ans <<endl ;
        
    }else{
        cout<<"NO" ; 
    }
    cout<<endl  ;

    return 0;
}
