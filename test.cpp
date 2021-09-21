#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_NUM 3200

using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	int n, m;
	queue<int> q;
	vector<int> man[MAX_NUM];
	vector<int> ans;
	int size[MAX_NUM] = { 0 };

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		man[a].push_back(b);
		size[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (size[i] == 0) {
			q.push(i);
			size[i] = -1;
		}
	}

	while (!q.empty()) {
		int temp = q.front();
		for (int j = 0; j < man[temp].size(); j++) {
			size[man[temp][j]]--;
			if (size[man[temp][j]] == 0)
				q.push(man[temp][j]);
		}
		man[temp].clear();
		ans.push_back(temp);
		size[temp] = -1;
		q.pop();
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}