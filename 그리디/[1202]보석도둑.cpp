/*
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.
상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다.
가방에는 최대 한 개의 보석만 넣을 수 있다.
상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)
다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)
다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)
모든 숫자는 양의 정수이다.

첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <set>
#define MAX	300000
#define ll long long
using namespace std;

bool com(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.second > b.second) return 1;
	return 0;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	ll n, k;
	ll ans = 0;
	ll fillbags = 0;
	cin >> n >> k;
	pair<ll, ll> jew[MAX];
	multiset<ll> bag;

	for (ll i = 0; i < n; i++)
		cin >> jew[i].first >> jew[i].second;
	for (ll i = 0; i < k; i++) {	//set, multiset 컨테이너는 삽입 즉시 오름차순으로 정렬이 된다.
		ll a;
		cin >> a;
		bag.insert(a);
	}
	sort(jew, jew + n, com);

	for (ll i = 0; i < n; i++) {
		if (fillbags == k) break;
		multiset<ll>::iterator whatbag = bag.lower_bound(jew[i].first);	//그냥 lower_bound가 아닌 multiset.lower_bound를 써야 시간복잡도가 O(nlogn)이 되어 시간초과가 안난다.
		if (whatbag == bag.end()) continue;
		bag.erase(whatbag);
		ans += jew[i].second;
		fillbags++;
	}

	cout << ans << endl;

}