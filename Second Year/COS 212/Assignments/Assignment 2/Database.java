
@SuppressWarnings("unchecked")
public class Database {
    String[][] database;
    String[] columnNames;
    Treap<Cell>[] indexes;

    public Database(String[] cols, int maxSize) 
    {
        this.database = new String[maxSize][cols.length];
        this.columnNames = cols;
        this.indexes = new Treap[cols.length];

        for (int i = 0; i < cols.length; i++) {
            indexes[i] = null;
        }
    }

    public void insert(String[] newRowDetails) throws DatabaseException 
    {
        if (newRowDetails == null || newRowDetails.length != columnNames.length) 
        {
            throw DatabaseException.invalidNumberOfColums();
        }

        for (int i = 0; i < indexes.length; i++) 
        {
            if(indexes[i] != null)
            {
                Cell testCell = new Cell(0, newRowDetails[i]);
                if (indexes[i].access(testCell) != null) 
                {
                    throw DatabaseException.duplicateInsert(newRowDetails[i]);
                }
            }
        }

        int InsertPos = -1;
        for (int i = 0; i < database.length; i++) 
        {
            if (database[i][0] == null) 
            {
                InsertPos = i;
                break;
            }
        }

        if (InsertPos == -1) 
        {
            throw DatabaseException.databaseFull();
        }

        try 
        {
            for (int i = 0; i < indexes.length; i++) 
            {
                if(indexes[i] != null)
                {
                    Cell testCell = new Cell(InsertPos, newRowDetails[i]);
                    indexes[i].insert(testCell);
                }
            }
            database[InsertPos] = newRowDetails;
        } 
        catch (DatabaseException e) 
        {
            throw e;
        }
    }

    public String[] removeFirstWhere(String col, String data) throws DatabaseException 
    {
        int CheckIndex = -1;
        for (int i = 0; i < columnNames.length; i++) 
        {
            if (col.equalsIgnoreCase(columnNames[i])) 
            {
                CheckIndex = i;
                break;
            }
        }
        if (CheckIndex == -1) 
        {
            throw DatabaseException.invalidColumnName(col);
        }

        Node<Cell> RemoveRow = null;
        if (indexes[CheckIndex] != null) 
        {
            Cell temp = new Cell(0, data);
            RemoveRow = indexes[CheckIndex].remove(temp);
            if (RemoveRow != null) 
            {
                int RemovePos = RemoveRow.data.databaseRow;
                for (int i = 0; i < indexes.length; i++) 
                {
                    temp = new Cell(0, database[RemovePos][i]);
                    if (indexes[i] != null) 
                    {
                        indexes[i].remove(temp);
                    }
                }
                
                String[] RemoveArr = new String[columnNames.length];

                for (int i = 0; i < columnNames.length; i++) 
                {
                    RemoveArr[i] = database[RemovePos][i];
                    database[RemovePos][i] = null;
                }
                return RemoveArr;
            } 
            else 
            {
                return new String[0];
            }

        } 
        else 
        {
            int RemovePos = -1;
            for (int i = 0; i < database.length; i++) 
            {
                if (database[i][CheckIndex] != null 
                && database[i][CheckIndex].compareToIgnoreCase(data) == 0) 
                {
                    RemovePos = i;
                    break;
                }
            }

            if (RemovePos == -1) 
            {
                return new String[0];
            }

            for (int i = 0; i < indexes.length; i++) 
            {
                // System.out.println("Database Row: " + database[RemovePos][i]);
                Cell temp = new Cell(0, database[RemovePos][i]);
                if (indexes[i] != null) 
                {
                    indexes[i].remove(temp);
                }
            }

            String[] RemoveArr = new String[columnNames.length];

            for (int i = 0; i < columnNames.length; i++) 
            {
                RemoveArr[i] = database[RemovePos][i];
                database[RemovePos][i] = null;
            }
            return RemoveArr;
        }
    }

    public String[][] removeAllWhere(String col, String data) throws DatabaseException 
    {
        try 
        {
            String[][] tempArr = new String[database.length][0];
            String[][] returnArr;
            String[] temp = new String[0];
            int count = 0;
            for (int i = 0; i < database.length; i++) 
            {
                temp = removeFirstWhere(col, data);
                tempArr[count] = temp;
                if(temp.length != 0) 
                {
                    count++;
                }
            }

            returnArr = new String[count][0];

            for (int i = 0; i < count; i++) 
            {
                returnArr[i] = tempArr[i];
            }
            return returnArr;
        } 
        catch (DatabaseException e) 
        {
            throw e;
        }
    }

    public String[] findFirstWhere(String col, String data) throws DatabaseException 
    {
        int CheckIndex = -1;
        for (int i = 0; i < columnNames.length; i++) 
        {
            if (col.equalsIgnoreCase(columnNames[i])) 
            {
                // System.out.println("Column Index to be searched: " + i);
                CheckIndex = i;
                break;
            }
        }

        if (CheckIndex == -1) 
        {
            throw DatabaseException.invalidColumnName(col);
        }

        Node<Cell> FindRow = null;
        if(indexes[CheckIndex] != null)
        {
            Cell FindCell = new Cell(0, data);
            
            FindRow = indexes[CheckIndex].access(FindCell);
            // System.out.println("Row Found: " + FindRow);
            if(FindRow != null)
            {
                int DBRowIndex = FindRow.data.databaseRow;
                // System.out.println("Database Row Index: " + DBRowIndex);

                String[] DBRow = database[DBRowIndex];

                // for (int i = 0; i < DBRow.length; i++) 
                // {
                //     if(indexes[i] != null && i != CheckIndex)
                //     {
                //         FindCell = new Cell(0, DBRow[i]);
                //         indexes[i].access(FindCell);
                //     }
                // }

                return DBRow;
            }
            else
            {
                return new String[0];
            }
            
        }
        else
        {
            // System.out.println("test 2");
            int FindPos = -1;
            for (int i = 0; i < database.length; i++) 
            {
                if (database[i][CheckIndex] != null
                &&    database[i][CheckIndex].compareToIgnoreCase(data) == 0) 
                {
                    FindPos = i;
                    break;
                }
            }

            if (FindPos == -1) 
            {
                return new String[0];
            }

            // System.out.println("Database Row: " + FindPos);

            // String[] DBRow = database[FindPos];
            // for (int i = 0; i < indexes.length; i++) 
            // {
            //     Cell temp = new Cell(0, DBRow[i]);
            //     if (indexes[i] != null) 
            //     {
            //         indexes[i].access(temp);
            //     }
            // }

            String[] findArr = new String[columnNames.length];

            for (int i = 0; i < columnNames.length; i++) 
            {
                findArr[i] = database[FindPos][i];
            }
            return findArr;
        }
    }

    public String[][] findAllWhere(String col, String data) throws DatabaseException 
    {
        int CheckIndex = -1;
        for (int i = 0; i < columnNames.length; i++) 
        {
            if (col.equalsIgnoreCase(columnNames[i])) 
            {
                // System.out.println("Column Index to be searched: " + i);
                CheckIndex = i;
                break;
            }
        }

        if (CheckIndex == -1) 
        {
            throw DatabaseException.invalidColumnName(col);
        }

        String[][] tempArr = new String[database.length][columnNames.length];
        // String[][] returnArr;
        // String[] temp = new String[0];
        int count = 0;

        for (int i = 0; i < database.length; i++) 
        {
            if(database[i][CheckIndex] != null
            &&    data.compareTo(database[i][CheckIndex]) == 0) 
            {
                tempArr[count] = database[i];
                count++;
            }
        }

        String[][] returnArr = new String[count][columnNames.length];

        for (int i = 0; i < count; i++) 
        {
            returnArr[i] = tempArr[i];
        }

        if(count == 0)
        {
            return new String[0][];
        }

        if(indexes[CheckIndex] != null)
        {
            Cell AccessCell = new Cell(0, returnArr[0][CheckIndex]);
            System.out.println("AccessCell: " + AccessCell);
            indexes[CheckIndex].access(AccessCell);
        }

        return returnArr;

    }

    public String[] updateFirstWhere(String col, String updateCondition, String data) throws DatabaseException 
    {
        try 
        {
            int TreapIndex = -1;
            for (int i = 0; i < columnNames.length; i++) 
            {
                if (col.equalsIgnoreCase(columnNames[i])) 
                {
                    // System.out.println("Column Index to be searched: " + i);
                    TreapIndex = i;
                    break;
                }
            }

            if (TreapIndex == -1) 
            {
                throw DatabaseException.invalidColumnName(col);
            }

            if(indexes[TreapIndex] != null)
            {
                Cell RemoveCell = new Cell(0, updateCondition);
                Node<Cell> RemovedNode = indexes[TreapIndex].remove(RemoveCell);

                if(RemovedNode != null)
                {
                    int DBRowIndex = RemovedNode.data.databaseRow;

                    Cell newCell = new Cell(DBRowIndex, data);
                    indexes[TreapIndex].insert(newCell);

                    database[DBRowIndex][TreapIndex] = data;

                    return database[DBRowIndex];
                }
                else
                {
                    return new String[0];
                }
            }
            else
            {
                for (int i = 0; i < database.length; i++) 
                {
                    if(database[i][TreapIndex] != null
                    &&    database[i][TreapIndex].compareTo(updateCondition) == 0)
                    {
                        database[i][TreapIndex] = data;
                        return database[i];
                    }
                }
                return new String[0];
            }
        } 
        catch (DatabaseException e) 
        {
            throw e;
        }
    }

    public String[][] updateAllWhere(String col, String updateCondition, String data) throws DatabaseException 
    {
        int TreapIndex = -1;
        for (int i = 0; i < columnNames.length; i++) 
        {
            if (col.equalsIgnoreCase(columnNames[i])) 
            {
                // System.out.println("Column Index to be searched: " + i);
                TreapIndex = i;
                break;
            }
        }

        if (TreapIndex == -1) 
        {
            throw DatabaseException.invalidColumnName(col);
        }

        String[][] ReturnArr, TempArr = new String[database.length][0];


        if(indexes[TreapIndex] != null)
        {
            updateFirstWhere(col, updateCondition, data);
            int count = 0;
            for (int i = 0; i < database.length; i++) 
            {

                if(database[i][TreapIndex] != null
                && database[i][TreapIndex].compareTo(data) == 0)
                {
                    TempArr[0] = database[i];
                    count++;
                }
            }

            ReturnArr = new String[count][0];

            for (int i = 0; i < count; i++) 
            {
                ReturnArr[i] = TempArr[i];
            }
            return ReturnArr;
        }
        else
        {
            int count = 0;
            for (int i = 0; i < database.length; i++) 
            {

                if(database[i][TreapIndex] != null
                && database[i][TreapIndex].compareTo(updateCondition) == 0)
                {
                    database[i][TreapIndex] = data;
                    TempArr[count] = database[i];
                    count++;
                }
            }

            ReturnArr = new String[count][0];

            for (int i = 0; i < count; i++) 
            {
                ReturnArr[i] = TempArr[i];
            }
            return ReturnArr;
        }
    }

    public Treap<Cell> generateIndexOn(String col) throws DatabaseException 
    {
        int index = -1;
        for (int i = 0; i < columnNames.length; i++) 
        {
            if (col.compareToIgnoreCase(columnNames[i]) == 0) 
            {
                index = i;
                break;
            }
        }

        if (index == -1) 
        {
            throw DatabaseException.invalidColumnName(col);
        }

        if (indexes[index] != null) 
        {
            return indexes[index];
        } 
        else 
        {
            indexes[index] = new Treap<>();
        }
        for (int i = 0; i < database.length; i++) 
        {
            try      
            {
                if (database[i][index] != null) 
                {
                    Cell newCell = new Cell(i, database[i][index]);
                    indexes[index].insert(newCell);
                }
                
            } 
            catch (DatabaseException e) 
            {
                indexes[index] = null;
                throw e;
            }
        }
        return indexes[index];
    }

    public Treap<Cell>[] generateIndexAll() throws DatabaseException 
    {
        for (int i = 0; i < columnNames.length; i++) 
        {
            try 
            {
                generateIndexOn(columnNames[i]);
            } 
            catch (DatabaseException e) 
            {
            }
        }
        return indexes;
    }

    public int countOccurences(String col, String data) throws DatabaseException 
    {
        int TreapIndex = -1;
        for (int i = 0; i < columnNames.length; i++) 
        {
            if (col.equalsIgnoreCase(columnNames[i])) 
            {
                // System.out.println("Column Index to be searched: " + i);
                TreapIndex = i;
                break;
            }
        }

        if (TreapIndex == -1) 
        {
            throw DatabaseException.invalidColumnName(col);
        }

        int count = 0;
        for (int i = 0; i < database.length; i++) 
        {

            if(database[i][TreapIndex] != null
            && database[i][TreapIndex].compareTo(data) == 0)
            {
                count++;
            }
        }
        return count;
    }
}
