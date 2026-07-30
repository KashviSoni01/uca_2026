import java.util.Scanner;

public class BitAnd {

    public static int bitAnd(int x, int y) {
        return ~(~x | ~y);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter x: ");
        int x = sc.nextInt();

        System.out.print("Enter y: ");
        int y = sc.nextInt();

        int result = bitAnd(x, y);

        System.out.println("bitAnd(" + x + ", " + y + ") = " + result);

        sc.close();
    }
}
