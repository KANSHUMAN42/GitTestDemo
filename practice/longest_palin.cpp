#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

bool helper(int l, int r, string &s, int memo[][1001], vector<int> &answer) {
		// Check if [ L ... R ] is already calculated before
        if (memo[l][r] != -1) {
            return memo[l][r];         
        }
        
		// Base case, every single letter or empty string is also a palindrome
        if (l >= r) {
            return true;
        }
        
        // Possible palindrome beginning
        bool found = false;
        
        if (s[l] == s[r]) {
            found = true && helper(l + 1, r - 1, s, memo, answer);
        }
        
        // Try other possibilities
        helper(l + 1, r , s, memo, answer);
        helper(l, r - 1, s, memo, answer);
        
        // Update longest palindrome position and width
        if (found && (r - l + 1) > answer[2]) {
            answer = {l, r, (r - l + 1)};
        }
        
        // Memoization
        memo[l][r] = found;
        
        return found;
    }

 string longestPalindrome(string s) {

        int memo[1001][1001];
        memset(memo, -1, sizeof(memo));
        vector<int> answer = {0, 0, 1};
        helper(0, s.size() - 1, s, memo, answer);
        return s.substr(answer[0], answer[2]);
    }

void solve()
{
    string s ; 
    cin >> s ; 
    cout<<longestPalindrome(s)<<endl ; 

    
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
