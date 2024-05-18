    // source : 
     
    #include <bits/stdc++.h>
    using namespace std;
     
    #define sz(v) ((int)(v).size)
    #define all(v) (v).begin(), (v).end()
     
    using ll = long long;
    using pii = pair<int, int>;
    using vi = vector<int>;
    const long long INF = 2000000;
    const int MOD = 1e9+7;
     
    int cnt[100005][2] = {};
     
    int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      
      int n;
      cin >> n;
      string s;
     
      int ans = 0;
      int c0 = 0, c1 = 0;
      bool all0 = true, all1 = true;
      for(int i = 0; i < n; i++){
        cin >> s;
        int si = s.size();
        for(int j = 0; j < si; j++){
          if(s[j] == '0'){
            cnt[i][0]++;
            all1 = false;
          }
          else{
            cnt[i][1]++;
            all0 = false;
          }
        }
        ans += min(cnt[i][0], cnt[i][1]);
        if(cnt[i][0] < cnt[i][1]) c0++;
        else if(cnt[i][1] < cnt[i][0]) c1++;
        else{
          c0++;
          c1++;
        }
      }
      if(c0==0 && !all0){
        int temp = INF;
        for(int i = 0; i < n; i++){
          temp = min(temp, cnt[i][0] - cnt[i][1]);
        }
        ans += temp;
      }
      else if(c1 == 0 && !all1){
        int temp = INF;
        for(int i = 0; i < n; i++){
          temp = min(temp, cnt[i][1] - cnt[i][0]);
        }
        ans += temp;
      }
     
      cout << ans;
      return 0;
    }