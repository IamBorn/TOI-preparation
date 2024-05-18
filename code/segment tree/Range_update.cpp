#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/** A data structure that can answer point update & range minimum queries. */
template <class T> class SumSegmentTree {
  private:
	const T DEFAULT = 0;

	vector<T> segtree;
	int len;

  public:
	SumSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	/** Sets the value at ind to val. */
	void set(int ind, T val) {
		ind += len;
		segtree[ind] += val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
		}
	}

	/** @return the minimum element in the range [start, end) */
	T range_sum(int start, int end) {
		T ret = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { ret += segtree[start++]; }
			if (end % 2 == 1) { ret += segtree[--end]; }
		}
		return ret;
	}
};

int main(){
  int n, q;
  std::cin >> n >> q;
  SumSegmentTree<long long> segtree(n);
  vector<long long> arr(n);
  for(int i = 0; i < n; i++){
    int in;
    std::cin >> in;
    arr[i] = in;
  }
  for(int i = 0; i < q; i++){
    int buff;
    std::cin >> buff;
    if(buff == 1){
      int a, b;
      long long u;
      std::cin >> a >> b >> u;
      segtree.set(a-1, u);
      segtree.set(b, -u);
    }
    else{
      int k;
      std::cin >> k;
      cout << segtree.range_sum(0, k-1) + arr[k-1] << '\n';
    }
  }
}