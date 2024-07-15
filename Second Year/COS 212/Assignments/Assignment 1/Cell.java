public class Cell 
{
    public int numRows, numCols, r, c, b;
    public Cell below, right, block;
    public Integer value;
    public List<Integer> possibleValues;

    public String toString() 
    {
        if (value == null) 
        {

            String res = " ";
            for (int i = 0; i < String.valueOf(numRows * numCols).length(); i++) 
            {
                res += "-";
            }
            res += " ";
            return res;
        }
        return " " + String.format("%" + String.valueOf(numRows * numCols).length() + "d", value).replace(" ", "0")
                + " ";
    }

    /*
     * Don't change anything above this line
     */

    public Cell(int nR, int nC, String inp) 
    {
        this.right = null;
        this.below = null;
        this.block = null;
        this.possibleValues = null;
        // System.out.println(inp);
        this.numRows = nR;
        this.numCols = nC;
        if (inp.equals("-")) 
        {
            this.value = null;
            possibleValues = new List<>();
            for (int i = 1; i <= numCols * numRows; i++) 
            {
                possibleValues.append(i);
            }
        }
        else
        {
            this.possibleValues = null;
            this.value = Integer.parseInt(inp);
        }
    }

    public void removeVal(int val) 
    {
        if(this.possibleValues != null)
        {
            // System.out.println("possibelvalues length = " + possibleValues.length);
            Node<Integer> ptr = possibleValues.head; 
            for (int i = 0; i < possibleValues.length; i++) 
            {
                if (ptr.data == val) 
                {
                    this.possibleValues.remove(val);
                    return;
                }
                ptr = ptr.next;
            }
        }        
    }

    public void setVal(int val) 
    {
        this.value = val;
        this.possibleValues = null;
    }

}
