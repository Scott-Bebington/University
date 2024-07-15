#pragma once

#include "Waiter.h"
class Table;

/*! \class Floor
*    \brief  A Floor class.
*    \details   This class represents a floor in a restaurant. It contains a list of tables and a MaitreD.
*    \author Alcodeholics Anonymous
*/
class Floor {
   private:
    Table* head; ///< A pointer to the first table in the list of tables.
        int availableTables = 0; ///< The number of available tables.
public:
    /*! \fn add
    *   \brief Adds a table to the list of tables.
    *   \param table A pointer to the table to be added.
    */
    void addTable(Table* table);
    /*! \fn remove
    *   \brief Removes a table from the list of tables.
    *   \param table A pointer to the table to be removed.
    *   \return A pointer to the removed table.
    */
    Table* remove(Table* table);
    /*! \fn combine
    *   \brief Combines two tables.
    *   \param table1 A pointer to the first table to be combined.
    *   \param table2 A pointer to the second table to be combined.
    *   \return A pointer to the combined table.
    */
    Table* combine(Table* table1, Table* table2);
    /*! \fn split
    *   \brief Splits a table into two.
    *   \param table A pointer to the table to be split.
    *   \return True if the table was split successfully, false otherwise.
    */
    bool split(Table* table);
    /*! \fn detach
    *   \brief Detaches a table from an employee.
    *   \param table A pointer to the table to be detached.
    */
    void detach(Table* table);
    /*! \fn attach
    *   \brief Assigns a waiter to a table.
    *   \param Waiter A pointer to the waiter to be attached to.
    *   \param table A pointer to the table to be attached.
    */
    void attach(Waiter* waiter, Table* table);
    /*! \fn getFirstAvailableTable
    *   \brief Returns a pointer to the first available table.
    *   \return A pointer to the first available table.
    */
    Table* getFirstAvailableTable();
    /*! \fn combineNumTables
    *   \brief Combines a number of tables.
    *   \param numTables The number of tables to be combined.
    *   \return A pointer to the combined table.
    */
    Table* combineTablesNumPeople(int numPeople);
    /*! \fn getAvailableSeats
    *   \brief Returns the number of available seats.
    *   \return The number of available seats.
    */
    int getAvailableSeats();
    /*! \fn getAvailableTables
    *   \brief Returns the number of available tables.
    *   \return The number of available tables.
    */
    int getAvailableTables();
    /*! \fn getAvailableForNumPeople
    *   \brief Returns a pointer to the first available table for a given number of people.
    *   \param numPeople The number of people.
    *  \return A pointer to the first available table for a given number of people.
    */
    Table* getAvailableForNumPeople(int numPeople);
    /*! \fn updateAvailability
    *   \brief Updates the number of available tables.
    */
    void updateAvailability();
    /*! \fn ~Floor
    *   \brief A destructor.
    */
    ~Floor();
};