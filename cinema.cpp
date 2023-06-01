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

  Filme filme1 = {"O Senhor dos Anés", "Fantásia", "12 anos", 180};
  Filme filme2 = {"Interestelar", "Ficção Científica", "12 anos", 169};
  Filme filme3 = {"Invocação do mal", "Terror", "14 anos", 111};
  
  Sessao sessao1 = {"15:00 - 17:20", "Sala 1", filme1};
  Sessao sessao2 = {"16:00 - 18:30 - 21:00", "Sala 2", filme3};
  Sessao sessao3 = {"15:30 - 20:00", "Sala 3", filme2};
  Sessao sessao4 = {"20:15", "Sala 4", filme1};

 
int escolha, sessao, fin_compra;
int i, qtd_pipoca[3], qtd_bebida[4], qtd_ingresso;
int compra_pipoca, compra_bebida, compra_ingresso;
int ingresso_poltrona, guarda_ingresso, guarda_pipoca, guarda_bebida;
char opcao_bebida, opcao_pipoca, opcao_ingresso;
float ing_int, ing_meia, total_ingresso, total_pipoca, total_bebida;
// variaveis para mudar valor
int qtd_filme = 4;

// variaveis de escolha de sessao e filme
char sele_sessao, escolha_hora;
int opcao;

  int main(){
  int escolha_sessao;
  ing_int = 30;
  ing_meia = 15;
  i = 0;
  opcao = 0;
  ingresso_poltrona = 0;
  guarda_ingresso = 0;
  guarda_pipoca = 0;
  total_ingresso = 0;
  total_pipoca = 0;
  qtd_ingresso = 0;
  escolha_sessao = 0;
  qtd_bebida[0] = 0;
  qtd_bebida[1] = 0;
  qtd_bebida[2] = 0;
  qtd_bebida[0] = 0;
  qtd_pipoca[1] = 0;
  qtd_pipoca[2] = 0;
  qtd_pipoca[3] = 0;
 
    cout << "--------------------------------";
    cout << "\nBem vindo ao nosso cinema!";
    cout << "\n--------------------------------";
    cout << endl;
    do{
    setlocale(LC_ALL, "Portuguese_Brazil");
    cout << "\n[1]-> Opcões de filme e sessões";
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
        cout << "\nDigite 'S' para SIM ou 'N' para NÃO: ";
        cin >> sele_sessao;
       if (sele_sessao == 'S' || sele_sessao == 's'){
          sessao_escolha();
        }
        
        //system("cls");
      } while (sele_sessao != 'S' && sele_sessao != 's' && sele_sessao != 'N' && sele_sessao != 'n');
      cout << endl;
      cout << "\nDigite 0 para voltar a tela inical: ";
      cin >> opcao;
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
          cout << "\nQuantida de ingressos: ";
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
      Comida comida1 = {"[1]Pipoca pequena R$ ", 10};
      Comida comida2 = {"[2]Pipoca media   R$ ", 12};
      Comida comida3 = {"[3]Pipoca grande  R$ ", 15};

      Bebida bebida1 = {"[1]Coca-cola lata     R$ ", 5};
      Bebida bebida2 = {"[2]Fanta uva lata     R$ ", 5};
      Bebida bebida3 = {"[3]Fanta laranja lata R$ ", 5};
      Bebida bebida4 = {"[4]Fanta guarana lata R$ ", 5};

      cout << "\nOpcÃµes de pipoca: ";
      cout << endl;
      cout << comida1.pipoca << comida1.preco << " reais" << endl;
      cout << comida2.pipoca << comida2.preco << " reais" << endl;
      cout << comida3.pipoca << comida3.preco << " reais" << endl;

      cout << "\nOpÃ§Ãµes de bebidas: ";
      cout << endl;
      cout << bebida1.refri << bebida1.preco << " reais" << endl;
      cout << bebida2.refri << bebida2.preco << " reais" << endl;
      cout << bebida3.refri << bebida3.preco << " reais" << endl;
      cout << bebida4.refri << bebida4.preco << " reais" << endl;

      cout << "\nDeseja comprar pipoca[S/N]: ";
      cin >> opcao_pipoca;

      while (opcao_pipoca == 's' || opcao_pipoca == 'S'){
        cout << "\nDigite o numero: ";
        cin >> compra_pipoca;
        switch (compra_pipoca){
        case 1:
          cout << "\nQuantidade: ";
          cin >> guarda_pipoca;
          guarda_pipoca = guarda_pipoca * comida1.preco;
          qtd_pipoca[0] = qtd_pipoca[0] + guarda_pipoca;
          break;
        case 2:
          cout << "\nQuantidade: ";
          cin >> guarda_pipoca;
          guarda_pipoca = guarda_pipoca * comida2.preco;
          qtd_pipoca[1] = qtd_pipoca[1] + guarda_pipoca;
          break;
        case 3:
          cout << "\nQuantidade: ";
          cin >> guarda_pipoca;
          guarda_pipoca = guarda_pipoca * comida3.preco;
          qtd_pipoca[2] = qtd_pipoca[2] + guarda_pipoca;
          break;
        default:
          cout << "\nValor invalido, Tente novamente!";
          break;
        }
        cout << "\nContinuar compra[S/N]: ";
        cin >> opcao_pipoca;
      }
      for (i = 0; i < 3; i++){
        total_pipoca = total_pipoca + qtd_pipoca[i];
      }

      cout << "\nDeseja comprar bebida[S/N]: ";
      cin >> opcao_bebida;
      while (opcao_bebida == 's' || opcao_bebida == 'S'){
        cout << "\nDigite o numero: ";
        cin >> compra_bebida;
        switch (compra_bebida){
        case 1:
          cout << "\nQuantidade: ";
          cin >> guarda_bebida;
          guarda_bebida = guarda_bebida * bebida1.preco;
          qtd_bebida[0] = qtd_bebida[0] + guarda_bebida;
          break;
        case 2:
          cout << "\nQuantidade: ";
          cin >> guarda_bebida;
          guarda_bebida = guarda_bebida * bebida2.preco;
          qtd_bebida[1] = qtd_bebida[1] + guarda_bebida;
          break;
        case 3:
          cout << "\nQuantidade: ";
          cin >> guarda_bebida;
          guarda_bebida = guarda_bebida * bebida3.preco;
          qtd_bebida[2] = qtd_bebida[2] + guarda_bebida;
          break;
        case 4:
          cout << "\nQuantidade: ";
          cin >> guarda_bebida;
          guarda_bebida = guarda_bebida * bebida4.preco;
          qtd_bebida[4] = qtd_bebida[4] + guarda_bebida;
          break;
        default:
          cout << "\nValor invalido, Tente novamente!";
          break;
        }
        cout << "\nContinuar compra[S/N]: ";
        cin >> opcao_bebida;
      }
      for (i = 0; i < 4; i++){
        total_bebida = total_bebida + qtd_bebida[i];
      }
      cout << "\nDigite 0 para voltar a tela inical: ";
      cin >> opcao;
    }

  } while (opcao == 0);
  return 0;
}

void sessao_filme(){
  setlocale(LC_ALL, "Portuguese_Brazil");
 // Exibindo informaÃ§Ãµes das sessÃµes
  cout << "Sessao 1:" << endl;
  cout << "Filme: " << sessao1.filme.titulo << endl;
  cout << "Horaio: " << sessao1.horario << endl;
  cout << "Sala: " << sessao1.sala << endl;
  cout << "Gênero: " << sessao1.filme.genero << endl;
  cout << "Classificação: " << filme1.classi << endl;
  cout << endl;
  
  cout << "Sessão 2:" << endl;
  cout << "Filme: " << sessao2.filme.titulo << endl;
  cout << "Horário: " << sessao2.horario << endl;
  cout << "Sala: " << sessao2.sala << endl;
  cout << "Gï¿½nero: " << sessao2.filme.genero << endl;
  cout << "Classificação: " << filme3.classi << endl;
  cout << endl;
 
  cout << "Sessão 3:" << endl;
  cout << "Filme: " << sessao3.filme.titulo << endl;
  cout << "Horário: " << sessao3.horario << endl;
  cout << "Sala: " << sessao3.sala << endl;
  cout << "Gï¿½nero: " << sessao3.filme.genero << endl;
  cout << "Classificação: " << filme2.classi << endl;
  cout << endl;

  cout << "Filme: " << sessao4.filme.titulo << endl;
  cout << "Sessão 4" << endl;
  cout << "Horário: " << sessao4.horario << endl;
  cout << "Sala: " << sessao4.sala << endl;
  cout << "Gênero: " << sessao4.filme.genero << endl;
  cout << "Classificação: " << filme1.classi << endl;
}

void sessao_escolha(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int escolha_hora;
  escolha_hora = 0;
  do{
    cout << "\nSelecione a sessão: ";
    cin >> opcao;
  switch (opcao){
    case 1:
      do{
      cout << "\nEscolhao horário:" << endl;
      cout << "[1]-> 15:00" << endl;
      cout << "[2]-> 17:20" << endl;
      cin >> escolha_hora;
    if(escolha_hora > 2 || escolha_hora <= 0){
      cout << "\nNÃ£o existe esse horário, tente novamente";
    }
  }while (escolha_hora > 2 || escolha_hora <= 0); 
      escolha_horario(escolha_hora, opcao); 
      break;
    case 2:
      do{
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
      cout << "\nEscolha o horário:" << endl;
      cout << "[1]-> 15:30" << endl;
      cout << "[2]-> 20:30" << endl;
      cin >> escolha_hora;
      }while (escolha_hora > 2 || escolha_hora <= 0); 
      escolha_horario(escolha_hora, opcao); 
      break;
    case 4:
      do{
      cout << "\nEscolhao horário:" << endl;
      cout << "[1]-> 20:15" << endl;
       cin >> escolha_hora;
    if(escolha_hora > 1 || escolha_hora <= 0){
      cout << "\nNï¿½o existe esse horário, tente novamente";
    }
    }while (escolha_hora > 2 || escolha_hora <= 0); 
      escolha_horario(escolha_hora, opcao); 
      break;
    default:
      cout << "\nSessão não existe, Tente novamente!";
      break;
    }
    
  }while (opcao > qtd_filme || opcao <= 0);
  cout << endl;
  
 
}

void escolha_horario(int escolha_hora, int opcao){
    setlocale(LC_ALL, "Portuguese_Brazil");
    cout << endl;
    cout << "\nSessão " << opcao << " selecionada" << "!" << endl;
    cout << "Sessão 1:" << endl;
    cout << "Filme: " << sessao1.filme.titulo << endl;
    
    if(escolha_hora == 1 && opcao == 1){
    cout << "Horário: " << "15:00"<< endl;
  }
    if(escolha_hora == 2 && opcao == 1){
    cout << "Horário: " << "17:20"<< endl;
  }
    if(escolha_hora == 1 && opcao == 2){
    cout << "Horário: " << "16:00"<< endl;
  }
    if(escolha_hora == 2 && opcao == 2){
    cout << "Horário: " << "18:30"<< endl;
  } 
    if(escolha_hora == 3 && opcao == 2){
    cout << "Horário: " << "21:00"<< endl;
  }
     if(escolha_hora == 1 && opcao == 3){
    cout << "Horário: " << "15:30"<< endl;
  }
    if(escolha_hora == 2 && opcao == 3){
    cout << "Horário: " << "20:00"<< endl;
  }
    if(escolha_hora == 1 && opcao == 4){
    cout << "Horário: " << "20:15"<< endl;
  }
    cout << "Sala: " << sessao1.sala << endl;
    cout << "Gênero: " << sessao1.filme.genero << endl;
    cout << "Classificação: " << filme1.classi << endl;
    
    
    
   
 
  
  

}    




