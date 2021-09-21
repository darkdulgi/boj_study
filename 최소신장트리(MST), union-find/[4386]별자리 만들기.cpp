/*
도현이는 우주의 신이다. 이제 도현이는 아무렇게나 널브러져 있는 n개의 별들을 이어서 별자리를 하나 만들 것이다. 별자리의 조건은 다음과 같다.
별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태이다.
모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 한다.
별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때마다 두 별 사이의 거리만큼의 비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하시오.

첫째 줄에 별의 개수 n이 주어진다. (1 ≤ n ≤ 100)
둘째 줄부터 n개의 줄에 걸쳐 각 별의 x, y좌표가 실수 형태로 주어지며, 최대 소수점 둘째자리까지 주어진다. 좌표는 1000을 넘지 않는 양의 실수이다.

첫째 줄에 정답을 출력한다. 절대/상대 오차는 10-2까지 허용한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int parent[1000];

struct lll {
	int a, b;
	float val;
};

vector<lll> line;

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return 0;
	parent[a] = b;
	return 1;
}
bool com(lll a, lll b) {
	return a.val < b.val;
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	int v, e;
	float ans = 0;
	cin >> v;
	vector<pair<float, float>> star(v + 1);
	e = v * (v - 1) / 2;
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 1; i <= v; i++)
		cin >> star[i].first >> star[i].second;

	for (int i = 1; i < v; i++) {
		for (int j = i + 1; j <= v; j++) {
			lll temp;
			temp.a = i;
			temp.b = j;
			temp.val = sqrt((star[i].first - star[j].first) * (star[i].first - star[j].first) + (star[i].second - star[j].second) * (star[i].second - star[j].second));
			line.push_back(temp);
		}

	}
	sort(line.begin(), line.end(), com);

	for (int i = 0; i < e; i++) {
		if (Union(line[i].a, line[i].b)) {
			ans += line[i].val;

		}
	}

	printf("%.2f", ans);
}