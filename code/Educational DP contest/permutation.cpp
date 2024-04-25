#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int kM = 1e9+7;
const int kMaxN = 3e3+5;


ll f[kMaxN][kMaxN], n;
string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> s;
  s = "  " + s;
  for (int i = 1; i <= n; i++) {
    f[1][i] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (s[i] == '<') {
        f[i][j] = (f[i][j - 1] + f[i - 1][j - 1]) % kM;
      } else {
        f[i][j] = (f[i][j - 1] + f[i - 1][i - 1] - f[i - 1][j - 1] + kM) % kM;
      }
    }
  }
  cout << f[n][n];
  return 0;
}