import java.util.Random;

// This is used to remove the warnings which occur when using generics
@SuppressWarnings("unchecked")
public class SkipList<T extends Comparable<T>> {
    private int maxLevel;
    private SkipListNode<T>[] root;
    private int[] powers;
    // Do not change the seed. This is used to generate the same values every run
    private Random randomGenerator = new Random(123456);

    T num;

    public SkipList(int maxLevel) {
        this.maxLevel = maxLevel;
        this.root = new SkipListNode[this.maxLevel];
        this.powers = new int[this.maxLevel];
        // [1, 5, 7]
        int PowN = (int) Math.pow(2, maxLevel) - 1;
        powers[0] = 1;
        root[0] = null;
        for (int i = 1; i < maxLevel; i++) {
            root[i] = null;
            powers[i] = powers[i - 1] + PowN / (int) Math.pow(2, i) + 1;
        }
    }

    public int chooseLevel() {
        int RandomNum = Math.abs(randomGenerator.nextInt()) % powers[maxLevel - 1] + 1;
        for (int i = 1; i < maxLevel; i++) {
            if (RandomNum < powers[i]) {
                return i - 1;
            }
        }
        return maxLevel - 1;
    }

    public void insert(T key) {
        SkipListNode<T>[] CurrentPtr = new SkipListNode[maxLevel];
        SkipListNode<T>[] PrevPtr = new SkipListNode[maxLevel];
        SkipListNode<T> newNode;
        int level, i;
        CurrentPtr[maxLevel - 1] = root[maxLevel - 1];
        PrevPtr[maxLevel - 1] = null;
        for (level = maxLevel - 1; level >= 0; level--) {
            while (CurrentPtr[level] != null && CurrentPtr[level].key.compareTo(key) <= 0) {
                PrevPtr[level] = CurrentPtr[level];
                CurrentPtr[level] = CurrentPtr[level].next[level];
            }

            if (level > 0) {
                if (PrevPtr[level] == null) {
                    CurrentPtr[level - 1] = root[level - 1];
                    PrevPtr[level - 1] = null;
                } else {
                    CurrentPtr[level - 1] = PrevPtr[level].next[level - 1];
                    PrevPtr[level - 1] = PrevPtr[level];
                }
            }

        }
        level = chooseLevel();

        newNode = new SkipListNode<T>(key, level + 1);
        for (i = 0; i <= level; i++) {
            newNode.next[i] = CurrentPtr[i];
            if (PrevPtr[i] == null) {
                root[i] = newNode;
            } else {
                PrevPtr[i].next[i] = newNode;
            }

        }
    }

    public boolean isEmpty() {
        return root[0] == null;
    }

    public SkipListNode<T> search(T key) { // works
        if (isEmpty()) {
            return null;
        }
        int i, count = 1;
        SkipListNode<T> PrevPtr = root[maxLevel - 1], ptr = root[maxLevel - 1];
        for (i = maxLevel - 1; i >= 0; i--) {
            if (root[i] == null) {
                continue;
            }
            if (count == 0) {
                ptr = PrevPtr.next[i];
            } else {
                ptr = root[i];
                PrevPtr = root[i];
                if (key.compareTo(PrevPtr.key) < 0) {
                    count = 1;
                } else {
                    count = 0;
                }
            }
            while (ptr != null && key.compareTo(ptr.key) > 0) {
                PrevPtr = ptr;
                ptr = ptr.next[i];
            }
            if (ptr != null && ptr.key.compareTo(key) == 0) {
                return ptr;
            }
        }
        return null;
    }

    @Override
    public String toString() {
        String str = "";
        SkipListNode<T> ptr = root[0];
        String[] levels = new String[maxLevel];
        for (int i = maxLevel - 1; i >= 0; i--) {
            levels[i] = "[Lvl " + i + "]";
        }
        while (ptr != null) {
            for (int i = maxLevel - 1; i >= 0; i--) {
                if (i < ptr.next.length) {
                    levels[i] += "->" + ptr.toString();
                } else {
                    levels[i] += "--" + ptr.emptyString();
                }
            }
            ptr = ptr.next[0];
        }
        int i;
        for (i = maxLevel - 1; i > 0; i--) {
            int temp = levels[i].lastIndexOf("]");
            levels[i] = levels[i].substring(0, temp + 1);

            str += levels[i] + "\n";
        }
        int temp = levels[i].lastIndexOf("]");
        levels[i] = levels[i].substring(0, temp + 1);

        str += levels[i];
        return str;
    }

    public boolean delete(T key) {
        if (isEmpty() || (search(key) == null)) 
        {
            return false;
        }
        int i, count = 1;
        SkipListNode<T> PrevPtr = root[maxLevel - 1], ptr = PrevPtr, NodeToBeDeleted = search(key);
        for (i = NodeToBeDeleted.next.length - 1; i >= 0; i--) {
            if (root[i] == null) 
            {
                continue;
            }
            if (count == 0) 
            {
                ptr = PrevPtr.next[i];
            } else {
                ptr = PrevPtr = root[i];
                if (key.compareTo(PrevPtr.key) >= 0) {
                    count = 1;
                } else {
                    count = 0;
                }
            }
            while (ptr != null && ptr != NodeToBeDeleted) {
                PrevPtr = ptr;
                ptr = ptr.next[i];
            }
            if (ptr == root[i] && ptr == NodeToBeDeleted) {
                root[i] = PrevPtr.next[i];
            }
            if (ptr != null && ptr == NodeToBeDeleted) {
                PrevPtr.next[i] = ptr.next[i];
            }
        }
        return true;
    }

    public void printSearchPath(T key) {
        if (isEmpty() || (search(key) == null)) 
        {
            System.out.println();
            return;
        }
        int i, count = 1;
        SkipListNode<T> PrevPtr = root[maxLevel - 1], ptr = PrevPtr;
        for (i = maxLevel - 1; i >= 0; i--) {

            if (root[i] == null) {
                continue;
            }
            if (count == 0) {
                ptr = PrevPtr.next[i];
                if (ptr != null) {
                    System.out.print(ptr.toString());
                }
            } else {
                ptr = PrevPtr = root[i];
                System.out.print(ptr);
                if (key.compareTo(PrevPtr.key) < 0) {
                    count = 1;
                } else {
                    count = 0;
                }
            }
            while (ptr != null && key.compareTo(ptr.key) > 0) {

                PrevPtr = ptr;
                ptr = ptr.next[i];
                if (ptr != null) {
                    System.out.print(ptr.toString());
                }
            }
            if (ptr != null && ptr.key.compareTo(key) == 0) {
                System.out.println();
                return;
            }
        }
        System.out.println();
    }
}
