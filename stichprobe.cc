#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
    int N_lines = 234;
    int current_value = 0;
    float mean = 0; // mut be float so that the division works!!
    float var = 0;
    float sigma = 0;

    ifstream fin("datensumme.txt");
    
    for(int i=0; i < N_lines; i++){
        fin >> current_value;
        mean += current_value;
        // cout << current_value;
    }
    mean /= N_lines;

    fin.close();
    fin.open("datensumme.txt");

    // std::ifstream fin("datensumme.txt");
    for(int i=0; i < N_lines; i++){
        fin >> current_value;
        var += (current_value - mean) * (current_value - mean) / N_lines;
    }

    sigma = sqrt(var);

    // cout << "mean: " << mean << endl;
    // cout << "var: " << var << endl;
    // cout << "sigma: " << sigma << endl;
    cout << sigma << endl;

    return 0;
}