class Solution {
    public int minRotations(String s) {
        int cnt = 0;
        int n = s.length();
        int current = 0; // Pointer starts at 0
        
        for (int i = 0; i < n; i++) {
            int target = s.charAt(i) - '0'; // Convert char to actual digit value
            int diff = Math.abs(current - target);
            cnt += Math.min(diff, 10 - diff); // Minimum rotations in either direction
            current = target; // Update current pointer position
        }
        
        return cnt;
    }
}