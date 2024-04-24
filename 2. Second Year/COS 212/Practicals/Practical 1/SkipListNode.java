// This is used to remove the warnings which occur when using generics
@SuppressWarnings("unchecked")
public class SkipListNode<T extends Comparable<T>> 
{
    public T key;
    public SkipListNode<T>[] next;

    public SkipListNode(T key, int levels) 
    {
        this.key = key;
        this.next = new SkipListNode[levels];
        for (int i = 0; i < levels; i++) 
        {
            this.next[i] = null;
        }
    }

    @Override
    public String toString() 
    {
        
        return "[" + key.toString() + "]";
    }

    public String emptyString() 
    {
        String str = "--";
        for (int i = 0; i < key.toString().length(); i++) 
        {
            str += "-";
        }
        return str;
    }
}