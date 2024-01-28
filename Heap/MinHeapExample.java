public class MinHeapExample {

    public static void main(String[] args) {

        int arr[] = { 24, 99, 62, 5, 3 };
        MinHeap mh = new MinHeap(arr);

        System.out.println(mh.toString());

        for (int i = 0; i < arr.length; ++i) {
            System.out.println(mh.getMin());
            mh.remove();
        }
    }
}