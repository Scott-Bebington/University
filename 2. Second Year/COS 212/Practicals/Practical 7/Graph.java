public class Graph {
    public Vertex[] vertices = new Vertex[0];
    public Edge[] edges = new Edge[0];

    public void addVertex(String v) 
    {
        Vertex newVertex = new Vertex(v);

        if(v == null || v.compareTo("") == 0)
        {
            return;
        }

        if(vertices.length == 0)
        {
            vertices = new Vertex[1];
            vertices[0] = newVertex;
            return;
        }

        if(getIndexOfVertex(newVertex) != -1)
        {
            return;
        }

        Vertex[] newVertices = new Vertex[vertices.length + 1];
        for (int i = 0; i < vertices.length; i++) 
        {
            newVertices[i] = vertices[i];
        }
        newVertices[vertices.length] = newVertex;
        vertices = new Vertex[newVertices.length];
        vertices = newVertices;
        
        sortVertices();
    }
    

    public void removeVertex(String v) 
    {
        Vertex newVertex = new Vertex(v);

        if(v == null || v.compareTo("") == 0)
        {
            return;
        }

        if(getIndexOfVertex(newVertex) == -1)
        {
            return;
        }

        if(vertices.length == 1 || vertices.length == 0)
        {
            vertices = new Vertex[0];
            edges = new Edge[0];
            return;
        }
        
        Edge[] removeEdge = new Edge[edges.length];
        int count = 0;
        for (int i = 0; i < edges.length; i++) 
        {
            if (edges[i].vertexA.name.compareTo(v) == 0 || edges[i].vertexB.name.compareTo(v) == 0) 
            {
                removeEdge[count] = edges[i];
                count++;
            }
        }

        for (int i = 0; i < count; i++) 
        {
            removeEdge(removeEdge[i].vertexA.name, removeEdge[i].vertexB.name);
        }

        count = 0;
        Vertex[] newVertices = new Vertex[vertices.length - 1];
        for (int i = 0; i < vertices.length; i++) 
        {
            if(vertices[i].compareTo(newVertex) != 0)
            {
                newVertices[count] = vertices[i];
                count++;
            }
        }
        vertices = new Vertex[newVertices.length];
        vertices = newVertices;
    }

    public void addEdge(String a, String b, int w) 
    {
        Vertex VertexA = new Vertex(a);
        Vertex VertexB = new Vertex(b);
        Edge newEdge = new Edge(VertexA, VertexB, w);

        if(a == null || a.equals("") || b == null || b.equals("")
        || getIndexOfVertex(VertexA) == -1 || getIndexOfVertex(VertexB) == -1
        || vertices.length == 0 || vertices.length == 1)
        {
            return;
        }

        if(edges.length == 0)
        {
            edges = new Edge[1];
            edges[0] = newEdge;
            return;
        }

        if(isContainedEdge(newEdge))
        {
            return;
        }

        Edge[] newEdges = new Edge[edges.length + 1];
        for (int i = 0; i < edges.length; i++) 
        {
            newEdges[i] = edges[i];
        }
        newEdges[edges.length] = newEdge;
        edges = new Edge[newEdges.length];
        edges = newEdges;

        sortEdges();
    }

    public void removeEdge(String a, String b) 
    {
        Vertex VertexA = new Vertex(a);
        Vertex VertexB = new Vertex(b);
        Edge newEdge = new Edge(VertexA, VertexB, 0);

        if(a == null || a.equals("") || b == null || b.equals("")
        || getIndexOfVertex(VertexA) == -1 || getIndexOfVertex(VertexB) == -1)
        {
            return;
        }

        if(!isContainedEdge(newEdge))
        {
            return;
        }

        if(edges.length == 1 || edges.length == 0)
        {
            edges = new Edge[0];
            return;
        }

        int count = 0;
        Edge[] newEdges = new Edge[edges.length - 1];
        for (int i = 0; i < edges.length; i++) 
        {
            if(edges[i].compareTo(newEdge) != 0)
            {
                newEdges[count] = edges[i];
                count++;
            }
        }
        edges = new Edge[newEdges.length];
        edges = newEdges;
    }

    public int[][] unionFind() 
    {
        int[] root = new int[vertices.length];
        int[] next = new int[vertices.length];
        int[] length = new int[vertices.length];
        int[] result = new int[vertices.length];

        for (int i = 0; i < vertices.length; i++) 
        {
            root[i] = i;
            next[i] = i;
            length[i] = 1;
        }
        
        for (Edge edge : edges) 
        {
            int v = getIndexOfVertex(edge.vertexA);
            int u = getIndexOfVertex(edge.vertexB);
        
            if (root[u] == root[v]) 
            {
                // Cycle detected
                // Use the same function cycle
                for (int i = 0; i < result.length; i++) 
                {
                    result[i] = 1;
                }
            } 
            else if (length[root[v]] < length[root[u]]) 
            {
                int rt = root[v];
                length[root[u]] += length[rt];
                root[rt] = root[u];
                for (int j = next[rt]; j != rt; j = next[j]) 
                {
                    root[j] = root[u];
                }
                int temp = next[rt];
                next[rt] = next[root[u]];
                next[root[u]] = temp;
            } 
            else 
            {
                // The same as the else if part, but with u and v reversed
                int rt = root[u];
                length[root[v]] += length[rt];
                root[rt] = root[v];
                for (int j = next[rt]; j != rt; j = next[j]) {
                    root[j] = root[v];
                }
                int temp = next[rt];
                next[rt] = next[root[v]];
                next[root[v]] = temp;
            }
        }

        int[][] finalresult = new int[4][vertices.length];
        finalresult[0] = root;
        finalresult[1] = next;
        finalresult[2] = length;
        finalresult[3] = result;

        return finalresult;
    }

    public boolean cycle() 
    {
        int[] root = new int[vertices.length];
        int[] next = new int[vertices.length];
        int[] length = new int[vertices.length];

        for (int i = 0; i < vertices.length; i++) 
        {
            root[i] = i;
            next[i] = i;
            length[i] = 1;
        }
        
        for (Edge edge : edges) 
        {
            int v = getIndexOfVertex(edge.vertexA);
            int u = getIndexOfVertex(edge.vertexB);
        
            if (root[u] == root[v]) 
            {
                return true;
            } 
            else if (length[root[v]] < length[root[u]]) 
            {
                int rt = root[v];
                length[root[u]] += length[rt];
                root[rt] = root[u];
                for (int j = next[rt]; j != rt; j = next[j]) 
                {
                    root[j] = root[u];
                }
                int temp = next[rt];
                next[rt] = next[root[u]];
                next[root[u]] = temp;
            } 
            else 
            {
                int rt = root[u];
                length[root[v]] += length[rt];
                root[rt] = root[v];
                for (int j = next[rt]; j != rt; j = next[j]) {
                    root[j] = root[v];
                }
                int temp = next[rt];
                next[rt] = next[root[v]];
                next[root[v]] = temp;
            }
        }
        return false;
    }

    public Graph minSpanningTree() 
    {
        Graph mst = new Graph();
        Edge[] sortedEdges = sortEdgesByWeight();
        int[] parent = new int[vertices.length];
        int[] rank = new int[vertices.length];
        for (int i = 0; i < vertices.length; i++) 
        {
            mst.addVertex(vertices[i].name);
            parent[i] = i;
            rank[i] = 0;
        }
        int edgeCount = 0;
        for (int i = 0; i < edges.length && edgeCount < vertices.length - 1; i++) 
        {
            Edge edge = sortedEdges[i];
            int rootA = findRoot(parent, getIndexOfVertex(edge.vertexA));
            int rootB = findRoot(parent, getIndexOfVertex(edge.vertexB));
    
            if (rootA != rootB) 
            {
                mst.addEdge(edge.vertexA.name, edge.vertexB.name, edge.weight);
                // union(parent, rank, rootA, rootB);
                if(rank[rootA] == rank[rootB])
                {
                    parent[rootB] = rootA;
                    rank[rootA]++;
                }
                else if(rank[rootA] > rank[rootB])
                {
                    parent[rootB] = rootA;
                }
                else if(rank[rootA] < rank[rootB])
                {
                    parent[rootA] = rootB;
                }
                edgeCount++;
            }
        }
        return mst;
    }

    public Vertex[][] brelazColouring() 
    {
        if(vertices.length == 0)
        {
            return new Vertex[0][0];
        }
        
        String[][] colourArray = new String[4][vertices.length];

        for (int i = 0; i < vertices.length; i++) 
        {
            colourArray[0][i] = vertices[i].name;
            colourArray[1][i] = "0";
            colourArray[2][i] = "" + getConnections(vertices[i]).length;
            colourArray[3][i] = "none";
        }

        Vertex startVertex = vertices[0];
        Vertex currVertex = startVertex;
        String[] connections = getConnections(currVertex);
        int smallestColour = 0;
        while (ColouringUnprocessed(colourArray))
        {
            currVertex = getHighestConnection(colourArray);
            connections = getConnections(currVertex);
            smallestColour = getLowestColour(connections, colourArray);

            for (int i = 0; i < connections.length; i++) 
            {
                int Index = getIndexOfVertex(new Vertex(connections[i]));
                if(colourArray[3][Index].equals("none"))
                {
                    if(CheckConnectionsColour(new Vertex(connections[i]), colourArray, smallestColour))
                    {
                        int tempSaturationDeg = Integer.parseInt(colourArray[1][Index]) + 1;
                        colourArray[1][Index] = "" + tempSaturationDeg;
                    }
                    int tempUncolouredDeg = Integer.parseInt(colourArray[2][Index]) - 1;
                    colourArray[2][Index] = "" + tempUncolouredDeg;
                }
            }
            int tempIndex = getIndexOfVertex(currVertex);
            colourArray[3][tempIndex] = "" + smallestColour;

            
        }

        int BiggestIndex = getBiggestIndex(colourArray) + 1;
        Vertex[][] returnVertex = new Vertex[BiggestIndex][];
        for (int i = 0; i < BiggestIndex; i++) 
        {
            Vertex[] LineLength = getLineOfVertices(colourArray, i);
            returnVertex[i] = new Vertex[LineLength.length];
            returnVertex[i] = LineLength;
        }

        return returnVertex;
    }

    

    @Override
    public String toString() 
    {
        if(vertices.length == 0)
        {
            return "";
        }
        int[][] array = new int[vertices.length][vertices.length];
        for (int i = 0; i < array.length; i++) 
        {
            for (int j = 0; j < array.length; j++) 
            {
                array[i][j] = 0;
            }
        }
        String str = "\t";
        for (int i = 0; i < vertices.length; i++) 
        {
            str += vertices[i].toString() + "\t";
        }
        str += "\n";
        if(edges.length != 0)
        {
            for (int i = 0; i < edges.length; i++) 
            {
                int IndexOfA = getIndexOfVertex(edges[i].vertexA);
                int IndexOfB = getIndexOfVertex(edges[i].vertexB);
                array[IndexOfA][IndexOfB] = edges[i].weight;
                array[IndexOfB][IndexOfA] = edges[i].weight;
            }
        }
        for (int i = 0; i < vertices.length; i++) 
        {
            str += vertices[i].toString() + "\t";
            for (int j = 0; j < vertices.length; j++) 
            {
                str += array[i][j] + "\t";
            }
            str += "\n";
        }
        str = str.substring(0, str.length() - 2);
        return str;
    }

    // Helper Functions
    public int getIndexOfVertex(Vertex v)
    {
        for(int i = 0; i < vertices.length; i++)
        {
            if(vertices[i].compareTo(v) == 0)
            {
                return i;
            }
        }
        return -1;
    }
    
    private int findRoot(int[] parent, int vertex) 
    {
        if (parent[vertex] != vertex) 
        {
            parent[vertex] = findRoot(parent, parent[vertex]);
        }
        return parent[vertex];
    }

    private Edge[] sortEdgesByWeight() 
    {
        Edge[] sortedEdges = new Edge[edges.length];
        for (int i = 0; i < edges.length; i++) 
        {
            sortedEdges[i] = edges[i];
        }
    
        for (int i = 0; i < sortedEdges.length - 1; i++) 
        {
            for (int j = 0; j < sortedEdges.length - i - 1; j++) 
            {
                if (sortedEdges[j].weight > sortedEdges[j + 1].weight) 
                {
                    Edge temp = sortedEdges[j];
                    sortedEdges[j] = sortedEdges[j + 1];
                    sortedEdges[j + 1] = temp;
                }
            }
        }
    
        return sortedEdges;
    }

    private void sortVertices() 
    {
        if(vertices.length == 0 || vertices.length == 1)
        {
            return;
        }
        for (int i = 0; i < vertices.length - 1; i++) 
        {
            for (int j = 0; j < vertices.length - i - 1; j++) 
            {
                if (vertices[j].compareTo(vertices[j + 1]) > 0) 
                {
                    Vertex temp = vertices[j];
                    vertices[j] = vertices[j + 1];
                    vertices[j + 1] = temp;
                }
            }
        }
    }

    private boolean isContainedEdge(Edge compareEdge)
    {
        for (int i = 0; i < edges.length; i++) 
        {
            if(compareEdge.compareTo(edges[i]) == 0)
            {
                return true;
            }
        }
        return false;
    }

    private void sortEdges() 
    {
        if(edges.length == 0 || edges.length == 1)
        {
            return;
        }
        for (int i = 0; i < edges.length - 1; i++) 
        {
            for (int j = 0; j < edges.length - i - 1; j++) 
            {
                if (edges[j].compareTo(edges[j + 1]) > 0) 
                {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    private String[] getConnections(Vertex x)
    {
        String str = "";
        for (int i = 0; i < edges.length; i++) 
        {
            if(edges[i].vertexA.compareTo(x) == 0)
            {
                str += edges[i].vertexB.name + ",";
            }
            else if(edges[i].vertexB.compareTo(x) == 0)
            {
                str += edges[i].vertexA.name + ",";
            }
        }
        String[] returnArr = str.split(",");
        return returnArr;
    }

    private Vertex getHighestConnection(String[][] array)
    {
        // int count = 0;
        Vertex returnVertex = vertices[0];
        int saturationDeg = -1;
        int uncolouredDeg = -1;

        // Setting the highest saturation degree
        for (int i = 1; i < vertices.length; i++) 
        {
            if(array[3][i].equals("none") && Integer.parseInt(array[1][i]) > saturationDeg)
            {
                saturationDeg = Integer.parseInt(array[1][i]);
            }
        }

        for (int i = 0; i < vertices.length; i++) 
        {
            if(Integer.parseInt(array[1][i]) == saturationDeg
            && Integer.parseInt(array[2][i]) > uncolouredDeg
            && array[3][i].equals("none"))
            {
                uncolouredDeg = Integer.parseInt(array[2][i]);
                returnVertex = vertices[i];
            }
        }
        return returnVertex;
    }

    private boolean ColouringUnprocessed(String[][] array)
    {
        for (int i = 0; i < vertices.length; i++) 
        {
            if(array[3][i].compareTo("none") == 0)
            {
                return true;
            }
        }
        return false;
    }

    private int getLowestColour(String[] connections, String[][] array)
    {
        for (int i = 0; i < connections.length; i++) 
        {
        }
        String[] colours = new String[connections.length];
        for (int i = 0; i < colours.length; i++) 
        {
            int Index = getIndexOfVertex(new Vertex(connections[i]));
            colours[i] = array[3][Index];
        }

        int count = 0;
        for (int i = 0; i < colours.length; i++) 
        {
            for (int j = 0; j < colours.length; j++) 
            {
                if(!colours[j].equals("none") && count == Integer.parseInt(colours[j]))
                {
                    count++;
                }
            }
        }
        return count;
    }

    private boolean CheckConnectionsColour(Vertex v, String[][] array, int colourIndex)
    {
        String[] connections = getConnections(v);
        for (int i = 0; i < connections.length; i++) 
        {
        }
        for (int i = 0; i < connections.length; i++) 
        {
            int Index = getIndexOfVertex(new Vertex(connections[i]));
            if(!array[3][Index].equals("none")
            && Integer.parseInt(array[3][Index]) == colourIndex)
            {
                return false;
            }
        }
        return true;
    }

    private int getBiggestIndex(String[][] array)
    {
        int count = 0;
        for (int i = 0; i < vertices.length; i++) 
        {
            int temp = Integer.parseInt(array[3][i]);
            if(temp > count)
            {
                count = temp;
            }
        }
        return count;
    }

    private Vertex[] getLineOfVertices(String[][] array, int colourIndex)
    {
        int count = 0;
        for (int i = 0; i < vertices.length; i++) 
        {
            if (Integer.parseInt(array[3][i]) == colourIndex) 
            {
                count++;
            }
        }
        Vertex[] Line = new Vertex[count];
        count = 0;
        
        for (int i = 0; i < vertices.length; i++) 
        {
            if (Integer.parseInt(array[3][i]) == colourIndex) 
            {
                Line[count] = new Vertex(array[0][i]);
                count++;
            }
        }
        return Line;
    }
    
}
