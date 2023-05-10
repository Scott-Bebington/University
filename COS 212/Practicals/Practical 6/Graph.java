import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Graph {
    private String[] vertices;
    private Integer[][] adjacencyMatrix;
    private int numVertices;
    private int numEdges;

    public Graph(String fileName) {
        if (fileName == "") {
            this.vertices = new String[0];
            this.adjacencyMatrix = new Integer[0][];
            this.numEdges = 0;
            this.numVertices = 0;
            return;
        }

        File f = new File(fileName);

        try (Scanner reader = new Scanner(f)) {
            int count = 0;
            int count2 = 0;
            while (reader.hasNext()) {
                String line = reader.nextLine();
                // System.out.println(line);
                if (count == 0) {
                    count++;
                    this.numVertices = Integer.parseInt(line);
                    this.numEdges = this.numVertices + 1;
                    this.adjacencyMatrix = new Integer[numVertices][numEdges];
                } else if (count == 1) {
                    count++;
                    String[] List = line.split(" ");
                    vertices = new String[List.length];
                    for (int i = 0; i < List.length; i++) {
                        insertVertex(List[i]);
                    }
                } else {
                    String start = vertices[count2];
                    String[] temp = line.split(" ");
                    Integer[] list = new Integer[temp.length];

                    for (int i = 0; i < temp.length; i++) {
                        list[i] = Integer.parseInt(temp[i]);
                    }

                    this.adjacencyMatrix[count2] = list;
                    count2++;
                }
            }
            reader.close();
        } catch (FileNotFoundException e) {
            System.out.println("FILE NOT FOUND!");
        }
    }

    public void insertVertex(String name) {
        for (int i = 0; i < numVertices; i++) {
            if (vertices[i] == null) {
                vertices[i] = name;
                return;
            }
        }

    }

    public void insertEdge(String start, String end, int weight) {

    }

    public void removeVertex(String name) {
        int Index = FindVertex(name);

        if (Index == -1) {
            return;
        }

    }

    public void removeEdge(String start, String end) {

    }

    @Override
    public String toString() {
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

    public String depthFirstTraversal() {
        if (adjacencyMatrix.length == 0) {
            return "";
        }
        int[] visits = new int[numVertices];
        for (int i = 0; i < visits.length; i++) {
            visits[i] = 0;
        }

        int[] VisistedOrder = new int[numVertices];
        int Index = FindVertex(vertices[0]);
        String str = "[" + vertices[0] + "]";
        visits[0]++;
        VisistedOrder[0] = 0;
        int count = 0;
        int test = -1;
        while (TestVisits(visits)) {
            for (int i = 0; i < numVertices; i++) {
                if (adjacencyMatrix[Index][i] != 0 && visits[i] == 0) {
                    visits[i]++;
                    str += "[" + vertices[i] + "]";
                    Index = FindVertex(vertices[i]);
                    VisistedOrder[count] = Index;
                    test = 1;
                    count++;
                    break;
                }
            }

            if (test == -1) {
                Index = FindVertex(vertices[VisistedOrder[count - 2]]);
            }
            test = -1;
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

        String str = "";

        while (TestVisits(visits)) {

            int Index = FindVertex(vertices[Enqueue[DequeueIndex]]);

            for (int i = 0; i < numVertices; i++) {
                if (adjacencyMatrix[Index][i] != 0 && visits[i] == 0) {
                    visits[i]++;

                    Enqueue[EnqueueIndex] = i;
                    EnqueueIndex++;
                }
            }

            Dequeue[DequeueIndex] = Enqueue[DequeueIndex];
            DequeueIndex++;

        }
        for (int i = 0; i < numVertices; i++) {
            str += "[" + vertices[Enqueue[i]] + "]";
        }
        return str;
    }

    public Double[][] shortestPaths() {
        return null;
    }

    public Double shortestPath(String start, String end) {
        return null;

    }

    public boolean cycleDetection() {
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

        return "";
    }

    // Helper Functions
    public boolean TestVisits(int[] visits) {
        for (int i = 0; i < visits.length; i++) {
            if (visits[i] == 0) {
                return true;
            }
        }
        return false;
    }

    public int FindVertex(String name) {
        int Index = -1;
        for (int i = 0; i < numVertices; i++) {
            if (vertices[i].compareTo(name) == 0) {
                Index = i;
                break;
            }
        }
        return Index;
    }

}