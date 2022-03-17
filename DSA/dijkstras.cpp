#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
int n ; 
unordered_map<int, vector<pair<int,int>> > mp ;

int dijkstras(int src, int dest){
    
    vector<int>dist(n, INT_MAX ) ;
    dist[src] = 0 ;
    set<pair<int,int>> ss ; 
    ss.insert({0,src}) ; // wt , node 
    while( !ss.empty() ){
         auto f = *(ss.begin()) ;
         ss.erase(ss.begin()) ;
         cout<<f.second <<" "<<f.first<<endl ;
         for(auto child: mp[f.second]){
             if(dist[child.first] > dist[f.second] + child.second){
                 dist[child.first] = dist[f.second] + child.second ; 
                 ss.insert({dist[child.first], child.first}) ;
             }
         }
    }

    for(auto it : dist ){
        cout<< it<< " " ;
    }
    cout<<endl ;
    return dist[dest] ;

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
    mp[a].push_back({b, wt}) ; 
   mp[b].push_back({a, wt}) ;
}

  cout<<dijkstras(0, 5) ;

    return 0;
}
