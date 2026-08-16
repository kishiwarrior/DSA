class Solution {
    public boolean stoneGameIX(int[] stones) {
        // Step 1: Count individual remainders (0, 1, 2)
        int[] count = new int[3];
        for (int i = 0; i < stones.length; i++) {
            count[stones[i] % 3]++;
        }
        
        // Step 2: Handle cases based on whether '0' remainders are Even or Odd
        // If count[0] is even, '0' stones cancel each other out in terms of turn parity.
        if (count[0] % 2 == 0) {
            // Alice needs both 1s and 2s to exist to manipulate the running sums safely.
            return Math.min(count[1], count[2]) > 0;
        }
        
        // If count[0] is odd, the '0' stones shift the turn advantage.
        // Alice can win only if the difference between 1s and 2s is strictly greater than 2.
        return Math.abs(count[1] - count[2]) > 2;
    }
}