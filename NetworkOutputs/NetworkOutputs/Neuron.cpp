#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

class neuron {
public:
	int input;
	int hidden;
	int output;
	double costInc = 0.001; //amount to increment cost by
	vector<vector<double>> weights;
	vector<vector<double>> bias;
	vector<vector<double>> activations;
	vector<vector<double>> cost;
	vector<vector<double>> costW;
	vector<vector<double>> costB;
	vector<int> fin;
	vector<int> outputData;

	neuron() {
	}

	neuron(int in, int h, int out, vector<int> outputs) {
		input = in;
		hidden = h;
		output = out;
		outputData = outputs;
		srand(time(NULL));
		fillWeights();
		srand(time(NULL));
		fillBiases();
	}

	void fillWeights() {
		for (int y = 0; y < (input); y++) {
			for (int x = 0; x < (input+hidden+output); x++) {
				weights[y][x] = rand() / RAND_MAX;
			}
		}
		weights.shrink_to_fit();
	}

	double sigmoid(double x) {
		return 1/(1-(exp(-x)));
	}

	void fillBiases() {
		for (int y = 0; y < (hidden); y++) {
			for (int x = 0; x < (hidden+output); x++) {
				bias[y][x] = rand() / RAND_MAX;
			}
		}
		bias.shrink_to_fit();
	}

	void changeOutPuts(vector<int> outs) {
		outputData = outs;
	}

	// old forward prop code that was ugly and didn't work well
/*	vector<double> forwardprop(vector<double> w, vector<double> b, vector<double> lastA) {
		double x = 0;
		vector<double> act;
		for (int y = 0; y < w.size(); y++) {
			x = w[y] * lastA[y];
			x = x + b[y];
			act[y] = x;
		}
		act.shrink_to_fit();
		return act;
	}*/

	//forward prop code that only worked for a specific data set
/*	void forwardProp(Text data) {
		for (int z = 0; z < data.inInts.size(); z++) {
			for (int x = 0; x < weights.size(); x++) {
				for (int y = 0; y < weights[x].size(); y++) {
					activations[x][y] = (weights[x][y] * data.inInts[z]) + bias[x][y];
				}
			}
		}
	}*/

	//universal forward prop code that applies the weights and biases in a linear fashion
	void forwardProp(vector<int> data) {
		for (int z = 0; z < data.size(); z++) {
			for (int x = 0; x < weights.size(); x++) {
				for (int y = 0; y < weights[x].size(); y++) {
					if (y == 0) {
						activations[x][y] = (weights[x][y] * data[z] + bias[x][y]);
					}
					else {
						activations[x][y] = (weights[x][y] * activations[x][y - 1]) + bias[x][y];
					}
				}
			}
		}
	}

	double inverseSigmoid(double x) {
		return log(1 - (1 / x));
	}

	vector<vector<double>> transpose(vector<double> x) {
		vector<vector<double>> out;
		for (int i = 0; i < x.size(); i++) {
			out[i][0] = x[i];
		}
		return out;
	}

	double deltaSigmoid(double x) {
		return (exp(x)) / (exp2(1 - exp(x)));
	}

	double multiplyVectors(vector<double> x, vector<vector<double>> y) {
		int z;
		for (int i = 0; i < y.size(); i++) {
			z = z + (x[i]*y[i][0]);
		}
		return z;
	}
	
	void backProp() {
		int t = 0; //stores intermediate calculation values
		int r = 0;
		int L = activations.size();
		vector<vector<double>> temp;
		vector<double> z;
		vector<double> error;
		//finds last layer of errors
		for (int i = 0; i < activations[activations.size()].size(); i++) {
			t = deltaSigmoid(activations[activations.size()][i]);
			r = activations[activations.size()][i] - outputData[i];
			cost[L][i] = r*t;
		}
		L--;
		int zs = 0;
		//finds rest of error layers
		for (int i = 0; i =! L; L--) {
			//assigns temporary values and clears extra data
			temp = transpose(weights[L + 1]);
			temp.shrink_to_fit();
			z = activations[L];
			z.shrink_to_fit();
			error = cost[L];
			error.shrink_to_fit();
			t = multiplyVectors(error, temp);
			for (int q = 0; q < activations[L].size(); q++) {
				zs = deltaSigmoid(z[q]);
				cost[L][q] = (t * zs);
			}
			temp.clear();
			z.clear();
			error.clear();
		}
		//finds errors for weights and biases
		L = activations.size();
		costB = cost;

		for (int i = 0; i = !L; L--) {
			z = activations[L - 1];
			z.shrink_to_fit();
			error = weights[L];
			error.shrink_to_fit();
			for (int q = 0; q < temp.size(); q++) {
				costW[L][q] = z[q] * error[q];
			}
			z.clear();
			error.clear();

		}
		applyCosts();
	}

	void applyCosts() {
		for (int x = 0; x < weights.size(); x++) {
			for (int y = 0; y < weights[x].size(); y++) {
				weights[x][y] = weights[x][y] + (costW[x][y] * costInc);
			}
		}
		for (int x = 0; x < bias.size(); x++) {
			for (int y = 0; y < bias.size(); y++) {
				bias[x][y] = bias[x][y] + (costB[x][y] * costInc);
			}
		}
	}

	void roundData() {
		int z = activations.size();
		for (int i = 0; i < activations[z][i]; i++) {
			if ((activations[z][i] + 0.5) >= ceil(activations[z][i])) {
				fin[i] = ceil(activations[z][i]);
			}
			else {
				fin[i] = floor(activations[z][i]);
			}
		}
	}

	//call to clear the neuron completely, I only use this at the end to 100% release my memory
	void close() {
		weights.clear();
		bias.clear();
		activations.clear();
		cost.clear();
		costW.clear();
		costB.clear();
		outputData.clear();
	}

};