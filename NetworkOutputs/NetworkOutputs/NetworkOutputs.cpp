// NetworkOutputs.cpp : Defines the entry point for the console application.
//
/*  Made by StormZilla, 2/27/2018
	If used please give credit where credit is due
	This is the code that takes the final weights and complies the final output based on the input given in data.txt */

#include "stdafx.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Neuron.cpp"

neuron n;
vector<char> datas;
vector<int> intData;
vector<char> outs;

void makeChars();
void getWeights();
void getData();
void makeDataInts();

int main()
{
	getWeights();
	getData();
	makeDataInts();
	n.forwardProp(intData);
	n.roundData();
	makeChars();
	cout << endl;
	for (int i = 0; i < outs.size(); i++) {
		cout << outs[i];
	}
    return 0;
}

void getWeights() {
	ifstream in;
	in.open("weights.dat");
	if (in.is_open()) {
		int x = 0;
		int y = 0;
		vector<vector<char>> temp;
		vector<vector<char>> temp2;
		string str;
		//pulls the weights out of the file and stores them in a character vector
		while (temp[x][y] != '/n') {
			while (temp[x][y] != '@') {
				temp[x][y] = in.get();
				x++;
			}
			x = 0;
			y++;
		}
		//pulls the biases out of a file and stores them in a different character vector
		while (temp2[x][y] != NULL) {
			while (temp2[x][y] != '@') {
				temp2[x][y] = in.get();
				x++;
			}
			x = 0;
			y++;
		}
		temp.shrink_to_fit();
		temp2.shrink_to_fit();
		x = 0;
		y = 0;
		double d;
		//puts the weights into the double vector for the weights of the neuron object
		for (int a = 0; a < temp.size(); a++) {
			for (int b = 0; b < temp[a].size(); b++) {
				if (temp[a][b] == ':') {
					istringstream(str) >> n.weights[x][y];
					x++;
					str.clear();
				}
				else {
					str.append(1,temp[a][b]);
				}
			}
			istringstream(str) >> d;
			if ((n.weights[x][y] - d) != 0) {
				istringstream(str) >> n.weights[x][y];
			}
			x = 0;
			str.clear();
			y++;
		}
		x = 0;
		y = 0;
		str.clear();
		//puts the bias into the bias vector for neuron n
		for (int a = 0; a < temp2.size(); a++) {
			for (int b = 0; b < temp2[a].size(); b++) {
				if (temp[a][b] == ':') {
					istringstream(str) >> n.bias[x][y];
					x++;
					str.clear();
				}
				else {
					str.append(1, temp[a][b]);
				}
			}
			istringstream(str) >> d;
			if ((n.bias[x][y] - d) != 0) {
				istringstream(str) >> n.bias[x][y];
			}
			x = 0;
			str.clear();
			y++;
		}
		str.clear();
	}

	else {
		cout << "error the specified file cannot be opened.";
	}
	in.clear();
}

void getData() {
	ifstream in;
	in.open("data.txt");
	if (in.is_open()) {
		int x = 0;
		while (datas[x] != NULL) {
			datas[x] = in.get();
			x++;
		}
	}
	else {
		cout << "error, data.txt could not be opened";
	}
}

void makeDataInts() {
	for (int i = 0; i < datas.size(); i++) {
		switch (datas[i])
		{
		case 'a':
		case 'A':
			intData[i] = 1;
			break;
		case 'b':
		case 'B':
			intData[i] = 2;
			break;
		case 'c':
		case 'C':
			intData[i] = 3;
			break;
		case 'd':
		case 'D':
			intData[i] = 4;
			break;
		case 'e':
		case 'E':
			intData[i] = 5;
			break;
		case 'f':
		case 'F':
			intData[i] = 6;
			break;
		case 'g':
		case 'G':
			intData[i] = 7;
			break;
		case 'h':
		case 'H':
			intData[i] = 8;
			break;
		case 'i':
		case 'I':
			intData[i] = 9;
			break;
		case 'j':
		case 'J':
			intData[i] = 10;
			break;
		case 'k':
		case 'K':
			intData[i] = 11;
			break;
		case 'l':
		case 'L':
			intData[i] = 12;
			break;
		case 'm':
		case 'M':
			intData[i] = 13;
			break;
		case 'n':
		case 'N':
			intData[i] = 14;
			break;
		case 'o':
		case 'O':
			intData[i] = 15;
			break;
		case 'p':
		case 'P':
			intData[i] = 16;
			break;
		case 'q':
		case 'Q':
			intData[i] = 17; break;
		case 'r':
		case 'R':
			intData[i] = 18;
			break;
		case 's':
		case 'S':
			intData[i] = 19;
			break;
		case 't':
		case 'T':
			intData[i] = 20;
			break;
		case 'u':
		case 'U':
			intData[i] = 21;
			break;
		case 'v':
		case 'V':
			intData[i] = 22;
			break;
		case 'w':
		case 'W':
			intData[i] = 23;
			break;
		case 'x':
		case 'X':
			intData[i] = 24;
			break;
		case 'y':
		case 'Y':
			intData[i] = 25;
			break;
		case 'Z':
		case 'z':
			intData[i] = 26;
			break;
		}
	}
}

void makeChars() {
	for (int i = 0; i < n.fin.size(); i++) {
		switch (n.fin[i])
		{
		case 1:
			outs[i] = 'a';
			break;
		case 2:
			outs[i] = 'b';
			break;
		case 3:
			outs[i] = 'c';
			break;
		case 4:
			outs[i] = 'd';
			break;
		case 5:
			outs[i] = 'e';
			break;
		case 6:
			outs[i] = 'f';
			break;
		case 7:
			outs[i] = 'g';
			break;
		case 8:
			outs[i] = 'h';
			break;
		case 9:
			outs[i] = 'i';
			break;
		case 10:
			outs[i] = 'j';
			break;
		case 11:
			outs[i] = 'k';
			break;
		case 12:
			outs[i] = 'l';
			break;
		case 13:
			outs[i] = 'm';
			break;
		case 14:
			outs[i] = 'n';
			break;
		case 15:
			outs[i] = 'o';
			break;
		case 16:
			outs[i] = 'p';
			break;
		case 17:
			outs[i] = 'q';
			break;
		case 18:
			outs[i] = 'r';
			break;
		case 19:
			outs[i] = 's';
			break;
		case 20:
			outs[i] = 't';
			break;
		case 21:
			outs[i] = 'u';
			break;
		case 22:
			outs[i] = 'v';
			break;
		case 23:
			outs[i] = 'w';
			break;
		case 24:
			outs[i] = 'x';
			break;
		case 25:
			outs[i] = 'y';
			break;
		case 26:
			outs[i] = 'z';
			break;
		}
	}
}