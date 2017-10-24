/*By:Nestor Saavedra
*Course: CSE 461
*HW2/Lab1
*10/7/17
*/
#include "Sdisk.h"
#include <fstream>

Sdisk::Sdisk(string diskName, int numOfBlocks, int blockSize)
{
	this->diskName = diskName;
	this->numOfBlocks = numOfBlocks;
	this->blockSize = blockSize;

	fstream fStream;
	//open the file
	fStream.open(diskName.c_str(), ios::in);
	if (fStream.fail()) {
	//when the file is not opened a new one is created
	fStream.open(diskName.c_str(), ios::out);

	// Add numOfBlocks * blocksize
	for (int i = 0; i < numOfBlocks * blockSize; i++)
				fStream.put('#');
	}
	//close the file
	
	fStream.close();

	
}
//retrieves block blocknumber from the disk and stores the data in 
//the string buffer. It returns an error code of 1 if successful 
//and 0 otherwise.

int Sdisk::getblock(int blockNumber, string& buffer)
{
	fstream fstream(diskName.c_str(), ios::in);

	if (fstream.fail())
		return 0;//fail

	fstream.seekg(blockNumber * blockSize);//start at blockNumber
	buffer = ""; //empty buffer

	for (int i = 0; i < blockSize;i++)
		buffer += fstream.get();

	fstream.close();

	return 1;//success
}
//writes the string buffer to block blocknumber. It returns
//an error code of 1 if successful and 0 otherwise.
int Sdisk::putblock(int blockNumber, string buffer)
{
	fstream fstream(diskName.c_str(), ios::in | ios::out);

	if (fstream.fail())
		return 0;//fail

	fstream.seekg(blockNumber * blockSize);

	for (int i = 0; i < buffer.length() && i < blockSize; i++)
		fstream.put(buffer[i]);

	fstream.close();

	return 1;//success
}

int Sdisk::getNumOfBlocks()
{
	return numOfBlocks;
}

int Sdisk::getBlockSize()
{
	return blockSize;
}

