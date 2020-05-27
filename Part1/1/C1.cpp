#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
pair<int, int> p[N];
int a[N];
int bit[N];
int ord[N], val[N];
int middle;

void add(int x, int val) {
    for ( ; x <= n; x += x & -x) {
        bit[x] += val;
    }
}

int get(int x) {
    if (x == 0) return 0;
    int ret = 0;
    for ( ; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

int getMedian() {
    int l = 1, r = n, ret = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(mid) >= middle) {
            r = mid - 1;
            ret = mid;
        } else {
            l = mid + 1;
        }
    }
    assert(ret != -1);
    return val[ret];
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    middle = (m + 1) / 2;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        ord[p[i].second] = i;
        val[i] = p[i].first;
    }
    for (int i = 1; i <= m; i++) {
        add(ord[i], 1);
    }
    int maxMedian = getMedian();
    for (int i = m + 1; i <= n; i++) {
        add(ord[i - m], -1);
        add(ord[i], 1);
        int res = getMedian();
        maxMedian = max(maxMedian, res);
    }
    cout << maxMedian << '\n';

    return 0;
}