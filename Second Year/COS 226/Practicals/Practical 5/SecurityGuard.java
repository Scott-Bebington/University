import java.util.LinkedList;

public class SecurityGuard extends Thread {
    ListInterface lockingType;
    LinkedList<Person> queue;

    String redColour = "\u001B[31m";
    String greenColour = "\u001B[32m";
    String resetColour = "\u001B[0m";

    public SecurityGuard(ListInterface lockingType, LinkedList<Person> queue) {
        this.lockingType = lockingType;
        this.queue = queue;
    }

    @Override
    public void run() {
        try {
            Thread.sleep(200);
            while (!queue.isEmpty()) {
                Person person = queue.remove();
                
                if (lockingType.add(person)) {
                    System.out.println("Thread-" + getID() + ": Add (" + person.name + ", " + person.time + ")");
                }
                else
                {
                    System.out.println(redColour + "Error: could not add " + person.name + resetColour);
                }
                long time = person.time;
                if (time < 200) {
                    time = 200;
                }
                Thread.sleep(time);
                if(lockingType.remove(person)) {
                    // PrintLinkedList();
                    lockingType.printQueue();
                }
                else
                {
                    System.out.println(redColour + "Error: could not remove " + person.name + resetColour);
                }                
            }

        } catch (Exception e) {
            System.out.println(redColour +  "An unknown error has occured" + resetColour);
        }
    }

    public void PrintLinkedList() {
        Object[] obj = queue.toArray();
        String str = "Thread-" + getID() + ": ";
        for (int i = 0; i < obj.length; i++) {
            Person person = (Person) obj[i];
            str += "(" + person.name + ", " + person.time + "ms), ";
        }
        str = str.substring(0, str.length() - 2);
        System.out.println(str + "\n");
    }

    public int getID() {
        return Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
    }

    public static long generateRandomLong(long min, long max) {
        long range = max - min + 1;
        long scaled = (long) (range * Math.random());
        return scaled + min;
    }
}
