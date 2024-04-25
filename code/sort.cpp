// source : https://atcoder.jp/contests/abc350/tasks/abc350_c
// status : complete
// date : 25/4/2024
// problem tags : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vi a(n+1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  vector<pii> b;
  for(int i = 1; i <= n; i++){
    while(a[i] != i){
      b.push_back({i, a[i]});
      int temp = a[i];
      swap(a[i], a[temp]);
    }
  }
  cout << b.size() << "\n";
  for(auto [x, y] : b){
    cout << x << " " << y << "\n";
  }
  return 0;
}