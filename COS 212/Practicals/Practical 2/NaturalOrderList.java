public class NaturalOrderList<T extends Comparable<T>> extends SelfOrderingList<T> {
    @Override
    public SelfOrderingList<T> getBlankList() 
    {
        return new NaturalOrderList<T>();
    }

    @Override
    public void access(T data) 
    {
        return;
    }

    @Override
    public void insert(T data) 
    {
        // System.out.println(data);
        Node<T> newNode = new Node<T>(data), ptr = null, prevPtr = null;
        if (head == null)
        {
            head = newNode;
            head.next = null;
            head.prev = null;
            return;
        }
        ptr = head;
        
        if (data.compareTo(head.data) > 0)
        {
            // System.out.println(data + " is greater than " + head.data);
            ptr = newNode;
            ptr.next = head;
            head.prev = ptr;
            head = ptr;
            return;
        }
        while (ptr != null)
        {
            if (data.compareTo(ptr.data) > 0)
            {
                newNode.next = ptr;
                newNode.prev = ptr.prev;
                ptr.prev.next = newNode;
                ptr.prev = newNode;
                return;
            }
            prevPtr = ptr;
            ptr = ptr.next;
        }
        prevPtr.next = newNode;
        newNode.prev = prevPtr;
    }
}
