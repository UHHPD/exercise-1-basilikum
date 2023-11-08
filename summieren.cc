#include <iostream>
#include <fstream>
// using namespace std;

int main(){

    std::ifstream fin("daten.txt");
    std::ofstream fout("datensumme.txt");
    
    int readint;
    int current_value = 0;
    int res = 0;
    
    for(int i=0; i<234*2; i++){
        fin >> current_value;
        res += current_value;

        if(i % 2 == 2-1){
            fout << res << std::endl;
            res = 0;
        }
    }
    
    fin.close();
    fout.close();

    return 0;
}
