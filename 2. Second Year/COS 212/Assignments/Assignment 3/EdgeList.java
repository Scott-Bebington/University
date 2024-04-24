public class EdgeList 
{
    private Edge[] Nodes;
    private int size;
    
    public EdgeList() 
    {
        Nodes = new Edge[0];
        size = 0;
    }
    
    public void addEdge(Edge Edge) 
    {
        Edge[] newNodes = new Edge[size + 1];
        System.arraycopy(Nodes, 0, newNodes, 0, size);
        newNodes[size] = Edge;
        Nodes = newNodes;
        size++;
    }

    public boolean Contains(Edge n)
    {
        for(Edge node: Nodes)
        {
            if(node == n)
                return true;
        }
        return false;
    }
    
    public Edge[] toArray() 
    {
        return Nodes;
    }

    public int size()
    {
        return size;
    }

    public int indexOf(Edge n)
    {
        for(int i = 0; i < size; i++)
        {
            if(Nodes[i] == n)
                return i;
        }
        return -1;
    }
}