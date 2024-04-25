#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MxN = 1e5+5;

vi adj[MxN];
bool isV[MxN];
int n, m;


int f(int i, int color){
  int ans = 1;
  isV[i] = true;
  if(color == 0){
    for(auto j : adj[i]){
      if(!isV[j]){
        ans *= (f(j, 0) + f(j, 1)) % m;
        ans %= m;
      }
    }
  }
  else{
    for(auto j : adj[i]){
      if(!isV[j]){
        ans *= (f(j, 1)) % m;
        ans %= m;
      }
    }
  }

  return ans;
}

void solve(int v){
  memset(isV, 0, sizeof(isV));
  cout << f(v, 0) << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  
  int x, y;
  for(int i = 0; i < n-1; i++){
    cin >> x >> y;
    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  for(int i = 0; i < n; i++){
    solve(i);
  }
  return 0;
}