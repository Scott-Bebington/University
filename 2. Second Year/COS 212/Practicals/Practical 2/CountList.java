public class CountList<T extends Comparable<T>> extends SelfOrderingList<T>
{
    @Override
    public SelfOrderingList<T> getBlankList() 
    {
        return new CountList<T>();
    }

    @Override
    public void access(T data) 
    {
        if (head == null)
        {
            return;
        }
        if (head.data.compareTo(data) == 0)
        {
            head.accessCount++;
            return;
        }
        Node<T> ptr = head;
        while (ptr != null && ptr.data.compareTo(data) != 0)
        {
            ptr = ptr.next;
        }
        if (ptr == null)
        {
            return;
        }
        ptr.accessCount++;
        Node<T> secondPtr = head;
        while (secondPtr != null)
        {
            if (ptr.accessCount > secondPtr.accessCount)
            {
                if (secondPtr.prev == null)
                {
                    remove(data);
                    ptr.next = head;
                    ptr.prev = null;
                    head.prev = ptr;
                    head = ptr;
                    return;
                }
                if (secondPtr.next != null)
                {
                    remove(data);
                    secondPtr.prev.next = ptr;
                    ptr.next = secondPtr;
                    ptr.prev = secondPtr.prev;
                    secondPtr.prev = ptr;
                    return;
                }
                return;
            }
            secondPtr = secondPtr.next;
        }
    }
}
