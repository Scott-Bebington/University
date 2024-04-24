public class Node {
    private final String annotation;
    private final EdgeList edges;
    
    public Node(String annot) 
    {
        annotation = annot;
        edges = new EdgeList();
    }
    
    public void addEdge(Node nextNode, String annotation, int compTime) 
    {
        Edge edge = new Edge(annotation, nextNode, compTime);
        edges.addEdge(edge);
    }

    public void addEdge(Edge edge) 
    {
        edges.addEdge(edge);
    }
    
    public String getAnnotation() 
    {
        return annotation;
    }
    
    public Edge[] getEdges() 
    {
        return edges.toArray();
    }

    public String toString()
    {
        //Provided function, do not alter!!!
        String res = annotation + ":\n";
        if(edges.toArray().length == 0)
            res += "\t" + "No out going edges" + "\n";
        else
            for(Object e: edges.toArray())
            {
                res += "\t" + e.toString() + "\n";
            } 
        return res;
    }
    
}
