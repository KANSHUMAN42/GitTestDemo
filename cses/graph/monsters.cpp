#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define f first
#define s second 
#define mod 1000000007
pair<int,int>strt ; 


void solve(){
    int n , m ; 
    cin >> n >> m ; 
    vector<string>v(n) ;
    for(int i = 0 ; i < n ; i++){
        string str ; 
        cin >> str ; 
    } 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            if(v[i][j] == 'A'){
                strt.f = i ; 
                strt.s = j ; 
            }
        }
    }
    vector<pair<int,int>>vp(n) ; 
    for(int i = 0 ; i <  n ; i++){
        for(int j = 0 ; j <  m ; j++){
            if(i==0 ){
                if(v[i][j]== '.'){
                    vp.push_back({i,j}) ; 
                }
            }else if(i == n-1){
                   if(v[i][j]== '.'){
                    vp.push_back({i,j}) ; 
                }
            }
            else if(j == 0){
                if(v[i][j]== '.'){
                    vp.push_back({i,j}) ; 
                }

            }else if(j == v[0].size()-1){
                if(v[i][j]== '.'){
                    vp.push_back({i,j}) ; 
                }

            }
        }
    }
    int dxy[4][2] = { {1,0}, {-1,0},{0,-1},{0,1}} ; 
    string pp = "DULR";

    for(int i = 0; i < vp.size(); i++){
        pair<int,int>p = vp[i] ; 
        queue<pair<int,int>>q ; 
        vector<vector<bool>>vis(n , vector<bool>(m , false) ) ;
        q.push(p) ;
        vis[p.f][p.s] = true ; 
        bool found = false ; 
        vector<vector<int>>prnt(n, vector<int>(v[0].size(),-1)) ;
        while(!q.empty()){
            auto  frnt = q.front() ; 
            q.pop() ; 
            if(found )continue ; 

            if(prnt[frnt.f][frnt.s] == 'A'){
              found = true ; 
              cout<<"YES" ;
              string ansStr = "" ;
              pair<int,int>tmp = frnt ; 
              while(prnt[tmp.f][tmp.s] != -1){
                  int k = prnt[tmp.f][tmp.s] ;
                  tmp.f = tmp.f - dxy[k][0] ;
                  tmp.s = tmp.s - dxy[k][1] ;
                  ansStr += pp[k] ;
                  
              }
              cout<<ansStr.size()<<"\n" <<ansStr<<endl ;

            }else if(prnt[frnt.f][frnt.s] == 'M'){
                   found = true ; 
            }
        
            for(int k = 0 ; k < 4 ; k++){
               int x = frnt.f + dxy[k][0] ; 
               int y = frnt.s + dxy[k][1] ;
               if(x < 0 || x >= n || y < 0 || y >= v[0].size() ||
                v[x][y] == '#' || vis[x][y]){
                    continue ; 
                }
                prnt[x][y] = k ; 
                 q.push({x,y})  ;

            }
        }



    //bfs over
    }

    


    
    
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
