#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve()
{  
    int n; 
    cin >> n ; 
    cout<<n<<" " ; 
    while(n > 1 ){
        
        if(n&1){
            n = n * 3 + 1 ;
        }else{
            n = n / 2 ; 
        }
        cout<< n <<" " ; 
    }
    cout<<endl ; 
    
    
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
