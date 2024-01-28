import java.util.ArrayList;

interface Heap {

    public int size();

    public void build(ArrayList<Integer> arr);

    public void insert(int val);

    public void remove();
}