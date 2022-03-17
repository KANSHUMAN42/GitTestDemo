#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

/*
A quick look over the above algorithm suggests that the running time is O(nlg(n)),
 since each call to Heapify costs O( log(n) ) and Build-Heap makes O(n) such calls.
 This upper bound, though correct, is not asymptotically tight.
 For finding the Time Complexity of building a heap,
  we must know the number of nodes having height h.
  For this we use the fact that, A heap of size n has at most { n/2^(h+1) } nodes with height h.

https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/

insertion is in log(n) {
    insert at the last and reach to the parent moving ahead by adjusting element
}
deletion or extract min is in log(n){
    process : 
    first replace last element to the first one 
    delete ast element 
    call heapify from zero
}







*/



void swap(int * x, int * y); 


class MinHeap{
    public:
    vector<int>arr; 
    MinHeap(int capacity) {
      //  arr.resize(capacity) ;
    }

    int parent(int i ){
        return (i-1) / 2 ; 
    }
    int left( int i ){
        return 2 * i + 1 ; 
    }
    int right(int i){
        return 2 * i + 2 ; 
    }

    void insertKeys(int k){
        arr.push_back(k) ;
        int i = arr.size() - 1 ; 
        arr[i] = k ; 
        while(i != 0 && arr[parent(i)] > arr[i]){
            swap(&arr[i], &arr[parent(i)]) ;
            i = parent(i) ;
        }
    }
  
    int exactMin() {
        if(arr.size() <= 0){
         return INT_MAX ; 
        }
        if(arr.size() ==1){
            arr.pop_back() ;
            return arr[0] ;
        }
        int root = arr[0] ; 
        arr[0] = arr[arr.size()-1] ; 
        arr.pop_back() ;
        MinHeapify(0);
        return root ; 
    }

    int getMin() {
        return arr[0] ;
    }
    void print(){
        for(int i = 0 ; i < arr.size() ; i++){
            cout<<arr[i]<<" " ;
        }
    }

    void MinHeapify(int i ){
        int l = left( i ) ; 
        int r = right( i ) ;
        int smallest = i ; 

        if( l < arr.size() && arr[l] < arr[i]){
            smallest = l ; 
        }

        if(r < arr.size() && arr[r] < arr[smallest] )
            smallest = r ; 

        if(smallest != i){
            swap(&arr[i], &arr[smallest]) ; 
            MinHeapify(smallest) ;
        }           
    }

    void swap(int *x, int *y){
        int temp = *x ; 
        *x = *y ; 
        *y = temp ; 
    }


   
};
        





int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif

 MinHeap* pq = new MinHeap(5) ;
 for(int i = 0 ; i <5 ; i++){
   int a ; 
   cin >> a; 
   pq->insertKeys(a) ;
 }
  pq->print() ;
  cout<<endl ;
  cout<<pq->exactMin() <<" " <<pq->exactMin()<<" "<<pq->exactMin()<<" " ;

    return 0;
}
