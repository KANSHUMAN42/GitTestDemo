#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007


void solve(){
    int n ; cin >> n; 
    //cout<< recur(n) ; 
    vector<int>arr(n+1,0) ; 
    arr[0] = 1; 
     arr[1] =  1 ; 
    for(int i = 2 ; i <= n ; i++){
        for( int j = 1 ; j <= 6 ; j++){
            if( i - j >= 0 ){
                arr[i] = (arr[i]+ arr[i-j]) % (1000000007) ; 
            }
        }
    }
    cout<<arr[n]  << endl ; 
    
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
