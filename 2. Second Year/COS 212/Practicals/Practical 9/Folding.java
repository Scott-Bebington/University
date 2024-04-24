public class Folding extends HashFunction 
{
    public boolean shift;

    public Folding(int n, boolean s) 
    {
        this.num = n;
        this.shift = s;
    }

    @Override
    public int hash(String input) 
    {
        String temp = stringToNum(input);

        int paddedLength = temp.length();

        while (paddedLength % num != 0) 
        {
            paddedLength++;
            temp = temp + "0";
        }

        int ReturnInt = 0;
        int count = 0;

        for (int i = 0; i < paddedLength; i += num) 
        {
            String sub = temp.substring(i, i + num);

            if (shift) 
            {
                ReturnInt += Integer.parseInt(sub);
            }
            else
            {
                if(count == 0)
                {
                    ReturnInt += Integer.parseInt(sub);
                    count++;
                }
                else if(count == 1)
                {
                    ReturnInt += Integer.parseInt(reverseString(sub));
                    count--;
                }
            }
        }
        return ReturnInt;
    }
    
    private String reverseString(String str) 
    {
        int length = str.length();

        String reversedString = "";

        for (int i = length - 1; i >= 0; i--) 
        {
            reversedString += str.charAt(i);
        }
        return reversedString;
    }
}
