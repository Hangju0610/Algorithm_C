#include <bits/stdc++.h>
using namespace std;

/**
 * 시간 1.5 초 · 메모리 4 MB (하단 참고)
 * 메모리가 굉장히 작음
 * 1. 비트마스킹으로 진행
 */

int m, n, x;
char s[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf(" %d", &m);
    for (int i = 0; i < m; i++) {
        scanf(" %s %d", &s, &x);
        if (s[0] == 'a' && s[1] == 'd') n |= (1 << x);
        else if (s[0] == 'r') n &= ~(1 << x);
        else if (s[0] == 'c') printf("%d\n", (n&(1 << x)) ==0? 0: 1);
        else if (s[0] == 't') n ^= (1 << x);
        else if (s[0] == 'a' && s[1] == 'l')n = (1 << 21) - 1;
        else n = 0;
    }
}
