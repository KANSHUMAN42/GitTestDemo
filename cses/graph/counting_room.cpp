#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

void dfs(vector<string>&v , int i, int j){
    int n = v.size() ; 
    int m = v[0].size() ; 
    v[i][j] = '#' ; 
    int dxy[4][2] = {{-1,0},{0,-1}, {1,0},{0 ,1}} ; 
    for(auto it : dxy){
        int x = i + it[0] ; 
        int y = j + it[1] ;
        if(x >= 0 && y>=0 && x<n && y<m &&   v[x][y] == '.'){
           dfs(v, x,y) ;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif
    int n ; cin >> n; 
    int m ; cin >> m  ; 
    vector<string>v(n) ; 
    for(auto &it : v){
        cin >> it ; 
    }
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< m ;j++){
            if(v[i][j] == '.'){
                cnt++ ; 
                dfs(v, i , j) ;
            }
        }
    }
    cout<<cnt<<endl ;
  
    return 0;
}
