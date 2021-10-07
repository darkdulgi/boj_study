/*
현재 N개의 앱, A1, ..., AN이 활성화 되어 있다고 가정하자. 이들 앱 Ai는 각각 mi 바이트만큼의 메모리를 사용하고 있다.
또한, 앱 Ai를 비활성화한 후에 다시 실행하고자 할 경우, 추가적으로 들어가는 비용(시간 등)을 수치화 한 것을 ci 라고 하자.
이러한 상황에서 사용자가 새로운 앱 B를 실행하고자 하여, 추가로 M 바이트의 메모리가 필요하다고 하자.
즉, 현재 활성화 되어 있는 앱 A1, ..., AN 중에서 몇 개를 비활성화 하여 M 바이트 이상의 메모리를 추가로 확보해야 하는 것이다.
여러분은 그 중에서 비활성화 했을 경우의 비용 ci의 합을 최소화하여 필요한 메모리 M 바이트를 확보하는 방법을 찾아야 한다.

입력은 3줄로 이루어져 있다. 첫 줄에는 정수 N과 M이 공백문자로 구분되어 주어지며, 둘째 줄과 셋째 줄에는 각각 N개의 정수가 공백문자로 구분되어 주어진다.
둘째 줄의 N개의 정수는 현재 활성화 되어 있는 앱 A1, ..., AN이 사용 중인 메모리의 바이트 수인 m1, ..., mN을 의미하며,
셋째 줄의 정수는 각 앱을 비활성화 했을 경우의 비용 c1, ..., cN을 의미한다
단, 1 ≤ N ≤ 100, 1 ≤ M ≤ 10,000,000이며, 1 ≤ m1, ..., mN ≤ 10,000,000을 만족한다. 또한, 0 ≤ c1, ..., cN ≤ 100이고, M ≤ m1 + m2 + ... + mN이다.

필요한 메모리 M 바이트를 확보하기 위한 앱 비활성화의 최소의 비용을 계산하여 한 줄에 출력해야 한다.
*/
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int n, m;
int mem[101] = { 0 };
int kost[101] = { 0 };
int dp[101][10001];

int f(int n, int k) {	//dp를 위한 점화식. 앱의 수와 종료 비용을 인자로 가지는 2차원 DP
	if (dp[n][k] != -1) return dp[n][k];
	if (n == 1) {
		if (k == kost[1]) {
			dp[1][k] = mem[1];
			return mem[1];
		}
		else {
			dp[1][k] = 0;
			return 0;
		}
	}

	int a = f(n - 1, k);
	dp[n - 1][k] = a;
	int b = f(n - 1, k - kost[n]);
	if (k - kost[n] < 0) {
		dp[n][k] = dp[n - 1][k];
		return dp[n - 1][k];
	}
	dp[n - 1][k - kost[n]] = b;
	b += mem[n];
	return dp[n][k] = max(a, b);
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 10001; j++)
			dp[i][j] = -1;
	}
	int sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> mem[i];
	for (int i = 1; i <= n; i++) {
		cin >> kost[i];
		sum += kost[i];
	}
	for (int i = 0; i < 10001; i++)f(n, i);
	for (int i = 0;; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			break;
		}
	}

}