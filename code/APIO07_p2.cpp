// source : https://dmoj.ca/problem/apio07p2

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = int;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 2e9+7;
const int MOD = 1e9+7;

struct wire{
  int i, j;
  ll cost;
};

class comp{
  public:
    bool operator()(wire a, wire b){
      return a.cost >= b.cost;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for(auto &it : a) cin >> it;

  priority_queue<wire, vector<wire>, comp> pq;
  for(int i = 0; i < n-1; i++){
    wire temp;
    temp.i = i;
    temp.j = i+1;
    temp.cost = a[i+1] - a[i];
    pq.push(temp);
  }
  /*while(!pq.empty()){
    cout << pq.top().cost << " ";
    pq.pop();
  }
  cout << "\n";*/
  vector<bool> used(n, false);
  ll ans = 0;
  for(int l = 0; l < k; l++){
    while(!pq.empty()){
      auto [i, j, cost] = pq.top();
      if(!used[i] && !used[j]){
        break;
      }
      pq.pop();
    }
    if(!pq.empty()){
      auto temp = pq.top();
      pq.pop();
      int i = temp.i;
      int j = temp.j;
      ll cost = temp.cost;
      ans += cost;
      used[i] = true;
      used[j] = true;
      if((i > 0) && (j < n-1)){
        wire ni;
        ni.i = i-1;
        ni.j = j+1;
        ni.cost = (a[i] - a[i-1]) + (a[j+1] - a[j]) - cost;
        pq.push(ni);
      }
    }
  }

  cout << ans;
  return 0;
}