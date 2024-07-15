public class NodeList 
{
    private Node[] Nodes;
    private int size;
    
    public NodeList() 
    {
        Nodes = new Node[0];
        size = 0;
    }
    
    public void addNode(Node Node) 
    {
        Node[] newNodes = new Node[size + 1];
        System.arraycopy(Nodes, 0, newNodes, 0, size);
        newNodes[size] = Node;
        Nodes = newNodes;
        size++;
    }

    public boolean Contains(Node n)
    {
        for(Node node: Nodes)
        {
            if(node == n)
                return true;
        }
        return false;
    }
    
    public Node[] toArray() 
    {
        return Nodes;
    }

    public int size()
    {
        return size;
    }

    public int indexOf(Node n)
    {
        for(int i = 0; i < size; i++)
        {
            if(Nodes[i] == n)
                return i;
        }
        return -1;
    }
}