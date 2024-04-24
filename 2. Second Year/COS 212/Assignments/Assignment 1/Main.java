public class Main {
    /*
     * Tips for using this Main
     * 
     * The output is in out.txt
     * 
     * Comment the tasks you are not currently testing
     * 
     * Look up "Text Comparison" for your IDE of choice. This way you can save your
     * output to a txt file and use that to see if there are differences between
     * your output and my output.
     * 
     * THESE TESTS ARE TRIVIAL. Make sure you expand and do more testing
     */
    public static void main(String[] args) 
    {
        // String file = "0x0.txt";
        // String file = "1x1.txt";
        // String file = "1x2.txt";
        // String file = "2x2.txt";
        // String file = "2x3.txt";
        String file = "3x3.txt";
        // String file = "4x4.txt";
        // String file = "5x5.txt";
        task1();
        task2(file);
        task3(file);
    }

    public static void task1() 
    {
        System.out.println("==========\nTask1\n==========");
        List<Integer> l = new List<>();

        for (int i = 1; i <= 9; i++) 
        {
            l.append(i);
        }

        System.out.println(l.length + "\t" + l);
        // l.remove(2);
        // System.out.println(l.length + "\t" + l);
        // l.remove(1);
        // System.out.println(l.length + "\t" + l);
        // l.remove(9);
        // System.out.println(l.length + "\t" + l);
        // l.remove(4);
        // System.out.println(l.length + "\t" + l);

        // // Testing "public boolean remove(List<T> val)"
        List<Integer> l2 = new List<>();
        // l2 = null;
        l2.append(2);
        l2.append(1);
        l2.append(9);
        l2.append(4);

        l.remove(l2);
        System.out.println(l.length + "\t" + l);

        // System.out.println("Testing contains");
        // System.out.println("Is 0 in the list: " + l.contains(0));
        // System.out.println("Is 1 in the list: " + l.contains(1));
        // System.out.println("Is 5 in the list: " + l.contains(5));
        // System.out.println("Is 9 in the list: " + l.contains(9));
        // System.out.println("Is 15 in the list: " + l.contains(15));
        // // Testing "public boolean equals(List<T> other)"
        // List<Integer> l3 = new List<>();
        // for (int i = 1; i <= 9; i++) 
        // {
        //     l3.append(i);
        // }

        // System.out.println("List 1 = " + l);
        // System.out.println("List 2 = " + l3);

        // l3.remove(7);

        // if (l.equals(l3)) 
        // {
        //     System.out.println("List 1 is the same as list 2");
        // }
        // else
        // {
        //     System.out.println("List 1 is not the same as list 2");
        // }
    }

    public static void task2(String inpfile) 
    {
        System.out.println("==========\nTask2\n==========");
        SudokuSolver s1 = new SudokuSolver(inpfile);
        System.out.println("### Print Board ###");
        System.out.println(s1.board());
        System.out.println("### testLinks ###");
        s1.board().testLinks();
        System.out.println("### testCells ###");
        s1.board().testCells();

        s1.board();

    }

    public static void task3(String inpfile) 
    {
        System.out.println("==========\nTask3\n==========");
        SudokuSolver s1 = new SudokuSolver(inpfile);
        s1.solveBoard();
    }
}
