#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// long  highProfit(int n , vector<int>v, int sup){
//     priority_queue<pair<int,int>> pq ;
//     //num cnt
//     unordered_map<int,int>freq ; 
//     for(auto it : v){
//         freq[it]++ ;
//     }
//     for(auto it : freq){
//         pq.push({it.first,it.second}) ;
//     }
//     int ans = 0 ; 
    
//     while(sup!=0 && !pq.empty()){
//         pair<int,int> p = pq.top() ;
//         cout<<p.first<<" "<<p.second<<endl  ;
//         pq.pop() ;

//         if(p.second <= sup){
//            ans+= p.second*p.first ;
//            sup-= p.second ;
//            if(p.first>=1){
//            pq.push({p.first-1,p.second});
//            }
//         }else{
//           ans+= sup * p.first ;
//           sup = 0; 
//            if(p.first>=1){
//            pq.push({p.first-1,p.second});
//            }
//         }
//     }
//     return ans ;


//}


long highestProfit(int n , vector<long>v, long sup){
    priority_queue<pair<int,int>> pq ;
    //num cnt
    unordered_map<int,int>freq ; 
    for(auto it : v){
        freq[it]++ ;
    }
    for(auto it : freq){
        pq.push({it.first,it.second}) ;
    }
    long ans = 0 ; 
    
    while(sup!=0 && !pq.empty()){
        pair<int,int> p = pq.top() ;
       // cout<<p.first<<" "<<p.second<<endl  ;
        pq.pop() ;

        if(p.second <= sup){
           ans+= p.second*p.first ;
           sup-= p.second ;
           if(p.first >= 1){
           pq.push({p.first-1,p.second});
           }
        }else{
          ans+= sup * p.first ;
          sup = 0; 
           if(p.first >= 1){
           pq.push({p.first-1,p.second});
           }
        }
    }
    return ans ;


}

void solve()
{
    int  n ; cin>> n; 
    vector<long>v(n) ; 
    for(auto &it: v){
        cin >> it ;
    }
    long sup ; 
    cin >> sup ;
    cout<<highestProfit(n,v,sup) ;
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
