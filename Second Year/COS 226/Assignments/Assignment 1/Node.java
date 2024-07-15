public class Node extends Thread {

    Crud crud;
	volatile boolean locked = false;
	volatile Node next = null;
	volatile Node prev = null;
	String threadname = "";
	int count = 1;

	Node() {}

	Node(Crud Crd) {
        crud = Crd;
    }

	@Override
    public void run() {
        // int num = 0;
        // for (int i = 0; i < 20; i++) {
        //     if (!crud.getCreate().isEmpty()) {
        //         crud.ExecuteCommand(num);
        //     }
        // }

        // num = 1;
        // for (int i = 0; i < 25; i++) {
        //     if (!crud.getRead().isEmpty()) {
        //         crud.ExecuteCommand(num);
        //     }
        // }

        // num = 2;
        // for (int i = 0; i < 20; i++) {
        //     if (!crud.update.isEmpty()) {
        //         crud.ExecuteCommand(num);
        //     }
        // }
        // crud.ExecuteCommand(1);
        
        // num = 3;
        // for (int i = 0; i < 20; i++) {
        //     if (!crud.getDelete().isEmpty()) {
        //         crud.ExecuteCommand(num);
        //     }
        // }
        // crud.ExecuteCommand(1);

        while (!crud.getCreate().isEmpty() || !crud.getUpdate().isEmpty() || !crud.getDelete().isEmpty()) {
            int num = generateRandomInt();
            while (crud.getCreate().isEmpty() && num == 0) {
                num = generateRandomInt();
            }
            while (crud.getRead().isEmpty() && num == 1) {
                num = generateRandomInt();
            }
            while (crud.getUpdate().isEmpty() && num == 2) {
                num = generateRandomInt();
            }
            while (crud.getDelete().isEmpty() && num == 3) {
                num = generateRandomInt();
            }
            crud.ExecuteCommand(num);
        }
    }

    private int generateRandomInt() {
        int min = 0;
        int max = 4;
        return (int) ((Math.random() * (max - min)) + min);
    }
}
