#include <stdio.h>

#define problemUrl "https://www.hackerrank.com/challenges/strong-password"

int minimumNumber(int n, char *password) {
    int minNum, length, hasUppercase, hasLowercase, hasSymbol, hasNumber;
    minNum = length = hasUppercase = hasLowercase = hasSymbol = hasNumber = 0;

    for (int i = 0; i < n; i++, length++) {
        if (password[i] >= 'A' && password[i] <= 'Z')
            hasUppercase = 1;
        else if (password[i] >= 'a' && password[i] <= 'z')
            hasLowercase = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            hasNumber = 1;
        else
            hasSymbol = 1;
    }

    int missing = !hasLowercase + !hasUppercase + !hasSymbol + !hasNumber;

    minNum = missing;
    length += missing;

    if (length < 6)
        minNum += 6 - length;
    return minNum;
}

int main(int argc, char *argv[]) {
    printf("%d", minimumNumber(5, "2bbbb"));
    return 0;
}