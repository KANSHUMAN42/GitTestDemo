#include <bits/stdc++.h>
using namespace std ;

#define int long long 
const int N = 2e5 + 10 ;
const int mod = 1e9+7 ;

struct Segtree{
	vector<multiset<int>> t ;
	int n ;
	
	Segtree(){
		n = N ;
		t.resize(4*n) ;
	}

	Segtree(int l){
		n = l ;
		t.resize(4*n) ;
	}
	// v is current vertex in segtree , tl , tr in array
	void build_util(int* a , int v , int tl , int tr){
		if(tl == tr){
			t[v] = multiset<int>{a[tl]} ;
		}else{
			int tm = (tl+tr)/2 ;
			build_util(a, 2*v, tl, tm) ; build_util(a, 2*v+1, tm+1, tr) ;
            merge(t[v * 2].begin(), t[2*v].end(), t[2*v + 1].begin(), t[2*v + 1].end(), back_inserter(t[v])) ;
		}
	}
	
	void build(int * a , int l){
		n = l ;
		build_util(a,1,0,n-1) ;
	}

	int query_util(int v , int tl , int tr , int l , int r, int x){
		if(l > r){
			return INT_MIN ;
		}
		if(tl == l && tr == r){
	        auto it = lower_bound(t[v].begin() , t[v].end() , x);
            if(it == t[v].begin()) return INT_MIN ;
            it-- ;
            return *it ;
        }
		int tm = (tl + tr) / 2 ;
		return max(query_util(2*v, tl, tm, l, min(r,tm), x) 
			, query_util(2*v + 1, tm + 1, tr, max(l,tm+1), r, x)) ;
	}

	int query(int l , int r, int x){
		return query_util(1,0,n-1,l,r, x) ;
	}

	void update_util(int v , int tl , int tr , int pos , int new_val){
		if(tl == tr){
            
		}else{
			int tm = (tl + tr) / 2 ;
			if(pos <= tm) // left jao
				update_util(2*v, tl, tm, pos, new_val) ;
			else 
				update_util(2*v + 1, tm+1, tr, pos, new_val) ;
			t[v] = max(t[2*v] , t[2*v + 1]);
		}
	}
	
	void update(int pos , int val){
		 update_util(1,0,n-1,pos,val) ;
	}

} ;


int32_t main(){
	
       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif
int n ; cin >> n; 
vector<int>a(n) ; 
vector<int> b(n) ; 
for(auto & it : a){
    cin >> it ; 
}
for(auto & it : b){
    cin >> it ; 
}

vector<vector<int> > v(n ) ; 
for(int i = 0 ; i < n ; i++){
    v[i] = {  a[i], i , b[i] } ; 
 } 

 sort(v.begin(), v.end(),[&](vector<int>& v1, vector<int>&v2){
     if(v1[0] == v2[0]){
         return v1[1] < v2[1] ; 
     }
     return v1[0] < v2[0] ; 
 } ) ; 

Segtree s(n) ; 
int ans = 0 ; 

for(int i = 0 ; i < n ; i++){
    ans += s.query(0, v[i][1])  ; 
    ans = ans % mod ; 
    s.update(v[i][1], v[i][2]) ; 
}
 cout<<ans % mod <<endl ; 


	return 0 ;
}

