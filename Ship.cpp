#include<fstream>

Ship::ship()
{
  ifstream file;
  file.open("ref/blueprint.txt");
  file.get();
}
