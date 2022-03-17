#include <bits/stdc++.h>
using namespace std;

void  solve()
{
    int n; 
    cin >> n; 
    unordered_map<int,vector<int>>mp ;
    for(int i = 1;  i <= n; i++){
        int a ; 
        while(cin >> a ){
            mp[i].push_back(a) ; 
        }
    }
    int s , e ; 
    cin >> s >> e ; 
    int cnt = 0 ; 
    queue<int>q ; 
    q.push(s) ; 
   
    vector<bool>vis(n);
     vis[s] = true ;
    bool flag = false ; 
    while(!q.empty()){
        int sz = q.size() ; 
        if(flag){
            break ; 
        }
        while(sz--){
        auto f = q.front() ; 
        q.pop() ; 
        if(f == e){
            flag = true ;
            break ;
        }
        for(auto it : mp[f]){
            if(!vis[it]){
                vis[it] = true; 
                q.push(it) ;
            }
        }
    }
    cnt++ ; 
    }
    if(flag){
    cout<<cnt+1 << endl ;
    }else{
        cout<< -1<<endl ;
    }
    
}
int main() {
 solve() ;
    return 0;
}
