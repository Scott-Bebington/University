public class Division extends HashFunction 
{
    public Division(int n) 
    {
        this.num = n;
    }

    @Override
    public int hash(String input) 
    {
        String temp = stringToNum(input);
        long val = Long.parseLong(temp);
        return (int) (val % num);
    }
}
