public class AtomicSRSW<T> implements Register<T> {
    long lastStamp;
    StampedValue<T> lastRead;
    StampedValue<T> r_value;

    public AtomicSRSW(T init) 
    {
        this.r_value = new StampedValue<T>(init);
    }

    @SuppressWarnings("unchecked")
    public T read() {
        StampedValue<T> result = StampedValue.max(r_value, lastRead);
        lastRead = result;
        return result.value;
    }

    public void write(T v) {
        long stamp = lastStamp + 1;
        r_value = new StampedValue<T>(stamp, v);
        lastStamp = stamp;
    }
}