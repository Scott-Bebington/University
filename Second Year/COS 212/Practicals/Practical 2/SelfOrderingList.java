abstract class SelfOrderingList<T extends Comparable<T>> 
{
    public Node<T> head = null;

    public void insert(T data) 
    {
        Node<T> newNode = new Node<T>(data);
        if (head == null) 
        {
            head = newNode;
            head.prev = null;
            head.next = null;
            return;
        }

        Node<T> ptr = head;
        while (ptr.next != null) {
            ptr = ptr.next;
        }
        ptr.next = newNode;
        ptr.next.prev = ptr;
        return;
    }

    public void remove(T data) 
    {
        if (head == null) 
        {
            return;
        }
        if(head.next == null)
        {
            head = null;
            return;
        }
        if (head.data.equals(data))
        {
            head = head.next;
            head.prev = null;
            return;
        }
        Node<T> ptr = head;
        while (ptr != null && ptr.data.compareTo(data) != 0) 
        {
            ptr = ptr.next;
        }
        if (ptr != null) 
        {
            if (ptr.next == null)
            {
                ptr.prev.next = null;
                return;
            }
            ptr.prev.next = ptr.next;
            ptr.next.prev = ptr.prev;
            return;
        }
    }

    public abstract void access(T data);

    public abstract SelfOrderingList<T> getBlankList();
}
