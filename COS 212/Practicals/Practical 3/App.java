public class App 
{
    public static void main(String[] args) 
    {
        giventest();
        TestingStandard();
        TestingMirrored();
    }

    public static void TestingMirrored()
    {
        BinaryTree<Integer> tree = new MirroredBinaryTree<>();

        tree.insert(5);
        tree.insert(3);
        tree.insert(1);
        tree.insert(4);
        tree.insert(7);
        tree.insert(6);
        tree.insert(8);

        System.out.println("Testing depth first traversal");
        tree.depthFirstTraversal();

        System.out.println("Testing FindParent Method");
        FindParent(tree);

        System.out.println("Testing Find Method");
        Find(tree);

        System.out.println("Testing Contains");
        Contains(tree);

        System.out.println("Testing convert tree method");
        ConvertTree(tree); 
    }

    public static void TestingStandard()
    {
        BinaryTree<Integer> tree = new StandardBinaryTree<>();

        tree.insert(5);
        tree.insert(3);
        tree.insert(1);
        tree.insert(4);
        tree.insert(7);
        tree.insert(6);
        tree.insert(8);

        System.out.println("Testing FindParent Method");
        FindParent(tree);

        System.out.println("Testing Find Method");
        Find(tree);

        System.out.println("Testing Contains");
        Contains(tree);

        System.out.println("Testing convert tree method");
        ConvertTree(tree);
        
    }

    public static void ConvertTree(BinaryTree<Integer> tree)
    {
        BinaryTree<Integer> convertedTree = tree.convertTree();
        System.out.println("Tree before reverse");
        VisualizeList(tree);
        System.out.println("Tree after reverse");
        VisualizeList(convertedTree);

        System.out.println("Testing depth first traversal");
        tree.depthFirstTraversal();

        System.out.println("Testing FindParent Method");
        FindParent(convertedTree);

        System.out.println("Testing Find Method");
        Find(convertedTree);

        System.out.println("Testing Perfectly balanced");
        System.out.println(convertedTree.perfectlyBalanced());

        System.out.println("Testing Contains");
        Contains(convertedTree);
    }

    public static void FindParent(BinaryTree<Integer> tree)
    {
        System.out.println("Searching at the root for [5]");
        System.out.println(tree.findParent(5));
        System.out.println("Searching in the middle(LHS) for [3]");
        System.out.println(tree.findParent(3));
        System.out.println("Searching in the middle(RHS) for [7]");
        System.out.println(tree.findParent(7));
        System.out.println("Searching at the end for [4]");
        System.out.println(tree.findParent(4));
        System.out.println("Searching for a node that doesnt exist (LHS), [0]");
        System.out.println(tree.findParent(0));
        System.out.println("Searching for a node that doesnt exist (RHS), [15]");
        System.out.println(tree.findParent(15));
        System.out.println();
    }

    public static void Contains(BinaryTree<Integer> tree)
    {
        System.out.println("Searching at the root for [5]");
        tree.contains(5);
        System.out.println("Searching in the middle(LHS) for [3]");
        tree.contains(3);
        System.out.println("Searching in the middle(RHS) for [7]");
        tree.contains(7);
        System.out.println("Searching at the end for [4]");
        tree.contains(4);
        System.out.println("Searching for a node that doesnt exist (LHS), [0]");
        tree.contains(0);
        System.out.println("Searching for a node that doesnt exist (RHS), [15]");
        tree.contains(15);
        System.out.println();
    }

    public static void Find(BinaryTree<Integer> tree)
    {
        System.out.println("Searching at the root for [5]");
        System.out.println(tree.find(5)); 
        System.out.println("Searching in the middle(LHS) for [3]");
        System.out.println(tree.find(3)); 
        System.out.println("Searching in the middle(RHS) for [7]");
        System.out.println(tree.find(7)); 
        System.out.println("Searching at the end for [4]");
        System.out.println(tree.find(4)); 
        System.out.println("Searching for a node that doesnt exist (LHS), [0]");
        System.out.println(tree.find(0)); 
        System.out.println("Searching for a node that doesnt exist (RHS), [15]");
        System.out.println(tree.find(15)); 
        System.out.println();
    }

    public static void VisualizeList (BinaryTree<Integer> tree)
    {
        System.out.println("      " + tree.root.data);
        System.out.println("  " + tree.root.left.data + "   |   " + tree.root.right.data);
        System.out.println(tree.root.left.left.data + " | " + tree.root.left.right.data
        + " | " + tree.root.right.left.data + " | " + tree.root.right.right.data);
    }

    public static void giventest() 
    {
        BinaryTree<Integer> t = new StandardBinaryTree<>();
    
        t.insert(2);
        t.insert(1);
        t.insert(3);

        //      [2]
        //   [1]   [3]
    
        System.out.println("Tree Height");
        System.out.println(t.height() + "\n");
        System.out.println("Tree Number of Leaves");
        System.out.println(t.numLeavesInTree() + "\n");
        System.out.println("Depth First Traversal");
        t.depthFirstTraversal();
        System.out.println("\nFind parent of [3]");
        t.findParent(3);
        System.out.println("\nFind [1]");
        t.find(1);
        System.out.println("\nContains [5]");
        t.contains(5);
    }
}

/*
Tree Height
1

Tree Number of Leaves
3

Depth First Traversal
L[null]<-[1]->R[null]
L[1]<-[2]->R[3]
L[null]<-[3]->R[null]

Find parent of [3]
L[1]<-[2]->R[3]

Find [1]
L[1]<-[2]->R[3]
L[null]<-[1]->R[null]

Contains [5]
L[1]<-[2]->R[3]
L[null]<-[3]->R[null]
 */