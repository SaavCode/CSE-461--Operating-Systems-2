/*By:Nestor Saavedra
* HW2/Lab1
* 10/7/17
* ***Sdisk header class
* Description: implement a class that simulates a disk drive. The disk drive
* will have numberofblocks many blocks where each block has blocksize many bytes. 
*/
#ifndef SDISK_H
#define SDISK_H
#include <string>


using namespace std;

class Sdisk
{
public:
	Sdisk(string diskName, int numOfBlocks, int blockSize);
	int getblock(int blockNumber, string& buffer);
	int putblock(int blockNumber, string buffer);
	int getNumOfBlocks();	// accessor function
	int getBlockSize();	   // accessor function

private:
	string diskName;	 // file name of software-disk
	int numOfBlocks;	// number of blocks on disk
	int blockSize;	   // block size in bytes
};
#endif