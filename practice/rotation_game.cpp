#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

vector<int>ComputeKmp( string str){
   int n = str.size() ; 
   vector<int>lps(n,0) ; 
   int i =1 , j = 0; 
     while(i<n){
       if(str[i] == str[j]){
           lps[i++] = ++j ; 
       }else{
           j ? (j= lps[j-1]): i++ ;
       }
   }
   return lps ;
}

void solve()
{
    int tc ; cin >> tc ; 
    while(tc--){
    string s , t ; 
    cin >> s >> t ; 

     t = t + t; 
    int m = s.size(); 
    int n = t.size() ;
    vector<int>lps(ComputeKmp(t)) ; 
    int i = 0, j = 0 ; 
    bool flag = false ;
    int idx = -1 ; 
    while(i < n ){
        if(t[i] == s[j]){
            i++ ; 
            j++ ;
        if(j == m){
           idx = i- m ; 
            flag = 1 ;
            break ; 
        }
        }else{
            j ? j = lps[j-1] :i++ ;
        }
    }
if(!flag ){
    cout <<"foul" <<  endl ;
}else{
    cout<<i-m <<endl ;
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
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
