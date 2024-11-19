#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10, mod = 1e9 + 7;
struct BIT {
	int tr[N];
	int lowbit(int x) {
		return x & -x;
	}
	int query(int x) {
		int sum = 0;
		for (int i = x; i && i > 0; i -= lowbit(i))
			sum += tr[i];
		return sum;
	}
	void add(int k, int x) {
		for (int i = k; i <= N && i >= 0; i += lowbit(i))tr[i] += x;
	}
}bit;
int res[N], hi[N];
vector<ll> solve(vector<int>& input) {
	auto n = input.size();
	for (int i = 1; i <= n; i++) {
		hi[i] = input[i];
		bit.add(hi[i] + 1, 1);
		res[i] += i - bit.query(hi[i] + 1);
	}
	memset(bit.tr, 0, sizeof bit.tr);
	for (int i = n; i >= 1; i--) {
		bit.add(hi[i] + 1, 1);
		res[i] += bit.query(hi[i]);
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++)sum += (ll)res[i] * (res[i] + 1) / 2;

	vector<ll> ans;
	ans.push_back(sum);
	return ans;
}


