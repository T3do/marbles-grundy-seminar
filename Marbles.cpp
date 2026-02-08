#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;

    const int MAX = 100;              // given li, ci <= 100
    const int INF = 1'000'000'000;    // "insta-win" marker
    static int g[MAX + 1][MAX + 1];

    // mex helper
    // mex values on this board stay small; 1024 is large enough.
    const int LIM = 1024;
    static int seen[LIM];
    int stamp = 1;

    // Mark insta-win cells: (i,0), (0,i), (i,i), and (0,0)
    g[0][0] = INF;
    for (int i = 1; i <= MAX; ++i) {
        g[i][0] = INF;
        g[0][i] = INF;
        g[i][i] = INF;
    }

    // Precompute g[l][c] for all other cells (l != c, l,c >= 1)
    for (int l = 1; l <= MAX; ++l) {
        for (int c = 1; c <= MAX; ++c) {
            if (l == c) continue; // already INF

            ++stamp;

            // Reachable by decreasing l: (l-u, c) => all rows < l in same column
            for (int i = 0; i < l; ++i) {
                int val = g[i][c];
                if (val < LIM) seen[val] = stamp;
            }

            // Reachable by decreasing c: (l, c-u) => all cols < c in same row
            for (int j = 0; j < c; ++j) {
                int val = g[l][j];
                if (val < LIM) seen[val] = stamp;
            }

            // Reachable by decreasing both equally: (l-u, c-u)
            int m = min(l, c);
            for (int t = 1; t <= m; ++t) {
                int val = g[l - t][c - t];
                if (val < LIM) seen[val] = stamp;
            }

            int mex = 0;
            while (mex < LIM && seen[mex] == stamp) ++mex;
            g[l][c] = mex;
        }
    }

    int xorsum = 0;
    for (int i = 0; i < N; ++i) {
        int l, c;
        cin >> l >> c;

        // If any marble starts on an insta-win cell, first player wins immediately.
        if (g[l][c] == INF) {
            cout << "Y\n";
            return 0;
        }
        xorsum ^= g[l][c];
    }

    cout << (xorsum ? 'Y' : 'N') << "\n";
    return 0;
}
