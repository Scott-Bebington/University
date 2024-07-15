public class Hashmap {
    public HashFunction[] functions;
    public String[][] hashStrings;

    public Hashmap(int length, HashFunction[] funcs) 
    {
        this.functions = funcs;
        this.hashStrings = new String[length][];
    }

    public int hash(String val) 
    {
        int result = 0;

        for (int i = 0; i < functions.length; i++) 
        {
            result += functions[i].hash(val);
        }

        return result % hashStrings.length;
    }

    public boolean contains(String val) 
    {
        int index = hash(val);

        if (index < 0 || index >= hashStrings.length) 
        {
            return false;
        }

        String[] chain = hashStrings[index];

        if (chain == null || chain.length == 0) 
        {
            return false;
        }

        for (String str : chain) 
        {
            if (str.equals(val)) 
            {
                return true;
            }
        }

        return false;
    }

    public void insert(String s) 
    {
        if (contains(s)) 
        {
            return;
        }

        int index = hash(s);

        if (index < 0 || index >= hashStrings.length) 
        {
            return;
        }

        String[] chain = hashStrings[index];

        if (chain == null || chain.length == 0) 
        {
            chain = new String[1];
            chain[0] = s;
            hashStrings[index] = chain;
            return;
        }

        String[] newChain = new String[chain.length + 1];

        for (int i = 0; i < chain.length; i++) 
        {
            newChain[i] = chain[i];
        }

        newChain[newChain.length - 1] = s;

        hashStrings[index] = newChain;
    }

    public void remove(String s) 
    {
        if(!contains(s))
        {
            return;
        }

        int index = hash(s);

        if (index < 0 || index >= hashStrings.length) 
        {
            return;
        }

        String[] chain = hashStrings[index];

        if (chain == null || chain.length == 0) 
        {
            return;
        }

        String[] newChain = new String[chain.length - 1];

        int count = 0;

        for (int i = 0; i < chain.length; i++) 
        {
            if(!chain[i].equals(s))
            {
                newChain[count] = chain[i];
                count++;
            }
        }

        hashStrings[index] = newChain;
    }

    public String toString() 
    {
        String str = "[";

        for (int i = 0; i < hashStrings.length; i++) 
        {
            String[] chain = hashStrings[i];

            if (chain != null) 
            {
                for (int j = 0; j < chain.length; j++) 
                {
                    if (j > 0) 
                    {
                        str += ",";
                    }
                    str += chain[j];
                }
            }
            str += ";";
        }

        str = str.substring(0, str.length() - 1);
        str += "]";
        return str;
    }
}
