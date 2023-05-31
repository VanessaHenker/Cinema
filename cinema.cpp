#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;
int selecionar_poltronas();
int sessao_filme();

struct Filme{
  string titulo;
  string genero;
  int duracao;
};

struct Sessao{
  string horario;
  string sala;
  Filme filme;
};

  struct Comida{
  string pipoca;
  int preco;
};

struct Bebida{
  string refri;
  int preco;
 };
int main(){
  
  int opcao, escolha, sessao; 
  int opcao_ingresso, qtd_ingresso, compra_pipoca, qtd_pipoca, qtd_bebida, compra_bebida;
  char compra_dnv, opcao_pipoca, opcao_bebida;
  float ing_int, ing_meia;
  ing_int = 30;
  ing_meia = 15;
  qtd_ingresso = 0;
  qtd_pipoca = 0;
  qtd_bebida = 0;
  do{
  cout << "--------------------------------";
  cout << "\nBem vindo ao nosso cinema!";
  cout << "\n--------------------------------";
  cout << endl;
  
  cout << "\n[1]Opcoes de filmes";
  cout << "\n[2]Valores do ingresso";
  cout << "\n[3]Selecionar as poltronas";
  cout << "\n[4]Comidas e bebidas";
  cout << endl;
  cin >> escolha;

  if(escolha == 1){
   Filme filme1 = {"O Senhor dos Anéis", "Fantasia", 180};
   Filme filme2 = {"Interestelar", "Ficção Científica", 169};

    // Criando sessões
    Sessao sessao1 = {"15:00", "Sala 1", filme1};
    Sessao sessao2 = {"18:30", "Sala 2", filme2};

    // Exibindo informações das sessões
    cout << "Sessão 1:" << endl;
    cout << "Horário: " << sessao1.horario << endl;
    cout << "Sala: " << sessao1.sala << endl;
    cout << "Filme: " << sessao1.filme.titulo << endl;
    cout << "Gênero: " << sessao1.filme.genero << endl;

    cout << endl;
    
    cout << "Sessão 2:" << endl;
    cout << "Horário: " << sessao2.horario << endl;
    cout << "Sala: " << sessao2.sala << endl;
    cout << "Filme: " << sessao2.filme.titulo << endl;
    cout << "Gênero: " << sessao2.filme.genero << endl;
  
  cout << endl;
  cout << "\nSeleione a sessao: ";
  cin >> opcao;
  
  cout << "\nDigite 0 para voltar a tela inical: ";
  cin >> opcao;
}
  
  if(escolha == 2){
  cout << "\n[1]Ingresso inteiro R$" << ing_int;
  cout << "\n[2]Ingresso meio R$" << ing_meia;
  cout << endl;
  do{
  cout << "\nSelecione a opção de ingressos! ";
  cin >> opcao_ingresso;

  if(opcao_ingresso == 1){
    cout << "\nQuantida de ingressos: ";
    cin >> qtd_ingresso;
    qtd_ingresso = qtd_ingresso * ing_int;
  }
  if(opcao_ingresso == 2){
    cout << "\nQuantidade de ingressos: ";
    cin >> qtd_ingresso;
    qtd_ingresso = qtd_ingresso * ing_int;
  }
  cout << "\nCompra mais ingressos[S/N]: ";
  cin >> compra_dnv;
  }while(compra_dnv == 's'|| compra_dnv == 'S');
  cout << "\nDigite 0 para voltar a tela inical: ";
  cin >> opcao;
  }
  
  if(escolha == 3){
  selecionar_poltronas();
  }
  
  if(escolha == 4){
  Comida comida1 = {"[1]Pipoca pequena R$ ", 10};
  Comida comida2 = {"[2]Pipoca media   R$ ", 12};
  Comida comida3 = {"[3]Pipoca grande  R$ ", 15};

  Bebida bebida1 = {"[1]Coca-cola lata     R$ ", 5};
  Bebida bebida2 = {"[2]Fanta uva lata     R$ ", 5};
  Bebida bebida3 = {"[3]Fanta laranja lata R$ ", 5};
  Bebida bebida4 = {"[4]Fanta guarana lata R$ ", 5};

  cout << "\nOpcões de pipoca: ";
  cout << endl;
  cout << comida1.pipoca << comida1.preco << " reais" << endl;
  cout << comida2.pipoca << comida2.preco << " reais" << endl;
  cout << comida3.pipoca << comida3.preco << " reais" << endl;
 
  cout << "\nOpções de bebidas: ";
  cout << endl;
  cout << bebida1.refri << bebida1.preco << " reais" << endl;
  cout << bebida2.refri << bebida2.preco << " reais" << endl;
  cout << bebida3.refri << bebida3.preco << " reais" << endl;
  cout << bebida4.refri << bebida4.preco << " reais" << endl;

  cout << "\nDeseja comprar pipoca[S/N]: ";
  cin >> opcao_pipoca;
  if(opcao_pipoca == 's' || opcao_pipoca == 'S'){
    cout << "\nDigite o numero: ";
    cin >> compra_pipoca;
    if(compra_pipoca == 1){
     cout << "\nQuantidade: ";
     cin >> qtd_pipoca;
     qtd_pipoca = qtd_pipoca * comida1.preco;
    }
    if(compra_pipoca == 2){
      cout << "\nQuantidade: ";
      cin >> qtd_pipoca;
      qtd_pipoca = qtd_pipoca * comida2.preco;
    }
    if(compra_pipoca == 3){
      cout << "\nQuantidade: ";
      cin >> qtd_pipoca;
      qtd_pipoca = qtd_pipoca * comida3.preco;
    }
  }
  cout << "\nDeseja comprar bebida[S/N]: ";
  cin >> opcao_bebida;
  if(opcao_bebida == 's' || opcao_bebida == 'S'){
  cout << "\nDigite o numero: ";
  cin >> compra_bebida;
  if(qtd_bebida == 1){
    cout << "\nQuantidade: ";
    cin >> qtd_bebida;
    qtd_bebida = qtd_bebida * bebida1.preco;
    }
  if(compra_bebida == 2){
    cout << "\nQuantidade: ";
    cin >> qtd_bebida;
    qtd_bebida = qtd_bebida * bebida2.preco;
  }
  if(compra_bebida == 3){
    cout << "\nQuantidade: ";
    cin >> qtd_bebida;
    qtd_bebida = qtd_bebida * bebida3.preco;
  }
  if(compra_bebida == 4){
    cout << "\nQuantidade: ";
    cin >> qtd_bebida;
    qtd_bebida = qtd_bebida * bebida4.preco;
  }
}

  cout << "\nDigite 0 para voltar a tela inical: ";
  cin >> opcao;
  
  }
  
  }while(opcao == 0);
  return 0;
}

int selecionar_poltronas(){
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
    cout << endl;
    }
    do{
    cout << "\nReservar a cadeira: ";
    cin >> escolha1 >> escolha2;
    if(escolha1 > 9 || escolha2 > 4){
     cout << "\nCadeira nao existe, Tente novamente!";
     cout << endl;
      }
    }while(escolha1 > 9 || escolha2 > 4);
    
    if(cadeiras[escolha1][escolha2] == true){
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

  return 0;
}

