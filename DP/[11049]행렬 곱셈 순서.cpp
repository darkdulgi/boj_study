/*
크기가 N×M인 행렬 A와 M×K인 B를 곱할 때 필요한 곱셈 연산의 수는 총 N×M×K번이다. 행렬 N개를 곱하는데 필요한 곱셈 연산의 수는 행렬을 곱하는 순서에 따라 달라지게 된다.
예를 들어, A의 크기가 5×3이고, B의 크기가 3×2, C의 크기가 2×6인 경우에 행렬의 곱 ABC를 구하는 경우를 생각해보자.
AB를 먼저 곱하고 C를 곱하는 경우 (AB)C에 필요한 곱셈 연산의 수는 5×3×2 + 5×2×6 = 30 + 60 = 90번이다.
BC를 먼저 곱하고 A를 곱하는 경우 A(BC)에 필요한 곱셈 연산의 수는 3×2×6 + 5×3×6 = 36 + 90 = 126번이다.
같은 곱셈이지만, 곱셈을 하는 순서에 따라서 곱셈 연산의 수가 달라진다.
행렬 N개의 크기가 주어졌을 때, 모든 행렬을 곱하는데 필요한 곱셈 연산 횟수의 최솟값을 구하는 프로그램을 작성하시오. 입력으로 주어진 행렬의 순서를 바꾸면 안 된다.

첫째 줄에 행렬의 개수 N(1 ≤ N ≤ 500)이 주어진다.
둘째 줄부터 N개 줄에는 행렬의 크기 r과 c가 주어진다. (1 ≤ r, c ≤ 500)
항상 순서대로 곱셈을 할 수 있는 크기만 입력으로 주어진다.

첫째 줄에 입력으로 주어진 행렬을 곱하는데 필요한 곱셈 연산의 최솟값을 출력한다.
정답은 231-1 보다 작거나 같은 자연수이다. 또한, 최악의 순서로 연산해도 연산 횟수가 231-1보다 작거나 같다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[501] = { 0 };
int memo[500][500] = { 0 };

int f(int a, int b) {	//행렬 ABCDEF의 곱셈 연산 횟수 최솟값을 구하려면 A(BCDEF)의 최솟값, (AB)(CDEF)의 최솟값, (ABC)(DEF)의 최솟값, .. (ABCDE)F의 최솟값 중 최솟값을 구해야 한다.
	if (memo[a][b] != 0)return memo[a][b];
	if (a == b)  return 0;
	if (b == a + 1) return memo[a][b] = arr[a] * arr[b] * arr[b + 1];
	int temp[500];
	for (int i = 0; i < b - a; i++) {
		temp[i] = f(a, a + i) + f(a + i + 1, b) + arr[a] * arr[a + i + 1] * arr[b + 1];
	}

	return memo[a][b] = *min_element(temp, temp + b - a);
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int n;
	int temp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		if (i == 0) cin >> arr[0] >> arr[1];
		else cin >> temp >> arr[i + 1];
	}

	cout << f(0, n - 1) << endl;
}