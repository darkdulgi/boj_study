/*
* 어떤 수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다.
min과 max가 주어지면, min과 max를 포함한 사이에 제곱ㄴㄴ수가 몇 개 있는지 출력한다.

첫째 줄에 두 정수 min과 max가 주어진다.

첫째 줄에 [min,max]구간에 제곱ㄴㄴ수가 몇 개인지 출력한다.
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
	for (ll i = 2; i * i <= max; i++) {	//min보다 큰 제곱ㄴㄴ수가 아닌 최소의 수를 구한 뒤 그 수~max까지 제곱수의 배수마다 체로 걸러내는 것처럼 1로 마킹한다.
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