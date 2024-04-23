#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

vector<ll> wi;
vector<ll> v;

ll f(int n, ll w){
  vector<ll> dp(w+1);

  for(int i = 0; i < n; i++){
    for(int j = w; j >= 0; j--){
      if(wi[i] <= j){
        dp[j] = max(dp[j], dp[j - wi[i]] + v[i]);
      }
    }
  }
  return dp[w];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  ll w;
  cin >> n >> w;
  ll a, b;
  for(int i = 0; i < n; i++){
    cin >> b >> a;
    v.push_back(a);
    wi.push_back(b);
  }

  cout << f(n, w);
  return 0;
}