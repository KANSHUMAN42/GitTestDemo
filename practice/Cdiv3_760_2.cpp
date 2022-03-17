#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

class DSU{
    public :    
    vector<int> v ; 
    int n ; 
    int cmp ; 
    DSU(int m){
        v = vector<int>(m, -1) ; 
        cmp = n ; 
    }

    int find(int a){
        if(v[a] == -1){
            return a ; 
        }
        return find(v[a]) ; 
    }
    void merge(int a, int b){
       int x = find(a) ; 
       int y = find(b) ; 
       if(x != y){
           if(v[x] > v[y]){
               swap(v[x], v[y]) ;
           }
           v[x] = y ; 
       }
       cmp -- ; 
    }
}; 

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif


  
    return 0;
}
