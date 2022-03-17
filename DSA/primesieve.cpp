#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007 

void solve(){
    vector<int>v( 100 , 0) ; 
    for(int i = 2 ; i < 100 ; i++){
          for(int j = i * i  ; j < 100 ; j+=i){
                v[j] = 1 ; 
          }
    }
    for(int i = 2 ; i < 30 ; i++ ){
        if(v[i] == 0){
            cout<< i <<endl ; 
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

    while(test--)
    {
        solve();
    }
    return 0;
}
