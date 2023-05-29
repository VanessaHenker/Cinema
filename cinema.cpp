#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int main(){
  bool cadeiras[10][5];
  int escolha1, escolha2, i, j;
  char n;

  escolha1 = 0;
  escolha2 = 0;
  i = 0;

  for (i = 0; i < 10; i++){
    for (j = 0; j < 5; j++){
      cadeiras[i][j] = false;
    }
  }

  do{
    for (i = 0; i < 10; i++){
      for (j = 0; j < 5; j++){
        if (cadeiras[i][j] == true){
          cout << "[--] ";
        }
        else{
          cout << "[" << i << j << "] ";
        }
      }
    }
    cout << endl;
    cout << "\nReservar a cadeira: ";
    cin >> escolha1 >> escolha2;
    if (cadeiras[escolha1][escolha2] == true){
      cout << "\nCADEIRA OCUPADA\n";
    }
    else{
      cadeiras[escolha1][escolha2] = true;
      cout << "\nA cadeira " << escolha1 << escolha2 << " foi RESERVADA\n";
    }
    if (n == 'n'){
      cout << "\nObrigado, boa sessao!\n";
    }
    cout << "\nQuer reservar outro?[S/N]: ";
    cin >> n;
    system("cls");
  } while (n == 's' || n == 'S');
}
