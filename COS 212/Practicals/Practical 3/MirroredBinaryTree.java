public class MirroredBinaryTree<T extends Comparable<T>> extends BinaryTree<T> {
    @Override
    public boolean contains(T data) 
    {
        if (find(data) != null) 
        {
            return true;
        }
        return false;
    }

    @Override
    public void depthFirstTraversal() 
    {
        if (root == null) 
        {
            return;
        }
        depthHelper(root);
    }

    public void depthHelper(Leaf<T> ptr) 
    {
        if (ptr.right != null) 
        {
            depthHelper(ptr.right);
        }
        System.out.println(ptr.toString());
        if (ptr.left != null) 
        {
            depthHelper(ptr.left);
        }
    }

    @Override
    public int numLeavesInTree() 
    {
        if (root == null) 
        {
            return 0;
        }
        int count = 0;
        count = LeavesHelper(root);
        return count;
    }

    public int LeavesHelper(Leaf<T> ptr) 
    {
        if (ptr == null) 
        {
            return 0;
        }
        return 1 + LeavesHelper(ptr.left) + LeavesHelper(ptr.right);
    }

    @Override
    public int height() 
    {
        if (root == null || (root.left == null && root.right == null))
        {
            return 0;
        }
        return heightHelper(root) - 1;
    }

    public int heightHelper(Leaf<T> ptr)
    {
        if (ptr != null) 
        {
            if (heightHelper(ptr.left) > heightHelper(ptr.right))
            {
                return 1 + heightHelper(ptr.left);
            }
            else
            {
                return 1 + heightHelper(ptr.right);
            }
        }
        return 0;
    }

    @Override
    public Leaf<T> findParent(T data) 
    {
        if (root == null) 
        {
            return null;
        }
        if (root.data.compareTo(data) == 0) 
        {
            System.out.println(root.toString());
            return null;
        }
        return findparentHelper(root, data);
        // return null;
    }

    public Leaf<T> findparentHelper(Leaf<T> ptr, T data) 
    {
        if (ptr != null && ptr.data.compareTo(data) <= 0) 
        {
            System.out.println(ptr.toString());
            if (ptr.left != null && ptr.left.data.compareTo(data) == 0) 
            {
                return ptr;
            }
            return findparentHelper(ptr.left, data);
        } 
        else if (ptr != null && ptr.data.compareTo(data) >= 0) 
        {
            System.out.println(ptr.toString());
            if (ptr.right != null && ptr.right.data.compareTo(data) == 0) 
            {
                return ptr;
            }
            return findparentHelper(ptr.right, data);
        }
        // System.out.println(ptr);
        return null;
    }

    @Override
    public void insert(T data) 
    {
        super.insert(data, false);
    }

    @Override
    public Leaf<T> find(T data) 
    {
        if (root != null) 
        {
            if (root.data.compareTo(data) == 0) 
            {
                System.out.println(root.toString());
                return root;
            }
            return findHelper(root, data);
        }
        return null;
    }

    public Leaf<T> findHelper(Leaf<T> ptr, T data) 
    {
        if (ptr != null && ptr.data.compareTo(data) < 0) 
        {
            System.out.println(ptr.toString());
            return findHelper(ptr.left, data);
        } 
        else if (ptr != null && ptr.data.compareTo(data) > 0) 
        {
            System.out.println(ptr.toString());
            return findHelper(ptr.right, data);
        }
        if (ptr != null)
        {
            System.out.println(ptr.toString());
            return ptr;
        }
        return null;
    }

    @Override
    public boolean perfectlyBalanced() 
    {
        if (root == null)
        {
            return false;
        }
        if (root.left == null && root.right == null)
        {
            return true;
        }
        if (getLeaves(root.left) != getLeaves(root.right))
        {
            return false;
        }
        return true;
    }

    public int getLeaves(Leaf<T> ptr) 
    {
        if (ptr == null) 
        {
            return 0;
        }
        return 1 + LeavesHelper(ptr.left) + LeavesHelper(ptr.right);
    }

    @Override
    public BinaryTree<T> convertTree() 
    {
        if (root == null)
        {
            return null;
        }
        BinaryTree<T> newTree = new StandardBinaryTree<T>();
        if (root.left == null && root.right == null)
        {
            newTree.root = new Leaf<T>(root.data);
            return newTree;
        }
        newTree.root = convertTreeHelper(root);
        return newTree;
    }

    public Leaf<T> convertTreeHelper(Leaf<T> ptr)
    {
        if (ptr != null) 
        {
            Leaf<T> tempPtr = new Leaf<T>(ptr.data);
            tempPtr.left = convertTreeHelper(ptr.right);
            tempPtr.right = convertTreeHelper(ptr.left);
            return tempPtr;
        }
        return null;
    }
}
