class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int n = dimensions.length;//give no of rows
        double maxi_diagonal = 0;
        int maxarea = 0;
        

        for (int i = 0; i < n; i++) {
            int ele1 = dimensions[i][0];
            int ele2 = dimensions[i][1];
            int area = ele1*ele2;
            double temp_diagonal = Math.sqrt(ele1 * ele1 + ele2 * ele2);
            if (maxi_diagonal < temp_diagonal || (temp_diagonal==maxi_diagonal && area>maxarea)) {
                maxi_diagonal = temp_diagonal;
                maxarea=area;
            }

        }
        return maxarea;
    }
}