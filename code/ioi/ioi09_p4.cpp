// source : https://dmoj.ca/problem/ioi09p4

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

int dp[55][55][55][55];
int ps[55][55];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> dp[i][j][i][j];
      ps[i][j] = (ps[i-1][j] + ps[i][j-1] - ps[i-1][j]) + dp[i][j][i][j];
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(i == 1 && j == 1) continue;
      for(int x = 1; x + i - 1 <= n; x++){
        for(int y = 1; y + j - 1 <= m; y++){
          int temp = INF;
          for(int k = 0; k < i-1; k++){
            temp = min(temp, dp[x][y][x+k][y+j-1] + dp[x+k+1][y][x+i-1][y+j-1]);
          }
          for(int k = 0; k < j-1; k++){
            temp = min(temp, dp[x][y][x+i-1][y+k] + dp[x][y+k+1][x+i-1][y+j-1]);
          }
          dp[x][y][x+i-1][y+j-1] = temp + ps[x+i-1][y+j-1] - ps[x+i+1][y-1] - ps[x-1][y+j-1] + ps[x-1][y-1];
        }
      }
    }
  }

  cout << dp[1][1][n][m];
  return 0;
}