// source : https://usaco.org/index.php?page=viewproblem2&cpid=861

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

vector<vector<pii>> adj;

int main(){
  
  int n, m, k;
  cin >> n >> m >> k;
  adj.resize(n);

  int u, v, t;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> t;
    
  }
  return 0;
}