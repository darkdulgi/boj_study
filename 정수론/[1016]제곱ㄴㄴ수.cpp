/*
* � �� X�� 1���� ū �������� ������ �������� ���� ��, ������������� �Ѵ�. �������� ������ �����̴�.
min�� max�� �־�����, min�� max�� ������ ���̿� ������������ �� �� �ִ��� ����Ѵ�.

ù° �ٿ� �� ���� min�� max�� �־�����.

ù° �ٿ� [min,max]������ ������������ �� ������ ����Ѵ�.
*/
#include <iostream>
#define ll long long

using namespace std;
int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	ll min, max;
	ll ans = 0;
	bool arr[1000001] = { 0 };
	cin >> min >> max;
	for (ll i = 2; i * i <= max; i++) {	//min���� ū ������������ �ƴ� �ּ��� ���� ���� �� �� ��~max���� �������� ������� ü�� �ɷ����� ��ó�� 1�� ��ŷ�Ѵ�.
		ll temp = min / (i * i);
		temp *= (i * i);
		if (temp < min)
			temp += (i * i);
		for (; temp <= max; temp += (i * i)) {
			arr[temp - min] = 1;
		}
	}
	for (ll i = 0; i <= max - min; i++) {
		if (arr[i] == 0)
			ans++;
	}
	cout << ans << endl;
}