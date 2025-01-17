#include <bits/stdc++.h>

using namespace std;

const int N = 30;
const int M = 30;
const int S = 300;
const int L = M * 26 + 25;

int n, m, l;
char axis;
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
    cin >> axis >> s;
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
    if (axis == 'N') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m * len - 1; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    } else if (axis == 'Y') {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m * len - 1; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    } else if (axis == 'X') {
        for (int i = 0; i < n; i++) {
            for (int j = m * len - 2; j >= 0; j--) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}