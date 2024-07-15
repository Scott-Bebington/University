public class StampedValue <T> 
{
    
    public long stamp;
    public T value;

    // initial value with zero timestamp
    public StampedValue(T init) 
    {
        this.stamp = 0;
        this.value = init;
    }
    // later values with timestamp provided
    public StampedValue(long stamp, T value) 
    {
        this.stamp = stamp;
        this.value = value;
    }

    @SuppressWarnings("rawtypes")
    public static StampedValue max(StampedValue x, StampedValue y) 
    {
        if (x != null && y != null)
        {
            if (x.stamp > y.stamp)
                return x;
            return y;
        }
        else if (x == null)
            return y;
        else
            return x;
    }
}
