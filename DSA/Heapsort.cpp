#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007


void heapify(vector<int>&arr, int n , int i){
    int l = 2* i+ 1 ; 
    int r = 2*i + 2 ; 
    int largest = i ; 
    if(i < n && arr[l] > arr[i]){
        largest = l ;
    }
    if(i < n && arr[r] > arr[largest]){
     largest  = r ;
    }
    if(largest!= i){
        swap(arr[largest] , arr[i]) ;
        heapify(arr,n, largest) ;
    }

}

void heapsort(vector<int>&arr){
    int n = arr.size() ;
    for(int i = n/2 -1 ; i >= 0 ; i--){
        heapify(arr,n,i) ;
    }
    for(int i = n -1 ; i >=0 ; i--){
        swap(arr[i], arr[0]) ;
        heapify(arr, i, 0) ;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

int n ; 
cin >> n ; 
vector<int>v(n) ;
for(int i = 0 ; i< n ; i++){
    cin >> v[i] ;
}
heapsort(v) ;
for(auto it : v){
    cout<<it<< " " ;
}

    return 0;
}
