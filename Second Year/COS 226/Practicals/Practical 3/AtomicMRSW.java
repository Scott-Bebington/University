public class AtomicMRSW<T> implements Register<T> {

    long lastStamp;
    private StampedValue<T>[][] a_table; // each entry is SRSW atomic

    @SuppressWarnings("unchecked")
    public AtomicMRSW(T init, int readers) {
        a_table = (StampedValue<T>[][]) new StampedValue[readers][readers];
        StampedValue<T> value = new StampedValue<T>(init);
        for (int i = 0; i < readers; i++) {
            for (int j = 0; j < readers; j++) {
                a_table[i][j] = value;
            }
        }
        lastStamp = 0;
    }

    @SuppressWarnings("unchecked")
    public T read() {
        int me = getID();
        StampedValue<T> value = a_table[me][me];
        for (int i = 0; i < a_table.length; i++) 
        {
            value = StampedValue.max(value, a_table[i][me]);
        }
        for (int i = 0; i < a_table.length; i++) 
        {
            if (i == me)
                continue;

            a_table[me][i] = value;
        }
        return value.value;
    }

    public void write(T v) 
    {
        lastStamp++;
        StampedValue<T> value = new StampedValue<T>(lastStamp, v);
        for (int i = 0; i < a_table.length; i++) {
            a_table[i][i] = value;
        }
    }

    public int getID() {
        return Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
    }
}
