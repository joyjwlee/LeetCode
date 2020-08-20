class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // get individual areas
        long int r1 = abs(A - C) * abs(B - D), r2 = abs(E - G) * abs(F - H);
        // get overlapping
        long int w = 0, h = 0;
        if (min(C, G) > max(A, E))
            w = min(C, G) - max(A, E);
        if (min(D, H) > max(B, F))
            h = min(D, H) - max(B, F);
        // return
        return r1 + r2 - w * h;
    }
};