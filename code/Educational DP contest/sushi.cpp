#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MxN = 305;

double f[MxN][MxN][MxN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int in;
  int a = 0, b = 0, c = 0;
  for(int i = 0; i < n; i++){
    cin >> in;
    if(in == 1) a++;
    else if(in == 2) b++;
    else c++;
  }
  f[0][0][0] = 1.;
  for (int k = 0; k <= n; k++) {
    for (int j = 0; j + k <= n; j++) {
      for (int i = 0; i + j + k <= n; i++) {
        if (i + j + k == 0) continue;

        auto &now = f[i][j][k];
        if (i) now += (1.0 * i / (i + j + k)) * f[i - 1][j][k];
        if (j) now += (1.0 * j / (i + j + k)) * f[i + 1][j - 1][k];
        if (k) now += (1.0 * k / (i + j + k)) * f[i][j + 1][k - 1];
        now += 1.0 * n / (i + j + k);
      }
    }
  }

  cout << fixed << setprecision(10) << f[a][b][c] - 1;
  return 0;
}