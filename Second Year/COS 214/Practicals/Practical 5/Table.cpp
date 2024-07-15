#include "Table.h"
#include "Floor.h"

void Table::setAvailable(bool available) {
    this->available = available;
}

bool Table::getAvailable() {
    return available;
}

int Table::getSize() {
    return size;
}

int Table::getNumber() {
    return number;
}

Table::Table(int size, bool available, int number) {
	this->size = size;
	this->available = available;
	this->number = number;
	this->next = nullptr;
	this->previous = nullptr;
	this->combined = false;
    this->combinedTable = nullptr;
}

Table::Table(int size, bool available, int number, bool combined, Table* combinedTable) {
	this->size = size;
	this->available = available;
	this->number = number;
	this->next = nullptr;
	this->previous = nullptr;
	this->combined = combined;
    this->combinedTable = combinedTable;
}

Table::~Table() {
    delete next;
    delete previous;
    delete combinedTable;
}

void Table::setCombinedTable(Table * combinedTable)
{
	combinedTable->getAvailable();
}

Table * Table::getCombinedTable()
{
	return this->combinedTable;
}

void Table::setWaiter(Waiter * waiter)
{
	this->waiter = waiter;
}

Waiter * Table::getWaiter()
{
	return this->waiter;
}

void Table::setNext(Table * next)
{
	this->next = next;
}

Table * Table::getNext()
{
	return this->next;
}

void Table::setPrevious(Table * previous)
{
	this->previous = previous;
}

Table * Table::getPrevious()
{
	return this->previous;
}
