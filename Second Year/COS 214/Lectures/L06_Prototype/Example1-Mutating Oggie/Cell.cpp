#include <iostream>
#include "Cell.h"


Cell::Cell(){
	str = new char[50];
}

void Cell::print(){
	std::cout<<str<<std::endl;
}

Cell::~Cell(){
	delete [] str;
}

Cell::Cell(const Cell& c) {
  str = new char[50];
  strcpy(str,c.str);
}

NormalCell::NormalCell() : Cell(){
	strcpy(str,"Normal");
}

Cell* NormalCell::divide() {
	return new NormalCell(*this);
}

NormalCell::NormalCell(const NormalCell& c) : Cell(c) {
}

AbnormalCell::AbnormalCell() : Cell(){
	strcpy(str,"Abnormal");
}

Cell* AbnormalCell::divide(){
	strcat(str,"!");
	return new AbnormalCell(*this);
}

AbnormalCell::AbnormalCell(const AbnormalCell& c) : Cell(c) {
}
