#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

vector<double> dp(1 << 19, -1);
double a[20][20];
int n;

double preMove(int pre_mask, int j){
	int k = __builtin_popcount(pre_mask);
	ll den = (k * (k - 1)) / 2;
	double moveprob = 0;

	for(int i = 0; i < n; i++){
		if((1 << i)&pre_mask){
			moveprob += a[i][j];
		}
	}

	return moveprob / den;
}

double f(int mask){
	int bc = __builtin_popcount(mask);
	
	if(bc == n){
		return 1;
	}

	if(dp[mask] > -0.9) return dp[mask];

	double sum = 0;
	for(int i = 0; i < n; i++){
		if(!(mask & (1 << i))){
			int pre_mask = mask^(1 << i);
			double pre = f(pre_mask);

			sum += pre * preMove(pre_mask, i);
		}
	}

	return dp[mask] = sum;
}

void solve(){
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		cout << fixed << setprecision(6) << f(1 << i) << ' ';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}
