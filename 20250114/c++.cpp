#include <cstdio>
#include<iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;
string a;
map<string, char>mp;
int main()
{
	mp[".-"] = 'A';
	mp["-..."] = 'B';
	mp["..."] = 'S';
	mp["---"] = 'O';
	mp["-.-."] = 'C';
	mp["-.."] = 'D';
	mp["."] = 'E';
	mp["..-."] = 'F';
	mp["--."] = 'G';
	mp["...."] = 'H';
	mp[".."] = 'I';
	mp[".---"] = 'J';
	mp["-.-"] = 'K';
	mp[".-.."] = 'L';
	mp["--"] = 'M';
	mp["-."] = 'N';
	mp[".--."] = 'P';
	mp["--.-"] = 'Q';
	mp[".-."] = 'R';
	mp["-"] = 'T';
	mp[".--"] = 'U';
	mp["...-"] = 'V';
	mp[".--"] = 'W';
	mp["-..-"] = 'X';
	mp["-.--"] = 'Y';
	mp["--.."] = 'Z';
	string k;
	while(cin >> k){
		cout <<mp[k];
	}  
}


