/*
�� ������ A�� B ���̿� �ϳ� �Ѿ� �������� �߰��ϴ� ���� �������� ���� �����ϴ� ��찡 �߻��Ͽ���.
�ռ��� ������ �־� �̵� �� �� ���� �������� ���� �������� �������� �ʵ��� ������� �Ѵ�.
���� ���, �������� ����Ǿ� �ִ� ��� A�� 1�� ��ġ�� B�� 8�� ��ġ�� �մ� ������,
A�� 3�� ��ġ�� B�� 9�� ��ġ�� �մ� ������,
A�� 4�� ��ġ�� B�� 1�� ��ġ�� �մ� �������� ���ָ� �����ִ� ��� �������� ���� �������� �ʰ� �ȴ�.

�������� �����뿡 ����Ǵ� ��ġ�� ������ ���������� ���ʴ�� ��ȣ�� �Ű�����.
�������� ������ �����ٵ��� �� �����뿡 ����Ǵ� ��ġ�� ��ȣ�� �־��� ��,
�����ִ� ��� �������� ���� �������� �ʰ� �ϱ� ���� ���־� �ϴ� �ּ� ������ �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ��� �� ������ ������ �������� ������ �־�����. �������� ������ 100,000 ������ �ڿ����̴�.
��° �ٺ��� �� �ٿ� �ϳ��� �������� A������� ����Ǵ� ��ġ�� ��ȣ�� B������� ����Ǵ� ��ġ�� ��ȣ�� ���ʷ� �־�����.
��ġ�� ��ȣ�� 500,000 ������ �ڿ����̰�, ���� ��ġ�� �� �� �̻��� �������� ����� �� ����.

ù° �ٿ� �����ִ� ��� �������� ���� �������� �ʰ� �ϱ� ���� ���־� �ϴ� �������� �ּ� ������ ����Ѵ�.
��° �ٺ��� �� �ٿ� �ϳ��� ���־� �ϴ� �������� A�����뿡 ����Ǵ� ��ġ�� ��ȣ�� ������������ ����Ѵ�. ���� ���� �� ���� �̻��̶�� �� �� �ϳ��� ����Ѵ�.
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