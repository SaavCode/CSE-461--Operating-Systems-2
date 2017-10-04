/*	[NESTOR SAAVEDRA]
		[10/02/2017]
			[LAB 1 : FILE I/0 ]
				|Description: In this laboratory, the goal was to maitain a user name and password system, by storing the username
				|and password in a file. The  file consists of a single username and password per line [with a space between them]*/
#include <iostream>
#include<string>
#include <fstream>
#include<vector>

using namespace std;

class PasswordFile {
public:
	PasswordFile(string filename);//opens file and reads the name and passwords in vectors user and password
	void addpw(string newuser, string newpassword);//adds new user and passw to the vectors
	bool checkpw(string user, string passwd);//returns true if the user exists and there is a password match
private:
	string filename;			//contains password info
	vector<string> users;		//list of usernames
	vector <string> passwords;   //pasword list
	void synch(); //write the password to the file

};

PasswordFile::PasswordFile(string filename) {
	this->filename = filename;
	string user, password;
	ifstream passwordfile;
	passwordfile.open(this->filename.c_str());
	passwordfile >> user >> password;
	//if everyting is good with the password file, add username and password to the vectors of users and passwords
	while (passwordfile.good()) {
		users.push_back(user);
		passwords.push_back(password);
		passwordfile >> user >> password;
	}
}

void PasswordFile::addpw(string newuser, string newpassword) {
	//use an auto iterator to check if the newuser already exists
	auto iterator = find(users.begin(), users.end(), newuser);
	//add if it does not exist
	if (iterator == users.end()) {
		users.push_back(newuser);
		passwords.push_back(newpassword);
		synch();
	}
	else {
		//the user is already in the list
		cout << "This user cannot be added, [" << newuser << "] is already in the list" << endl;
	}
}

//check if user and password is in the vectors
bool PasswordFile::checkpw(string user, string password) {
	for (int i = 0; i < users.size(); i++) {
		if (users[i] == user && passwords[i] == password) {
			return true;
		}
		else {
			return false;
		}
	}
}

void PasswordFile::synch() {//write to file
		ofstream outfile;
		//open file
		outfile.open(filename.c_str());
		for (int i = 0; i < users.size(); i++) {
			outfile << users[i] << " " << passwords[i] << endl;
		}
		//close file
		outfile.close();
}

//create a password text file
int main() {
	PasswordFile passfile("password.txt");
	passfile.addpw("rotesn", "123qwe");
	passfile.addpw("ness", "124heli");
	passfile.addpw("edd", "568rentor");
	//will not be written
	passfile.addpw("edd", "568rentor");
	//test if it works here
	bool checkpw(string user, string passwd);
}