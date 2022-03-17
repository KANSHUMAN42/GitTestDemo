// #include <bits/stdc++.h>
// using namespace std;
// #define int long long 
// #define mod 1000000007
// void solve(){
//     int n ; cin >>n; 
//     int money ; cin >> money ; 
//     vector<int>price(n) ; 
//     // vector<int>pages(n) ;
//     for(int i = 0 ; i < n ; i++){
//         cin >> price[i] ; 
//     }
//     for(auto &page : pages){
//         cin >> page ;
//     }
//     vector<vector<int>> dp(n + 1 , vector<int>(money+1, 0)) ; 
//     for(int i = 1 ; i <= n ; i++){
//         for(int j = 0 ; j <= money ; j++){
//             dp[i][j] = dp[i-1][j] ;
//             if(price[i-1] <= j){
//                 dp[i][j] = max(dp[i][j], dp[i-1][j - price[i-1]]+ pages[i-1]) ;
//             }
//         }
//     }

//     cout<< dp[n][money] <<endl ;
// }
// int32_t main() {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
//     freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
// #endif

//     int test=1;
// //cin>>test;
//     while(test--)
//     {
//         solve();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,x;
    cin>>n>>x;

    vector<int> page(n),price(n);
    int a,b;

    for(int&i : price)
    cin>>i;

    for(int&i : page)
    cin>>i;

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            //option1 = book number i-1 is not included, hence no pages added.
            //option2 = book number i-1 is included, hence pages are added.
            //option1 = dp[i-1][j] ...book not included so total price(j) remains same.
            //option2 = dp[i-1][j-price[i-1]] + page[i-1]....total price(j) decreased and pages are counted for book i-1.
            
            dp[i][j] = dp[i-1][j];
            if(j >= price[i-1])
            {
                dp[i][j] = max (dp[i][j],dp[i-1][j-price[i-1]] + page[i-1]); //max of both the boxes included in dp[i][j]. 
            }
        }
    }

    cout<< dp[n][x] <<endl;

    return 0;
}