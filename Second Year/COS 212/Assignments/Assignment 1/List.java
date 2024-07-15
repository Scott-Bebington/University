public class List<T> 
{
    public int length;
    public Node<T> head;

    public List() 
    {
        head = null;
        length = 0;
    }

    public String toString() 
    {
        String nodelist = "";
        Node<T> ptr = head;
        if (ptr == null)
        {
            return "";
        }
        
        while (ptr.next != null)
        {
            nodelist += ptr.data + ",";
            ptr = ptr.next;
        }
        nodelist += ptr.data;
        return nodelist;
    }

    public void append(T val) 
    {
        Node<T> newNode = new Node<>(val), ptr = head;
        if (head == null) 
        {
            head = newNode;
            length++;
            return;
        }
        while (ptr.next != null) 
        {
            ptr = ptr.next;
        }
        ptr.next = newNode;
        length++;
    }

    public boolean remove(T val) 
    {
        if (head == null)
        {
            return false;
        }
        Node<T> ptr = head, prevPtr = null;
        if (head.data.equals(val)) 
        {
            head = head.next;
            length--;
            return true;
        }

        while (ptr != null && !ptr.data.equals(val)) 
        {
            prevPtr = ptr;
            ptr = ptr.next;
        }

        if (ptr != null) 
        {
            prevPtr.next = ptr.next;
            length--;
            return true;
        }
        return false;
    }

    public boolean remove(List<T> val) 
    {
        if (val == null)
        {
            return false;
        }
        Node<T> ptr = val.head;
        int count = 0;
        while (ptr != null) 
        {
            if (remove(ptr.data))
            {
                count ++;
            }
            ptr = ptr.next;
        }
        if (count != 0) 
        {
            return true;
        }
        return false;
    }

    public boolean contains(T search) 
    {
        if (head == null)
        {
            return false;
        }
        Node<T> ptr = head;
        while (ptr != null)
        {
            if (ptr.data.equals(search))
            {
                return true;
            }
            ptr = ptr.next;
        }
        return false;
    }

    public boolean equals(List<T> other) 
    {
        Node<T> ptr = head, otherPtr = other.head;
        int count = 1;
        if(other.length != length)
        {
            return false;
        }
        while (ptr.next != null)
        {
            if (ptr.data.equals(otherPtr.data)) 
            {
                count ++;
            }
            ptr = ptr.next;
            otherPtr = otherPtr.next;
        }
        if (count == length) 
        {
            return true;
        }
        return false;
    }
}
