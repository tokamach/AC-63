#include<fstream>

Ship::ship()
{
  ifstream file;
  file.open("blueprint.txt");
  file.get();
}
