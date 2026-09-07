/**
 * 무게를 적게 담을 수 있는 가방부터 보석 넣기
 * 보석 중 가치가 최대인 보석만 하나만 넣는 것.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
double temp;
priority_queue<double> pq;
vector<double> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &temp);
        if (pq.size() == 5) {
            pq.push(temp);
            pq.pop();
        } else {
            pq.push(temp);
        }
    }
    while (pq.size()) {
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());
    for (double i : v) printf("%.1lf\n", i);
}