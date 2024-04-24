public class Board {
    private int numRows, numCols;
    private Cell cells[], rows[], cols[], blocks[];

    public String toString() {
        String res = "";
        for (int r = 0; r < numRows * numCols; r++) {
            if (r % numRows == 0) {
                res += horizLine() + "\n";
            }
            for (int c = 0; c < numRows * numCols; c++) {
                if (c % numCols == 0) {
                    res += "|";
                }
                res += cells[r * numRows * numCols + c];
            }
            res += "|\n";
        }

        res += horizLine();
        return res;
    }

    public String horizLine() {
        String res = "";
        for (int i = 0; i < numRows + 1 + (numRows * numCols * (String.valueOf(numRows * numCols).length() + 2)); i++) {
            res += "-";
        }
        return res;
    }

    public void testLinks() {
        System.out.println("Rows forward");

        for (int r = 0; r < numRows * numCols; r++) {
            System.out.print("Row " + r + "\t");
            Cell ptr = rows[r];
            while (ptr != null) {
                System.out.print(indexOf(ptr) + " ");
                ptr = ptr.right;
            }
            System.out.println();
        }

        System.out.println("Cols forward");

        for (int c = 0; c < numRows * numCols; c++) {
            System.out.print("Col " + c + "\t");
            Cell ptr = cols[c];
            while (ptr != null) {
                System.out.print(indexOf(ptr) + " ");
                ptr = ptr.below;
            }
            System.out.println();
        }

        System.out.println("Blocks");
        for (int b = 0; b < numRows * numCols; b++) {
            System.out.print("Block " + b + "\t");
            Cell ptr = blocks[b];
            while (ptr != null) {
                System.out.print(indexOf(ptr) + " ");
                ptr = ptr.block;
            }
            System.out.println();
        }
    }

    public void testCells() {
        System.out.println("Cell\tCoord\tBlock\ttoString");
        for (Cell c : cells) {
            System.out.println(indexOf(c) + "\t(" + c.r + "," + c.c + ")\t" + c.b + "\t" + c);
        }
    }

    public int indexOf(Cell c) {
        for (int i = 0; i < numRows * numRows * numCols * numCols; i++) {
            if (cells[i].equals(c)) {
                return i;
            }
        }
        return -1;
    }

    public Cell cellAt(int r, int c) {
        if (r < 0 || r >= numRows * numCols || c < 0 || c >= numRows * numCols) {
            return null;
        }
        return cells[r * numRows * numCols + c];
    }

    /*
     * Don't change anything above this line
     */

    public Board(int r, int c, String boardString) 
    {
        this.numRows = r;
        this.numCols = c;
        int size = numCols * numRows, count = 0, arrtemp = 0, tempcount =0;
        int[] arr = new int[size];
        int[][] arr2 = new int[size][size];
        for (int i = 1; i <= size/r; i++) 
        {
            for (int j = 1; j <= size; j++) 
            {
                arr[j - 1] = arrtemp;
                if (j % c == 0)
                {
                    arrtemp++;
                }
            }
            for (int x = tempcount; x < tempcount + r; x++) 
            {
                arr2[x] = arr;
            }
            tempcount += r;
            arr = null;
            arr = new int[size];
        }
        
        String [] cellsline = boardString.split(" ");

        cells = new Cell[cellsline.length];
        // rows
        for (int i = 0; i < size*size; i++) 
        {
            cells[i] = new Cell(r, c, cellsline[i]);
        }

        
        for (int j = 0; j < size; j++) 
        {
            arr[j] = j;
            // columns
            for (int i = 0; i < size; i++) 
            {
                cells[count].r = j;
                cells[count].c = i;
                cells[count].b = arr2[j][i];
                count++;
            }
        }
        setLinks();
    }

    public void setLinks() 
    {
        if (numRows == 0 || numCols == 0)
        {
            return;
        }
        

        int size = this.numRows * this.numCols;
        this.rows = new Cell[size];
        this.cols = new Cell[size];
        this.blocks = new Cell[size];
        Cell ptrB = null, ptrR = null, ptrC = null;

        if (size == 1)
        {
            this.rows[0] = this.cells[0];
            this.cols[0] = this.cells[0];
            this.blocks[0] = this.cells[0];
            return;
        }

        int rowcount = 0, blockcount = 0;
        for (int i = 0; i < cells.length; i++) 
        {
            if (cells[i].b == blockcount) 
            {
                blocks[blockcount] = cells[i];
                blockcount++;
            }

            if (cells[i].r == rowcount)
            {
                rows[rowcount] = cells[i];
                rowcount++;
            }
        }

        for (int i = 0; i < size; i++) 
        {
            cols[i] = cells[i];
            ptrB = blocks[i];
            ptrR = rows[i];
            ptrC = cols[i];
            
            for (int j = 0; j < cells.length; j++) 
            {
                if (cells[j].b == i)
                {
                    ptrB.block = cells[j];
                    ptrB = ptrB.block;
                }

                if (cells[j].r == i)
                {
                    ptrR.right = cells[j];
                    ptrR = ptrR.right;
                }

                if (cells[j].c == i)
                {
                    ptrC.below = cells[j];
                    ptrC = ptrC.below;
                }
            }
        }



        // for (int i = 0; i < size; i++) 
        // {
        //     System.out.println("Test");
        //     rows[i] = cells[rowcount];
        //     ptr = rows[i];
        //     // for (int j = i * size; j < size * i + size; j++) 
        //     // {
        //     //     ptr.right = cells[j];
        //     //     ptr = ptr.right;
        //     // }
        //     for (int j = 0; j < size; j++) 
        //     {
        //         System.out.println("test");
        //         ptr.right = cells[rowcount];
        //         rowcount ++;
        //         ptr = ptr.right;
        //     }
        // }
        // ptr = null;
        // for (int i = 0; i < size; i++) 
        // {
        //     int x = i;
        //     ptr = cols[i] = cells[i];
        //     for (int j = 1; j < size; j++) 
        //     {
        //         x = x + size;
        //         ptr.below = cells[x];
        //         ptr = ptr.below;
        //     }
        // }
        // int x = 0;
        // for (int i = 0; i < cells.length; i++) 
        // {
        //     if (cells[i].b == x) 
        //     {
        //         blocks[x] = cells[i];
        //         x++;
        //     }
        // }
        // for (int i = 0; i < size; i++) 
        // {
        //     ptr = blocks[i];
        //     for (int j = 0; j < cells.length; j++) 
        //     {
        //         if (cells[j].b == i)
        //         {
        //             ptr.block = cells[j];
        //             ptr = ptr.block;
        //         }
        //     }
        // }
    }

    public void fullProp() 
    {
        for (int i = 0; i < numRows * numRows * numCols * numCols; i++) 
        {
            propCell(cells[i]);
        }
    }

    public void propCell(Cell cell) 
    {
        int size = numCols * numRows;
        if (cell.value == null) 
        {
            return;    
        }
        Cell ptrRows = rows[cell.r]; 
        Cell ptrCols = cols[cell.c]; 
        Cell ptrBlocks = blocks[cell.b]; 
        for (int i = 0; i < size; i++) 
        {
            if (ptrRows.value == null)
            {
                ptrRows.removeVal(cell.value);
            }
            ptrRows = ptrRows.right;
            if (ptrCols.value == null)
            {
                ptrCols.removeVal(cell.value);
            }
            ptrCols = ptrCols.below;
            if (ptrBlocks.value == null)
            {
                ptrBlocks.removeVal(cell.value);
            }
            ptrBlocks = ptrBlocks.block;
        }
    }

    public void solve() 
    {
        int count = 0;
        while (soleCandidate() || uniqueCandidate() || duplicateCells())
        {
            count++;
        }
        System.out.println("Number of moves: " + count);
    }

    public boolean soleCandidate() 
    {
        for (int c = 0; c < cells.length; c++) 
        {
            if (cells[c].possibleValues != null && cells[c].possibleValues.length == 1)
            {
                int value = cells[c].possibleValues.head.data;
                cells[c].setVal(value);
                propCell(cells[c]);
                return true;
            }
        }
        return false;
    }

    public boolean uniqueCandidate() 
    {
        for (Cell col: rows) 
        {
            int[] counts = new int[numRows * numCols];
            Cell rowPtr = col;

            while (rowPtr != null)
            {
                if(rowPtr.possibleValues != null)
                {
                    Node<Integer> nodePtr = rowPtr.possibleValues.head;
                    while (nodePtr != null)
                    {
                        counts[nodePtr.data - 1]++;
                        nodePtr = nodePtr.next;
                    }
                }
                rowPtr = rowPtr.right;
            }
            for (int i = 0; i < numCols * numRows; i++) 
            {
                if (counts[i] == 1) 
                {
                    rowPtr = col;
                    while (rowPtr != null)
                    {
                        if (rowPtr.possibleValues != null && rowPtr.possibleValues.contains(i + 1)) 
                        {
                            rowPtr.setVal(i + 1);
                            propCell(rowPtr);
                        }
                        rowPtr = rowPtr.right;
                    } 
                    return true;   
                }
            }
        }
        // cols
        for (Cell col: cols) 
        {
            int[] counts = new int[numRows * numCols];
            Cell colPtr = col;

            while (colPtr != null)
            {
                if(colPtr.possibleValues != null)
                {
                    Node<Integer> nodePtr = colPtr.possibleValues.head;
                    while (nodePtr != null)
                    {
                        counts[nodePtr.data - 1]++;
                        nodePtr = nodePtr.next;
                    }
                }
                colPtr = colPtr.below;
            }
            for (int i = 0; i < numCols * numRows; i++) 
            {
                if (counts[i] == 1) 
                {
                    colPtr = col;
                    while (colPtr != null)
                    {
                        if (colPtr.possibleValues != null && colPtr.possibleValues.contains(i + 1)) 
                        {
                            colPtr.setVal(i + 1);
                            propCell(colPtr);
                        }
                        colPtr = colPtr.below;
                    } 
                    return true;   
                }
            }
        }

        // blocks
        for (Cell block: blocks) 
        {
            int[] counts = new int[numRows * numCols];
            Cell blockPtr = block;

            while (blockPtr != null)
            {
                if(blockPtr.possibleValues != null)
                {
                    Node<Integer> nodePtr = blockPtr.possibleValues.head;
                    while (nodePtr != null)
                    {
                        counts[nodePtr.data - 1]++;
                        nodePtr = nodePtr.next;
                    }
                }
                blockPtr = blockPtr.block;
            }
            for (int i = 0; i < numCols * numRows; i++) 
            {
                if (counts[i] == 1) 
                {
                    blockPtr = block;
                    while (blockPtr != null)
                    {
                        if (blockPtr.possibleValues != null && blockPtr.possibleValues.contains(i + 1)) 
                        {
                            blockPtr.setVal(i + 1);
                            propCell(blockPtr);
                        }
                        blockPtr = blockPtr.block;
                    } 
                    return true;   
                }
            }
        }
        return false;
    }

    public boolean duplicateCells() 
    {
        for (Cell row: rows) 
        {
            Cell rowPtr = row;
            while (rowPtr != null)
            {
                if (rowPtr.possibleValues != null && rowPtr.possibleValues.length == 2)
                {
                    Cell secondPtr = rowPtr.right;
                    while (secondPtr != null)
                    {
                        if (rowPtr.possibleValues.equals(secondPtr.possibleValues))
                        {
                            Cell thirdPtr = row;
                            boolean change = false;
                            while (thirdPtr != null)
                            {
                                if (thirdPtr != secondPtr && thirdPtr != rowPtr && thirdPtr.possibleValues != null)
                                {
                                    change = change || thirdPtr.possibleValues.remove(rowPtr.possibleValues);
                                }
                                thirdPtr = thirdPtr.right;
                            }
                            if (change)
                            {
                                return true;
                            }
                        }
                        secondPtr = secondPtr.right;
                    }
                }
                rowPtr = rowPtr.right;
            }
        }

        // cols
        for (Cell col: cols) 
        {
            Cell colPtr = col;
            while (colPtr != null)
            {
                if (colPtr.possibleValues != null && colPtr.possibleValues.length == 2)
                {
                    Cell secondPtr = colPtr.below;
                    while (secondPtr != null)
                    {
                        if (colPtr.possibleValues.equals(secondPtr.possibleValues))
                        {
                            Cell thirdPtr = col;
                            boolean change = false;
                            while (thirdPtr != null)
                            {
                                if (thirdPtr != secondPtr && thirdPtr != colPtr && thirdPtr.possibleValues != null)
                                {
                                    change = change || thirdPtr.possibleValues.remove(colPtr.possibleValues);
                                }
                                thirdPtr = thirdPtr.below;
                            }
                            if (change)
                            {
                                return true;
                            }
                        }
                        secondPtr = secondPtr.below;
                    }
                }
                colPtr = colPtr.below;
            }
        }

        // block
        for (Cell block: blocks) 
        {
            Cell blockPtr = block;
            while (blockPtr != null)
            {
                if (blockPtr.possibleValues != null && blockPtr.possibleValues.length == 2)
                {
                    Cell secondPtr = blockPtr.block;
                    while (secondPtr != null)
                    {
                        if (blockPtr.possibleValues.equals(secondPtr.possibleValues))
                        {
                            Cell thirdPtr = block;
                            boolean change = false;
                            while (thirdPtr != null)
                            {
                                if (thirdPtr != secondPtr && thirdPtr != blockPtr && thirdPtr.possibleValues != null)
                                {
                                    change = change || thirdPtr.possibleValues.remove(blockPtr.possibleValues);
                                }
                                thirdPtr = thirdPtr.block;
                            }
                            if (change)
                            {
                                return true;
                            }
                        }
                        secondPtr = secondPtr.block;
                    }
                }
                blockPtr = blockPtr.block;
            }
        }
        return false;
    }
}