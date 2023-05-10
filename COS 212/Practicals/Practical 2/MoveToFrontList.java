public class MoveToFrontList<T extends Comparable<T>> extends SelfOrderingList<T> {
    @Override
    public SelfOrderingList<T> getBlankList() 
    {
        return new MoveToFrontList<T>();
    }

    @Override
    public void access(T data) 
    {
        if (head.data.compareTo(data) == 0)
        {
            return;
        }
        Node<T> ptr = head;
        while (ptr != null)
        {
            if (ptr.data.compareTo(data) == 0)
            {
                remove(data);
                head.prev = ptr;
                ptr.next = head;
                ptr.prev = null;
                head = ptr;
            }
            ptr = ptr.next;

        }
    }
}
