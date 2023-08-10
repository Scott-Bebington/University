#include "Artefact.h"
#include "MagicItem.h"

#include "Inventory.h"
#include "Inventory.cpp"

#include "SearchableInventory.h"
#include "SearchableInventory.cpp"

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  Artefact *art1 = new Artefact("Silver Spoon", SILVER, 5);
  Artefact *art2 = new Artefact("Old Shoe", COPPER, 3, 1500);
  Artefact *art3 = new Artefact("Crystal Skull", STONE, 350);
  Artefact *art4 = new Artefact("Golden Skeptre", GOLD, 1000);

  MagicItem *m1 = new MagicItem("Magic Wand", 25, 5);
  MagicItem *m2 = new MagicItem("Invisibility Cloak", 20, 15);
  MagicItem *m3 = new MagicItem("Potion of Health", 5, 10);

  SearchableInventory<Artefact> invArt; // inventory of Artefacts

  Inventory<MagicItem> invMagic; // inventory of Magic Items

  invArt.addItem(art1);
  invArt.addItem(art2);
  invArt.addItem(art3);
  invArt.addItem(art4);

  invMagic.addItem(m1);
  invMagic.addItem(m2);
  invMagic.addItem(m3);

  cout << "Artefacts stored in Inventory<Artefact>: " << endl;
  for (int i = 0; i < invArt.getNumItems(); i++)
  {
    cout << invArt.inspectItem(i)->getDescription() << endl;
  }

  cout << "\nMagic Items stored in Inventory<MagicItem>: " << endl;
  for (int i = 0; i < invMagic.getNumItems(); i++)
  {
    cout << invMagic.inspectItem(i)->getTitle() << endl;
  }

  // Searchable
  cout << endl;

  try
  {
    int index = invArt.findItem(art2);

    cout << "The index of " << art2->getDescription();
    cout << " in SearchableInventory<Artefact> ";
    cout << "is " << index << endl;
  }
  catch (...)
  {
    cout << "Some error has occured!" << endl;
  }

  cout << endl;

  return 0;
}
