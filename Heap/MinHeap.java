import java.util.ArrayList;

class MinHeap implements Heap {

    private ArrayList<Integer> arr;
    private int size;

    private void swap(int x, int y) {

        Integer tmp = arr.get(x);
        arr.set(x, arr.get(y));
        arr.set(y, tmp);
    }

    MinHeap(ArrayList<Integer> arr) {

        build(arr);
    }

    @Override
    public int size() {
        return size;
    }

    private void heapifyDown(int node) {

        int lchild = 2 * node + 1;
        int rchild = 2 * node + 2;

        int smallest = node;

        if (lchild < size && arr.get(lchild) < arr.get(smallest)) {

            smallest = lchild;
        }
        if (rchild < size && arr.get(rchild) < arr.get(smallest)) {

            smallest = rchild;
        }

        if (smallest != node) {

            swap(node, smallest);
            heapifyDown(smallest);
        }
    }

    private void heapifyUp(int node) {

        int parent = (node - 1) / 2;

        if (parent >= 0 && arr.get(node) < arr.get(parent)) {

            swap(node, parent);

            heapifyUp(parent);
        }
    }

    @Override
    public void build(ArrayList<Integer> arr) {

        this.arr = arr;
        this.size = arr.size();

        for (int i = (size - 1) / 2; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    @Override
    public void remove() {

        swap(size - 1, 0);
        arr.remove(size - 1);
        size = arr.size();

        heapifyDown(0);
    }

    public int getMin() {

        return arr.get(0);
    }

    @Override
    public void insert(int val) {

        arr.add(val);
        size = arr.size();

        heapifyUp(size - 1);
    }

    @Override
    public String toString() {

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < size; ++i) {

            Integer e = arr.get(i);
            sb.append(e.toString());

            if (i < size - 1) {

                sb.append(", ");
            }
        }

        return sb.toString();
    }
}