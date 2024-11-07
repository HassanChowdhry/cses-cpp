#include <bits/stdc++.h>
# define ll long long
int MOD=1000000007;
using namespace std;


int main() {
  string s1, s2; cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  for (int i = 0; i <= n; ++i) 
    { dp[i][0] = i; }

  for (int i = 0; i <= m; ++i) 
    { dp[0][i] = i; }
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s1[i-1] == s2[j-1]) 
        { dp[i][j] = dp[i-1][j-1]; continue; }
      
      dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
    }
  }
  
  cout << dp[n][m];
}