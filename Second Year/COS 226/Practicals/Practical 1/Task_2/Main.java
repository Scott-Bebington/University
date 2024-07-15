package Task_2;

public class Main 
{
    public static void main(String[] args) 
    {
        int n = 0;
        int m = 100;


        // Consider adding 1 to the end to include m in the search range
        int size = m - n;
        Integer[] array = new Integer[size];

        // Initialize the array with integers from n to m
        for (int i = 0; i < size; i++) 
        {
            array[i] = n + i;
        }

        Task2(array);
    }

    public static void Task2(Integer[] arr) 
    {
        System.out.println();

        Thread t1 = new SharedCounter(arr);
        Thread t2 = new SharedCounter(arr);

        // need to set name in order for lock to work (Array out of bounds exception)
        t1.setName("Thread-0");
        t2.setName("Thread-1");

        t1.start();
        t2.start();

        try 
        {
            t1.join();
            t2.join();
        } 
        catch (Exception e) 
        {
            System.out.println("Error: " + e);
        }
    }
}