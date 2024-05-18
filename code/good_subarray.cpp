// source : https://codeforces.com/contest/1398/problem/C

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vi a(n);
  for(int i = 0; i < n; i++){
    a[i] = s[i] - '0';
  }
  map<int, ll> sum;
  sum[0] = 1;
  ll cnt = 0;
  ll ans = 0;
  for(int i = 0; i < n; i++){
    cnt += a[i];
    int x = cnt - i - 1;
    sum[x]++;
    ans += sum[x]-1;
  }
  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}