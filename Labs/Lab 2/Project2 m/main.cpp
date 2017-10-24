/*
 *By Dr.Murphy
 *Edited by Nestor Saavedra
 *Course: CSE 461
 *HW2/Lab1
 *10/7/17
*/
//sample main program from lab2
#include "Sdisk.h"
#include <iostream>
#include <string>


using namespace std;

// You can use this to test your Sdisk class 

int main()
{
	Sdisk disk1("test1", 16, 32);
	string block1, block2, block3, block4;
	for (int i = 1; i <= 32; i++) block1 = block1 + "1";//fill block1 with 32 char's
	for (int i = 1; i <= 32; i++) block2 = block2 + "2";//fill block2 with 32 char's
	disk1.putblock(4, block1);
	disk1.getblock(4, block3);
	cout << "Should be 32 1s : ";
	cout << block3 << endl;
	disk1.putblock(8, block2);
	disk1.getblock(8, block4);
	cout << "Should be 32 2s : ";
	cout << block4 << endl;
	system("pause");
}
