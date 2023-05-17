#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

int main(){
    using namespace std;

    bool cadeiras[10];
    int escolha, i;
    char n;

    escolha = 0;
    i = 0;
    n = 's';
    cadeiras[0] = false;
    cadeiras[1] = false;
    cadeiras[2] = false;
    cadeiras[3] = false;
    cadeiras[4] = false;
    cadeiras[5] = false;
    cadeiras[6] = false;
    cadeiras[7] = false;
    cadeiras[8] = false;
    cadeiras[9] = false;

    for (i = 0; i < 10; i++){ // for para as posições das cadeiras
        if (cadeiras[i] == true){ // se a condição for verdadeira ocupará a cadeira com x
            cout << "[x]";
        }
        else{
            cout << "[B" << i << "]"; // preencher as cadeiras com os numeros
        }
    }

    cout << endl;
    cout << "Reservar a cadeira B";
    cin >> escolha;

    cout << endl;
    cadeiras[escolha] = true; // cadeiras na posicao escolha for verdadeira sera reservada
    cout << "Cadeira B" << escolha << " foi RESERVADA\n";

    cout << endl;
    n = 's'; // n recebe 's' para utilização do while
    while (n == 's'){ // while ira se repitir enquanto a pessoa digitar 's'
        for (i = 0; i < 10; i++){ // for para as possições das cadeiras
            if (cadeiras[i] == true){ // se a condição for verdadeira ocupará a cadeira com x
                cout << "[x]";
            }
            else{
                cout << "[B" << i << "]"; // preencher as cadeiras com os numeros
            }
        }
        cout << endl;
        cout << "Quer reservar outro?[S/N]"; // se a condicao receber ´s' reservará outra cadeira
        cin >> n;
        cout << endl;
        if (n == 's'){
            cout << "Reservar a cadeira B";
            cin >> escolha;
        }
        if (cadeiras[escolha] == true){ // se a condição for igual a true
            cout << "CADEIRA OCUPADA\n"; // cadeira ja foi escolhida
        }
        else{
            cadeiras[escolha] = true; // se a a condição receber true
            cout << "A cadeira B" << escolha << " foi RESERVADA\n";
        }
        if (n == 'n'){// se a condição for igual 'n'
            cout << "Obrigado, boa sessao!\n"; // fim do programa
        }
    }
}
