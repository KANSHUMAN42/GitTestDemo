#include <bits/stdc++.h>
using namespace std;

class seats{ 
       vector<vector<bool>>(11 , vector<int>(7) ) ;

};

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif
   
 
   int total_seat = 80 ; 
   int avail_seat = 80 ; 
   vector<bool>avail(81) ; 
   avail[0] = true ; 
   int t ; cin >> t ; 
   while(t--){
       int numseat ; 
       cin >> numseat ; 
       if(numseat > 7 ){
           cout<<"you can reserve only 7 seat at  time ";
       }
       if(numseat == 7){
           int j = 80 ; 
           while(! avail[j] ){
                j = j-8 ; 
           }
           if(j>0){
               for(int k = j ; k > j-8 ; k--){
                   if(!avail[k]){
                   avail[k] = true ;
               }else{
                   cout<<"No compartment with 7 seats are empty ";
               }
           }
       }



   }


 
    return 0;
}
