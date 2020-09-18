class Solution {
  public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
        // get entire sum
        int tot = 0;
        for (int n : distance)
            tot += n;

        // if start loops around
        int size = distance.size();
        if (start > destination)
            destination += size;

        // get start to dest
        int dist = 0;
        for (int i = start; i < destination; i++)
            dist += distance[i % size];

        // return smaller
        return (dist < tot - dist) ? dist : tot - dist;
    }
};