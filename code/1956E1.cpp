#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve(){
	int n;
	cin >> n;
	vi a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	while(true){
		bool can = false;
		for(int i = 1; i <= n; i++){
			a[(i % n) + 1] = max(0, a[(i % n) + 1] - a[i]);
		}
		for(int i = 1; i <= n; i++){
			if(a[i] > 0 && a[(i % n) + 1] > 0){
				can = true;
				break;
			}
		}
		if(!can) break;
	}

	int cnt = 0;
	vi ans;
	for(int i = 1; i <= n; i++){
		if(a[i] > 0){
			cnt++;
			ans.push_back(i);
		}
	}
	cout << cnt << "\n";
	for(auto it : ans) cout << it << " ";
	cout << "\n";
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
