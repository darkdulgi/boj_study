/*
N���� ������ �̷���� ������ ���� ��, ũ�Ⱑ ����� �κм��� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� ������ ������ ��Ÿ���� N�� ���� S�� �־�����. (1 �� N �� 40, |S| �� 1,000,000)
��° �ٿ� N���� ������ �� ĭ�� ���̿� �ΰ� �־�����. �־����� ������ ������ 100,000�� ���� �ʴ´�.

ù° �ٿ� ���� S�� �Ǵ� �κм����� ������ ����Ѵ�.
*/

#include <iostream>
#define MAXSIZE 4000000
#define MAXSIZE2 8000000
#define ll long long

using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	ll n, s;
	ll m;
	ll ans = 0;
	ll left[20] = { 0 };	//������ �� �κ����� ����
	ll right[20] = { 0 };
	ll leftsum[MAXSIZE2] = { 0 };	//�ε����� ���� ��, �����Ͱ� �ε����� ������ ������ ������ ��
	ll rightsum[MAXSIZE2] = { 0 };
	cin >> n >> s;

	for (ll i = 0; i < n / 2; i++)
		cin >> left[i];

	if (n % 2 == 1) {	//������ ������ ������ Ȧ��, ¦���Ŀ� ���� ������ ��찡 �ٸ�
		for (ll i = 0; i < n / 2 + 1; i++)
			cin >> right[i];
		m = n / 2 + 1;
	}
	else {
		for (ll i = 0; i < n / 2; i++)
			cin >> right[i];
		m = n / 2;
	}

	for (ll i = 1; i < (1 << n / 2); i++) {	//��Ʈ����ŷ�� �̿���, ���� �� ������ ��� �κ������� ������ ���� ����� leftsum, rightsum�� ����
		ll sum = 0;
		for (ll j = 0; j < n / 2; j++) {
			if (i & (1 << j)) {
				sum += left[j];
			}
		}
		leftsum[sum + MAXSIZE]++;
	}

	for (int i = 1; i < (1 << m); i++) {
		ll sum = 0;
		for (ll j = 0; j < m; j++) {
			if (i & (1 << j)) {
				sum += right[j];
			}
		}
		rightsum[sum + MAXSIZE]++;
	}
	for (ll i = 0; i < MAXSIZE2; i++) {
		if (leftsum[i] != 0 && rightsum[s - i + MAXSIZE2] != 0)	//left�� �κ�����, right�� �κ������� ������ ���� S�� ���, �� ������ ��츦 ����
			ans += leftsum[i] * rightsum[s - i + MAXSIZE2];
		if (i == s + MAXSIZE)		//left�̳� right �� �ʿ����� �κ������� ������ ���� S�� ��츦 ����
			ans += leftsum[i] + rightsum[i];

	}

	cout << ans << endl;

}