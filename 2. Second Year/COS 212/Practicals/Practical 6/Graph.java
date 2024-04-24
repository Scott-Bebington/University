import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Graph {
    private String[] vertices;
    private Integer[][] adjacencyMatrix;
    private int numVertices;
    private int numEdges;

    public Graph(String fileName) 
    {
        if (fileName == "") 
        {
            this.vertices = new String[0];
            this.adjacencyMatrix = new Integer[0][];
            this.numEdges = 0;
            this.numVertices = 0;
            return;
        }

        File f = new File(fileName);

        try (Scanner reader = new Scanner(f)) 
        {
            int count = 0;
            int count2 = 0;
            while (reader.hasNext()) 
            {
                String line = reader.nextLine();
                // System.out.println(line);
                if (count == 0) 
                {
                    count++;
                    this.numVertices = Integer.parseInt(line);
                    this.numEdges = 0;
                    this.adjacencyMatrix = new Integer[numVertices][numVertices];
                } 
                else if (count == 1) 
                {
                    count++;
                    String[] List = line.split(" ");
                    vertices = new String[List.length];
                    for (int i = 0; i < List.length; i++) 
                    {
                        insertVertex(List[i]);
                    }
                } 
                else 
                {
                    String[] temp = line.split(" ");
                    for (int i = 0; i < temp.length; i++) 
                    {
                        this.adjacencyMatrix[count2][i] = Integer.parseInt(temp[i]);
                    }
                    count2++;
                }
            }
            reader.close();
            CountEdges();
        } 
        catch (FileNotFoundException e) 
        {
            System.out.println("FILE NOT FOUND!");
        }
    }

    public void insertVertex(String name) 
    {
        if (name == null || name == "") 
        {
            return;
        }
        for (int i = 0; i < numVertices; i++) 
        {
            if (vertices[i] == null || vertices[i] == "") 
            {
                vertices[i] = name;
                return;
            }
        }
        String[] temp = new String[numVertices + 1];
        for (int i = 0; i < numVertices; i++) 
        {
            temp[i] = vertices[i];
        }
        temp[numVertices] = name;
        vertices = new String[numVertices + 1];
        vertices = temp;
        numVertices++;

        Integer[][] temp2 = new Integer[numVertices][numVertices];
        for (int i = 0; i < numVertices - 1; i++) 
        {
            for (int j = 0; j < numVertices - 1; j++) 
            {
                temp2[i][j] = adjacencyMatrix[i][j];
            }
        }
        for (int i = 0; i < numVertices - 1; i++) 
        {
            temp2[numVertices - 1][i] = 0;
        }
        for (int i = 0; i < numVertices; i++) 
        {
            temp2[i][numVertices - 1] = 0;
        }
        this.adjacencyMatrix = new Integer[numVertices][numVertices];
        this.adjacencyMatrix = temp2;
    }

    public void insertEdge(String start, String end, int weight) 
    {
        int Index1 = FindVertex(start);
        int Index2 = FindVertex(end);

        if (Index1 == -1 || Index2 == -1 || weight == 0) 
        {
            return;
        }


        if (this.adjacencyMatrix[Index1][Index2] == 0) 
        {
            this.adjacencyMatrix[Index1][Index2] = weight;
            numEdges++;
        }
        else
        {
            this.adjacencyMatrix[Index1][Index2] = weight;
        }
    }

    public void removeVertex(String name) 
    {
        int Index = FindVertex(name);

        if (Index == -1) 
        {
            return;
        }

        String[] temp = new String[numVertices - 1];
        int count = 0;
        for (int i = 0; i < numVertices; i++) 
        {
            if(i != Index)
            {
                temp[count] = vertices[i];
                count++;
            }
        }
        this.vertices = new String[numVertices - 1];
        this.vertices = temp;

        Integer[][] temp2 = new Integer[numVertices - 1][numVertices - 1];
        count = 0;
        int count2 = 0;
        for (int i = 0; i < numVertices; i++) 
        {
            if(i != Index)
            {
                for (int j = 0; j < numVertices; j++) 
                {
                    if(j != Index)
                    {
                        temp2[count][count2] = adjacencyMatrix[i][j];
                        count2++;
                    }
                }
                count++;
                count2 = 0;
            }
        }
        this.adjacencyMatrix = new Integer[numVertices - 1][numVertices - 1];
        this.adjacencyMatrix = temp2;
        numVertices--;
        CountEdges();
    }

    public void removeEdge(String start, String end) 
    {
        int Index1 = FindVertex(start);
        int Index2 = FindVertex(end);

        if (Index1 == -1 || Index2 == -1 || this.adjacencyMatrix[Index1][Index2] == 0) 
        {
            return;
        }

        this.adjacencyMatrix[Index1][Index2] = 0;
        numEdges--;
    }

    @Override
    public String toString() 
    {
        if(this.adjacencyMatrix.length == 0)
        {
            return "(0,0)";
        }
        String str = "(" + numVertices + "," + numEdges + ")";
        str += "\t";

        for (int i = 0; i < numVertices - 1; i++) {
            str += vertices[i] + "\t";
        }
        str += vertices[numVertices - 1] + "\n";
        // Finished

        // Inserting Edges
        for (int i = 0; i < numVertices - 1; i++) {
            str += vertices[i] + "\t";
            for (int j = 0; j < numVertices - 1; j++) {
                str += adjacencyMatrix[i][j] + "\t";
            }
            str += adjacencyMatrix[i][numVertices - 1] + "\n";
        }
        str += vertices[numVertices - 1] + "\t";
        for (int j = 0; j < numVertices - 1; j++) {
            str += adjacencyMatrix[numVertices - 1][j] + "\t";
        }
        str += adjacencyMatrix[numVertices - 1][numVertices - 1];
        return str;
    }

    public String depthFirstTraversal() 
    {
        if (adjacencyMatrix.length == 0) 
        {
            return "";
        }
    
        int[] visits = new int[numVertices];
        for (int i = 0; i < visits.length; i++) {
            visits[i] = 0;
        }
    
        int startIndex = FindVertex(vertices[0]);
        String str = "[" + vertices[0] + "]";
        visits[startIndex]++;
    
        int[] visitedOrder = new int[numVertices];
        visitedOrder[0] = startIndex;
        int count = 1;
    
        while (TestVisits(visits)) 
        {
            
            int currentIndex = visitedOrder[count - 1];
            boolean foundNextVertex = false;
    
            for (int i = 0; i < numVertices; i++) {
                if (adjacencyMatrix[currentIndex][i] != 0 && visits[i] == 0) 
                {
                    visits[i]++;
                    str += "[" + vertices[i] + "]";
                    visitedOrder[count] = i;
                    count++;
                    foundNextVertex = true;
                    break;
                }
            }
    
            if (!foundNextVertex) 
            {
                count--;
            }

            if (count == 0) 
            {
                break;    
            }
        }

        for (int i = 0; i < numVertices; i++) 
        {
            if(visits[i] == 0)
            {
                str += "[" + vertices[i] + "]";
            }
        }
    
        return str;
    }
    

    public String breadthFirstTraversal() {
        if (adjacencyMatrix.length == 0) {
            return "";
        }
        int[] visits = new int[numVertices];
        for (int i = 0; i < visits.length; i++) {
            visits[i] = 0;
        }

        int[] Enqueue = new int[numVertices];
        Enqueue[0] = 0;
        visits[0]++;

        int[] Dequeue = new int[numVertices];
        Dequeue[0] = 0;

        int EnqueueIndex = 1;
        int DequeueIndex = 0;

        String str = "[" + vertices[0] + "]";

        while (TestVisits(visits)) 
        { 
            int Index = FindVertex(vertices[Enqueue[DequeueIndex]]);
            // System.out.println(Index);
            for (int i = 0; i < numVertices; i++) 
            {
                if (adjacencyMatrix[Index][i] != 0 && visits[i] == 0) 
                {
                    visits[i]++;

                    Enqueue[EnqueueIndex] = i;
                    str += "[" + vertices[Enqueue[EnqueueIndex]] + "]";
                    EnqueueIndex++;
                }
            }
            DequeueIndex++;
            if (DequeueIndex == numVertices) 
            {
                break;
            }
        }

        for (int i = 0; i < numVertices; i++) 
        {
            if(visits[i] == 0)
            {
                str += "[" + vertices[i] + "]";
            }
        }

        return str;
    }

    public Double[][] shortestPaths() 
    {
        if (adjacencyMatrix.length == 0) 
        {
            return new Double[0][0];
        }
    
        Double[][] weight = new Double[numVertices][numVertices];
    
        for (int i = 0; i < numVertices; i++) 
        {
            for (int j = 0; j < numVertices; j++) 
            {
                if (i == j) 
                {
                    weight[i][j] = 0.0;
                } 
                else if (adjacencyMatrix[i][j] != 0) 
                {
                    weight[i][j] = (double) adjacencyMatrix[i][j];
                } 
                else 
                {
                    weight[i][j] = Double.POSITIVE_INFINITY;
                }
            }
        }
    
        // Compute shortest paths using Floyd-Warshall algorithm
    //     for i = 1 to |V|
        //   for j = 1 to |V|
            // 	for k = 1 to |V| 
            // 	  if weight[j][k] > weight[j][i] + weight[i][k] 
            // 	    weight[j][k] = weight[j][i] + weight[i][k]

        for (int i = 0; i < numVertices; i++) 
        {
            for (int j = 0; j < numVertices; j++) 
            {
                for (int k = 0; k < numVertices; k++) 
                {
                    if (weight[j][k] > weight[j][i] + weight[i][k]) 
                    {
                        weight[j][k] = weight[j][i] + weight[i][k];
                    }
                }
            }
        }

        // System.out.print("\t");
        // for (int i = 0; i < numVertices; i++) 
        // {
        //     System.out.print(vertices[i] + "\t");   
        // }
        // System.out.println();
        // for (int i = 0; i < weight.length; i++) 
        // {
        //     System.out.print(vertices[i] + "\t");
        //     for (int j = 0; j < weight[i].length; j++) 
        //     {
        //         if (weight[i][j] == Double.POSITIVE_INFINITY) 
        //         {
        //             System.out.print("0.0\t");
        //         }
        //         else
        //         {
        //             System.out.print(weight[i][j] + "\t");
        //         }
                
        //     }
        //     System.out.println();
        // }
    
        return weight;
    }
    

    public Double shortestPath(String start, String end) 
    {
        int Index1 = FindVertex(start);
        int Index2 = FindVertex(end);

        if (Index1 == -1 || Index2 == -1) 
        {
            return null;
        }

        Double[][] paths = shortestPaths();
        return paths[Index1][Index2];
    }

    public boolean cycleDetection() 
    {
        int[] visits = new int[numVertices];
        for (int i = 0; i < numVertices; i++) 
        {
            if (visits[i] == 0 && hasCycle(i, visits)) 
            {
                return true;
            }
        }
        return false;
    }
    
    public String stronglyConnectedComponents() 
    {
        if (adjacencyMatrix.length == 0) 
        {
            return "";
        }
        int[] visits = new int[numVertices];
        for (int i = 0; i < visits.length; i++) 
        {
            visits[i] = 0;
        }

        // int count = 0;

        // while(TestVisits(visits))
        // {
            
        // }
        return "";
    }


    // Helper Functions
    private boolean TestVisits(int[] visits) {
        for (int i = 0; i < visits.length; i++) {
            if (visits[i] == 0) {
                return true;
            }
        }
        return false;
    }

    private int FindVertex(String name) 
    {
        int Index = -1;
        for (int i = 0; i < numVertices; i++) 
        {
            if (vertices[i].compareTo(name) == 0) 
            {
                Index = i;
                break;
            }
        }
        return Index;
    }

    private void CountEdges()
    {
        this.numEdges = 0;
        for (int i = 0; i < numVertices; i++) 
        {
            for (int j = 0; j < numVertices; j++) 
            {
                if (this.adjacencyMatrix[i][j] != 0) 
                {
                    this.numEdges++;
                }
            }
        }
    }
    
    private boolean hasCycle(int vertex, int[] visits) 
    {
        visits[vertex] = 1;
    
        for (int i = 0; i < numVertices; i++) 
        {
            if (adjacencyMatrix[vertex][i] != 0) 
            {
                if (visits[i] == 1) 
                {
                    return true;
                } 
                else if (visits[i] == 0 && hasCycle(i, visits)) 
                {
                    return true;
                }
            }
        }
    
        visits[vertex] = 2;
        return false;
    }

}