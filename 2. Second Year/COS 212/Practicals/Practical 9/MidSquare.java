public class MidSquare extends HashFunction 
{

    public MidSquare(int n) 
    {
        this.num = n;
    }

    @Override
    public int hash(String input) 
    {
        Long val = Long.parseLong(stringToNum(input));
        
        val = val * val;

        String convertedLong = "" + val;
        

        if (convertedLong.length() <= num) 
        {
            return Integer.parseInt(convertedLong);
        } 
        else 
        {
            boolean oddFlag = true;

            if(num % 2 == 0)
            {
                oddFlag = false;
            }

            if(convertedLong.length() % 2 != 0 && !oddFlag)
            {
                convertedLong = convertedLong + "0";
            }
            else if(convertedLong.length() % 2 == 0 && oddFlag)
            {
                convertedLong = convertedLong + "0";
            }

            int length = convertedLong.length();
            int start = (length - num) / 2;
            int end = start + num;
            String sub = convertedLong.substring(start, end);


            return Integer.parseInt(sub);
        }
    }
}
