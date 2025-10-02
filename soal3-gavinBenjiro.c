#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Accounts {
    char name[20];
    int number;
    int totalBiaya;
};

int main() {
    struct Accounts akun[20] = {
        {"Gavin", 1001, 250000},
        {"Ihsan", 1002, 175000},
        {"Nabila", 1003, 300000},
        {"Veiron", 1004, 220000},
        {"Arsyad", 1005, 195000},
        {"Rifqi", 1006, 410000},
        {"Yolanda", 1007, 280000},
        {"Nasywa", 1008, 360000},
        {"Bintang", 1009, 150000},
        {"Marchel", 1010, 500000}
    };

    struct Accounts akunLogin;
    int nAkun = 10;
    int accountNumber;
    bool isValid = false;

    printf("Input your Account Number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < nAkun; i++) {
        if (accountNumber == akun[i].number) {
            isValid = true;
            akunLogin = akun[i]; 
        }
    }

    printf("\n");
    if (isValid) {
        printf("Your Account Number is Valid\n");
        printf("Name: %s\n", akunLogin.name);
        printf("Account Number: %d\n", akunLogin.number);
        printf("Total Biaya: Rp.%d\n", akunLogin.totalBiaya);
    } else {
        printf("Account Number is Not Found\n");
    }

    return 0;
}
