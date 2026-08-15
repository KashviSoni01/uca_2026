import java.util.Scanner;

public class findNumber {

    public static int findnumber(int[] nums) {

        int ans = 0;

        for (int bit = 0; bit < 32; bit++) {

            int count = 0;
            for (int num : nums) {

                if (((num >> bit) & 1) == 1) {
                    count++;
                }
            }

            if (count % 3 == 1) {
                ans |= (1 << bit);
            }
        }

        return ans;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] nums = new int[n];

        System.out.println("Enter array elements:");

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int result = findnumber(nums);

        System.out.println("Number repeated 4 times: " + result);

        sc.close();
    }
}
