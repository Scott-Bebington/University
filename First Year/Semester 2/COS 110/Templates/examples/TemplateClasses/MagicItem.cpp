#include "MagicItem.h"

MagicItem::MagicItem(string t, int m, double w) 
	: magica(m), title(t), weight(w) 
{}

string MagicItem::getTitle() const
{
	return title;
}

int MagicItem::getMagica() const
{
	return magica;
}

double MagicItem::getWeight() const
{
	return weight;
}

bool MagicItem::operator< (MagicItem& m)
{
	if(this->title < m.title) return true;
	else return false;
}