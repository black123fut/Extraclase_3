#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <map>

using namespace std;

/**
 * realiza el diccionario mientras lee caracter por caracter y los va introducciendo
 *
 * */
template<typename Iterator>
Iterator compresionar(const string &datoOriginal, Iterator resultado) {
    int diccSize = 256;
    map<string, int> diccionario;
    ///Agrega los 256 caracteres del código ASCII
    for (int i = 0; i < 256; i++) {
        diccionario[string(1, i)] = i;
    }
    string w;
    ///iteratorAux es cada letra del string
    for (string::const_iterator iteratorAux = datoOriginal.begin();
         iteratorAux != datoOriginal.end(); ++iteratorAux) {

        char k = *iteratorAux; ///Es la siguiente letra de la palabra

        string wk = w + k;


        if (diccionario.count(wk)) { /// Si lo encuentra crea una nueva codificación

            w = wk;
        } else {
            *resultado++ = diccionario[w];
            diccionario[wk] = diccSize++;
            w = string(1, k);
        }

    }
    if (!w.empty()) {
        *resultado++ = diccionario[w];
    }
    return resultado;
};

template<typename Iterator>
string descomprimir(Iterator inicio, Iterator final) {
    int diccSize = 256;
    map<int, string> diccionario;
    ///Agrega los 256 caracteres del código ASCII
    for (int i = 0; i < 256; i++)
        diccionario[i] = string(1, i);
    string w(1, *inicio++);
    string resultado = w;
    string entrada;
    for (; inicio != final; inicio++) {
        int k = *inicio;
        if (diccionario.count(k))
            entrada = diccionario[k];
        else if (k == diccSize)
            entrada = w + w[0];
        else {
            cout << "Error de compresion con k (siguiente valor)" << endl;
            return NULL;
        }
        resultado += entrada;
        diccionario[diccSize++] = w + entrada[0];
        w = entrada;
    }
    return resultado;

}

int main() {
    vector<int> compresion;

    compresionar("SOHCAHTOACACAOHTOTOA", back_inserter(compresion));

    ///Muestra la números de la codificación que se encuentra en el vector
    ///compresion
    copy(compresion.begin(), compresion.end(), ostream_iterator<int>(cout, " - "));

    string descompri = descomprimir(compresion.begin(), compresion.end());
    cout << descompri << endl;


    return 0;
}