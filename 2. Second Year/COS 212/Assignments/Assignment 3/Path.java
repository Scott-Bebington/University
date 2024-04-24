public class Path {
    private final Node startNode;
    private Node endNode;
    private final NodeList nodes;
    private final EdgeList edges;

    public Path(Node startNode, Node endNode, Node[] nodes, Edge[] edges)
    {
        this.startNode = startNode;
        this.endNode = endNode;

        this.nodes = new NodeList();
        if(nodes != null)
        {
            for(Node n: nodes)
            {
                this.nodes.addNode(n);
            }
        }
        
        this.edges = new EdgeList();
        if(edges != null)
        {
            for(Edge e: edges)
            {
                this.edges.addEdge(e);
            }
        }
    }

    public Path(Path other)
    {
        this.startNode = other.startNode;
        this.endNode = other.endNode;
        this.nodes = other.nodes;
        this.edges = other.edges;
    }

    public int computationalCostOfPath()
    {
        int cost = 0;
        for (int i = 0; i < edges.toArray().length; i++) 
        {
            cost += (edges.toArray()[i]).getCompTime();
        }
        return cost;
    }

    @SuppressWarnings("unchecked")
    public void appendToPath(Path p)
    {
        
    }

    public boolean validPath()
    {
        Node[] TempNodes = nodes.toArray();
        Edge[] TempEdges = edges.toArray();
        int i = 0;
        for (i = 0; i < TempEdges.length; i++) 
        {
            Node EndNode = TempNodes[i + 1];
            if(!TempEdges[i].getNext().getAnnotation().equals(EndNode.getAnnotation()))
            {
                return false;
            }
        }
        if(TempNodes[i].getAnnotation().equals(endNode.getAnnotation()))
        {
            return true;
        }
        return false;
    }

    public String toString()
    {
        //Provided function, do not alter!!!
        String str = "";
        str += ((Node)nodes.toArray()[0]).getAnnotation();
        for(Object e: edges.toArray()){
            str += e.toString();
        }
        return str;
    }


    // Helper functions
    public Node getStartNode()
    {
        return startNode;
    }

    public Node getEndNode()
    {
        return endNode;
    }

    public Node[] getNodes()
    {
        return nodes.toArray();
    }

    public Edge[] getEdges()
    {
        return edges.toArray();
    }
    
}
