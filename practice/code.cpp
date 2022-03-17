#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void solve()
{
    
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

   int n ; cin >> n; 
   vector<int> v (n) ; 
   for(int &i : v){
       cin >> i ; 
   }
   for(int i = 0 ; i < n ; i++){
       for(int j = 2*(i)+1 ;   j < n ; j+=(i+1)){
        if(v[j]- v[i] > 0) v[j]-= v[i] ;
        cout<< j<<" " ; 
       }
       cout<<endl ; 
   }
   for(auto it : v){
       cout<< it<<" " ; 
   }
    return 0;
}
