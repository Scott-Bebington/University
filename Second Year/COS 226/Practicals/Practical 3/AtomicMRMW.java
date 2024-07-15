public class AtomicMRMW<T> implements Register<T> {

    private StampedValue<T>[] a_table; // array of atomic MRSW registers

    @SuppressWarnings("unchecked")
    public AtomicMRMW(int capacity, T init) {

        // System.out.println(capacity);
        a_table = (StampedValue<T>[]) new StampedValue[capacity];
        StampedValue<T> value = new StampedValue<T>(init);

        for (int j = 0; j < a_table.length; j++) {
            a_table[j] = value;
        }

    }

    @SuppressWarnings("unchecked")
    public void write(T value) {
        int me = getID();
        StampedValue<T> max = null;
        for (int i = 0; i < a_table.length; i++) {
            max = StampedValue.max(max, a_table[i]);
        }
        a_table[me] = new StampedValue<T>(max.stamp + 1, value);
        // System.out.println("Write Stamp: " + a_table[me].stamp + " Write Value: " + a_table[me].value);
    }

    @SuppressWarnings("unchecked")
    public T read() {
        // StampedValue<T> max = StampedValue.MIN_VALUE;
        StampedValue<T> max = null;
        for (int i = 0; i < a_table.length; i++) {
            max = StampedValue.max(max, a_table[i]);
        }
        // System.out.println(" Read Stamp: " + max.stamp);
        return max.value;
    }

    public int getID() {
        return Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
    }
}
