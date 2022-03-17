//Algorithm for string matching 
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

//compute lps array 
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

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

string s, t ; 
cin>>s >>t ; 
//find if(s is present in t  ) 
vector<int>lps(ComputeKmp(s)) ;
for(auto it : lps){
    cout<<it ;
}
cout<<endl ;
int n = t.length() ;
int m  = s.length() ; 
int i = 0, j = 0 ; 
bool flag = false ;
while(i < n ){
    if(t[i] == s[j]){
        i++ ; 
        j++ ;
    if(j == m){
        cout<< i-m <<endl ;
        flag = 1 ;
        break ; 
    }
    }else{
        j ? j = lps[j-1] :i++ ;
    }
}
if(flag ){
    cout <<"Mil gya hai" <<  endl ;
}

    return 0;
}
