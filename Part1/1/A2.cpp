#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int M = 15;
const int S = 100;
const int L = M * 26 + 25;

int n, m, l;
string s;
char ans[2 * N][S * 5];
char CC[2 * N][2 * L];

inline void fill(int pos, int ord) {
    int bound_ans = pos * m;
    int bound_CC = ord * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][bound_ans + j] = CC[i][bound_CC + j];
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    cin >> s;
    int len = s.size();
    l = m * 26 + 25;
    string str;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        assert((int) str.size() == l);
        for (int j = 0; j < l; j++) {
            CC[i][j] = str[j];
        }
        CC[i][l] = ' ';
    }
    ++m;
    for (int i = 0; i < len; i++) {
        assert('A' <= s[i] && s[i] <= 'Z');
        int ord = s[i] - 'A';
        fill(i, ord);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m * len; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}