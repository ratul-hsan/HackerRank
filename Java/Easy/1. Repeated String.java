import java.util.*;

public class Solution {
    String problemUrl = "https://www.hackerrank.com/challenges/repeated-string";

    public static long repeatedString(String s, long n) {
        long occurrence = 0;
        int length = s.length(), firstOccurence = length;
        long quotient = 0, remainder = 0;

        if (n >= length) {
            for (int i = 0; i < length; i++)
                if (s.charAt(i) == 'a') {
                    occurrence++;
                    if (firstOccurence == length)
                        firstOccurence = i;
                }
            quotient = n / length;
            remainder = n % length;
        } else {
            remainder = n;
            quotient = 0;
        }
        if (n == length)
            return occurrence;

        occurrence *= quotient;

        if (firstOccurence < remainder)
            for (int i = 0; i < remainder; i++)
                if (s.charAt(i) == 'a')
                    occurrence++;

        return occurrence;
    }
    
    public static double pow(long base, long power) {
        if (power < 2) {
            if (power < 0)
                return 1 / pow(base, power * -1);
            else
                return power == 1 ? base : 1;
        }

        long result = base * base;
        
        for (int i = 3; i <= power; i++)
            result *= base;
        return result;
    }
    
    public static void main(String[] args) {
        System.out.println(repeatedString("a", (long) pow(10, 12)));
    }
}