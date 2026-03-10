#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

int main() {
    while(scanf("%d", &n) != EOF) {
        ll cnt = 1;
        int ret = 1;
        while (true)
        {
            if (cnt % n == 0) {
                printf("%d\n", ret);
                break;
            } else {
                cnt = (cnt * 10) + 1;
                cnt %= n;
                ret++;
            }
        }
    }
    return 0;
}

/*
a의 배수 = a * x

+ 모듈러 연산을 생각하자
(a + b) % n = (a % n) + (b % n)
(a * b) % n = (a % n) * (b % n)
*/