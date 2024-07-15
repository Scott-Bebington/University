public class CFG 
{
    private Node startNode;
    private NodeList nodes;
    private EdgeList edges;
    private NodeList exitNodes;

    public CFG()
    {
        startNode = null;
        nodes = new NodeList();
        edges = new EdgeList();
        exitNodes = new NodeList();
    }

    public CFG(Node[] nodes, Edge[] edges, Node sNode, Node[] exitNodes)
    {
        this.startNode = sNode;
        this.nodes = new NodeList();
        this.edges = new EdgeList();
        this.exitNodes = new NodeList();

        for(Node n: nodes)
        {
            this.nodes.addNode(n);
        }

        for(Edge e: edges)
        {
            this.edges.addEdge(e);
        }

        for(Node n: exitNodes)
        {
            this.exitNodes.addNode(n);
        }
    }

    public CFG(CFG other)
    {
        this.startNode = other.startNode;
        this.nodes = other.nodes;
        this.edges = other.edges;
        this.exitNodes = other.exitNodes;
    }

    public boolean isValid()
    {
        if(startNode == null)
        {
            return false;
        }
        if(exitNodes.size() == 0)
        {
            return false;
        }

        for(Node n: nodes.toArray())
        {
            // System.out.println(n.getAnnotation());
            for (int i = 0; i < exitNodes.size(); i++) 
            {
                if(isReachable(n, exitNodes.toArray()[i]))
                {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean isSESE()
    {
        if(isValid() && exitNodes.size() == 1)
            return true;
        else
            return false;
    }

    public CFG[] splitGraph()
    {
        if(isSESE())
        {
            CFG[] returnCGFArray = new CFG[1];
            returnCGFArray[0] = new CFG(this);
            return returnCGFArray;
        }
        // For each exit node EN , make a new CFG with the 1
            // current CFG s start node as the start node and EN
            // as the exit node .  

        // For every node N in the current CFG check if N can 2
            // reach each of the exit nodes . If it can then add
            // that node to the appropriate new CFG .

        // Remember to also add all the appropriate edges .
        CFG[] newCFGArray = new CFG[exitNodes.toArray().length];
        int count = 0;
        for(Node exitNode: exitNodes.toArray())
        {
            CFG newCFG = new CFG();
            newCFG.startNode = startNode;
            newCFG.exitNodes.addNode(exitNode);

            for(Node n: nodes.toArray())
            {
                if(isReachable(n, exitNode))
                {
                    Edge[] NsEdges = n.getEdges();
                    for (int i = 0; i < NsEdges.length; i++) 
                    {
                        if(isReachable(NsEdges[i].getNext(), exitNode))
                        {
                            newCFG.addEdge(NsEdges[i].getAnnotation(), n, NsEdges[i].getNext(), NsEdges[i].getCompTime());
                        }
                    }
                }
            }
            newCFGArray[count] = newCFG;
            count++;
        }
        return newCFGArray;
    }

    public boolean isReachable(Node startNode, Node goalNode) 
    {
        if(!nodes.Contains(goalNode) || !nodes.Contains(startNode))
        {
            return false;
        }
        boolean[] visited = new boolean[nodes.size()];
        return isReachableHelper(startNode, goalNode, visited);
    }

    private boolean isReachableHelper(Node currentNode, Node goalNode, boolean[] visited) 
    {
        if (currentNode == goalNode) 
        {
            return true;
        }

        int currentNodeIndex = nodes.indexOf(currentNode);
        visited[currentNodeIndex] = true;

        for (Edge edge : currentNode.getEdges()) 
        {
            Node nextNode = edge.getNext();
            int nextNodeIndex = nodes.indexOf(nextNode);

            if (!visited[nextNodeIndex] && isReachableHelper(nextNode, goalNode, visited)) 
            {
                return true;
            }
        }

        return false;
    }

    public int compTimeRequired(Path p)
    {
        return p.computationalCostOfPath();
    }

    public Path shortestCompTimePath(Node sN, Node gN)
    {
        Path[] paths = getSimplePaths();
        Path shortestPath = paths[0];
        int compTime = Integer.MAX_VALUE;

        for (int i = 0; i < paths.length; i++) 
        {
            if(paths[i].getStartNode().getAnnotation().equals(sN.getAnnotation())
            && paths[i].getEndNode().getAnnotation().equals(gN.getAnnotation())
            && compTimeRequired(paths[i]) < compTime)
            {
                compTime = compTimeRequired(paths[i]);
                shortestPath = paths[i];
            }
        }
        return shortestPath;
    }

    public Path[] getPrimePaths() 
    {
        Path[] simplePaths = getSimplePaths();
        Path[] primePaths = new Path[0];
    
        for (int i = 0; i < simplePaths.length; i++) 
        {
            boolean isPrime = true;
    
            for (int j = i + 1; j < simplePaths.length; j++) 
            {
                if (isSubPath(simplePaths[j].getNodes(), simplePaths[i].getNodes())) 
                {
                    isPrime = false;
                    break;
                }
            }
    
            if (isPrime) 
            {
                primePaths = addToPath(primePaths, simplePaths[i]);
            }
        }
    
        return primePaths;
    }
    
    private boolean isSubPath(Node[] nodesInSimplePath, Node[] nodesInPath) 
    {
        if (nodesInSimplePath.length < nodesInPath.length) 
        {
            return false;
        }
    
        for (int i = 0; i <= nodesInSimplePath.length - nodesInPath.length; i++) 
        {
            if (nodesInSimplePath[i].getAnnotation().equals(nodesInPath[0].getAnnotation())) 
            {
                int j = 0;
                while 
                (
                    j < nodesInPath.length 
                    && nodesInSimplePath[i + j].getAnnotation().equals(nodesInPath[j].getAnnotation())
                ) 
                {
                    j++;
                }
                if (j == nodesInPath.length) 
                {
                    return true;
                }
            }
        }
    
        return false;
    }
    

    public Path[] getSimplePaths() 
    {
        Path[] paths = new Path[nodes.toArray().length];
        Node[] pathNodes = this.nodes.toArray();
    
        for (int i = 0; i < paths.length; i++) 
        {
            Node[] PathLength1Nodes = new Node[1];
            PathLength1Nodes[0] = pathNodes[i];
            paths[i] = new Path(startNode, startNode, PathLength1Nodes, null);
        }
    
        Path[] newPaths = simplePathHelper(paths);
        for (int j = 0; j < pathNodes.length; j++) 
        {
            for (int i = 0; i < newPaths.length; i++) 
            {
                paths = addToPath(paths, newPaths[i]);
            }
            newPaths = simplePathHelper(newPaths);
        }
        return paths;
    }

    private Path[] simplePathHelper(Path[] newPaths)
    {
        Path[] paths = new Path[0];
        for (int i = 0; i < newPaths.length; i++) 
        {
            NodeList nodesInPath = new NodeList();
            for (Node n : newPaths[i].getNodes()) 
            {
                nodesInPath.addNode(n);
            }

            EdgeList edgesInPath = new EdgeList();
            for (Edge e : newPaths[i].getEdges()) 
            {
                edgesInPath.addEdge(e);
            }

            Node[] tempNodes = new Node[1];
            tempNodes[0] = nodesInPath.toArray()[nodesInPath.toArray().length - 1];

            Path[] newPathOfLength3 = getPathsOfLength2(tempNodes);
            for (int j = 0; j < newPathOfLength3.length; j++) 
            {
                Node[] pathNodes = new Node[nodesInPath.toArray().length + 1];
                for (int k = 0; k < nodesInPath.toArray().length; k++) 
                {
                    pathNodes[k] = nodesInPath.toArray()[k];
                }
                pathNodes[pathNodes.length - 1] = newPathOfLength3[j].getEndNode();

                Edge[] pathEdges = new Edge[edgesInPath.toArray().length + 1];
                for (int k = 0; k < edgesInPath.toArray().length; k++) 
                {
                    pathEdges[k] = edgesInPath.toArray()[k];
                }
                pathEdges[pathEdges.length - 1] = newPathOfLength3[j].getEdges()[0];
                
                Path newPath = 
                new Path
                (
                    pathNodes[0], 
                    pathNodes[pathNodes.length - 1], 
                    pathNodes, 
                    pathEdges
                );

                if(newPath.validPath() && checkPathRequirements(newPath))
                {
                    paths = addToPath(paths, newPath);
                }
            }
        }
        return paths;
    }

    private boolean checkPathRequirements(Path newPath) 
    {
        Node[] pathNodes = newPath.getNodes();
        for (int i = 1; i < pathNodes.length - 1; i++) 
        {
            int[] Occurences = getAllIndexOf(pathNodes, pathNodes[i]);
            int CountOccurences = Occurences.length;
            if(CountOccurences > 1)
            {
                // System.out.print("Last Index: " + (getAllIndexOf(paths[j].getNodes(), nodePtr).length));
                for (int k = 0; k < CountOccurences; k++) 
                {
                    if(Occurences[k] == 0
                    || Occurences[k] == pathNodes.length - 1)
                    {
                        // System.out.println("Added to paths: true");
                        // continue;
                    }
                    else
                    {
                        return false;
                    }
                    // System.out.print(", " + getAllIndexOf(paths[j].getNodes(), nodePtr)[k]);
                }
                // System.out.println();
            }
        }
        return true;
    }
    
    private int[] getAllIndexOf(Node[] pathNodes, Node nodeToFind) {
        int count = 0;
        for (int i = 0; i < pathNodes.length; i++) {
            if (nodeToFind.getAnnotation().equals(pathNodes[i].getAnnotation())) {
                count++;
            }
        }
    
        int[] indices = new int[count];
        int index = 0;
        for (int i = 0; i < pathNodes.length; i++) {
            if (nodeToFind.getAnnotation().equals(pathNodes[i].getAnnotation())) {
                indices[index++] = i;
            }
        }
    
        return indices;
    }
    
    

    private Path[] getPathsOfLength2(Node[] nodes)
    {
        Path[] paths = new Path[0];
        Node[][] Length2 = new Node[0][];
        for(int i = 0; i < nodes.length; i++)
        {
            for(int j = 0; j < nodes[i].getEdges().length; j++)
            {
                Node[] PathLength2Nodes = new Node[2];
                PathLength2Nodes[0] = nodes[i];
                PathLength2Nodes[1] = nodes[i].getEdges()[j].getNext();

                Node[][] tempNodes = new Node[Length2.length + 1][];
                for(int k = 0; k < Length2.length; k++)
                {
                    tempNodes[k] = Length2[k];
                }
                tempNodes[tempNodes.length - 1] = PathLength2Nodes;
                Length2 = tempNodes;
                Path[] tempPath = new Path[paths.length + 1];
                for(int x = 0; x < paths.length; x++)
                {
                    tempPath[x] = paths[x];
                }

                Edge[] tempEdge = new Edge[1];
                tempEdge[0] = nodes[i].getEdges()[j];

                tempPath[tempPath.length - 1] = 
                new Path(PathLength2Nodes[0], PathLength2Nodes[1], PathLength2Nodes, tempEdge);
                paths = tempPath;
            }
        }
        return paths;
    }

    private Path[] addToPath(Path[] paths, Path p)
    {
        Path[] tempPath = new Path[paths.length + 1];
        for(int i = 0; i < paths.length; i++)
        {
            tempPath[i] = paths[i];
        }
        tempPath[tempPath.length - 1] = p;
        return tempPath;
    }

    public void addNode(String annotation)
    {
        Node newNode = new Node(annotation);
        if(!nodes.Contains(newNode))
            nodes.addNode(newNode);
    }

    public void addNode(Node node)
    {
        if(!nodes.Contains(node))
            nodes.addNode(node);
    }

    public void addEdge(String annotation, Node fromNode, Node toNode, int computationalTime)
    {
        Edge newEdge = new Edge(annotation, toNode, computationalTime);
        if(edges.Contains(newEdge))
        {
            return;
        }

        edges.addEdge(newEdge);
        for(Node n: nodes.toArray())
        {
            if(n == fromNode)
            {
                n.addEdge(newEdge);
            }
        }
    }

    public void addExitNode(Node n)
    {
        if(n == null)
        {
            return;
        }

        if(!exitNodes.Contains(n))
        {
            
            exitNodes.addNode(n);
        }

        if(!nodes.Contains(n))
        {
            nodes.addNode(n);
        }
        // System.out.println("Exit nodes size: " + exitNodes.size());
    }

    public void addStartNode(Node n)
    {
        // System.out.println(startNode);
        if(n == null)
        {
            return;
        }

        if(!nodes.Contains(n))
        {
            
            nodes.addNode(n);
        }
        
        if(startNode == null)
        {
            // System.out.println("Adding Start Node");
            this.startNode = n;
        }
    }

    public String toString() 
    {
        //Provided function, do not alter!!!
        String res = "";
        for(Object n: nodes.toArray())
        {
            res += n.toString();
        }
        return res;
    }

    public Node getNode(String annotation)
    {
        for(Node n: nodes.toArray())
        {
            if(n.getAnnotation().equals(annotation))
            {
                return n;
            }
        }
        return null;
    }
}
