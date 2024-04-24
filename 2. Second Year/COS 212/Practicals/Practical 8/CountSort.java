public class CountSort<T extends Comparable<T>> extends Sort<T> 
{
    @Override
    @SuppressWarnings("unchecked")
    public Comparable<T>[] sort(Comparable<T>[] arr) 
    {
        //Do not alter given code nor add code above
        int[] count = formCountArr(arr);
        printArr(arr, count);
        int[] sumCount = sumCount(count);
        printArr(arr, sumCount);
        Comparable<T>[] res = new Comparable[arr.length]; //This array needs to be populated with the final result
        //Add code below this
        
        for (int i = 0; i < arr.length; i++) 
        {
            int index = arr[i].hashCode();
            res[sumCount[index] - 1] = arr[i];
            sumCount[index]--;
        }

        //Do not change the statement below
        printArr(res, sumCount);
        //Ensure only return statement is below this
        return res;
        
    }

    private int[] formCountArr(Comparable<T>[] arr) 
    {
        int countArrSize = countArraySize(arr);
        int[] countArr = new int[countArrSize];
    
        for (Comparable<T> element : arr) 
        {
            // System.out.println(element + " has hash code: " + element.hashCode());
            int index = element.hashCode();
            countArr[index]++;
        }
        
        return countArr;
    }
    

    private int[] sumCount(int[] countArr)
    {
        int[] sumCountArr = new int[countArr.length];
        sumCountArr[0] = countArr[0];
        for (int i = 1; i < countArr.length; i++) 
        {
            sumCountArr[i] = sumCountArr[i-1] + countArr[i];
        }
        return sumCountArr;
    }

    private int countArraySize(Comparable<T>[] arr)
    {
        int BiggestHashCode = 0;
        for (int i = 0; i < arr.length; i++) 
        {
            if(arr[i].hashCode() > BiggestHashCode)
            {
                BiggestHashCode = arr[i].hashCode();
            }
        }
        return BiggestHashCode + 1;
    }

    private void printArr(Comparable<T>[] arr, int[] count)
    {
        if(arr == null || count == null)
            System.out.println("NULL ARRAYS");

        String res = "[";
        for(Comparable<T> t: arr){
            res += t + "{" + count[t.hashCode()] + "},";
        }
        if(res.length() > 0){
            res = res.substring(0, res.length()-1);
        }
        res += "]";
        System.out.println(res);
    }


}
