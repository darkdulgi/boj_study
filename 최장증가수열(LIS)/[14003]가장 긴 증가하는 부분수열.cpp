/*
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.

ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000,000)�� �־�����.
��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (-1,000,000,000 �� Ai �� 1,000,000,000)

ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.
��° �ٿ��� ������ �� �� �ִ� ���� �� �����ϴ� �κ� ������ ����Ѵ�.
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