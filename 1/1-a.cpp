#include <bits/stdc++.h>
using namespace std;

/*
1. 아홉 난쟁이의 키가 주어진다.
2. 일곱 난쟁이의 키의 합이 100이 되야 한다.
- 아무렇게나 막 더해도 되겠네? -> 조합 
3. 일곱 난쟁이의 키를 오름차순으로 출력한다.
*/

vector<int> a(9), ret;

int k = 7, n = 9;

void combi(int start, vector<int> &b, int sum) {
    if(b.size() == k && sum == 100) {
        ret = b;
        return;
    }

    if(b.size() == k) {
        return;
    }

    for (int i = start + 1; i < n; i++) {
        b.push_back(a[i]);
        sum += a[i];
        combi(i, b, sum);
        b.pop_back();
        sum -= a[i];
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }

    vector<int> b;
    combi(-1, b, 0);

    sort(ret.begin(), ret.end());

    for (int i = 0; i < 7; i++)
    {
        cout << ret[i] << "\n";
    }
    return 0;
}

/*
이렇게도 풀 수 있지만,

9C7 = 9C2 즉,
7개를 더해서 100을 만들 수 있지만
반대로 전체를 더한 다음, 2개만 뺏을 때, 100이 되면 된다.
로직적으로 이게 더 빠를듯

*/