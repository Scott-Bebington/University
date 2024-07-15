public class TransposeList<T extends Comparable<T>> extends SelfOrderingList<T> {
    @Override
    public SelfOrderingList<T> getBlankList() {
        return new TransposeList<T>();
    }

    @Override
    public void access(T data) 
    {
        if(head != null)
        {
            Node<T> ptr = head.next;
            Node<T> prevPtr = head;
            while(ptr != null)
            {
                if(ptr.data.compareTo(data) == 0)
                {
                    if(prevPtr.prev == null)
                    {
                        head = ptr;
                    }
                    else
                    {
                        prevPtr.prev.next = ptr;
                    }
                    if(ptr.next != null)
                    {
                        ptr.next.prev = prevPtr;
                    }
                    ptr.prev = prevPtr.prev;
                    prevPtr.next = ptr.next;

                    ptr.next = prevPtr;
                    prevPtr.prev = ptr;
                    return;
                }
                else
                {
                    prevPtr = ptr;
                    ptr = ptr.next; 
                }
            }
        }
        else
        {
            return;
        }
    }


}
