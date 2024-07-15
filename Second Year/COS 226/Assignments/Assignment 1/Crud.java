import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.locks.Lock;

public class Crud {
    private volatile Queue<Info> database = new LinkedList<>();

    private volatile Queue<Info> create = new LinkedList<>();
    private volatile Queue<Boolean> read = new LinkedList<>();
    private volatile Queue<Info> update = new LinkedList<>();
    private volatile Queue<Info> delete = new LinkedList<>();

    Lock l;

    String redColorCode = "\u001B[31m";
    // ANSI escape code to reset text color
    String resetColorCode = "\u001B[0m";

    public Crud(Lock l) {
        this.l = l;
        String ids[] = { "u123", "u456", "u789", "u321", "u654", "u215", "u147", "u258", "u369", "u741", "u852",
                "u963" }; // 12
        String names[] = { "Thabo", "Luke", "James", "Lunga", "Ntando", "Scott", "Michael", "Ntati", "Lerato", "Niel",
                "Saeed", "Rebecca" }; // 12

        for (int i = 0; i < 20; i++) {
            read.add(true);

            if (i < 12)
                create.add(new Info(ids[i], names[i], 'c'));

            if (i < 4)
                update.add(new Info(ids[i + 1], names[i + 1], 'u'));
            if (i < 4)
                delete.add(new Info(ids[i + 2], names[i + 2], 'd'));

            if (i >= 9 && i < 12) {
                update.add(new Info(ids[i], names[i], 'u'));
                delete.add(new Info(ids[i], names[i], 'd'));
            }
        }
    }

    public Queue<Info> getDatabase() {
        return database;
    }

    public Queue<Info> getCreate() {
        return create;
    }

    public Queue<Boolean> getRead() {
        return read;
    }

    public Queue<Info> getUpdate() {
        return update;
    }

    public Queue<Info> getDelete() {
        return delete;
    }

    public void ExecuteCommand(int num) {
        char operation = PrintReady(num);

        if (!checkEmpty(num))
            System.out.println(Thread.currentThread().getName() + " " + operation + " is waiting for request.");
        l.lock();
        try {
            try {

                switch (num) {
                    case 0: // create
                        Insert(operation);
                        break;

                    case 1: // read
                        Read();
                        break;

                    case 2: // update
                        Update();
                        break;

                    case 3: // delete
                        Delete();
                        break;

                    default:
                        break;
                }

            } catch (Exception e) {
            }
        } finally {
            if (!checkEmpty(num)) {
                System.out.println(Thread.currentThread().getName() + " " + operation + " is sleeping.\n");
                long random = generateRandomLong(50, 100);
                try {
                    Thread.sleep(random);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            l.unlock();
        }
    }

    private boolean checkEmpty(int num) {
        switch (num) {
            case 0: // create
                if (create.isEmpty())
                    return true;
                break;

            case 1: // read
                if (read.isEmpty())
                    return true;
                break;

            case 2: // update
                if (update.isEmpty())
                    return true;
                break;

            case 3: // delete
                if (delete.isEmpty())
                    return true;
                break;
        }
        return false;
    }

    private long generateRandomLong(long min, long max) {
        long range = max - min + 1;
        long scaled = (long) (range * Math.random());
        return scaled + min;
    }

    private char PrintReady(int num) {
        char operation = ' ';
        switch (num) {
            case 0:
                operation = 'c';
                break;

            case 1:
                operation = 'r';
                break;

            case 2:
                operation = 'u';
                break;

            case 3:
                operation = 'd';
                break;

            default:
                break;
        }
        return operation;
    }

    private void Insert(char operation) {
        Info info = create.remove();
        database.add(info);
        System.out.println(Thread.currentThread().getName() + " " + operation + " success " + " { ID: " + info.id
                + ", Name: " + info.name + ",\tPractical: " + info.practicals + ",\tAssignment: "
                + info.assignments + "}");

    }

    private void Read() {
        read.remove();
        Object[] arr = database.toArray();
        System.out.println(Thread.currentThread().getName() + " r");
        System.out.println("Start----------------------------------------------------------------------");

        for (int i = 0; i < arr.length; i++) {
            Info info = (Info) arr[i];
            System.out.println("\tID: " + info.id + ", Name: " + info.name + ", Practical: " + info.practicals
                    + ", Assignment: " + info.assignments);
        }
        System.out.println("End----------------------------------------------------------------------");
    }

    private void Update() {
        Object[] arr = database.toArray(); // Converts the queue to an array
        Info Update = update.peek(); // Gets the head of the queue

        for (int i = 0; i < arr.length; i++) {
            Info info = (Info) arr[i];
            if (info.id.equals(Update.id)) {
                info.practicals = Update.practicals;
                info.assignments = Update.assignments;
                System.out.println(Thread.currentThread().getName() + " u success " + " { ID: " + info.id + ", Name: "
                        + info.name + ", Practical: " + info.practicals + ", Assignment: " + info.assignments + "}");
                update.remove();
                return;
            }
        }
        Info failed = update.element();
        failed.attempt++;

        if (failed.attempt > 1) {
            update.remove();
            System.out.println(Thread.currentThread().getName() + " u failed { ID: "
                    + failed.id + ", Name: " + failed.name + ", Attempts: " + failed.attempt + "}");
            return;
        }
        update.remove();
        update.add(failed);
        System.out.println(Thread.currentThread().getName() + " u failed { ID: "
                + failed.id + ", Name: " + failed.name + ", Attempts: " + failed.attempt + "}");

    }

    private void Delete() {
        Object[] arr = database.toArray(); // Converts the queue to an array
        Info Delete = delete.peek(); // Gets the head of the queue

        for (int i = 0; i < arr.length; i++) {
            Info info = (Info) arr[i];
            if (info.id.equals(Delete.id)) {
                database.remove(info);
                delete.remove();
                System.out.println(Thread.currentThread().getName() + " d success " + " { ID: " + info.id + ", Name: "
                        + info.name + ", Practical: " + info.practicals + ", Assignment: " + info.assignments + "}");
                return;
            }
        }
        Info failed = delete.element();
        failed.attempt++;

        if (failed.attempt > 1) {
            delete.remove();
            System.out.println(Thread.currentThread().getName() + " u failed { ID: "
                    + failed.id + ", Name: " + failed.name + ", Attempts: " + failed.attempt + "}");
            return;
        }
        delete.remove();
        delete.add(failed);
        System.out.println(Thread.currentThread().getName() + " u failed { ID: "
                + failed.id + ", Name: " + failed.name + ", Attempts: " + failed.attempt + "}");
    }

}