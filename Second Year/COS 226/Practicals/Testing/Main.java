package Testing;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

public class Main {

}

class TestLock implements Lock {
    private int myChance;
    private boolean busy = false;

    public void lock() {
        int myTurn = Integer.parseInt(Thread.currentThread().getName().split("-")[1]);
        do 
        {
            do 
            {
                myChance = myTurn;
            } 
            while (busy);
            busy = true;
        } 
        while (myChance != myTurn);
    }

    public void unlock() {
        busy = false;
    }

    @Override
    public void lockInterruptibly() throws InterruptedException {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'lockInterruptibly'");
    }

    @Override
    public boolean tryLock() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'tryLock'");
    }

    @Override
    public boolean tryLock(long time, TimeUnit unit) throws InterruptedException {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'tryLock'");
    }

    @Override
    public Condition newCondition() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'newCondition'");
    }
}