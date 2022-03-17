#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

int n ; 
unordered_map<int,vector<pair<int,int>> >mp ; 

int Prims_Mst(){
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq ;
    vector<bool>vis(n, false)  ;
    pq.push({0,0}) ; 
    int ans  = 0 ; 
    while(!pq.empty()){
        auto f = pq.top() ; 
         pq.pop() ; 
         if(vis[f.second])continue ; 

         ans += f.first ;
         vis[f.second] = true ;
         for(auto it : mp[f.second]){
           if(!vis[it.first]){
            pq.push({it.second , it.first}) ;
           }
         }
    }
return ans ;
}


int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

cin >> n ;
int m ; cin>> m ; 
for(int i = 0 ; i < m ; i++){
    int a , b , wt; 
    cin >> a >> b >> wt; 
    mp[a-1].push_back({b-1, wt}) ; 
    mp[b-1].push_back({a-1, wt}) ;
}

cout<<Prims_Mst()<<endl ;
  
    return 0;
}

// 3 3
// 1 2 5 
// 1 3 6 
// 2 3 1 