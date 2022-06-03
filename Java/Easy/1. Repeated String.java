import java.util.*;

public class RepeatedString {
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
    
    public static void main(String[] args) {
        System.out.println(repeatedString("aab", (long) Math.pow(10, 12)));
    }
}