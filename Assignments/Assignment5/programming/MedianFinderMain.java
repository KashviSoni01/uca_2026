import java.util.PriorityQueue;
import java.util.Collections;

class MedianFinder {

    // Min-heap stores the larger half
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();

    // Max-heap stores the smaller half
    PriorityQueue<Integer> maxHeap =
            new PriorityQueue<>(Collections.reverseOrder());

    public MedianFinder() {
    }

    public void addNum(int num) {

        // minHeap can have one more element
        if (minHeap.size() == 0) {
            minHeap.add(num);
        }

        // minHeap currently has more elements
        else if (minHeap.size() > maxHeap.size()) {

            if (minHeap.peek() < num) {
                maxHeap.add(minHeap.poll());
                minHeap.add(num);
            } 
            else {
                maxHeap.add(num);
            }
        }

        // Both heaps have equal size
        else {

            if (num < maxHeap.peek()) {
                minHeap.add(maxHeap.poll());
                maxHeap.add(num);
            } 
            else {
                minHeap.add(num);
            }
        }
    }

    public double findMedian() {

        // Odd number of elements
        if (minHeap.size() > maxHeap.size()) {
            return minHeap.peek();
        }

        // Even number of elements
        return (minHeap.peek() + maxHeap.peek()) / 2.0;
    }
}


public class MedianFinderMain {

    public static void main(String[] args) {

        MedianFinder mf = new MedianFinder();

        // Insert numbers one by one
        mf.addNum(1);
        System.out.println("After inserting 1: " + mf.findMedian());

        mf.addNum(2);
        System.out.println("After inserting 2: " + mf.findMedian());

        mf.addNum(3);
        System.out.println("After inserting 3: " + mf.findMedian());

        mf.addNum(4);
        System.out.println("After inserting 4: " + mf.findMedian());

        mf.addNum(5);
        System.out.println("After inserting 5: " + mf.findMedian());
    }
}
