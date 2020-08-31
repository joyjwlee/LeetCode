class Solution {
  public:
    // return parent of number n
    int _find(int n, vector<int> &parent) {
        if (parent[n] == -1)
            return n;
        parent[n] = _find(parent[n], parent);
        return parent[n];
    }

    // do union on n and m
    void _union(int n, int m, vector<int> &parent) {
        int np = _find(n, parent);
        int mp = _find(m, parent);
        // if they have differing parents, make one parent/child of another
        if (np != mp)
            parent[np] = mp;
    }

    int largestComponentSize(vector<int> &A) {
        // make parent array, set all to -1
        vector<int> parent(100005, -1);
        // loop through, union based on prime factorization
        for (int n : A) {
            // only check up to sqrt(n) by sieve
            for (int i = 2; i <= sqrt(n); i++) {
                // if factor, union n and both factors
                if (n % i == 0) {
                    _union(n, i, parent);
                    _union(n, n / i, parent);
                }
            }
        }

        // get size of all unions
        unordered_map<int, int> sizeOfUnion;
        for (int n : A)
            sizeOfUnion[_find(n, parent)]++;

        // find size of largest union
        int ans = 0;
        for (int n : A)
            if (sizeOfUnion[_find(n, parent)] > ans)
                ans = sizeOfUnion[_find(n, parent)];
        return ans;
    }
};