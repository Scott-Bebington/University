public class RecursiveTraverse<T extends Comparable<T>> extends Traverser<T>{
    public RecursiveTraverse()
    {
        this.list = null;
    }
    
    public RecursiveTraverse(SelfOrderingList<T> list)
    {
        this.list = list.getBlankList();
        Node<T> ptr = list.head;
        constructorhelper(ptr, this.list);
    }
    public void constructorhelper(Node<T> ptr, SelfOrderingList<T> nlist)
    {
        if (ptr == null)
        {
            return;
        }
        else
        {
            nlist.insert(ptr.data);
            constructorhelper(ptr.next, nlist);
        }
    }

    @Override
    public SelfOrderingList<T> reverseList() 
    {
        if (this.list == null)
        {
            return null;
        }
        SelfOrderingList<T> nlist = this.list.getBlankList();
        Node<T> ptr = this.list.head;
        reverseListHelper(ptr, nlist);
        return nlist;
    }
    public void reverseListHelper(Node<T> ptr, SelfOrderingList<T> nlist)
    {
        if (ptr == null)
        {
            return;
        }
        else
        {
            reverseListHelper(ptr.next, nlist);
            nlist.insert(ptr.data);
        }
    }

    @Override
    public boolean contains(T data) 
    {
        if (this.list == null)
        {
            return false;
        }
        Node<T> ptr = this.list.head;
        boolean flag = containsHelper(ptr, data);
        return flag;
    }
    public boolean containsHelper (Node<T> ptr, T data)
    {
        if (ptr == null)
        {
            return false;
        }
        else
        {
            if (ptr.data.compareTo(data) == 0)
            {
                return true;
            }
            return containsHelper(ptr.next, data);
        }
    }

    @Override
    public String toString() 
    {
        if (this.list == null)
        {
            return "";
        }
        String str = tostringhelper("", this.list.head);
        return str;
    }
    public String tostringhelper(String str, Node<T> ptr)
    {
        if (ptr == null)
        {
            return str;
        }
        else
        {
            str += "->";
            str += ptr.toString();
            return tostringhelper(str, ptr.next);
        }
    }

    @Override
    public Node<T> get(int pos) 
    {
        // System.out.println(this.list.head);
        if (this.list == null)
        {
            return null;
        }
        int count = 0;
        Node<T> ptr = list.head;
        return getHelper(count, pos, ptr);
        
    }
    public Node<T> getHelper(int count, int pos, Node<T> ptr)
    {
        // System.out.println(ptr);
        if (ptr == null)
        {
            return null;
        }
        if (count == pos)
        {
            // System.out.println("Found");
            return ptr;
        }
        else
        {
            count = count + 1;
            return getHelper(count, pos, ptr.next);
        }
    }

    @Override
    public Node<T> find(T data) 
    {
        if (this.list == null)
        {
            return null;
        }
        Node<T> ptr = this.list.head;
        return findHelper(data, ptr);
    }
    public Node<T> findHelper(T data, Node<T> ptr)
    {
        if (ptr == null)
        {
            return null;
        }
        if (ptr.data.compareTo(data) == 0)
        {
            return ptr;
        }
        else
        {
            return findHelper(data, ptr.next);
        }
    }

    @Override
    public int size() 
    {
        if (this.list == null)
        {
            return 0;
        }
        Node<T> ptr = this.list.head;
        int count = 0;
        return sizeHelper(count, ptr);
    }
    public int sizeHelper(int count, Node<T> ptr)
    {
        if (ptr == null)
        {
            return count;
        }
        else
        {
            count++;
            return sizeHelper(count, ptr.next);
        }
    }

    @Override
    public SelfOrderingList<T> clone(SelfOrderingList<T> otherList) 
    {
        SelfOrderingList<T> listtoclone = list.getBlankList();
        constructorhelper(otherList.head, listtoclone);
        return listtoclone;
    }
}
