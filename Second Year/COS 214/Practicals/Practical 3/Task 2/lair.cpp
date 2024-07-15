#include "lair.h"

lair::lair()
{
    cout << "Blank Lair Created" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            board[i][j] = new Traps(" ", 0, 0);
        }
    }
    board[0][0] = new Traps("#", 0, 0);
    this->treasureAdded = false;
}

void lair::displayBoard()
{
    cout << "\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t";
        for (int j = 0; j < 10; j++)
        {
            cout << board[i][j]->getType() << "\t";
        }
        cout << endl;
    }
}

void lair::createTile(int x, int y)
{
    if (x < 0 || x > 9 || y < 0 || y > 9)
    {
        cout << "Invalid Coordinates, please choose a number between 0-9" << endl;
        return;
    }

    // Check if tile already exists
    if (this->board[x][y]->getType() == "#")
    {
        cout << "Tile already exists at position: (" << x << ", " << y << ")" << endl;
        return;
    }

    // cout << "Tile being created at position: (" << x << ", " << y << ")" << endl;
    // Check if there is a connecting tile in any direction but diagonal
    // if (
    //     (this->board[x - 1][y] != nullptr && this->board[x - 1][y]->getType() == "#")
    //     || (this->board[x + 1][y] != nullptr && this->board[x + 1][y]->getType() == "#")
    //     || (this->board[x][y - 1] != nullptr && this->board[x][y - 1]->getType() == "#") 
    //     || (this->board[x][y + 1] != nullptr && this->board[x][y + 1]->getType() == "#")
    //     )
    // {
        cout << "Tile Created at position: (" << x << ", " << y << ")" << endl;
        this->board[x][y] = new Traps("#", 0, 0);
    //     return;
    // }

    // // Cant create tile
    // cout << "Tile must be connected to another tile in any direction other than diagonal" << endl;
}

void lair::removeTile(int x, int y)
{
    if (x < 0 || x > 9 || y < 0 || y > 9)
    {
        cout << "Invalid Coordinates, please choose a number between 0-9" << endl;
        return;
    }

    // check if tile is start tile
    if (x == 0 && y == 0)
    {
        cout << "Cannot remove start tile" << endl;
        return;
    }

    // Check if tile is an end tile
    if (checkTilesConnection(x, y) == 1)
    {
        cout << "Tile Removed at position: (" << x << ", " << y << ")" << endl;
        this->board[x][y] = new Traps(" ", 0, 0);
        return;
    }
    if (this->board[x - 1][y]->getType() == "#" && checkTilesConnection(x - 1, y) < 3)
    {
        cout << "Cannot remove tile as it breaks the game" << endl;
        return;
    }
    if (this->board[x + 1][y]->getType() == "#" && checkTilesConnection(x + 1, y) < 3)
    {
        cout << "Cannot remove tile as it breaks the game" << endl;
        return;
    }
    if (this->board[x][y - 1]->getType() == "#" && checkTilesConnection(x, y - 1) < 3)
    {
        cout << "Cannot remove tile as it breaks the game" << endl;
        return;
    }
    if (this->board[x][y + 1]->getType() == "#" && checkTilesConnection(x, y + 1) < 3)
    {
        cout << "Cannot remove tile as it breaks the game" << endl;
        return;
    }

    if (this->board[x][y]->getType() == "#")
    {
        cout << "Tile Removed at position: (" << x << ", " << y << ")" << endl;
        this->board[x][y] = new Traps(" ", 0, 0);
    }
    else
    {
        cout << "No Tile at position: (" << x << ", " << y << ")" << endl;
    }
}

int lair::checkTilesConnection(int x, int y)
{
    int count = 0;
    if (this->board[x - 1][y]->getType() == "#")
    {
        count++;
    }
    if (this->board[x + 1][y]->getType() == "#")
    {
        count++;
    }
    if (this->board[x][y - 1]->getType() == "#")
    {
        count++;
    }
    if (this->board[x][y + 1]->getType() == "#")
    {
        count++;
    }
    cout << "Number of connections for tile (" << x << ", " << y << "): " << count << endl;
    return count;
}

void lair::displayTile(int x, int y)
{
    cout << endl;
    cout << "Displaying Tile:" << endl;
    cout << "Type: " << this->board[x][y]->getType() << endl;
    cout << "Damage: " << this->board[x][y]->getDamage() << endl;
    cout << "Cost: " << this->board[x][y]->getCost() << endl;
    cout << endl;
}

void lair::AddTreasure(int x, int y)
{
    if (this->treasureAdded)
    {
        cout << "Treasure already exists" << endl;
        return;
    }

    if(this->board[x][y]->getType() != "#")
    {
        cout << "Treasure must be placed on a tile" << endl;
        return;
    }

    this->board[x][y] = new Traps("X", 0, 0);
    cout << "Treasure Added" << endl;
    this->treasureAdded = true;
}

void lair::AddTrap(int x, int y, string Type, int Damage, int Cost)
{
    if (x < 0 || x > 9 || y < 0 || y > 9)
    {
        cout << "Invalid Coordinates, please choose a number between 0-9" << endl;
        return;
    }

    // Check if trap already exists
    if (this->board[x][y]->getType() == "PT" || this->board[x][y]->getType() == "FT")
    {
        cout << "Trap already exists at position: (" << x << ", " << y << ")" << endl;
        return;
    }

    // Check to see if the trap is being placed on a tile
    if (this->board[x][y]->getType() != "#")
    {
        cout << "Trap must be placed on a tile" << endl;
        return;
    }

    cout << "Trap Added at position: (" << x << ", " << y << ")" << endl;
    this->board[x][y] = new Traps(Type, Damage, Cost);
}
