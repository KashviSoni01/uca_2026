import java.util.*;

class Solution {

    int reversePairs = 0;

    public int reversePairs(int[] nums) {
        mergeSort(nums, 0, nums.length - 1);
        return reversePairs;
    }

    private void mergeSort(int[] arr, int l, int r) {
        if (l >= r) {
            return;
        }

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        countPairs(arr, l, mid, r);

        merge(arr, l, mid, r);
    }

    private void countPairs(int[] arr, int l, int mid, int r) {
        int right = mid + 1;

        for (int left = l; left <= mid; left++) {
            while (right <= r && arr[left] > 2L * arr[right]) {
                right++;
            }
            reversePairs += (right - (mid + 1));
        }
    }

    private void merge(int[] arr, int l, int mid, int r) {
        int[] temp = new int[r - l + 1];

        int i = l;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= r) {
            temp[k++] = arr[j++];
        }

        for (int index = 0; index < temp.length; index++) {
            arr[l + index] = temp[index];
        }
    }
}

public class CountSignificantReversePairs {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> list = new ArrayList<>();

        while (sc.hasNextInt()) {
            list.add(sc.nextInt());
        }

        int[] nums = new int[list.size()];

        for (int i = 0; i < list.size(); i++) {
            nums[i] = list.get(i);
        }

        Solution sol = new Solution();
        System.out.println(sol.reversePairs(nums));

        sc.close();
    }
}
