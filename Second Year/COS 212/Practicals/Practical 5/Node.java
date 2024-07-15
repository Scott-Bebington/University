public class Node<T extends Comparable<T>> 
{

	private Comparable<T>[] keys;
	private Node<T>[] children;

	/**
	 * 
	 * @param m
	 */
	@SuppressWarnings("unchecked")
	public Node(int m) 
	{
		this.keys = (T[]) new Comparable[m - 1];
		this.children = new Node[m];
		// throw new UnsupportedOperationException();
	}

	public Node<T>[] getChildren()
	{
		return this.children;
	}

	public Comparable<T>[] getKeys()
	{
		return this.keys;
	}

	public Comparable<T> getData(int pos)
	{
		return this.keys[pos];
	}

	public void setKey(int pos, T data)
	{
		this.keys[pos] = data;
	}



	// DO NOT CHANGE
	@Override
	public String toString() 
	{
		String res = "[";
		for (int i = 0; i < keys.length; i++) 
		{
			if (keys[i] != null)
				res += keys[i];
			else
				res += "null";
			res += ",";
		}
		if (res.length() > 1) 
		{
			res = res.substring(0, res.length() - 1);
		}
		return res + "]";
	}

}