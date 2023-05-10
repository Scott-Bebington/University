@SuppressWarnings("unchecked")
public class minDHeap<T extends Comparable<T>> {
    private int d;
    private T[] nodes;

    @Override
    public String toString() 
    {
        if (nodes.length == 0) 
        {
            return "";
        }

        return "[" + nodes[0] + "]\n" + toStringRec(0, "");
    }

    public String toStringRec(int i, String pre) 
    {
        if (i >= nodes.length) 
        {
            return "";
        }
        String res = "";
        for (int k = 0; k < d; k++) 
        {
            int c = d * i + k + 1;
            if (c < nodes.length) {
                if (k == d - 1 || c + 1 >= nodes.length) {
                    res += pre + "└── " + "[" + nodes[c] + "]\n" + toStringRec(c, pre + "    ");
                } else {
                    res += pre + "├── " + "[" + nodes[c] + "]\n" + toStringRec(c, pre + "│   ");
                }
            }
        }
        return res;
    }

    public T[] getNodes() {
        return nodes;
    }

    /*
     * Don't change anything above this line
     */

    public minDHeap(int d) {
        this.d = d;
        this.nodes = (T[]) new Comparable[0];
    }

    public void insert(T val) {
        if (nodes.length == 0) 
        {
            nodes = (T[]) new Comparable[1];
            nodes[0] = val;
            return;
        }

        int OldLength = nodes.length;
        int NewLength = OldLength + 1;
        T[] newArr = (T[]) new Comparable[NewLength];
        for (int i = 0; i < OldLength; i++) 
        {
            newArr[i] = nodes[i];
        }
        newArr[OldLength] = val;

        int childPos = OldLength;
        int parentPos = (childPos - 1) / d;

        while (parentPos >= 0 && newArr[childPos].compareTo(newArr[parentPos]) < 0) 
        {
            T temp = newArr[childPos];
            newArr[childPos] = newArr[parentPos];
            newArr[parentPos] = temp;

            childPos = parentPos;
            parentPos = (childPos - 1) / d;
        }
        nodes = newArr;
    }

    public void remove(T val) 
    {
        if (nodes.length != 0) 
        {
            int OldLength = nodes.length;
            int NewLength = OldLength - 1;
            T[] newArr;
            if (nodes.length >= 1)
            {
                newArr = (T[]) new Comparable[NewLength];
            }
            else
            {
                nodes = (T[]) new Comparable[0];
                return;
            }

            int removePos = -1;
            for (int i = 0; i < OldLength; i++) 
            {
                if (nodes[i].equals(val)) 
                {
                    removePos = i;
                    break;
                }
            }

            if (removePos == -1) 
            {
                return;
            }

            nodes[removePos] = nodes[NewLength];

            for (int i = 0; i < newArr.length; i++) 
            {
                newArr[i] = nodes[i];
            }

            nodes = newArr;

            if (removePos < nodes.length) 
            {
                goDown(removePos);
            }
        }
        return;
    }

    private void goDown(int Pos) 
    {
        int childPos = SmallChild(Pos);

        if(childPos != -1 && nodes[childPos].compareTo(nodes[Pos]) < 0)
        {
            swapNodes(Pos, childPos);
            goDown(childPos);
        }
        return;
    }

    private int SmallChild(int Pos) 
    {
        int childPos = (Pos * d) + 1;
        int smallPos = childPos;

        if (childPos >= nodes.length)
        {
            return -1;
        }

        for (int i = childPos; i < childPos + d; i++) 
        {
            if (i < nodes.length && (nodes[i]).compareTo(nodes[smallPos]) < 0) 
            {
                smallPos = i;
            }
        }
        return smallPos;
    }

    private void swapNodes(int Parent, int Child) 
    {
        T temp = nodes[Parent];
        nodes[Parent] = nodes[Child];
        nodes[Child] = temp;
    }

    public void changeD(int newD) 
    {
        this.d = newD;

        int lastNonLeafPos = (nodes.length - 2) / d;
        for (int i = lastNonLeafPos; i >= 0; i--) 
        {
            changeDhelper(i);
        }
    }

    private void changeDhelper(int i) {
        int smallest = i;
        int firstChildPos = (d * i) + 1;

        for (int j = 0; j < d; j++) 
        {
            int childPos = firstChildPos + j;
            if (childPos < nodes.length && nodes[childPos].compareTo(nodes[smallest]) < 0) 
            {
                smallest = childPos;
            }
        }

        if (smallest != i) 
        {
            T temp = nodes[i];
            nodes[i] = nodes[smallest];
            nodes[smallest] = temp;
            changeDhelper(smallest);
        }
    }

    public T min(int i) 
    {
        if (i < 0 || i > nodes.length - 1 || nodes.length <= 0) 
        {
            return null;
        }
        return nodes[i];
    }

    public T max(int i) 
    {
        if (i < 0 || i > nodes.length - 1 || nodes.length == 0) 
        {
            return null;
        }

        if(i == 0)
        {
            T maxNode = nodes[0];

            for (int j = 1; j < nodes.length; j++) 
            {
                if (nodes[j].compareTo(maxNode) > 0) 
                {
                    maxNode = nodes[j];
                }
            }
            return maxNode;
        }
        return BigChild(i);
    }

    private T BigChild(int Pos)
    {
        T[] newArr = (T[]) new Comparable[nodes.length+1];
        newArr[0] = nodes[Pos];

        int temp = Pos;
        int startPos = temp * d + 1;
        int endPos = startPos + d - 1;
        int newArrayPos = 1;
        int heightCount = 1;
        {
            while(startPos < nodes.length)
            {
                for (int i = startPos; i <= endPos; i++) 
                {
                    if(i < nodes.length)
                    {
                        newArr[newArrayPos] = nodes[i];
                        newArrayPos++;
                    }
                }
                heightCount++;
                startPos = startPos * d + 1;
                endPos = startPos + (int)Math.pow(d, heightCount) - 1;
            }
        }

        T maxNode = newArr[0];

        for (int j = 0; j < newArr.length; j++) 
        {
            if(newArr[j] != null)
            {
                if (newArr[j].compareTo(maxNode) > 0) 
                {
                    maxNode = newArr[j];
                }
            }
            
        }
        return maxNode;
    }

    public String pathToRoot(T val) 
    {
        if (nodes.length != 0) 
        {
            int nodePos = -1;
            for (int i = 0; i < nodes.length; i++) 
            {
                if (val.equals(nodes[i])) 
                {
                    nodePos = i;
                    break;
                }
            }

            if (nodePos == -1) 
            {
                return "";
            }

            String str = "";
            while (nodePos > 0) 
            {
                str += "[" + nodes[nodePos] + "]";
                nodePos = (nodePos - 1) / d;
            }
            str += "[" + nodes[0] + "]";
            return str;
        }
        return "";
    }
}
