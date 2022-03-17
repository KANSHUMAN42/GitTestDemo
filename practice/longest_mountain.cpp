#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
void getMountain(vector<int>& A , int k) {
    priority_queue<pair<int,int> > pq ;
        int maxLength = 0;
        int i = 1;
        
        while (i < A.size()) {
            int increasing = 0, decreasing = 0;
            
            while(i < A.size() && A[i - 1] < A[i]) i++, increasing++;
            while(i < A.size() && A[i - 1] > A[i]) i++, decreasing++;
            
            if (increasing > 0 && decreasing > 0){
                int len =increasing + decreasing - 1 ;
                pq.push({ len, i}) ;
                cout<< len << "->"<<i <<endl ;
                
            }
            
            while(i < A.size() && A[i - 1] == A[i]) i++;
        }
        
       
        vector<vector<int>>vans ;
        for(int i = 0 ; i < k ; i++){
            vector<int>v ; 
            auto f = pq.top( ) ; 
            pq.pop() ; 
            for(int j = f.second ; j> i-f.first ; j--){
                v.push_back(A[j]) ;
            }
          vans.push_back(v) ;
        }

        for(auto it : vans){
            for(auto e : it){
                cout<< e<<" " ;
            }
            cout<<endl ;
        }

    }
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

  int n ; cin >> n; 
  vector<int>arr(n) ; 
  for(auto &i: arr){
      cin>>i ;
  }
  int k ; cin >> k ; 
   getMountain(arr, k) ;
    return 0;
}
