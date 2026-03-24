#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    int i = 666;
    for (;; i++) {
        if (to_string(i).find("666") != string::npos)
            n--;
        if (n == 0)
            break;
    }

    cout << i << '\n';
}

/*
무식하게 푸는 것이 가능 1 <= n <= 10000 이기 때문에 숫자가 크지 않다.

*/