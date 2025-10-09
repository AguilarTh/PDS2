#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int numBWords, numBWordsFound[10]= {0};
    cin >> numBWords;
    cin.ignore();

    string bWords[10], phrase;
    for(int i=0; i<numBWords; i++){
        cin >> bWords[i];
        cin.ignore();
    }

    getline(cin, phrase);
    stringstream sphrase (phrase);
    string palavraAtual, novaFrase;

    while (sphrase >> palavraAtual) {
        for(int i=0; i<numBWords; i++){
            if (palavraAtual == bWords[i]){
                int palavraAtualLength = palavraAtual.length();
                numBWordsFound[i]++;
                palavraAtual = "";

                for(int j=0; j<palavraAtualLength; j++){
                    palavraAtual += "*";
                }
                
                break;
            }
        }
        novaFrase += palavraAtual + " ";
    }

    cout << novaFrase << endl;

    for(int i=0; i<numBWords; i++) {
        cout << "Palavra " << bWords[i] << " substituida " << numBWordsFound[i] << " vez(es)" << endl;
    }
    
    return 0;
}