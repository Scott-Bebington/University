public class Treap<T extends Comparable<T>> {
    public Node<T> root = null;

    @Override
    public String toString() {
        if (root == null) {
            return "";
        }

        return root.toString() + "\n" + toString(root, "");
    }

    private String toString(Node<T> curr, String pre) {
        if (curr == null)
            return "";
        String res = "";

        if (curr.left != null) {
            if (curr.right != null) {
                res += pre + "├(L)─ " + curr.left.toString() + "\n" + toString(curr.left, pre + "|    ");
            } else {
                res += pre + "└(L)─ " + curr.left.toString() + "\n" + toString(curr.left, pre + "     ");
            }
        }

        if (curr.right != null) {
            res += pre + "└(R)─ " + curr.right.toString() + "\n" + toString(curr.right, pre + "   ");
        }
        return res;
    }

    /*
     * Don't change anything above this line
     */

    public void insert(T data) throws DatabaseException 
    {
        Node<T> newNode = new Node<T>(data);
        // System.out.println(newNode.priority);
        if (root == null) 
        {
            root = newNode;
            return;
        }
        if (DataChecker(data)) 
        {
            // access(data);
            throw DatabaseException.duplicateInsert(data);
        }
        Node<T> ptr = root;
        Node<T> prevPtr = null;
        while (ptr != null) 
        {
            prevPtr = ptr;
            if (data.compareTo(ptr.data) > 0) 
            {
                ptr = ptr.right;
            } 
            else 
            {
                ptr = ptr.left;
            }
        }
        if (data.compareTo(prevPtr.data) > 0) 
        {
            prevPtr.right = newNode;
        } 
        else 
        {
            prevPtr.left = newNode;
        }

        Node<T> Parent = prevPtr;
        Node<T> Node = newNode;
        while (Parent != null && Parent.priority <= Node.priority)
        {
            // System.out.println("Node: " + Node);
            // System.out.println("Parent: " + Parent);
            if(Node.data.compareTo(Parent.data) > 0)
            {
                // System.out.println("Left Rotation" + "\n");
                leftRotation(Parent, Node);
            }
            else
            {
                // System.out.println("Right Rotation" + "\n");
                rightRotation(Parent, Node);
            }
            Node = getParentNode(root, Parent.data);
            Parent = getParentNode(root, Node.data);
            
        }
    }

    public void leftRotation(Node<T> parent, Node<T> rightchild)
    {
        Node<T> grandParent = getParentNode(root, parent.data);
        Node<T> left = rightchild.left;

        if (grandParent != null)
        {
            if (grandParent.data.compareTo(parent.data) > 0)
            {
                grandParent.left = rightchild;
            }
            else
            {
                grandParent.right = rightchild;
            }
        }
        else
        {
            root = rightchild;
        }
        if (left != null)
        {
            parent.right = left;
        }
        else
        {
            parent.right = null;
        }
        rightchild.left = parent;
    }

    public void rightRotation(Node<T> parent, Node<T> leftchild)
    {
        Node<T> grandParent = getParentNode(root, parent.data);
        Node<T> right = leftchild.right;

        if (grandParent != null)
        {
            if (grandParent.data.compareTo(parent.data) > 0)
            {
                grandParent.left = leftchild;
            }
            else
            {
                grandParent.right = leftchild;
            }
        }
        else
        {
            root = leftchild;
        }
        if (right != null)
        {   
            
            parent.left = right;
        }
        else
        {
            parent.left = null;
        }
        leftchild.right = parent;
    }

    public Node<T> getParentNode(Node<T> ptr, T NodeData)
    {
        if (ptr == null || ptr.data.compareTo(NodeData) == 0)
        {
            return null;
        }
        Node <T> parentPtr = null;
        while (ptr != null)
        {
            if (ptr.data.compareTo(NodeData) == 0) 
            {
                return parentPtr;
            } 
            else if (ptr.data.compareTo(NodeData) < 0) 
            {
                parentPtr = ptr;
                ptr = ptr.right;
            } 
            else 
            {
                parentPtr = ptr;
                ptr = ptr.left;
            } 
        }
        return null;
    }

    public boolean DataChecker(T data) 
    {
        if (root == null) 
        {
            return false;
        }
        return datacheckHelper(root, data);
    }

    public boolean datacheckHelper(Node<T> ptr, T data) 
    {
        if (ptr == null) 
        {
            return false;
        }
        if (ptr.data.compareTo(data) == 0) 
        {
            return true;
        } 
        else if (ptr.data.compareTo(data) < 0) 
        {
            return datacheckHelper(ptr.right, data);
        } 
        else 
        {
            return datacheckHelper(ptr.left, data);
        }
    }

    public Node<T> remove(T data) 
    {
        if (!DataChecker(data) || root == null)
        {
            return null;
        }
        if (root.left == null && root.right == null)
        {
            Node<T> temp = root;
            root = null;
            return temp;
        }
        Node<T> ptr = root;
        Node<T> prevPtr = null;
        while (ptr.data.compareTo(data) != 0)
        {
            if (data.compareTo(ptr.data) > 0)
            {
                prevPtr = ptr;
                ptr = ptr.right;
            }
            else
            {
                prevPtr = ptr;
                ptr = ptr.left;
            }
        }
        Node<T> deleteNodeParent = ptr;
        while (deleteNodeParent.left != null || deleteNodeParent.right != null)
        {
            if (deleteNodeParent.left == null)
            {
                Node<T> deleteNodeChild = deleteNodeParent.right;
                leftRotation(deleteNodeParent, deleteNodeChild);
            }
            else if (deleteNodeParent.right == null)
            {
                Node<T> deleteNodeChild = deleteNodeParent.left;
                rightRotation(deleteNodeParent, deleteNodeChild);
            }
            else if (deleteNodeParent.left.priority > deleteNodeParent.right.priority)
            {
                Node<T> deleteNodeChild = deleteNodeParent.left;
                rightRotation(deleteNodeParent, deleteNodeChild);
            }
            else
            {
                Node<T> deleteNodeChild = deleteNodeParent.right;
                leftRotation(deleteNodeParent, deleteNodeChild);
            }
        }

        Node<T> nonLeaf = getParentNode(root, deleteNodeParent.data);

        if (nonLeaf.right != null && nonLeaf.right.equals(deleteNodeParent))
        {
            nonLeaf.right = null;
        }
        else
        {
            nonLeaf.left = null;
        }
        return deleteNodeParent;
    }

    public Node<T> access(T data) 
    {
        // System.out.println("Node being accessed: " + data);
        if (!DataChecker(data) || root == null)
        {
            return null;
        }
        // System.out.println("Root node: " + root);
        Node<T> ptr = root;
        Node<T> prevPtr = null;
        while (ptr != null && ptr.data.compareTo(data) != 0)
        {
            // System.out.println("Checking: " + ptr.data);
            if (data.compareTo(ptr.data) > 0)
            {
                prevPtr = ptr;
                ptr = ptr.right;
            }
            else
            {
                prevPtr = ptr;
                ptr = ptr.left;
            }
        }

        ptr.priority++;
        Node<T> Parent = prevPtr;
        Node<T> Node = ptr;

        while (Parent != null && Parent.priority <= Node.priority)
        {
            if (Node.data.compareTo(Parent.data) > 0)
            {
                leftRotation(Parent, Node);
            }
            else
            {
                rightRotation(Parent, Node);
            }
            Node = getParentNode(root, Parent.data);
            Parent = getParentNode(root, Node.data);
        }
        return ptr;
    }

}
