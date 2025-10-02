import java.util.Scanner;

class Accounts {
    String name;
    int number;
    int totalBiaya;

    Accounts(String name, int number, int totalBiaya) {
        this.name = name;
        this.number = number;
        this.totalBiaya = totalBiaya;
    }
}

public class soal3_veiron {
    public static void main(String[] args) {
        Accounts[] akun = {
            new Accounts("Gavin", 1001, 250000),
            new Accounts("Ihsan", 1002, 175000),
            new Accounts("Nabila", 1003, 300000),
            new Accounts("Veiron", 1004, 220000),
            new Accounts("Arsyad", 1005, 195000),
            new Accounts("Rifqi", 1006, 410000),
            new Accounts("Yolanda", 1007, 280000),
            new Accounts("Nasywa", 1008, 360000),
            new Accounts("Bintang", 1009, 150000),
            new Accounts("Marchel", 1010, 500000)
        };

        Scanner input = new Scanner(System.in);
        Accounts akunLogin = null;
        int nAkun = 10;
        boolean isValid = false;

        System.out.print("Input your Account Number: ");
        int accountNumber = input.nextInt();

        for (int i = 0; i < nAkun; i++) {
            if (accountNumber == akun[i].number) {
                isValid = true;
                akunLogin = akun[i];
            }
        }

        if (isValid) {
            System.out.println("Your Account Number is Valid");
            System.out.println("Name: " + akunLogin.name);
            System.out.println("Account Number: " + akunLogin.number);
            System.out.println("Total Biaya: " + akunLogin.totalBiaya);
        } else {
            System.out.println("Account Number is Not Found");
        }
        input.close();
    }
}
