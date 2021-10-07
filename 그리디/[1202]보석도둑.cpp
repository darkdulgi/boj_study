/*
�������� ���� ����̴� �������� �б�� ����ߴ�.
����̰� �� ���������� ������ �� N�� �ִ�. �� ������ ���� Mi�� ���� Vi�� ������ �ִ�. ����̴� ������ K�� ������ �ְ�, �� ���濡 ���� �� �ִ� �ִ� ���Դ� Ci�̴�.
���濡�� �ִ� �� ���� ������ ���� �� �ִ�.
����̰� ��ĥ �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� N�� K�� �־�����. (1 �� N, K �� 300,000)
���� N�� �ٿ��� �� ������ ���� Mi�� Vi�� �־�����. (0 �� Mi, Vi �� 1,000,000)
���� K�� �ٿ��� ���濡 ���� �� �ִ� �ִ� ���� Ci�� �־�����. (1 �� Ci �� 100,000,000)
��� ���ڴ� ���� �����̴�.

ù° �ٿ� ����̰� ��ĥ �� �ִ� ���� ������ ���� �ִ��� ����Ѵ�.
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
	for (ll i = 0; i < k; i++) {	//set, multiset �����̳ʴ� ���� ��� ������������ ������ �ȴ�.
		ll a;
		cin >> a;
		bag.insert(a);
	}
	sort(jew, jew + n, com);

	for (ll i = 0; i < n; i++) {
		if (fillbags == k) break;
		multiset<ll>::iterator whatbag = bag.lower_bound(jew[i].first);	//�׳� lower_bound�� �ƴ� multiset.lower_bound�� ��� �ð����⵵�� O(nlogn)�� �Ǿ� �ð��ʰ��� �ȳ���.
		if (whatbag == bag.end()) continue;
		bag.erase(whatbag);
		ans += jew[i].second;
		fillbags++;
	}

	cout << ans << endl;

}