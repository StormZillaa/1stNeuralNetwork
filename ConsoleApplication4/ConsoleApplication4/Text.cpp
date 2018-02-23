#include <vector>

using namespace std;

//contains the input text and its associated output text
int chToInt(char in);
class Text {
public:
	//basically all this is is vectors, wahoo!!
	vector<char> input;
	vector<char> output;
	vector<int> inInts;
	vector<int> outInts;
	vector<double> errors;
	vector<int> moddedInputs;

	void getInput(vector<char> in) {
		input = in;
	}
	void getOutput(vector<char> out) {
		output = out;
	}
	vector<char> returnIn() {
		return input;
	}
	vector<char> returnOut() {
		return output;
	}
	
	//call function to fill outInts and inInts with integers that are based on the input and output fields
	void convertToInt() {
		int x = 0;
		for (int i = 0; i < input.size(); i++) {
			chToInt(input.at(i));
			if (x =! 30) {
				inInts[i] = x;
			}
			else {
				inInts[i] = 0;
			}
		}
		for (int i = 0; i < output.size(); i++) {
			chToInt(output.at(i));
			if (x = !30) {
				outInts[i] = x;
			}
			else {
				outInts[i] = 0;
			}
		}
	}

};

int chToInt(char in) {
	//large switch statement that takes the character and makes it a value 1-26 depending on the letter
	switch (in) {
	case 'a':
	case 'A':
		return 1;
		break;
	case 'b':
	case 'B':
		return 2;
		break;
	case 'c':
	case 'C':
		return 3;
		break;
	case 'd':
	case 'D':
		return 4;
		break;
	case 'e':
	case 'E':
		return 5;
		break;
	case 'f':
	case 'F':
		return 6;
		break;
	case 'g':
	case 'G':
		return 7;
		break;
	case 'h':
	case 'H':
		return 8;
		break;
	case 'i':
	case 'I':
		return 9;
		break;
	case 'j':
	case 'J':
		return 10;
		break;
	case 'k':
	case 'K':
		return 11;
		break;
	case 'l':
	case 'L':
		return 12;
		break;
	case 'm':
	case 'M':
		return 13;
		break;
	case 'n':
	case 'N':
		return 14;
		break;
	case 'o':
	case 'O':
		return 15;
		break;
	case 'p':
	case 'P':
		return 16;
		break;
	case 'q':
	case 'Q':
		return 17; break;
	case 'r':
	case 'R':
		return 18;
		break;
	case 's':
	case 'S':
		return 19;
		break;
	case 't':
	case 'T':
		return 20;
		break;
	case 'u':
	case 'U':
		return 21;
		break;
	case 'v':
	case 'V':
		return 22;
		break;
	case 'w':
	case 'W':
		return 23;
		break;
	case 'x':
	case 'X':
		return 24;
		break;
	case 'y':
	case 'Y':
		return 25;
		break;
	case 'Z':
	case 'z': 
		return 26;
		break;
	}
	return 30;
}