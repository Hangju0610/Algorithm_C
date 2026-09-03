#include <bits/stdc++.h>
using namespace std;
string a, b;
int n, t;

string add(string a, string b) {
    string result;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    n = max(a.size(), b.size());
    for (int i = 0; i < n; i++) {
        int tempA = (i < (int)a.size()) ? a[i] - '0' : 0;
        int tempB = (i < (int)b.size()) ? b[i] - '0' : 0;
        int temp = 0;
        if (tempA >= 0)
        {
            temp += tempA;
        }
        if (tempB >= 0) {
            temp += tempB;
        }
        temp += t;
        t = temp / 10;
        result.append(to_string(temp % 10));
        // cout << a[i] << " " << b[i] << " " << temp << " " << t << " " << result << '\n';
    }
    if (t != 0) {
        result.append(to_string(t));
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    cin >> a >> b;
    cout << add(a, b) << '\n';
}
