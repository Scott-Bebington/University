public class App 
{
	public static void main(String[] args) throws Exception 
	{
		BTree<Integer> tree = new BTree<>(3);
		Node<Integer> insertedNode;
		System.out.println("Node [42]");
		insertedNode = tree.insert(42);
		
		System.out.println("Node [15]");
		insertedNode = tree.insert(15);

		System.out.println("Node [30]");
		insertedNode = tree.insert(30);

		System.out.println("Node [100]");
		insertedNode = tree.insert(100);

		System.out.println("Node [5]");
		insertedNode = tree.insert(5);

		System.out.println("Node [35]");
		insertedNode = tree.insert(35);



		tree.DisplayTree();
	}

}