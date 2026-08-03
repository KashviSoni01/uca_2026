import java.util.*;

public class QuickSelect {

    static Random random = new Random();

    public static List<Integer> smallestK(int[] arr, int k) {

        quickSelect(arr, 0, arr.length - 1, k);

        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            result.add(arr[i]);
        }

        return result;
    }


    private static void quickSelect(int[] arr, int left, int right, int k) {

        if (left >= right)
            return;

        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k - 1)
            return;

        else if (pivotIndex > k - 1)
            quickSelect(arr, left, pivotIndex - 1, k);

        else
            quickSelect(arr, pivotIndex + 1, right, k);
    }


    private static int partition(int[] arr, int left, int right) {

        int randomIndex = left + random.nextInt(right - left + 1);

        swap(arr, randomIndex, right);

        int pivot = arr[right];

        int i = left;


        for (int j = left; j < right; j++) {

            if (arr[j] <= pivot) {

                swap(arr, i, j);
                i++;
            }
        }


        swap(arr, i, right);

        return i;
    }


    private static void swap(int[] arr, int i, int j) {

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }



    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);


        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();


        int[] arr = new int[n];


        System.out.println("Enter elements:");

        for(int i = 0; i < n; i++)
            arr[i] = sc.nextInt();


        System.out.print("Enter k: ");
        int k = sc.nextInt();


        List<Integer> result = smallestK(arr, k);


        System.out.println("Smallest " + k + " elements:");

        for(int x : result)
            System.out.print(x + " ");


        sc.close();
    }
}
