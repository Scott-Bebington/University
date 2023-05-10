public class Cell implements Comparable<Cell> 
{
    int databaseRow;
    String value;

    @Override
    public int compareTo(Cell o) 
    {
        return value.compareTo(o.value);
    }

    @Override
    public String toString() 
    {
        return value + "{" + databaseRow + "}";
    }

    public Cell(int DBR, String val)
    {
        this.databaseRow = DBR;
        this.value = val;
    }
}
