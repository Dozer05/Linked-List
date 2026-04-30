#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	List<string> Nullscape;
	Nullscape.insert("Baby", 1);
	Nullscape.insert("Mart", 2);
	Nullscape.insert("Springer", 3);
	Nullscape.insert("ICBM", 4);
	Nullscape.insert("Bell", 5);
	Nullscape.insert("Husk", 6);
	Nullscape.insert("Operator", 7);
	Nullscape.insert("Kolona", 8);
	Nullscape.insert("NIL", 9);
	Nullscape.insert("Guardian", 10);
	Nullscape.print();
	Nullscape.remove(4);
	Nullscape.print();
	cout << Nullscape.search("Operator");
	cout << Nullscape.read(8);
}
