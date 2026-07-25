import java.util.*;

class Solution {

    class Pair {
        int value;
        int index;

        Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    int[] ans;

    public List<Integer> countSmaller(int[] nums) {

        int n = nums.length;
        ans = new int[n];

        Pair[] arr = new Pair[n];

        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(nums[i], i);
        }

        mergeSort(arr, 0, n - 1);

        List<Integer> result = new ArrayList<>();

        for (int x : ans) {
            result.add(x);
        }

        return result;
    }

    private void mergeSort(Pair[] arr, int l, int r) {

        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }

    private void merge(Pair[] arr, int l, int mid, int r) {

        Pair[] temp = new Pair[r - l + 1];

        int i = l;
        int j = mid + 1;
        int k = 0;

        int rightCount = 0;

        while (i <= mid && j <= r) {

            if (arr[i].value > arr[j].value) {

                rightCount++;
                temp[k++] = arr[j++];

            } else {

                ans[arr[i].index] += rightCount;
                temp[k++] = arr[i++];
            }
        }

        while (i <= mid) {

            ans[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }

        while (j <= r) {
            temp[k++] = arr[j++];
        }

        for (int x = 0; x < temp.length; x++) {
            arr[l + x] = temp[x];
        }
    }
}


public class CountSmallerAfterSelf {

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

        List<Integer> result = sol.countSmaller(nums);

        for (int i = 0; i < result.size(); i++) {

            if (i > 0)
                System.out.print(" ");

            System.out.print(result.get(i));
        }

        sc.close();
    }
}
