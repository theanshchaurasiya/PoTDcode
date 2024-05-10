class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int len = arr.length;
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
                (a, b) -> {
                    double x = (double) a[0] / a[1];
                    double y = (double) b[0] / b[1];
                    return x > y ? -1 : 1;
                });

        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                minHeap.offer(new int[] { arr[i], arr[j] });
                if (minHeap.size() > k) {
                    minHeap.poll();
                }
            }
        }
        return minHeap.poll();
    }
}