#include <bits/stdc++.h>
using namespace std;

int n, ret, temp, x, c;
vector<int> v;
stack<int> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    cin >> x;

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        while (s.size()) {
            c = s.top() + v[i];
            if (c > x) {
                s.pop();
            } else if (c == x) {
                ret++;
                s.pop();
                break;
            } else {
                s.push(v[i]);
                break;
            }
        }
        s.push(v[i]);
    }

    cout << ret;
}

/**
 *  투포인터 방식
 *  int l =  0, r = n - 1;
    while(l < r){
        if(a[l] + a[r] == x)r--, ret++;
        else if(a[l] + a[r] > x)r--;
        else if(a[l] + a[r] < x)l++;
    }
 */