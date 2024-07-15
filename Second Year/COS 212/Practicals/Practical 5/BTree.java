public class BTree<T extends Comparable<T>> {

	private int m;
	private Node<T> root;

	/**
	 * 
	 * @param m
	 */
	public BTree(int m) {
		this.m = m;
		this.root = new Node<T>(m);
		// throw new UnsupportedOperationException();
	}

	/**
	 * Inserts a new data element into the BTree.
	 * 
	 * @param data the data element to be inserted.
	 * @return the node where the data was inserted.
	 */

	public Node<T> insert(T data) 
	{
		Node<T> newNode = new Node<T>(m);
		if (root == null) 
		{
			System.out.println("Inserted 1 \n");
			root = newNode;
			root.setKey(0, data);
			return null;
		}

		if(isFullChildren(root))
		{
			System.out.println("klubavleruvbae");
		}

		if (isEmptyChildren(root)) 
		{
			System.out.println("Children is empty");
			if (insertHelper(root, data, m) != null) 
			{
				System.out.println("Inserted 2 \n");
				return null;
			} 
			else 
			{
				System.out.println("Split");
				System.out.println("Root node: " + root);
				Node<T> tempNode = new Node<T>(m + 1);
				int pos = (m - 1) / 2;

				for (int i = 0; i < m - 1; i++) {
					insertHelper(tempNode, (T) root.getData(i), m + 1);
				}
				insertHelper(tempNode, data, m + 1);
				System.out.println("Temp node: " + tempNode);
				System.out.println("Splitting now...");
				root = new Node<T>(m);
				root.setKey(0, data);

				Node<T>[] children = root.getChildren();
				children[0] = new Node<T>(m);
				children[0].setKey(0, (T) tempNode.getData(0));

				children[1] = new Node<T>(m);
				children[1].setKey(0, (T) tempNode.getData(2));
				System.out.println();
			}
		} 
		else 
		{
			System.out.println("Children is not empty");
			int count = -1;
			for (int i = 0;root.getData(i) != null && i < m - 1; i++) 
			{
				if (data.compareTo((T) root.getData(i)) > 0 && count == -1)
				{
					// System.out.println(i);
					count = i;
				}
			}
			// System.out.println("Place to insert: " + count);
			Node<T>[] children = root.getChildren();
			if(count == -1)
			{
				insertHelper(children[0], data, m);
				System.out.println("Inserted 3 \n");
				return null;
			}
			else
			{
				insertHelper(children[count+1], data, m);
				System.out.println("Inserted 4 \n");
				return null;
			}
			
		}
		return root;
	}

	/**
	 * 
	 * @param data
	 */
	public Node<T> find(T data) {
		// TODO - implement BTree.find
		throw new UnsupportedOperationException();
	}

	public Node<T>[] nodes() {
		// TODO - implement BTree.leaves
		throw new UnsupportedOperationException();
	}

	public int numKeys() {
		// TODO - implement BTree.numKeys
		throw new UnsupportedOperationException();
	}

	public int countNumNodes() {
		// TODO - implement BTree.countNumLeaves
		throw new UnsupportedOperationException();
	}

	// Helper Functions
	public Node<T> sortNode(Node<T> node, int length) {
		Comparable<T>[] keys = node.getKeys();

		// Sort the keys in ascending order using bubble sort algorithm
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length - i; j++) {
				if (keys[j].compareTo((T) keys[j + 1]) > 0) {
					Comparable<T> temp = keys[j];
					keys[j] = keys[j + 1];
					keys[j + 1] = temp;
				}
			}
		}

		// Copy the sorted keys back into the node
		for (int i = 0; i < length; i++) {
			node.setKey(i, (T) keys[i]);
		}

		return node;
	}

	public void DisplayTree() {
		if (root == null) {
			System.out.println("Tree is empty");
			return;
		}
		System.out.println(root);
		Node<T>[] children = root.getChildren();
		for (int i = 0; i < children.length; i++) {
			if (children[i] != null) {
				System.out.println("│");
				System.out.print("├──[" + i + "]: ");
				System.out.print(children[i]);
			}
			System.out.println();
		}
	}

	public Node<T> insertHelper(Node<T> ptr, T data, int m) {
		// System.out.println("m: " + m);
		// System.out.println("Ptr before insert: " + ptr);
		int count = isEmptyNode(ptr, m);
		if (count != -1 && ptr == null || ptr.getData(m - 2) != null) {
			return null;
		}

		Node<T> insertNode = ptr;
		insertNode.setKey(count, data);
		insertNode = sortNode(insertNode, count);
		// System.out.println("Ptr after insert: " + ptr);
		return insertNode;
	}

	public int isEmptyNode(Node<T> node, int m) 
	{
		if (node.getData(m - 2) != null) {
			return -1;
		}
		Node<T> insertNode = node;
		int count = 0;
		while (insertNode.getData(count) != null) {
			count++;
		}
		return count;
	}

	public boolean isEmptyChildren(Node<T> ptr) 
	{
		boolean flag = true;
		Node<T>[] node = ptr.getChildren();

		for (int i = 0; i < node.length; i++) 
		{
			if (node[i] != null) 
			{
				flag = false;
			}
		}
		return flag;
	}
	public boolean isFullChildren(Node<T> ptr) 
	{
		boolean flag = true;
		Node<T>[] node = ptr.getChildren();
		System.out.println("Testing full");
		for (int i = 0; i < node.length; i++) 
		{
			System.out.println("Node: " + node[i]);
			if (node[i] != null) 
			{
				
				for (int j = 0; j < m - 2; j++) 
				{
					if(node[i].getData(j) == null)
					{
						flag = false;
					}
				}
			}
		}
		System.out.println("Are the children full: " + flag);
		return flag;
	}

}