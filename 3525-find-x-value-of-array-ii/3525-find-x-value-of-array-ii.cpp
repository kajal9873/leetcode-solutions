class Solution {
public:
    static int K; // modulus, 1..5

    struct Node {
        int prod;                 // product of this segment's elements, mod K
        int cnt[5][5];             // cnt[r][s] = # positions j in segment with (r * partialProduct_j) % K == s
    };

    static Node makeLeaf(long long val) {
        Node nd{};
        int a = (int)(val % K);
        nd.prod = a;
        memset(nd.cnt, 0, sizeof(nd.cnt));
        for (int r = 0; r < K; r++) {
            int s = (r * a) % K;
            nd.cnt[r][s] = 1;
        }
        return nd;
    }

    static Node identityNode() {
        Node nd{};
        nd.prod = 1 % K;
        memset(nd.cnt, 0, sizeof(nd.cnt));
        return nd;
    }

    static inline Node merge(const Node &L, const Node &R) {
        Node nd{};
        nd.prod = (L.prod * R.prod) % K;
        for (int r = 0; r < K; r++) {
            int r2 = (r * L.prod) % K;
            for (int s = 0; s < K; s++) {
                nd.cnt[r][s] = L.cnt[r][s] + R.cnt[r2][s];
            }
        }
        return nd;
    }

    int n;
    vector<Node> tree;

    void build(int node, int l, int r, vector<long long>& arr) {
        if (l == r) { tree[node] = makeLeaf(arr[l]); return; }
        int mid = (l + r) >> 1;
        build(2*node, l, mid, arr);
        build(2*node+1, mid+1, r, arr);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) { tree[node] = makeLeaf(val); return; }
        int mid = (l + r) >> 1;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return identityNode();
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) >> 1;
        Node left = query(2*node, l, mid, ql, qr);
        Node right = query(2*node+1, mid+1, r, ql, qr);
        return merge(left, right); // order matters: left first, then right
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        K = k;
        n = (int)nums.size();
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) arr[i] = nums[i];

        tree.assign(4*n, Node{});
        build(1, 0, n-1, arr);

        int r0 = 1 % K; // residue of the empty product (identity)
        vector<int> result;
        result.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n-1, index, value);
            Node res = query(1, 0, n-1, start, n-1);
            result.push_back(res.cnt[r0][x]);
        }
        return result;
    }
};

int Solution::K = 1;