#include "Artefact.h"

Artefact::Artefact(string d, Material m, int a, int v) 
{
  description = d;
  material = m;
  age = a;
  value = v;
}

Artefact::~Artefact()
{}

string Artefact::getDescription() const
{
  return description;
}

int Artefact::getAge() const
{
  return age;
}

int Artefact::getValue() const
{
  return value;
}

Material Artefact::getMaterial() const
{
  return material;
}

void Artefact::setValue(int v)
{
  value = v;
}

bool Artefact::operator< (Artefact& art)
{
	if(this->description < art.description) return true;
	else return false;
}