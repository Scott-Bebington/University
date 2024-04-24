public class Edge 
{
    private final String annotation;
    private final Node nextNode;
    private final int computationalTime;

    public Edge(String annot, Node nextNode, int compTime)
    {
        this.annotation = annot;
        this.nextNode = nextNode;
        this.computationalTime = compTime;
    }

    public Node getNext()
    {
        return this.nextNode;
    }

    public String getAnnotation()
    {
        return this.annotation;
    }

    public int getCompTime()
    {
        return this.computationalTime;
    }

    public String toString()
    {
        //Provided function, do not alter!!!
        String res = "-> " + annotation + " -[" + computationalTime + "]-"; 
        
        if(nextNode == null)
            res += "> NULL";
        else
            res += "> " + nextNode.getAnnotation();

        return res;
    }
}
