/*
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 40, |S| ≤ 1,000,000)
둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.
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
	ll left[20] = { 0 };	//집합을 두 부분으로 나눔
	ll right[20] = { 0 };
	ll leftsum[MAXSIZE2] = { 0 };	//인덱스가 수의 합, 데이터가 인덱스를 합으로 가지는 집합의 수
	ll rightsum[MAXSIZE2] = { 0 };
	cin >> n >> s;

	for (ll i = 0; i < n / 2; i++)
		cin >> left[i];

	if (n % 2 == 1) {	//집합의 원소의 개수가 홀수, 짝수냐에 따라 나누는 경우가 다름
		for (ll i = 0; i < n / 2 + 1; i++)
			cin >> right[i];
		m = n / 2 + 1;
	}
	else {
		for (ll i = 0; i < n / 2; i++)
			cin >> right[i];
		m = n / 2;
	}

	for (ll i = 1; i < (1 << n / 2); i++) {	//비트마스킹을 이용해, 나눈 두 집합의 모든 부분집합의 원소의 합을 계산해 leftsum, rightsum에 적용
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
		if (leftsum[i] != 0 && rightsum[s - i + MAXSIZE2] != 0)	//left의 부분집합, right의 부분집합의 원소의 합이 S인 경우, 두 집합의 경우를 곱합
			ans += leftsum[i] * rightsum[s - i + MAXSIZE2];
		if (i == s + MAXSIZE)		//left이나 right 한 쪽에서만 부분집합의 원소의 합이 S인 경우를 더함
			ans += leftsum[i] + rightsum[i];

	}

	cout << ans << endl;

}