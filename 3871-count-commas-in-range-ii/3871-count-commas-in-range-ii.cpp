class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000)
            return 0;

        long long threshhold = 1000;
        long long total = 0;
        while (n >= threshhold) {

            total += (n - threshhold + 1);
            if (threshhold > 1e15)
                break;
            threshhold *= 1000;
        }
        return total;
    }
};