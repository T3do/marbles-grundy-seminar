#include <bits/stdc++.h>
using namespace std;

// Solve "Marbles" impartial game via Sprague–Grundy DP on (l,c) with moves:
// (l-u,c), (l,c-u), (l-u,c-u), u>0, staying inside board.
// Overall result is xor of Grundy numbers of each marble.

int main() {
    int N;
    cin >> N;

    const int MAX = 100;          // given li, ci <= 100
    int g[MAX + 1][MAX + 1];      // Grundy table

    // mex helper
    // Grundy values on a 101x101 board are small; 512 is large enough.
    const int LIM = 512;
    static int seen[LIM];
    int stamp = 1;

    // Compute Grundy for all (l,c) from (0,0) to (100,100)
    for (int l = 0; l <= MAX; ++l) {
        for (int c = 0; c <= MAX; ++c) {
            if (l == 0 && c == 0) {
                g[l][c] = 0;
                continue;
            }

            ++stamp; // new mex marking session so that it does not interfere with past cells

            // Moves: (l-u, c)
            for (int u = 1; u <= l; ++u) {
                int val = g[l - u][c];
                if (val < LIM) seen[val] = stamp;
            }
            // Moves: (l, c-u)
            for (int u = 1; u <= c; ++u) {
                int val = g[l][c - u];
                if (val < LIM) seen[val] = stamp;
            }
            // Moves: (l-u, c-u)
            for (int u = 1; u <= min(l, c); ++u) {
                int val = g[l - u][c - u];
                if (val < LIM) seen[val] = stamp;
            }

            // mex
            int mex = 0;
            while (mex < LIM && seen[mex] == stamp) ++mex;
            g[l][c] = mex;
        }
    }

    int xorsum = 0;
    for (int i = 0; i < N; ++i) {
        int l, c;
        cin >> l >> c;
        xorsum ^= g[l][c];
    }

    cout << (xorsum ? 'Y' : 'N') << "\n";
    return 0;
}
