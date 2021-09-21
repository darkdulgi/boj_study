/*
두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다.
합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
예를 들어, 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄,
A의 3번 위치와 B의 9번 위치를 잇는 전깃줄,
A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든 전깃줄이 서로 교차하지 않게 된다.

전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다.
전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때,
남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 최소 개수의 전깃줄을 구하는 프로그램을 작성하시오.

첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 전깃줄의 개수는 100,000 이하의 자연수이다.
둘째 줄부터 한 줄에 하나씩 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호가 차례로 주어진다.
위치의 번호는 500,000 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다.

첫째 줄에 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 출력한다.
둘째 줄부터 한 줄에 하나씩 없애야 하는 전깃줄의 A전봇대에 연결되는 위치의 번호를 오름차순으로 출력한다. 만약 답이 두 가지 이상이라면 그 중 하나를 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	int n;
	vector <int> v;
	vector <int> vtemp;
	vector <int> ans;
	vector <int> result;
	cin >> n;
	vector<pair<int, int>> line(n);
	vector<int> idx(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> line[i].second >> line[i].first;
	}
	sort(line.begin(), line.end());

	for (int i = 0; i < n; i++)
		v.push_back(line[i].second);
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

	sort(v.begin(), v.end());
	sort(ans.begin(), ans.end());
	set_difference(v.begin(), v.end(), ans.begin(), ans.end(), inserter(result, result.begin()));

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';
}