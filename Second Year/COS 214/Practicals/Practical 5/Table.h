#pragma once

class Floor;
class Waiter;
//generate doxygen comments

/**
 * \class Table
 *  \brief Class that represents a table in the restaurant.
 *  \details Each Table represent a node in a linked list. There are previous and next pointers to navigate through the list.
 *  Each table has a waiter assigned to it and a pointer to another table if it is combined. There are also other attributes for example the table number, size and its availability.
 *    \author Alcodeholics Anonymous
 */
class Table {
   private:
    bool available; /*!< Indicates the availability of a table  */
    int number; /*!< The Table number, as used in restaurants, is a unqiue indicator for each table */
    int size; /*!< The max amount of people that can be seated at a table */
    Waiter* waiter; /*!< The waiter that has been assigned to the table */

    Floor* floor; /*!< The floor that the table is on */
    Table *next; ///< Pointer to the next table in the list
    Table *previous; ///< Pointer to the previous table in the list
    Table* combinedTable; /*!< Pointer to the table that is combined with this table */

   public:
    
    bool combined; /*!< Indicates if a table is combined with another table */

    /*!
    *   \fn setCombinedTable
    *   \brief Sets the combinedTable attribute of a table
    *   \param combinedTable The table that is combined with this table
    */
    void setCombinedTable(Table* combinedTable);
    /*!
    *   \fn getCombinedTable
    *   \brief Gets the combinedTable attribute of a table
    *   \return The table that is combined with this table
    */
    Table* getCombinedTable();
    /*! \fn setWaiter
    *   \brief Sets the waiter attribute of a table
    *   \param waiter The waiter that is assigned to this table
    */
    void setWaiter(Waiter* waiter);
    /*! \fn getWaiter
    *   \brief Gets the waiter attribute of a table
    *   \return The waiter that is assigned to this table
    */
    Waiter* getWaiter();
    /*! \fn setNext
    *   \brief Sets the next attribute of a table
    *   \param next The table that is next in the list
    */
    void setNext(Table* next);
    /*! \fn getNext
    *   \brief Gets the next attribute of a table
    *   \return The table that is next in the list
    */
    Table* getNext();
    /*! \fn setPrevious
    *   \brief Sets the previous attribute of a table
    *   \param previous The table that is previous in the list
    */
    void setPrevious(Table* previous);
    /*! \fn getPrevious
    *   \brief Gets the previous attribute of a table
    *   \return The table that is previous in the list
    */
    Table* getPrevious();
    /*! \fn setAvailable
    *   \brief Sets the availability of a table
    *   \param available The availability of a table
    */
    void setAvailable(bool available);
	/*! \fn getAvailable
    *   \brief Gets the availability of a table
    *   \return The availability of a table
    */
    bool getAvailable();
    /*! \fn getSize
    *   \brief Gets the size of a table
    *   \return The size of a table
    */
    int getSize();
    /*! \fn getNumber
    *   \brief Gets the number of a table
    *   \return The number of a table
    */
    int getNumber();
    /*! \fn Table
    *   \brief Constructor for a table
    *   \param size The size of a table
    *   \param available The availability of a table
    *   \param number The number of a table
    */
    Table(int size, bool available, int number);
    /*! \fn Table
    *   \brief Constructor for a table
    *   \param size The size of a table
    *   \param available The availability of a table
    *   \param number The number of a table
    *   \param combined The combined status of a table
    *   \param combinedTable The table that is combined with this table
    */
    Table(int size, bool available, int number, bool combined, Table* combinedTable);
    /*! \fn ~Table
    *   \brief Destructor for a table
    */
    ~Table();
};