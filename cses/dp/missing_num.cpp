#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve()
{
    int n ; 
    cin >> n ; 
    vector< int> v(n-1) ; 
    for( int i = 0; i < n-1; i++){
        cin >> v[i] ; 
    }
    for(int i = 0; i < n-1 ; i++){
        while(v[i] != i+1  && v[i] < n && v[v[i]-1] != v[i]){
            swap(v[i], v[v[i]-1]) ; 
        }
    }
    int i = 0 ; 
    for(    ; i < n-1 ; i++){
        if(v[i] != i+1){
            cout<<i+1<<" " ; 
            break ; 
        }
    }
    if(i == n-1){
        cout<< n << endl ; 
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
