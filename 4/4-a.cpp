#include <bits/stdc++.h>
using namespace std;
const int maxInt = 987654321;
int n, p, f, s, v, ret = maxInt;
vector<array<int, 5>> a;

map<int, vector<vector<int>>> map_ret;

int main()
{
    cin >> n;
    cin >> p >> f >> s >> v;
    for (int i = 0; i < n; i++) {
        int mp, mf, ms, mv, mc;
        cin >> mp >> mf >> ms >> mv >> mc;
        a.push_back({mp, mf, ms, mv, mc});
    }

    for (int i = 0; i < (1 << n); i++) {
        int tp = 0, tf = 0, ts = 0, tv = 0, tc = 0;
        vector<int> vect;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                vect.push_back(j + 1);
                tp += a[j][0];
                tf += a[j][1];
                ts += a[j][2];
                tv += a[j][3];
                tc += a[j][4];
            }
        }

        if (tp >= p && tf >= f && ts >= s && tv >= v) {
            if (tc <= ret) {
                ret = min(ret, tc);
                map_ret[ret].push_back(vect);
            }
        }
        
    }
    if (ret == maxInt) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ret << '\n';
    sort(map_ret[ret].begin(), map_ret[ret].end());
    for(int a : map_ret[ret][0]){
        cout << a << " ";
    }
    return 0;
}

/*
Struct 사용하기
동일한 ret일 경우, 모두 추가한 다음 sort 하기

답안지 케이스
#include<bits/stdc++.h>
using namespace std;  
typedef long long ll; 
const int INF = 987654321;
int n, mp, mf, ms, mv;
int b, c, d, e, ret = INF, sum;
struct A{
	int mp, mf, ms, mv, cost; 
}a[16]; 
map<int, vector<vector<int>>> ret_v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; 
    cin >> mp >> mf >> ms >> mv;  
    for(int i = 0; i < n; i++){
    	cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;  
	}
	for(int i = 1; i < (1 << n); i++){
		b = c = d = e = sum = 0;
        vector<int> v; 
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
                v.push_back(j + 1);
				b += a[j].mp;
				c += a[j].mf;
				d += a[j].ms;
				e += a[j].mv;
				sum += a[j].cost;
			}
		}
		if(b >= mp && c >= mf && d >= ms && e >= mv){
			if(ret >= sum){
				ret = sum;
                ret_v[ret].push_back(v); 
			}
		} 
	}  
	if(ret == INF) cout << -1 << '\n';
	else{
        sort(ret_v[ret].begin(), ret_v[ret].end());  
		cout << ret << "\n";
		for(int a : ret_v[ret][0]){
			cout << a << " ";
		} 
	}  
	return 0; 
}
*/