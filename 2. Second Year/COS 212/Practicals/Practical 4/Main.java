public class Main 
{
    public static void main(String[] args) 
    {
        maingiven();
        // mainmine();
        // minDHeap<Integer> heap = new minDHeap<>(3);

        // System.out.println("....................Testing Insert....................");
        // heap  = testInsert(heap);
        // System.out.println(heap);

        // System.out.println("....................Testing Delete....................");
        // heap  = testDelete(heap);

        // System.out.println("....................Testing Path To Root..............");
        // heap  = testInsert(heap);
        // testPath(heap);

        // System.out.println("....................Testing Min.......................");
        // testMin(heap);

        // System.out.println("....................Testing Max.......................");
        // testMax(heap);
    }

    public static void testMax(minDHeap<Integer> heap)
    {

        int x = 0;
        System.out.println("Testing Max: Node at index [" + x + "]");
        System.out.println("Node value is [0]");
        System.out.println("Should be 10: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + x + "]");
        System.out.println("Node value is [5]");
        System.out.println("Should be 10: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + x + "]");
        System.out.println("Node value is [2]");
        System.out.println("Should be 9: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + x + "]");
        System.out.println("Node value is [1]");
        System.out.println("Should be 8: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + x + "]");
        System.out.println("Node value is [10]");
        System.out.println("Should be 10: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + x + "]");
        System.out.println("Node value is [7]");
        System.out.println("Should be 7: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + x + "]");
        System.out.println("Node value is [6]");
        System.out.println("Should be 6: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + x + "]");
        System.out.println("Node value is [9]");
        System.out.println("Should be 9: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + x + "]");
        System.out.println("Node value is [4]");
        System.out.println("Should be 4: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + x + "]");
        System.out.println("Node value is [3]");
        System.out.println("Should be 3: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + x + "]");
        System.out.println("Node value is [8]");
        System.out.println("Should be 8: " + heap.max(x));
        x++;
        System.out.println("Testing max: Node at index [" + 120 + "]");
        System.out.println("Should be null: " + heap.max(120));
    }   

    public static void testMin(minDHeap<Integer> heap)
    {
        int x = 0;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be " + 0 + ": " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be 5: " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be 2: " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be 1: " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be 10: " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be 7: " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be 6: " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be 9: " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be 4: " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be 3: " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + x + "]");
        System.out.println("Should be 8: " + heap.min(x));
        x++;
        System.out.println("Testing Min: Node at index [" + 120 + "]");
        System.out.println("Should be null: " + heap.min(120));
    }   

    public static void testPath(minDHeap<Integer> heap)
    {
        
        int x = 0;
        // System.out.println("Testing Path To Root: Node [" + x + "]");
        // System.out.println("Should be [0]: " + heap.pathToRoot(x) + "\n");
        x++;
        // System.out.println("Testing Path To Root: Node [" + x + "]");
        // System.out.println("Should be [1][0]: " + heap.pathToRoot(x) + "\n");
        x++;
        // System.out.println("Testing Path To Root: Node [" + x + "]");
        // System.out.println("Should be [2][0]: " + heap.pathToRoot(x) + "\n");
        x++;
        // System.out.println("Testing Path To Root: Node [" + x + "]");
        // System.out.println("Should be [3][2][0]: " + heap.pathToRoot(x) + "\n");
        x++;
        // System.out.println("Testing Path To Root: Node [" + x + "]");
        // System.out.println("Should be [4][2][0]: " + heap.pathToRoot(x) + "\n");
        x++;
        // System.out.println("Testing Path To Root: Node [" + x + "]");
        // System.out.println("Should be [5][0]: " + heap.pathToRoot(x) + "\n");
        x++;
        // System.out.println("Testing Path To Root: Node [" + x + "]");
        // System.out.println("Should be [6][5][0]: " + heap.pathToRoot(x) + "\n");
        x++;
        System.out.println("Testing Path To Root: Node [" + x + "]");
        System.out.println("Should be [7][5][0]: " + heap.pathToRoot(x) + "\n");
        x++;
        // System.out.println("Testing Path To Root: Node [" + x + "]");
        // System.out.println("Should be [8][1][0]: " + heap.pathToRoot(x) + "\n");
        x++;
        // System.out.println("Testing Path To Root: Node [" + x + "]");
        // System.out.println("Should be [9][2][0]: " + heap.pathToRoot(x) + "\n");
        // x++;
        // System.out.println("Testing Path To Root: Node [" + x + "]");
        // System.out.println("Should be [10][5][0]: " + heap.pathToRoot(x) + "\n");
        // x++;
        // System.out.println("Testing Path To Root: Node [" + 120 + "]");
        // System.out.println("Should be an empty string: " + heap.pathToRoot(120));
        System.out.println(heap);
    }

    public static minDHeap<Integer> testDelete(minDHeap<Integer> heap)
    {
        for (int i = 0; i <= 10; i++) 
        {
            heap.remove(i);
            System.out.println("Deleting " + "[" + i + "]");
            System.out.println(heap);
        }
        return heap;
    }

    public static minDHeap<Integer> testInsert(minDHeap<Integer> heap)
    {
        for (int i = 10; i >= 0; i--) 
        {
            heap.insert(i);
        }
        return heap;
    }

    public static void mainmine() 
    {
        minDHeap<Integer> heap = new minDHeap<>(3);

        for (int i = 10; i >= 0; i--) 
        {
            heap.insert(i);
        }

        System.out.println("Heap with d = 3 and values 100 to 0");
        System.out.println(heap);

        System.out.println("Removing head: [0]");
        heap.remove(0);
        System.out.println(heap);

        System.out.println("Removing Middle Left: [5]");
        heap.remove(5);
        System.out.println(heap);

        System.out.println("Removing Middle Middle: [2]");
        heap.remove(2);
        System.out.println(heap);

        System.out.println("Removing Middle Right: [8]");
        heap.remove(8);
        System.out.println(heap);

        System.out.println("Removing Bottom Left: [10]");
        heap.remove(10);
        System.out.println(heap);

        System.out.println("Removing Middle Right: [7]");
        heap.remove(7);
        System.out.println(heap);

        System.out.println("Removing A value that isnt in the heap: [17]");
        heap.remove(1);
        heap.remove(3);
        heap.remove(4);
        heap.remove(9);
        System.out.println(heap);

        System.out.println("Removing The Heap: [All]");
        heap.remove(7);
        System.out.println(heap);
        System.out.println("Should be left with [6] as the ToString doesnt work with a null heap");

        heap.remove(6);
        for (int i = 10; i >= 0; i--) 
        {
            heap.insert(i);
        }
        System.out.println("Testing Change D from 3 to 2");
        heap.changeD(2);
        System.out.println("New Heap for testing path to root");
        System.out.println(heap);

        System.out.println("Testing Path To Root: Root Node [0]");
        System.out.println(heap.pathToRoot(0));

        System.out.println("Testing Path To Root: Middle Top Node [1]");
        System.out.println(heap.pathToRoot(1));

        System.out.println("Testing Path To Root: Middle Bottom Node [3]");
        System.out.println(heap.pathToRoot(3));

        System.out.println("Testing Path To Root: Bottom Node [10]");
        System.out.println(heap.pathToRoot(10));

        System.out.println("Testing Path To Root: Node That Doesnt Exist [15]");
        System.out.println(heap.pathToRoot(15));
        System.out.println("NB!! there should be no output in the line above here");

        for (int i = 10; i >= 0; i--) 
        {
            heap.remove(i);
        }
        for (int i = 1; i <= 10; i++) 
        {
            heap.insert(i);
        }
        System.out.println("New Heap for testing Min / Max");
        heap.changeD(3);
        System.out.println(heap);

        System.out.println("Testing Min: Root Node [0]");
        System.out.println("Should be 1: " + heap.min(0));

        System.out.println("Testing Min: Middle Node [2]");
        System.out.println("Should be 3: " + heap.min(2));

        System.out.println("Testing Min: Bottom Node [8]");
        System.out.println("Should be 9: " + heap.min(8));

        System.out.println("Testing Min: Node That Doesnt Exist [20]");
        System.out.println("Should be null: " + heap.min(20));
        System.out.println();

        System.out.println("Testing Max: Root Node [0]");
        System.out.println("Should be 10: " + heap.max(0));

        System.out.println("Testing Max: Middle Node [1]");
        System.out.println("Should be 7: " + heap.max(1));

        System.out.println("Testing Max: Bottom Node [8]");
        System.out.println("Should be 9: " + heap.max(8));

        System.out.println("Testing Max: Node That Doesnt Exist [20]");
        System.out.println("Should be null: " + heap.max(20));
    }
    
    public static void maingiven() // Given
    {
        minDHeap<Integer> heap = new minDHeap<>(3);

        for (int i = 10; i >= 0; i--) 
        {
            heap.insert(i);
        }

        System.out.println(heap);

        heap.changeD(2);

        System.out.println(heap);
        System.out.println(heap.pathToRoot(5));

        for (int i = 0; i <= 5; i++) 
        {
            heap.remove(i);
        }

        System.out.println(heap);
    }
}