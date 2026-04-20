// 이 문제는 다음에 다시 풀어볼 것.
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int n, a[44], ret = INF;

void go(int here){
	if(here == n + 1){
        // 열은 게산하는 로직으로 진행
		int sum = 0; 
		for(int i = 1; i <= (1 << (n - 1)); i *= 2){ // 2의 배수, 즉 자리수를 기반으로 곱셈
			int cnt = 0; 
			for(int j = 1; j <= n; j++) if(a[j] & i)cnt++; // 특정 자리 수가 같으면 cnt++ 하기
			sum += min(cnt, n - cnt); // 더 적은것의 개수를 계산해서 뒤집을지 안뒤집을지 정한다.
		}
		ret = min(ret, sum);
		return;
	} 

    // 행은 뒤집기 진행. 양쪽 다 뒤집으면서 계산하기는 어려우니, 한쪽씩만 뒤집어서 계산하자.
	go(here + 1);
	a[here] = ~a[here]; // HHT = 100 -> TTH -> 011로 변경
	go(here + 1);
}

string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int value = 1;
        for(int j = 0; j < s.size(); j++){
			if(s[j] == 'T')a[i] |= value; 
			value *= 2;
		}
    }

    go(1);
	cout << ret << "\n";
    return 0;
}