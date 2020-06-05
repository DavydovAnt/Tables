#include "TSortTable.h"
#include "TArrayHashTable.h"
#include "TTreeTable.h"
#include <conio.h>
#include <iostream>
#include <fstream>


int main() {
	ofstream out;
	out.open("tree.txt");
	TTreeTable a;
	a.InsRecord(150, "150");
	a.InsRecord(241, "241");
	a.InsRecord(17, "17");
	a.InsRecord(754, "754");
	a.InsRecord(1150, "1150");
	a.PrintTable(out);
	_getch();
}