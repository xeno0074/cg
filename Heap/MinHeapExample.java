import java.util.ArrayList;

public class MinHeapExample {

    public static void main(String[] args) {

        ArrayList<Integer> arrayList = new ArrayList<>() {
            {
                add(-24);
                add(-99);
                add(-62);
                add(-5);
                add(-3);
            }
        };

        MinHeap mh = new MinHeap(arrayList);

        System.out.println("Input ArrayList: " + arrayList.toString());
        System.out.println("Heap: " + mh.toString());

        mh.remove();

        System.out.println("Heap: " + mh.toString());

        mh.insert(3);

        System.out.println("Heap: " + mh.toString());

        int length = arrayList.size();
        for (int i = 0; i < length; ++i) {
            System.out.println("getMin: " + mh.getMin());
            mh.remove();
        }
    }
}