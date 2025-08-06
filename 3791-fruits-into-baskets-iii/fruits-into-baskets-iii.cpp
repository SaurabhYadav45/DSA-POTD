#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> seg;

    void build(vector<int>& baskets, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = baskets[l];
            return;
        }
        int mid = (l + r) / 2;
        build(baskets, idx*2, l, mid);
        build(baskets, idx*2+1, mid+1, r);
        seg[idx] = max(seg[idx*2], seg[idx*2+1]);
    }

    // Find leftmost index with capacity >= val
    int query(int idx, int l, int r, int val) {
        if (seg[idx] < val) return -1; // no basket in range fits
        if (l == r) return l; // found basket
        int mid = (l + r) / 2;
        if (seg[idx*2] >= val) return query(idx*2, l, mid, val);
        return query(idx*2+1, mid+1, r, val);
    }

    void update(int idx, int l, int r, int pos) {
        if (l == r) {
            seg[idx] = 0; // mark basket used
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(idx*2, l, mid, pos);
        else update(idx*2+1, mid+1, r, pos);
        seg[idx] = max(seg[idx*2], seg[idx*2+1]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n = baskets.size();
        seg.assign(4*n, 0);

        // Build segment tree
        build(baskets, 1, 0, n-1);

        int unplaced = 0;
        for (int f : fruits) {
            int pos = query(1, 0, n-1, f);
            if (pos == -1) {
                unplaced++;
            } else {
                update(1, 0, n-1, pos);
            }
        }
        return unplaced;
    }
};
