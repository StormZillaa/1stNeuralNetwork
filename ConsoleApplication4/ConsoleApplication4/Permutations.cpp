#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Text.cpp"

using namespace std;


class Permutations {
	public:
		//data vectors
		vector<int> ins;
		vector<int> outs;
		vector<double> weights1;
		vector<int> endVals;
		vector<double> activation;
		vector<double> bias;
		vector<double> errors;

		//the weights have to be something to be useful, so we randomly fill them
		//only fills to size of the current input, will fill for other sizes randomly later...
		void firstWeights() {
			srand(time(NULL));
			for (int i = 0; i < ins.size(); i++) {
				weights1.push_back(rand());
				bias.push_back(rand());
				activation.push_back(rand());
			}
		}
		
		//takes vectors in and saves them for usage here
		void fillData(vector<int> in, vector<int> out) {
			ins = in;
			outs = out;
		}

		//sigmoid function. has uses. yay.
		double sigmoid(double x) {
			double y = exp(-x);
			y = 1 + y;
			return 1 / y;
		}

		double inverseSigmoid(double x) {
			return log(1 - (1 / x));
		}
		//fills error array with errors squared at each position
		void findError() {
			double y = 0;
			for (int i = 0; i < endVals.size(); i++) {
				y = endVals.at(i) - outs.at(i);
				y = y*y;
				errors.push_back(y);
			}
		}

		//applies weights to the inputs and saves them in the endVals vector

		// this need to be redone... whoops
		void applyWeights() {
			//need to fill rest of the weights because some are probably missing
			srand(time(NULL));
			for (int i = weights1.size(); i < ins.size(); i++) {
				weights1.push_back(rand());
				bias.push_back(rand());
				activation.push_back(rand());
			}
			double z = 0;
			int x = 0;
			//does the math for applying the weights here, more weights can be added later if desired
			for (int i = 0; i < weights1.size(); i++) {
				z = weights1.at(i)*ins.at(i);
				z = sigmoid(z);
				z = z + weights2.at(i);
				z = inverseSigmoid(z);
				z = round(z);
				x = (int)z;
				endVals.push_back(x);
			}
		}
		
		//clears all of the vectors because it's easier to fill them again this way
		void clearAll() {
			ins.clear();
			outs.clear();
			endVals.clear();
		}
		
};