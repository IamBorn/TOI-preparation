// source : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

vector<ll> dp;
map<vector<ll>, ll> ma = {};
vector<ll> primes;

ll f2(vector<ll> a, int sum){
  if(sum == 0) return 1;
  if(ma[a] != 0) return ma[a];
  ll cnt = 1;
  ll ans = 0;
  for(int i = 0; i < a.size(); i++){
    cnt *= (a[i]+1);
    if(a[i] > 0){
      a[i]--;
      ans = max(ans, f2(a, sum-1));
      a[i]++;
    }
  }
  return ma[a] = ans + cnt;
}

ll f(int i){
  if(i == 1) return 1;
  if(dp[i] != 0) return dp[i];

  ll ans = 1;
  ll cnt = 1;
  ll temp = i;
  for(auto j : primes){
    ll a = 0;
    while(temp > 1 && temp % j == 0){
      a++;
      temp /= j;
    }
    cnt *= (a+1);
    if(temp == 1) break;
  }
  //cout << i << " " << cnt << "\n";
  for(auto j : primes){
    if(j >= i) break;

    if(i % j == 0){
      ans = max(ans, f(i/j));
    }
  }
  //cout << cnt + ans << "\n";
  return dp[i] = cnt + ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll a, b;
  cin >> a >> b;

  for(ll i = 2; i <= b; i++){
    bool can = true;
    for(auto j : primes){
      if(i % j == 0){
        can = false;
        break;
      }
    }
    if(can){
      primes.push_back(i);
      //cout << i << " ";
    }
  }
  ll ans = 0;
  for(ll i = b; i >= a; i--){
    vector<ll> temp;
    ll cnt = 0;
    ll sum;
    ll l = i;
    for(auto j : primes){
      while(l % j == 0){
        cnt++;
        l /= j;
      }
      temp.push_back(cnt);
      sum += cnt;
      cnt = 0;
    }

    ans += f2(temp, sum)-1;
    //cout << dp[i] << "\n";
  }
  cout << ans;
  return 0;
}