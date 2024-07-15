import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the task number (1-4): ");
        int taskNumber = scanner.nextInt();
        scanner.close();

        switch (taskNumber) {
            case 1:
                System.out.println("Fine Grain Locking");
                Task_1();
                break;
            case 2:
                System.out.println("Optimistic Locking");
                Task_2();
                break;
            case 3:
                System.out.println("Lazy Locking");
                Task_3();
                break;
            case 4:
                System.out.println("Non-blocking Locking");
                Task_4();
                break;
            default:
                System.out.println("Invalid task number.");
        }
    }

    public static LinkedList<Person> FillQueues(int start, int end) {
        LinkedList<Person> queue = new LinkedList<Person>();
        for (int i = start; i <= end; i++) {
            queue.add(new Person("P-" + i, generateRandomLong(100, 1000)));
        }
        return queue;
    }

    public static long generateRandomLong(long min, long max) {
        long range = max - min + 1;
        long scaled = (long) (range * Math.random());
        return scaled + min;
    }

    public static void Task_1() {

        LinkedList<Person> Entrance1 = FillQueues(1, 10);
        LinkedList<Person> Entrance2 = FillQueues(11, 20);
        LinkedList<Person> Entrance3 = FillQueues(21, 30);
        LinkedList<Person> Entrance4 = FillQueues(31, 40);
        LinkedList<Person> Entrance5 = FillQueues(41, 50);

        ListInterface fine_grain = new Fine_Grain();
        SecurityGuard security1 = new SecurityGuard(fine_grain, Entrance1);
        SecurityGuard security2 = new SecurityGuard(fine_grain, Entrance2);
        SecurityGuard security3 = new SecurityGuard(fine_grain, Entrance3);
        SecurityGuard security4 = new SecurityGuard(fine_grain, Entrance4);
        SecurityGuard security5 = new SecurityGuard(fine_grain, Entrance5);

        int guards = 5;
        Thread[] threads = new Thread[guards];
        threads[0] = new Thread(security1);
        threads[1] = new Thread(security2);
        threads[2] = new Thread(security3);
        threads[3] = new Thread(security4);
        threads[4] = new Thread(security5);

        for (int i = 0; i < guards; i++) {
            threads[i].start();
        }
        for (int i = 0; i < guards; i++) {
            try {
                threads[i].join();
            } catch (Exception e) {
            }
        }
    }

    public static void Task_2() {
        LinkedList<Person> Entrance1 = FillQueues(1, 10);
        LinkedList<Person> Entrance2 = FillQueues(11, 20);
        LinkedList<Person> Entrance3 = FillQueues(21, 30);
        LinkedList<Person> Entrance4 = FillQueues(31, 40);
        LinkedList<Person> Entrance5 = FillQueues(41, 50);

        ListInterface Optimistic = (ListInterface) new Optimistic();
        SecurityGuard security1 = new SecurityGuard(Optimistic, Entrance1);
        SecurityGuard security2 = new SecurityGuard(Optimistic, Entrance2);
        SecurityGuard security3 = new SecurityGuard(Optimistic, Entrance3);
        SecurityGuard security4 = new SecurityGuard(Optimistic, Entrance4);
        SecurityGuard security5 = new SecurityGuard(Optimistic, Entrance5);

        int guards = 5;
        Thread[] threads = new Thread[guards];
        threads[0] = new Thread(security1);
        threads[1] = new Thread(security2);
        threads[2] = new Thread(security3);
        threads[3] = new Thread(security4);
        threads[4] = new Thread(security5);

        for (int i = 0; i < guards; i++) {
            threads[i].start();
        }
        for (int i = 0; i < guards; i++) {
            try {
                threads[i].join();
            } catch (Exception e) {
            }
        }

    }

    public static void Task_3() {
        LinkedList<Person> Entrance1 = FillQueues(1, 10);
        LinkedList<Person> Entrance2 = FillQueues(11, 20);
        LinkedList<Person> Entrance3 = FillQueues(21, 30);
        LinkedList<Person> Entrance4 = FillQueues(31, 40);
        LinkedList<Person> Entrance5 = FillQueues(41, 50);

        ListInterface Lazy = (ListInterface) new LockFreeStack();
        SecurityGuard security1 = new SecurityGuard(Lazy, Entrance1);
        SecurityGuard security2 = new SecurityGuard(Lazy, Entrance2);
        SecurityGuard security3 = new SecurityGuard(Lazy, Entrance3);
        SecurityGuard security4 = new SecurityGuard(Lazy, Entrance4);
        SecurityGuard security5 = new SecurityGuard(Lazy, Entrance5);

        int guards = 5;
        Thread[] threads = new Thread[guards];
        threads[0] = new Thread(security1);
        threads[1] = new Thread(security2);
        threads[2] = new Thread(security3);
        threads[3] = new Thread(security4);
        threads[4] = new Thread(security5);

        for (int i = 0; i < guards; i++) {
            threads[i].start();
        }
        for (int i = 0; i < guards; i++) {
            try {
                threads[i].join();
            } catch (Exception e) {
            }
        }

    }

    public static void Task_4() {
        LinkedList<Person> Entrance1 = FillQueues(1, 10);
        LinkedList<Person> Entrance2 = FillQueues(11, 20);
        LinkedList<Person> Entrance3 = FillQueues(21, 30);
        LinkedList<Person> Entrance4 = FillQueues(31, 40);
        LinkedList<Person> Entrance5 = FillQueues(41, 50);

        ListInterface non_blocking = (ListInterface) new non_blocking();
        SecurityGuard security1 = new SecurityGuard(non_blocking, Entrance1);
        SecurityGuard security2 = new SecurityGuard(non_blocking, Entrance2);
        SecurityGuard security3 = new SecurityGuard(non_blocking, Entrance3);
        SecurityGuard security4 = new SecurityGuard(non_blocking, Entrance4);
        SecurityGuard security5 = new SecurityGuard(non_blocking, Entrance5);

        int guards = 5;
        Thread[] threads = new Thread[guards];
        threads[0] = new Thread(security1);
        threads[1] = new Thread(security2);
        threads[2] = new Thread(security3);
        threads[3] = new Thread(security4);
        threads[4] = new Thread(security5);

        for (int i = 0; i < guards; i++) {
            threads[i].start();
        }
        for (int i = 0; i < guards; i++) {
            try {
                threads[i].join();
            } catch (Exception e) {
            }
        }

    }
}
