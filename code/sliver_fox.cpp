#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main(){
  int n;
  int d, a;
  cin >> n >> d >> a;
  vector<pii> x(n);
  vi diff(n, 0);
  for(int i = 0; i < n; i++){
    cin >> x[i].first >> x[i].second;
  }
  sort(all(x));
  cout << x[0].first << '\n';
  int ans = 0;
  int now = 1;
  for(int i = 0; i < n; i++){
    while(now < n && x[now].first - x[i].first <= 2*d) now++;

    diff[i] = diff[i-1];
    x[i].second += diff[i];

    if(x[i].second > 0){
      int cnt = (x[i].second - 1) / a + 1;
      ans += cnt;
      diff[i] -= cnt*a;
      diff[now] += cnt*a;
    }
  }
  cout << ans;
  return 0;
}