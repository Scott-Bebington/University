public class IterativeTraverse<T extends Comparable<T>> extends Traverser<T>{
    public IterativeTraverse()
    {
        this.list = null;
    };
    
    public IterativeTraverse(SelfOrderingList<T> list)
    {
        this.list = list;
        this.list.head = list.head;
        Node<T> thisptr = this.list.head;
        Node<T> ptr = list.head;
        while (ptr.next != null)
        {
            thisptr.next = ptr.next;
            thisptr = thisptr.next;
            ptr = ptr.next;
        }

    }

    @Override
    public SelfOrderingList<T> reverseList() 
    {
       
        if (list.head == null)
        {
            return null;
        } 
        
        Node<T> ptr = list.head;
        while (ptr.next != null)
        {
            ptr = ptr.next;
        }
        SelfOrderingList<T> newList = list.getBlankList();

        while (ptr != null)
        {
            newList.insert(ptr.data);
            ptr = ptr.prev;
        }
        return newList;
    }

    @Override
    public boolean contains(T data) 
    {
        Node<T> ptr = list.head;
        while (ptr != null)
        {
            if (ptr.data.compareTo(data) == 0)
            {
                return true;
            }
            ptr = ptr.next;
        }
        return false;
    }

    @Override
    public String toString() 
    {
        String str = "";
        Node<T> ptr = list.head;

        while (ptr != null)
        {
            str += "->" + ptr.toString();
            ptr = ptr.next;
        }
        return str;
    }

    @Override
    public Node<T> get(int pos) 
    {
        if (list.head == null)
        {
            return null;
        }

        Node<T> ptr = list.head;
        int count = 0;
        while (ptr != null)
        {
            if (count == pos)
            {
                return ptr;
            }
            count++;
            ptr = ptr.next;
        }
        return null;
    }

    @Override
    public Node<T> find(T data) 
    {
        if (list.head == null)
        {
            return null;
        }
        Node<T> ptr = list.head;
        while (ptr != null)
        {
            if (ptr.data.compareTo(data) == 0)
            {
                return ptr;
            }
            ptr = ptr.next;
        }
        return null;
    }

    @Override
    public int size() 
    {
        if (list.head == null)
        {
            return 0;
        }
        int count = 0;
        Node<T> ptr = list.head;
        while (ptr != null)
        {
            count ++;
            ptr = ptr.next;
        }
        return count;
    }

    @Override
    public SelfOrderingList<T> clone(SelfOrderingList<T> otherList) 
    {
        SelfOrderingList<T> newList = list.getBlankList();
        Node<T> ptr = otherList.head;
        while (ptr != null)
        {
            newList.insert(ptr.data);
            ptr = ptr.next;
        }
        return newList;
    }
}
