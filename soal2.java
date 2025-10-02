import java.util.Scanner;

public class soal2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int input, basefee = 0, addfee = 0, starthour, endhour, total;
        String pickup;

        System.out.print("berapa device yang akan di service? ");
        input = scanner.nextInt();

        System.out.print("akan dikerjakan dari jam berapa hingga berapa? ");
        starthour = scanner.nextInt();
        endhour = scanner.nextInt();

        System.out.print("pickup dan dropoff(y/n) ");
        pickup = scanner.next();

        if (input == 1 || input == 2) {
            basefee = 50;
            addfee = 0;
        } else if (input >= 3 && input <= 10) {
            basefee = 100;
            addfee = 10 * input;
        } else if (input > 10) {
            basefee = 500;
            addfee = 10 * input;
        }

        if ((starthour < 9 || starthour > 17) || (endhour < 9 || endhour > 17)) {
            basefee = basefee * 2;
        }

        if (pickup.equals("y")) {
            basefee = basefee / 2;
        }

        total = basefee + addfee;
        System.out.println("total cost: " + total);

        scanner.close();
    }
}
