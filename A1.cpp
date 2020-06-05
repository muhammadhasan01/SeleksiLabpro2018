#include <bits/stdc++.h>

using namespace std;

const int N = 5;
const int M = 4;
const int S = 100;
const int L = 103;

string s;
char ans[2 * N][S * 5];
char CC[2 * N][2 * L];

inline void fill(int pos, int ord) {
    int bound_ans = pos * M;
    int bound_CC = ord * M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans[i][bound_ans + j] = CC[i][bound_CC + j];
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    string str;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, str);
        assert((int) str.size() == L);
        for (int j = 0; j < L; j++) {
            CC[i][j] = str[j];
        }
        CC[i][L] = ' ';
    }
    int n = s.length();
    for (int i = 0; i < n; i++) {
        assert('A' <= s[i] && s[i] <= 'Z');
        int ord = s[i] - 'A';
        fill(i, ord);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4 * n - 1; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}