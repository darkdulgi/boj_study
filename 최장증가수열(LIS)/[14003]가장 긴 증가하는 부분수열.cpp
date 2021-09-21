/*
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 30, 50} 이고, 길이는 4이다.

첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)

첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
둘째 줄에는 정답이 될 수 있는 가장 긴 증가하는 부분 수열을 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	int n;
	vector <ll> vtemp;
	vector <ll> ans;
	cin >> n;
	vector <ll> v(n);
	vector<int> idx(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vtemp.push_back(v[0]);

	for (int i = 1; i < n; i++) {
		if (v[i] <= vtemp.back()) {
			int lb = lower_bound(vtemp.begin(), vtemp.end(), v[i]) - vtemp.begin();
			vtemp[lb] = v[i];
			idx[i] = lb;
		}
		else {
			idx[i] = vtemp.size();
			vtemp.push_back(v[i]);
		}
	}
	int ii = vtemp.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (ii == idx[i]) {
			ans.push_back(v[i]);
			ii--;
		}
	}
	sort(ans.begin(), ans.end());
	cout << vtemp.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
}
