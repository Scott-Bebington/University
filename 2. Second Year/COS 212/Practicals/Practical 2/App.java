public class App 
{
    public static void main(String[] args) throws Exception 
    {
        TransposeList<Integer> countlist = new TransposeList<>();
        insertlist(countlist);
        
        IterativeTraverse<Integer> list = new IterativeTraverse<>(countlist);
        System.out.println(list);

        accessFromfront(countlist);
        list.setList(countlist);
        System.out.println(list);

        
    }
    public static void insertlist(SelfOrderingList<Integer> list)
    {
        // char [] arr = {'0', 1, 2, 3, 4};
        for(int i = 0; i < 5; i++)
        {
            // list.insert(arr[i]);
            list.insert(i);
        }
    }
    public static void accessFromfront(SelfOrderingList<Integer> list)
    {
        // System.out.println("Accessing from the head of the list");
        int [] arr = {0, 2, 1, 2, 3, 0, 3, 0, 2, 0, 2, 2, 4, 4};
        for (int i = 0; i < 14; i++) 
        {
            // System.out.println("Accessing " + i);
            list.access(arr[i]);  
        }
        System.out.println();
    }
}