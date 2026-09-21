class Solution {
    public boolean lemonadeChange(int[] bills) {
        int sum5 = 0, sum10 = 0, sum20 = 0;
        int n = bills.length;
        for (int i = 0; i < n; i++) {
            int curr = bills[i];
            if (curr == 5) {
                sum5 += 5;
                continue;
            }
            if (curr == 10) {
                if (sum5 >= 5) {
                    sum5 -= 5;
                    sum10 += 10;
                } else {
                    return false;
                }
            } else if (curr == 20) {
                if (sum10 >= 10 && sum5 >= 5) {
                    sum5 -= 5;
                    sum10 -= 10;
                    sum20 += 20;
                } else if(sum5>=15){
                    sum5-=15;
                    sum20+=20;
                }
                else return false;
            }
        }
        return true;
    }
}