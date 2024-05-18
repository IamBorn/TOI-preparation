// source : https://dmoj.ca/problem/ioi05p2

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  double prev;
  cin >> prev;
  double in;
  double ans = INF;
  for(int i = 1; i < n; i++){
    cin >> in;
    ans = min(ans, in - prev);
    prev = in;
  }
  cout << ans+1;
  return 0;
}