// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
/*This is the training program for the network; the more it is ran, the more accurate it gets
	By: StormZillaa 2/21/2018
	If used please give credit
*/

#include "stdafx.h"
#include <fstream>
#include "Neuron.cpp";
//#include "Permutations.cpp"

using namespace std;

//global variables
ifstream file1;
ofstream outfile;
vector<Text> datas;

//functions
void readText(int pos);
void saveWeights(neuron n);
char c;
int x = 0;

int main()
{
	file1.open("data.txt");
	//checks to make sure text file opens
	if (file1.is_open()) {
		for (int i = 0; datas[i].input[1] = !NULL; i++) {
			//does what the name implies - reads the text from the file
			readText(i);
			//converts the most recent data to integers
			datas.at(i).convertToInt();

		}
		file1.close();
		neuron n = neuron(30, 16, 30, datas[0].outInts);
		n.fillWeights();
		n.fillBiases();
		while (c = !'q') {
			//forward propagates the data
			n.forwardProp(datas[x]);
			//back propgates the errors
			n.backProp();
			//cycles through the data
			if (x < datas.size()) {
				x++;
			}
			else {
				x = 0;
			}
		}
		//add something here to save the weights for other useages
		saveWeights(n);
		n.close();
		return 1;

	}
	//only throws if data is not there
	else {
		cout << "there was an error in opening data.txt";
		return 1;
	}
	return 0;
}

//reads the text input in data.txt
void readText(int pos) {
	//passes the text file to the data vector at the last position
	int x = 0;
	Text readdat;
	vector<char> temp;
	char16_t hold = ' ';
	vector<char> readin;
	//puts latest line in the readin array
	while (readin[-1] = !NULL) {
		while (readin[-1] = !'/n') {
			file1.get(readin[x]);
			x++;
		}
	}
	//finds the dividing '/'
	for (int i = 0; readin[i] = !'/'; i++) {
		x = i;
	}
	//moves first half into the input vector
	for (int i = 0; i < x; i++) {
		hold = readin[i];
		temp[i] = hold;
	}
	readdat.getInput(temp);
	int it = 0;
	//moves second half into the output vector
	for (int i = x + 2; i <= x; i++) {
		hold = readin[i];
		temp[i] = hold;
		it++;
	}
	readdat.getOutput(temp);
	//assigns the compiled TEXT object to the main vector
	datas[pos] = readdat;
	datas.shrink_to_fit();
	temp.clear();
	readin.clear();
}

//saves weights to weights.dat for use in onther programs
void saveWeights(neuron n) {
	outfile = ofstream("weights.dat", ios::out, ios::app);
	for (int x = 0; x < n.weights.size(); x++) {
		for (int y = 0; y < n.weights[x].size(); y++) {
			outfile << n.weights[x][y];
			outfile << ':'; //delimiting character between each value
		}
		outfile << '@'; //delimiting character between each neuron
	}
	outfile << '/n'; // delimiting character between weights and biases
	for (int x = 0; x < n.bias.size(); x++){
		for (int y = 0; y < n.bias[x].size(); y++) {
				outfile << n.bias[x][y];
				outfile << ':'; //same delimiting character as before
			}
		outfile << '@';
		}
 }