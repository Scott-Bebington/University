public class Extraction extends HashFunction 
{
    public Extraction(int n) 
    {
        this.num = n;
    }

    @Override
    public int hash(String input) 
    {
        String temp = stringToNum(input);

        if (temp.length() <= num) 
        {
            return Integer.parseInt(temp);
        } 
        else 
        {
            String lastNum = temp.substring(temp.length() - this.num);
            return Integer.parseInt(lastNum);
        }
    }
}
