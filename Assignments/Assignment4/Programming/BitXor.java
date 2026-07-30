import java.util.Scanner;

public class BitXor {

    public static int bitXor(int x, int y) {
        return ~(~(x & ~y) & ~(~x & y));
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter x: ");
        int x = sc.nextInt();

        System.out.print("Enter y: ");
        int y = sc.nextInt();

        System.out.println("bitXor(" + x + ", " + y + ") = " + bitXor(x, y));

        sc.close();
    }
}
