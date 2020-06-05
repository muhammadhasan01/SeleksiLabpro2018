#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ans;
    ans = (1 << 31);
    n = ans;
    assert(n != 0);
    m = n - 1;
    n = n + 1;
    assert(-n == m);
    cout << ans << '\n';

    return 0;
}