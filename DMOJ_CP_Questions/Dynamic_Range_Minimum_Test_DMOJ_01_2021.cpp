#include <bits/stdc++.h>
using namespace std;

// C++ Program to implement
// iterative segment tree.
#include <bits/stdc++.h>
using namespace std;

void build_st(vector<int>& segtree,
                            vector<int>& a, int n)
{
    // assign values to leaves of the segment tree
    for (int i = 0; i < n; i++)
        segtree[n + i] = a[i];

    /* assign values to internal nodes
    to compute maximum in a given range */
    for (int i = n - 1; i >= 1; i--)
        segtree[i] = min(segtree[2 * i],
                         segtree[2 * i + 1]);
}

void update(vector<int>& segtree, int pos, int value,
            int n)
{
    // change the index to leaf node first
    pos += n;

    // update the value at the leaf node
    // at the exact index
    segtree[pos] = value;

    while (pos > 1) {

        // move up one level at a time in the tree
        pos >>= 1;

        // update the values in the nodes in
        // the next higher level
        segtree[pos] = min(segtree[2 * pos],
                           segtree[2 * pos + 1]);
    }
}

int query(vector<int>& segtree, int left, int
                                                    right,
                int n)
{
    /* Basically the left and right indices will move
        towards right and left respectively and with
        every each next higher level and compute the
        maximum at each height. */
    // change the index to leaf node first
    left += n;
    right += n;

    // initialize maximum to a very low value
    int mi = 1000001;

    while (left < right) {

        // if left index in odd
        if (left & 1) {
            mi = min(mi, segtree[left]);

            // make left index even
            left++;
        }

        // if right index in odd
        if (right & 1) {

            // make right index even
            right--;

            mi = min(mi, segtree[right]);
        }

        // move to the next higher level
        left /= 2;
        right /= 2;
    }
    return mi;
}

// Driver code
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int M;
    cin >> N >> M;
    vector<int> a(N);
    vector<int> segtree(N * 4);

    int n = a.size();
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    build_st(segtree, a, n);
    for (int a = 0; a < M; a++) {
        char op;
        int p1, p2;
        cin >> op >> p1 >> p2;
        if(op == 'M') {
            int i = p1;
            int x = p2;
            update(segtree, i, x, n);
        } else {
            int i = p1, j = p2;
int ans = query(segtree, i, j + 1, n);
            cout << ans << '\n';
        }
    }
    return 0;


}

/*
Sample Input

5 10
35232
390942
649675
224475
18709
Q 1 3
M 4 475689
Q 2 3
Q 1 3
Q 1 2
Q 3 3
Q 2 3
M 2 645514
M 2 680746
Q 0 4

Sample Output

224475
224475
224475
390942
224475
224475
35232
*/
