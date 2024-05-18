// source : https://usaco.org/index.php?page=viewproblem2&cpid=597

#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

void setIO(string name = "") {

	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io

	if (sz(name)) {

		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output

		freopen((name + ".out").c_str(), "w", stdout);

	}

}

bool f(vi &a, int i, int ra){
  int l = i, r = i;
  int si = a.size();
  //ra++;
  while(true){
    int nl = lower_bound(all(a), a[l] - ra) - a.begin();
    int nr = upper_bound(all(a), a[r] + ra) - a.begin();
    if(nl == l && nr == r){
      break;
    }
    l = nl;
    r = nr;
    if(l == 0 && r == si-1){
      break;
    }
    ra--;
  }

  return (l == 0 && r == si-1);
}

int main(){
  
  int n;
  cin >> n;
  vi a(n);
  for(auto &it : a) cin >> it;

  sort(all(a));

  int l = 1, r = 1e9+1;
  while(l < r){
    int m = (l + r) / 2;
    //cout << m << "\n";

    bool check = false;
    for(int i = 0; i < n; i++){
      check |= f(a, i, m);
    }

    if(check){
      l = m;
    }
    else{
      r = m-1;
    }
  }

  cout << l;
  return 0;
}