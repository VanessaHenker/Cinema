#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <locale.h>
using namespace std;

int selecionar_poltronas();
void sessao_escolha();
void sessao_filme();
void escolha_horario(int escolha_hora, int opcap);
int bebidas(int escolha_coca, int guarda_coca);

struct Filme{
  string titulo;
  string genero;
  string classi;
  int duracao;
};

struct Sessao{
  string horario;
  string sala;
  Filme filme;
};

struct Comida{
  string pipoca;
  float preco;
};

struct Bebida{
  string refri;
  float preco;
};

  Filme filme1 = {"O Senhor dos Anéis", "Fantásia", "12 anos", 180};
  Filme filme2 = {"Interestelar", "Ficção Científica", "12 anos", 169};
  Filme filme3 = {"Invocação do mal", "Terror", "14 anos", 111};
  
  Sessao sessao1 = {"15:00 - 17:20", "Sala 1", filme1};
  Sessao sessao2 = {"16:00 - 18:30 - 21:00", "Sala 2", filme3};
  Sessao sessao3 = {"15:30 - 20:00", "Sala 3", filme2};
  Sessao sessao4 = {"20:15", "Sala 4", filme1};

  Bebida bebida1 = {"[1]Coca-cola  237ml R$", 4};
  Bebida bebida2 = {"[2]Coca-cola  350ml R$", 6};
  Bebida bebida3 = {"[3]Coca-cola  350ml ZERO R$", 6.50};
  Bebida bebida4 = {"[4]Coca-cola  600ml R$", 8};

  Bebida bebida5 = {"[1]Fanta uva  237ml R$ ", 4};
  Bebida bebida6 = {"[2]Fanta uva  350ml R$ ", 6};
  Bebida bebida7 = {"[3]Fanta uva  350ml ZERO R$ ", 6.50};
  Bebida bebida8 = {"[4]Fanta uva  600ml", 8};

  Bebida bebida9  = {"[1]Fanta laranja  237ml R$ ", 4};
  Bebida bebida10 = {"[2]Fanta laranja  350ml R$ ", 6};
  Bebida bebida11 = {"[3]Fanta laranja  350ml ZERO R$ ", 6.50};
  Bebida bebida12 = {"[4]Fanta laranja  600ml", 8};

  Bebida bebida13 = {"[1]Fanta guaraná  237ml R$ ", 4};
  Bebida bebida14 = {"[2]Fanta guaraná  350ml R$ ", 6};
  Bebida bebida15 = {"[3]Fanta guaraná  350ml ZERO R$ ", 6.50};
  Bebida bebida16 = {"[4]Fanta guaraná  600ml R$ ", 8};
 
int escolha, sessao, fin_compra;
int i, qtd_ingresso;
int ingresso_poltrona, guarda_ingresso, compra_ingresso;
char opcao_ingresso;
float ing_int, ing_meia, total_ingresso;
// variaveis de escolha de sessao e filme
int qtd_filme = 4;
char sele_sessao;
int opcao = 0, escolha_hora = 0;
// variáveis de escolha comidas e bebidas;
int escolha_bebida, escolha_coca = 0, guarda_coca;
char sele_bebida;
  
  int main(){
  int qtd_coca[4], qtd_laran[4], qtd_uva[4], qtd_guara[4];
  int escolha_sessao;
  ing_int = 30;
  ing_meia = 15;
  i = 0;
  opcao = 0;
  ingresso_poltrona = 0;
  guarda_ingresso = 0;
  total_ingresso = 0;
  qtd_ingresso = 0;
  escolha_sessao = 0;
 
    cout << "--------------------------------";
    cout << "\nBem vindo ao nosso cinema!";
    cout << "\n--------------------------------";
    cout << endl;
    do{
    setlocale(LC_ALL, "Portuguese_Brazil");
    cout << "\n[1]-> Opções de filme e sessões";
    cout << "\n[2]-> Comprar ingressos";
    cout << "\n[3]-> Selecionar poltronas";
    cout << "\n[4]-> Comidas e bebidas";
    cout << endl;
    cin >> escolha;
    //system("cls");
    if (escolha == 1){
      sessao_filme();
      cout << endl;
     do{
        cout << "Se deseja selecionar alguma sessão";
        cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
        cin >> sele_sessao;
       if (sele_sessao == 'S' || sele_sessao == 's'){
          sessao_escolha();
        }
      } while (sele_sessao != 'S' && sele_sessao != 's' && sele_sessao != 'N' && sele_sessao != 'n');
      cout << endl;
      cout << "\nDigite 0 para voltar a tela inical: ";
      cin >> opcao;
      //system("cls");
    }

    if (escolha == 2){
      setlocale(LC_ALL, "Portuguese_Brazil");
      cout << "\n[1]Ingresso inteiro R$" << ing_int;
      cout << "\n[2]Ingresso meio R$" << ing_meia;
      cout << endl;
      do{
        cout << "\nSelecione a opcao de ingressos! ";
        cin >> compra_ingresso;

        if (compra_ingresso == 1){
          cout << "\nQuantidade de ingressos: ";
          cin >> qtd_ingresso;
          ingresso_poltrona = ingresso_poltrona + qtd_ingresso;
          qtd_ingresso = qtd_ingresso * ing_int;
          guarda_ingresso = guarda_ingresso + qtd_ingresso;
        }
        if (compra_ingresso == 2){
          cout << "\nQuantidade de ingressos: ";
          cin >> qtd_ingresso;
          ingresso_poltrona = ingresso_poltrona + qtd_ingresso;
          qtd_ingresso = qtd_ingresso * ing_meia;
          guarda_ingresso = guarda_ingresso + qtd_ingresso;
        }
        cout << "\nCompra mais ingressos[S/N]: ";
        cin >> opcao_ingresso;
      } while (opcao_ingresso == 's' || opcao_ingresso == 'S');
      total_ingresso = total_ingresso + guarda_ingresso;
      cout << "\nDigite 0 para voltar a tela inical: ";
      cin >> opcao;
    }

    if (escolha == 3){
      setlocale(LC_ALL, "Portuguese_Brazil");
      bool cadeiras[10][5];
      int escolha1, escolha2, i, j, reserva_polt;
      char n;
      escolha1 = 0;
      escolha2 = 0;
      reserva_polt = 0;
      i = 0;
      for (i = 0; i < 10; i++){
        for (j = 0; j < 5; j++){
          cadeiras[i][j] = false;
        }
      }
      if (ingresso_poltrona == 0){
        cout << "\nNao teve nenhuma compra de ingresso!";
        cout << "\nSe deseja reservar poltronas volte ao menu incial!";
        cout << endl;
        cout << "\nDigite 0 para voltar ao menu inicial: ";
        cin >> opcao;
      }
      else{
        while (reserva_polt < ingresso_poltrona){
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
            if (escolha1 > 9 || escolha2 > 4){
              cout << "\nCadeira nao existe, Tente novamente!";
              cout << endl;
            }
          } while (escolha1 > 9 || escolha2 > 4);
          if (cadeiras[escolha1][escolha2] == true){
            cout << "\nCADEIRA OCUPADA\n";
          }
          else{
            cadeiras[escolha1][escolha2] = true;
            cout << "\nA cadeira " << escolha1 << escolha2 << " foi RESERVADA\n";
            reserva_polt++;
          }
          if (reserva_polt >= ingresso_poltrona){
            cout << "\nSe deseja reservar mais poltronas volte ao menu incial!";
            cout << endl;
            cout << "\nDigite 0 para voltar ao menu inicial: ";
            cin >> opcao;
          }
        }
      }
    }

    if (escolha == 4){
      setlocale(LC_ALL, "Portuguese_Brazil");
      
      cout << "Opçoes comidas: " << endl;
      cout << "[1]Pipocas" << endl;
      cout << "[2]Chocolates" << endl;
      cout << "[3]Fandangos" << endl;
      cout << "[4]Doritos" << endl;
      cout << "[5]Ruffles" << endl;
      cout << "[6]Cheetos" << endl;
      cout << endl;
      
      cout << "\nOpções bebidas:" << endl;
      cout << "[1]Coca-cola" << endl;
      cout << "[2]Fanta uva" << endl;
      cout << "[3]Fanta laranja" << endl;
      cout << "[4]Fanta guarana" << endl;
      cout << endl;
      
      cout << "Deseja entrar na opções de bebidas" << endl;
      cout << "\nDigite 'S' para SIM ou 'N' para 'NÂO': ";
      cin >> sele_bebida;
      if(sele_bebida == 's' || sele_bebida == 'S'){
        cout << "\nDigite o numero: ";
        cin >> escolha_bebida;
       switch (escolha_bebida){
        case 1 :
        cout << bebida1.refri << bebida1.preco << endl;
        cout << bebida2.refri << bebida2.preco << endl;
        cout << bebida3.refri << bebida3.preco << endl;
        cout << bebida4.refri << bebida4.preco << endl;
        cin >> escolha_coca;
        break;
        case 2:
        cout << bebida5.refri << bebida5.preco << endl;
        cout << bebida6.refri << bebida6.preco << endl;
        cout << bebida7.refri << bebida7.preco << endl;
        cout << bebida8.refri << bebida8.preco << endl;
        break;
        case 3:
        cout << bebida9.refri << bebida9.preco << endl;
        cout << bebida10.refri << bebida10.preco << endl;
        cout << bebida11.refri << bebida11.preco << endl;
        cout << bebida12.refri << bebida12.preco << endl;
        break;
        case 4:
        cout << bebida13.refri << bebida13.preco << endl;
        cout << bebida14.refri << bebida14.preco << endl;
        cout << bebida15.refri << bebida15.preco << endl;
        cout << bebida16.refri << bebida16.preco << endl;
        break;
        default:
        cout << "\nNumero não existe, Tente novamente!";
          break;
        } 
      }
    }
  }while(opcao == 0);
  return 0;
}

void sessao_filme(){
  setlocale(LC_ALL, "Portuguese_Brazil");
 // Exibindo informações das sessões
  cout << "----------------------------------------------" << endl;
  cout << "Sessão 1:" << endl;
  cout << "Filme: " << sessao1.filme.titulo << endl;
  cout << "Horários: " << sessao1.horario << endl;
  cout << "Sala: " << sessao1.sala << endl;
  cout << "Gêero: " << sessao1.filme.genero << endl;
  cout << "Classificação: " << filme1.classi << endl;
  cout << "----------------------------------------------" << endl;
  cout << endl;
  
  cout << "----------------------------------------------" << endl;
  cout << "Sessão 2:" << endl;
  cout << "Filme: " << sessao2.filme.titulo << endl;
  cout << "Horários: " << sessao2.horario << endl;
  cout << "Sala: " << sessao2.sala << endl;
  cout << "Gênero: " << sessao2.filme.genero << endl;
  cout << "Classificação: " << filme3.classi << endl;
  cout << "----------------------------------------------" << endl;
  cout << endl;
 
  cout << "----------------------------------------------" << endl;
  cout << "Sessão 3:" << endl;
  cout << "Filme: " << sessao3.filme.titulo << endl;
  cout << "Horários: " << sessao3.horario << endl;
  cout << "Sala: " << sessao3.sala << endl;
  cout << "Gênero: " << sessao3.filme.genero << endl;
  cout << "Classificação: " << filme2.classi << endl;
  cout << "----------------------------------------------" << endl;
  cout << endl;

  cout << "----------------------------------------------" << endl;
  cout << "Filme: " << sessao4.filme.titulo << endl;
  cout << "Sessão 4" << endl;
  cout << "Horários: " << sessao4.horario << endl;
  cout << "Sala: " << sessao4.sala << endl;
  cout << "Gênero: " << sessao4.filme.genero << endl;
  cout << "Classificação: " << filme1.classi << endl;
  cout << "----------------------------------------------" << endl;
}
void sessao_escolha(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  do{
    cout << "\nSelecione a sessão: ";
    cin >> opcao;
  switch (opcao){
    case 1:
      do{
      //system("cls");
      cout << "\nEscolha o horário:" << endl;
      cout << "[1]-> 15:00" << endl;
      cout << "[2]-> 17:20" << endl;
      cin >> escolha_hora;
    if(escolha_hora > 2 || escolha_hora <= 0){
      cout << "\nNão existe esse horário, tente novamente";
    }
  }while (escolha_hora > 2 || escolha_hora <= 0); 
      escolha_horario(escolha_hora, opcao); 
      break;
    case 2:
      do{
      //system("cls");
      cout << "\nEscolha o horário:" << endl;
      cout << "[1]-> 16:00" << endl;
      cout << "[2]-> 18:30" << endl;
      cout << "[3]-> 21:00" << endl;
      cin >> escolha_hora;
    }while (escolha_hora > 3 || escolha_hora <= 0);   
      escolha_horario(escolha_hora, opcao); 
      break;
    case 3:
      do{ 
      //system("cls");
      cout << "\nEscolha o horário:" << endl;
      cout << "[1]-> 15:30" << endl;
      cout << "[2]-> 20:30" << endl;
      cin >> escolha_hora;
      }while (escolha_hora > 2 || escolha_hora <= 0); 
      escolha_horario(escolha_hora, opcao); 
      break;
    case 4:
      do{
      //system("cls");
      cout << "\nEscolha o horário:" << endl;
      cout << "[1]-> 20:15" << endl;
      cin >> escolha_hora;
    if(escolha_hora > 1 || escolha_hora <= 0){
      cout << "\nNão existe esse horário, tente novamente";
    }
    }while (escolha_hora > 2 || escolha_hora <= 0); 
      escolha_horario(escolha_hora, opcao); 
      break;
    default:
      cout << "\nSessão não existe, Tente novamente!";
      break;
    }
  }while (opcao > qtd_filme || opcao <= 0);
}
void escolha_horario(int escolha_hora, int opcao){
    setlocale(LC_ALL, "Portuguese_Brazil");
    // Horário selecionado da opcao 1
    if(escolha_hora == 1 && opcao == 1 || escolha_hora == 2 && opcao == 1){
    cout << "\nSessão " << opcao << ":" << " SELECIONADA" << "!" << endl;
    cout << "Filme: " << sessao1.filme.titulo << endl;
    if(escolha_hora == 1 && opcao == 1){
    cout << "Horário: " << "15:00"<< endl;
  }
    if(escolha_hora == 2 && opcao == 1){
    cout << "Horário: " << "17:20"<< endl;
  }
    cout << "Sala: " << sessao1.sala << endl;
    cout << "Gênero: " << sessao1.filme.genero << endl;
    cout << "Classificação: " << filme1.classi << endl;
  }
    // Horário selecionado da opcao 2
    if(escolha_hora == 1 && opcao == 2 || escolha_hora == 2 && opcao == 2 || escolha_hora == 3 && opcao == 2){
    cout << "\nSessão " << opcao << ":" << " SELECIONADA" << "!" << endl;
    cout << "Filme: " << sessao2.filme.titulo << endl;
    if(escolha_hora == 1 && opcao == 2){
    cout << "Horário: " << "16:00"<< endl;
  }
    if(escolha_hora == 2 && opcao == 2){
    cout << "Horário: " << "18:30"<< endl;
  } 
    if(escolha_hora == 3 && opcao == 2){
    cout << "Horário: " << "21:00"<< endl;
  }
    cout << "Sala: " << sessao2.sala << endl;
    cout << "Gênero: " << sessao2.filme.genero << endl;
    cout << "Classificação: " << filme3.classi << endl;  
  }   
     //Horário selecionado da opcao 3
    if(escolha_hora == 1 && opcao == 3 || escolha_hora == 2 && opcao == 3){
    cout << "\nSessão " << opcao << ":" << " SELECIONADA" << "!" << endl;
    cout << "Filme: " << sessao3.filme.titulo << endl;
    if(escolha_hora == 1 && opcao == 3){
    cout << "Horário: " << "15:30"<< endl;
  }
    if(escolha_hora == 2 && opcao == 3){
    cout << "Horário: " << "20:30"<< endl;
  }
    cout << "Sala: " << sessao3.sala << endl;
    cout << "Gênero: " << sessao3.filme.genero << endl;
    cout << "Classificação: " << filme2.classi << endl;  
  }  
    // Horário selecionado da opcao 4
    if(escolha_hora == 1 && opcao == 4){
    cout << "\nSessão " << opcao << ":" << " SELECIONADA" << "!" << endl;
    cout << "Filme: " << sessao4.filme.titulo << endl;
    cout << "Horário: " << "20:15"<< endl;
    cout << "Sala: " << sessao4.sala << endl;
    cout << "Gênero: " << sessao4.filme.genero << endl;
    cout << "Classificação: " << filme1.classi << endl;  
  }
}    

int bebidas(int escolha_coca, int guarda_coca){
  setlocale(LC_ALL, "Portuguese_Brazil");
  if(escolha_coca == 1){
    do{
    cout << "\nQuantidade: ";
    cin >> guarda_coca;
    if(guarda_coca < 0){
      cout << "\nQuantidade inválida, tente novamente! ";
    }
    } while(guarda_coca < 0);
    guarda_coca = guarda_coca * bebida1.preco;
    
    return guarda_coca;
  }
  if(escolha_coca == 2){
    do{
    cout << "\nQuantidade: ";
    cin >> guarda_coca;
    if(guarda_coca < 0){
      cout << "\nQuantidade inválida, tente novamente! ";
    }
    } while(guarda_coca < 0);
    guarda_coca = guarda_coca * bebida2.preco;
    
    return guarda_coca;
  }
  if(escolha_coca == 3){
    do{
    cout << "\nQuantidade: ";
    cin >> guarda_coca;
    if(guarda_coca < 0){
      cout << "\nQuantidade inválida, tente novamente! ";
    }
    } while(guarda_coca < 0);
    guarda_coca = guarda_coca * bebida3.preco;
    
    return guarda_coca;
  }
  if(escolha_coca == 4){
    do{
    cout << "\nQuantidade: ";
    cin >> guarda_coca;
    if(guarda_coca < 0){
      cout << "\nQuantidade inválida, tente novamente! ";
    }
    } while(guarda_coca < 0);
    guarda_coca = guarda_coca * bebida4.preco;
    
    return guarda_coca;
  }
  return 0;
}



