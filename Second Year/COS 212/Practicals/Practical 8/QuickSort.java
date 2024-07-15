public class QuickSort<T extends Comparable<T>> extends Sort<T> {
    @Override
    @SuppressWarnings("unchecked")
    public Comparable<T>[] sort(Comparable<T>[] data) 
    {
        printArr(data);
        if (data.length > 1) 
        {
            int pivotIndex = getPivotPoint(data);

            Comparable<T> pivot = data[pivotIndex];

            int leftIndex = 0;
            int rightIndex = 0;
            Comparable<T>[] left = new Comparable[data.length];
            Comparable<T>[] right = new Comparable[data.length];

            for (int i = 0; i < data.length; i++) 
            {
                if (data[i].compareTo((T)pivot) < 0) 
                {
                    left[leftIndex] = data[i];
                    leftIndex++;
                } 
                else if (data[i].compareTo((T)pivot) > 0) 
                {
                    right[rightIndex] = data[i];
                    rightIndex++;
                }
            }
            left = Resize(left);
            right = Resize(right);

            sort(left);
            sort(right);

            int dataIndex = 0;
            for (int i = 0; i < leftIndex; i++) 
            {
                data[dataIndex] = left[i];
                dataIndex++;
            }

            data[dataIndex] = pivot;
            dataIndex++;

            for (int i = 0; i < rightIndex; i++) 
            {
                data[dataIndex] = right[i];
                dataIndex++;
            }
        }
        return data;
    }

    private int getPivotPoint(Comparable<T>[] arr) 
    {
        if (arr == null || arr.length == 0)
            return 0;

        if (arr.length % 2 == 0)
            return (int) Math.floor(arr.length / 2) - 1;
        else
            return (int) Math.floor(arr.length / 2);
    }

    @SuppressWarnings("unchecked")
    private Comparable<T>[] Resize(Comparable<T>[] data)
    {
        // resize the array to remove null values
        int count = 0;
        for (int i = 0; i < data.length; i++) 
        {
            if (data[i] != null)
                count++;
        }
        Comparable<T>[] temp = new Comparable[count];
        for (int i = 0; i < temp.length; i++) 
        {
            temp[i] = data[i];
        }
        return temp;
    }
}
