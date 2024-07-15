public class MergeSort <T extends Comparable<T>> extends Sort<T> 
{
    @Override
    public Comparable<T>[] sort(Comparable<T>[] arr) 
    {
        return mergeSort(arr, 0, arr.length-1);
    }

    @SuppressWarnings("unchecked")
    private Comparable<T>[] mergeSort(Comparable<T>[] data, int first, int last)
    {
        //Do not change the position of this function.
        printArr(data);
        //Add any code below

        if(data.length == 0 || data == null)
        {
            return new Comparable[0];
        }
        if(first < last)
        {
            int mid = getMidPoint(first, last);

            Comparable<T>[] left = new Comparable[mid + 1];
            for (int i = 0; i <= mid; i++) 
            {
                left[i] = data[i];
            }
            mergeSort(left, first, mid);


            Comparable<T>[] right = new Comparable[last-mid];

            int index = 0;
            for (int i = mid + 1; i < last; i++) 
            {
                right[index] = data[i];
                index++;
            }
            right[index] = data[last];
            mergeSort(right, 0, last - mid - 1);


            Comparable<T>[] merged = merge(left, right);
            System.arraycopy(merged, 0, data, first, merged.length);
        }

        return data;
    }

    @SuppressWarnings("unchecked")
    private Comparable<T>[] merge(Comparable<T>[] LHS, Comparable<T>[] RHS)
    {
        Comparable<T>[] array = new Comparable[LHS.length + RHS.length];

        boolean flag = true;
        int arrayIndex = 0;
        while(flag)
        {
            if(LHS.length != 0 && RHS.length != 0)
            {
                if(LHS[0] != null && RHS[0] != null && LHS[0].compareTo((T) RHS[0]) < 0)
                {
                    array[arrayIndex] = LHS[0];
                    LHS = removeNode(LHS);
                    arrayIndex++;
                }
                else
                {
                    array[arrayIndex] = RHS[0];
                    RHS = removeNode(RHS);
                    arrayIndex++;
                }
            }
            else if(LHS.length == 0 && RHS.length != 0)
            {
                array[arrayIndex] = RHS[0];
                RHS = removeNode(RHS);
                arrayIndex++;
            }
            else if(LHS.length != 0 && RHS.length == 0)
            {
                array[arrayIndex] = LHS[0];
                LHS = removeNode(LHS);
                arrayIndex++;
            }
            else
            {
                flag = false;
            }
        }
        return array;
    }

    private int getMidPoint(int first, int last)
    {
        return (int)Math.floor((first+last)/2);
    }

    // Helper Functions
    @SuppressWarnings("unchecked")
    private Comparable<T>[] removeNode(Comparable<T>[] Array)
    {
        Comparable<T>[] arr = new Comparable[Array.length-1];
        for (int i = 0; i < arr.length; i++) 
        {
            arr[i] = Array[i + 1];
        }
        return arr;
    }
    
}


