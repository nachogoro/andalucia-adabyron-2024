// Problema H - Scalextric
// Backtracking with profile-based memoization.
//
// Bit encoding for piece directions:
//   N = bit 0 (value 1), E = bit 1 (value 2),
//   S = bit 2 (value 4), W = bit 3 (value 8).
//
// We process cells in row-major order. The DP state is:
//   (r, c, profile, h) where
//     - profile has C bits: profile[c'] = south-going bit of the most
//       recently placed cell in column c'. For columns c' >= c this is
//       the south bit of row r-1 (the north constraint for the cell we
//       are about to place at (r, c')); for columns c' <  c it is the
//       south bit of row r (the north constraint for row r+1 later).
//     - h = east-going bit of cell (r, c-1), i.e. the west constraint
//       for cell (r, c). h is reset to 0 at the start of every row.
//
// Boundary conditions are encoded automatically:
//   - profile starts as 0, so first row has northReq = 0 everywhere.
//   - h starts as 0 at every row's first cell, so leftmost cells have
//     westReq = 0.
//   - For the last row we forbid pieces with a south line.
//   - For the last column we forbid pieces with an east line.
//
// Total states: R * C * 2^(C+1) <= 121 * 4096 ~= 5e5, each with up to
// 4 transitions, so well under 2e6 operations per test case.

#include <bits/stdc++.h>
using namespace std;

static const int N_BIT = 1;
static const int E_BIT = 2;
static const int S_BIT = 4;
static const int W_BIT = 8;

static int R, C;
static int profileShift;                     // = C + 1
static vector<vector<vector<int>>> pieceRotations;
static vector<int8_t> memo;

// 90° clockwise rotation of a piece's direction bitmask.
//   N -> E, E -> S, S -> W, W -> N.
static int rotate90(int bits) {
    int result = 0;
    if (bits & N_BIT) result |= E_BIT;
    if (bits & E_BIT) result |= S_BIT;
    if (bits & S_BIT) result |= W_BIT;
    if (bits & W_BIT) result |= N_BIT;
    return result;
}

// Distinct 90° rotations of a piece.
static vector<int> getRotations(int bits) {
    set<int> s;
    int cur = bits;
    for (int i = 0; i < 4; i++) {
        s.insert(cur);
        cur = rotate90(cur);
    }
    return vector<int>(s.begin(), s.end());
}

static int parsePiece(const string& s) {
    if (s == "x") return 0;
    int bits = 0;
    for (char ch : s) {
        switch (ch) {
            case 'N': bits |= N_BIT; break;
            case 'E': bits |= E_BIT; break;
            case 'S': bits |= S_BIT; break;
            case 'W': bits |= W_BIT; break;
            default: break;
        }
    }
    return bits;
}

static bool solve(int r, int c, int profile, int h) {
    if (r == R) return true; // every cell placed; profile is 0 by construction

    int idx = ((r * C + c) << profileShift) | (profile << 1) | h;
    if (memo[idx] != -1) return memo[idx] == 1;

    int northReq = (profile >> c) & 1;
    int westReq  = h;
    bool lastRow = (r == R - 1);
    bool lastCol = (c == C - 1);

    bool result = false;
    for (int bits : pieceRotations[r][c]) {
        int n = (bits >> 0) & 1;
        int e = (bits >> 1) & 1;
        int s = (bits >> 2) & 1;
        int w = (bits >> 3) & 1;

        if (n != northReq) continue;
        if (w != westReq)  continue;
        if (lastRow && s)  continue;   // bottom edge cannot send a line south
        if (lastCol && e)  continue;   // right  edge cannot send a line east

        int newProfile = (profile & ~(1 << c)) | (s << c);
        int newH = e;

        int nr = r, nc = c + 1;
        if (nc == C) { nr++; nc = 0; newH = 0; }

        if (solve(nr, nc, newProfile, newH)) {
            result = true;
            break;
        }
    }

    memo[idx] = result ? 1 : 0;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> R >> C && (R || C)) {
        pieceRotations.assign(R, vector<vector<int>>(C));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                string s;
                cin >> s;
                int bits = parsePiece(s);
                pieceRotations[r][c] = getRotations(bits);
            }
        }
        profileShift = C + 1;
        long long memoSize = (long long)R * C * (1LL << profileShift);
        memo.assign((size_t)memoSize, (int8_t)-1);

        cout << (solve(0, 0, 0, 0) ? "SOLUCIONABLE" : "NOSOLUCIONABLE") << '\n';
    }
    return 0;
}
