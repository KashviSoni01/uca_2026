import java.util.*;

class Solution {
    int count = 0;

    public int inversionCount(int arr[]) {
        mergeSort(arr, 0, arr.length - 1);
        return count;
    }

    public void mergeSort(int arr[], int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    public void merge(int[] arr, int l, int mid, int r) {
        int[] temp = new int[r - l + 1];

        int i = l;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= r) {
            if (arr[i] > arr[j]) {
                temp[k++] = arr[j++];
                count += (mid - i + 1);
            } else {
                temp[k++] = arr[i++];
            }
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= r)
            temp[k++] = arr[j++];

        for (int index = 0; index < temp.length; index++)
            arr[l + index] = temp[index];
    }
}

public class CountInversion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> list = new ArrayList<>();

        while (sc.hasNextInt()) {
            list.add(sc.nextInt());
        }

        int[] arr = new int[list.size()];
        for (int i = 0; i < list.size(); i++)
            arr[i] = list.get(i);

        Solution sol = new Solution();
        System.out.println(sol.inversionCount(arr));

        sc.close();
    }
}
