#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
    int N_lines = 234;
    int current_value = 0;
    float mean_sample = 0; // mut be float so that the division works!!
    int sample_size = 9;

    // calculate sample mean
    ifstream fin("datensumme.txt");
    ofstream fout_mean("mittelwerte.txt");
    for(int i=0; i < N_lines; i++){
        fin >> current_value;
        mean_sample += current_value;

        if(i % sample_size == sample_size-1){
            mean_sample /= sample_size;
            fout_mean << mean_sample << endl;
            mean_sample = 0;
        }
    }
    fout_mean.close();


    // calculate sample var

    fin.close();
    fin.open("datensumme.txt"); // open the file again, cursor move back to the beginning

    ifstream fin_mean("mittelwerte.txt");
    ofstream fout_var("varianzen.txt");
    
    float var_sample = 0;

    for(int j=0; j<N_lines/sample_size; j++){
        fin_mean >> mean_sample;
        for(int i=0; i < sample_size; i++){
            fin >> current_value;
            var_sample += (current_value - mean_sample) * (current_value - mean_sample) / sample_size; // biased
            // var_sample += (current_value - mean_sample) * (current_value - mean_sample) / (sample_size-1); // unbiased
        }
        fout_var << var_sample << endl;
        var_sample = 0;
    }

    fin.close();


    // mean of the sample mean; mean of the sample var
   
    fin_mean.close();
    fin_mean.open("mittelwerte.txt");
    
    ifstream fin_var("varianzen.txt");
    float read_sample_mean = 0;
    float read_sample_var = 0;

    float mean_sample_mean = 0;
    float mean_sample_var = 0;

    for(int i=0; i<N_lines/sample_size; i++){
        fin_mean >> read_sample_mean;
        fin_var >> read_sample_var;
        // cout << read_sample_mean;
        mean_sample_mean += read_sample_mean / (N_lines/sample_size);
        mean_sample_var += read_sample_var / (N_lines/sample_size);
    }
    
    fin_mean.close();
    fout_var.close();

    // cout << "mean of mean: " << mean_sample_mean << endl;
    // cout << "mean of var: " << mean_sample_var << endl;
    
    cout << mean_sample_var << endl;
    // This demonstrates that the \sum (x-\bar{x})^2 / n is a biased estimator!!!
    return 0;
}