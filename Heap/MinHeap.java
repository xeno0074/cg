class MinHeap implements Heap {

    private int[] arr;
    private int size;

    private void swap(int x, int y) {

        int tmp = arr[x];
        arr[x] = arr[y];
        arr[y] = tmp;
    }

    MinHeap(int[] arr) {

        build(arr);
    }

    @Override
    public void heapify(int node) {

        int lchild = 2 * node + 1;
        int rchild = 2 * node + 2;

        int smallest = node;

        if (lchild < size && arr[lchild] < arr[smallest]) {

            smallest = lchild;
        }
        if (rchild < size && arr[rchild] < arr[smallest]) {

            smallest = rchild;
        }

        if (smallest != node) {

            swap(node, smallest);
            heapify(smallest);
        }
    }

    @Override
    public void build(int[] arr) {

        this.arr = arr;
        this.size = arr.length;

        for (int i = (size - 1) / 2; i >= 0; --i) {
            heapify(i);
        }
    }

    @Override
    public void remove() {
        swap(size - 1, 0);
        size--;

        heapify(0);
    }

    public int getMin() {
        return arr[0];
    }

    @Override
    public String toString() {

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < size; ++i) {

            Integer e = arr[i];
            sb.append(e.toString());

            if (i < size - 1) {

                sb.append(", ");
            }
        }

        return sb.toString();
    }
}