#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <locale.h>
using namespace std;

int selecionar_poltronas();
int escolher_tam_bc();

void sessao_escolha();
void sessao_filme();
void escolha_horario(int escolha_hora, int opcao);
void escolher_tipo_bc();
void sessao_1();
void sessao_2();
void sessao_3();
void sessao_4();
void polt_selecionada();
void mostrar_sala();
void loop_hora();
void nota_fiscal();
void finalizar_compra();

float escolha_tipo_comida(int escolha_comida);
float escolha_tipo_bebida(int escolha_bebida);
float compra_ing(int guarda_polt);
float soma_pipoca(int escolha_pipoca);
float soma_fandangos(int escolha_fand);
float soma_doritos(int escolha_doritos);
float soma_ruffles(int escolha_ruffles);
float soma_cheetos(int escolha_cheetos);
float soma_chocolate(int escolha_choc);

float soma_coca(int escolha_coca);
float soma_fanta_uva(int escolha_uva);
float soma_fanta_laran(int escolha_laran);
float soma_fanta_guara(int escolha_guara);

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
  string aperit;
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

Bebida bebida1 = {"[1]Coca-cola       237ml R$", 4};
Bebida bebida2 = {"[2]Coca-cola       350ml R$", 6};
Bebida bebida3 = {"[3]Coca-cola ZERO  350ml R$", 6.50};
Bebida bebida4 = {"[4]Coca-cola       600ml R$ ", 8};

Bebida bebida5 = {"[1]Fanta uva       237ml R$ ", 4};
Bebida bebida6 = {"[2]Fanta uva       350ml R$ ", 6};
Bebida bebida7 = {"[3]Fanta uva ZERO  350ml R$ ", 6.50};
Bebida bebida8 = {"[4]Fanta uva       600ml R$ ", 8};

Bebida bebida9 =  {"[1]Fanta laranja        237ml R$ ", 4};
Bebida bebida10 = {"[2]Fanta laranja        350ml R$ ", 6};
Bebida bebida11 = {"[3]Fanta laranja ZERO   350ml R$ ", 6.50};
Bebida bebida12 = {"[4]Fanta laranja        600ml R$", 8};

Bebida bebida13 = {"[1]Fanta guaraná        237ml R$ ", 4};
Bebida bebida14 = {"[2]Fanta guaraná        350ml R$ ", 6};
Bebida bebida15 = {"[3]Fanta guaraná ZERO   350ml R$ ", 6.50};
Bebida bebida16 = {"[4]Fanta guaraná        600ml R$ ", 8};

Comida comida1 = {"[1]Pipoca pequena R$ ", 10};
Comida comida2 = {"[2]Pipoca média   R$ ", 12.50};
Comida comida3 = {"[3]Pipoca grande  R$ ", 15.50};

Comida comida4 = {"[1]Fandangos 37g  R$ ", 4};
Comida comida5 = {"[2]Fandangos 45g  R$ ", 6};
Comida comida6 = {"[3]Fandangos 90g  R$ ", 9};
Comida comida7 = {"[4]Fangangos 140g R$ ", 12};

Comida comida8 =  {"[1]Doritos 37g   R$ ", 4};
Comida comida9 =  {"[2]Doritos 45g   R$ ", 6};
Comida comida10 = {"[3]Doritos 90g  R$ ", 9};
Comida comida11 = {"[4]Doritos 140g R$ ", 12};

Comida comida12 = {"[1]RufFles 37g  R$ ", 4.50};
Comida comida13 = {"[2]RufFles 45g  R$ ", 6};
Comida comida14 = {"[3]RufFles 90g  R$ ", 9};
Comida comida15 = {"[4]RufFles 140g R$ ", 15};

Comida comida16 = {"[1]Cheetos 37g  R$ ", 5};
Comida comida17 = {"[2]Cheetos 45g  R$ ", 6};
Comida comida18 = {"[3]Cheetos 90g  R$ ", 9};
Comida comida19 = {"[4]Cheetos 140g R$ ", 15};

Comida comida20 = {"[1]Chocolate Garoto Castanha de Caju 90g R$ ", 7.50};
Comida comida21 = {"[2]Chocalate Garoto Negresco 90g         R$ ", 7.50};
Comida comida22 = {"[3]Chocolate Garoto Crocante 90g         R$ ", 7.50};
Comida comida23 = {"[4]Chocalate Garoto ao Leite 90g         R$ ", 7.50};

// váriaveis de ingressos
int escolha, sessao, fin_compra;
int i, qtd_ingresso[2], loop_menu;
int ingresso_poltrona = 0, guarda_ingresso = 0, compra_ingresso = 0, mostra_ing = 0;
char sele_ingresso;
float ing_int, ing_meia, total_ingresso, guarda_sessao = 0;

// variaveis de escolha de sessao e filme
int qtd_filme = 4;
char sele_sessao;
int opcao = 0, escolha_hora = 0;
string cadeiras1[10][5], cadeiras2[12][6], cadeiras3[10][6], cadeiras4[12][6];

// variáveis de escolha comidas e bebidas;
int escolha_bebida = 0, escolha_comida = 0, escolha_coca = 0, escolha_uva = 0, escolha_laran, escolha_guara = 0;
int escolha_pipoca = 0, escolha_fand = 0, escolha_dori = 0, escolha_ruffles = 0, escolha_cheetos = 0, escolha_choc = 0;
int guarda_pipoca = 0, guarda_fand = 0, guarda_dori = 0, guarda_ruffles = 0, guarda_cheetos = 0, guarda_choc = 0;
int loop_tela = 0, guarda_coca = 0, guarda_uva = 0, guarda_laran = 0, guarda_guara = 0;
char sele_bebida, sele_comida;
float total_bc = 0, soma_comida = 0, guarda_comida = 0, soma_bebida = 0, guarda_bebida = 0;

// variáveis de finalizar compra
float dinheiro = 0, troco = 0, total_final = 0;

// variaveis pra sessao filme
int loop_sessao = 0;

int main(){
  int escolha_sessao;

  while (loop_menu == 0){
   //system("cls");
    cout << "----------------------------------------------";
    cout << "\nBem vindo ao nosso cinema!";
    cout << "\n----------------------------------------------";
    cout << endl;
    sessao_filme();
    sele_sessao = 't';
    while (sele_sessao != 'N' && sele_sessao != 'n' && sele_sessao != 's' && sele_sessao != 'S'){
      cout << "                                                SELECIONAR SESSÂO ->";
      cout << "\nSe deseja selecionar alguma sessão";
      cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
      cin >> sele_sessao;
      if (sele_sessao == 'S' || sele_sessao == 's'){
        sessao_escolha();
        //system("cls");
        mostrar_sala();
      }
    }
    //system("cls");
    escolher_tipo_bc();
    if(total_final > 0){
      finalizar_compra();
    }
    loop_menu = 0;
  }
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
  cout << "Gênero: " << sessao1.filme.genero << endl;
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
  cout << "Sessão 4" << endl;
  cout << "Filme: " << sessao4.filme.titulo << endl;
  cout << "Horários: " << sessao4.horario << endl;
  cout << "Sala: " << sessao4.sala << endl;
  cout << "Gênero: " << sessao4.filme.genero << endl;
  cout << "Classificação: " << filme1.classi << endl;
  cout << "----------------------------------------------" << endl;
}
void sessao_escolha(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  escolha_hora = 0;
  opcao = 5;

  while (opcao > qtd_filme || opcao < 0){
    cout << "\nSelecione a sessão: ";
    cin >> opcao;
    switch (opcao){
    case 1:
      while (escolha_hora > 2 || escolha_hora <= 0){
        cout << "\nEscolha o horário:" << endl;
        cout << "[1]-> 15:00" << endl;
        cout << "[2]-> 17:20" << endl;
        cin >> escolha_hora;
        if (escolha_hora > 2 || escolha_hora <= 0){
          cout << "\nNão existe esse horário, tente novamente" << endl;
        }
      }
      escolha_horario(escolha_hora, opcao);
      //system("cls");
      break;
    case 2:
      while (escolha_hora > 3 || escolha_hora <= 0){
        cout << "\nEscolha o horário:" << endl;
        cout << "[1]-> 16:00" << endl;
        cout << "[2]-> 18:30" << endl;
        cout << "[3]-> 21:00" << endl;
        cin >> escolha_hora;
      }
      escolha_horario(escolha_hora, opcao);
      //system("cls");
      break;
    case 3:
      while (escolha_hora > 2 || escolha_hora <= 0){
        cout << "\nEscolha o horário:" << endl;
        cout << "[1]-> 15:30" << endl;
        cout << "[2]-> 20:30" << endl;
        cin >> escolha_hora;
      }
      escolha_horario(escolha_hora, opcao);
      //system("cls");
      break;
    case 4:
      while (escolha_hora > 2 || escolha_hora <= 0){
        cout << "\nEscolha o horário:" << endl;
        cout << "[1]-> 20:15" << endl;
        cin >> escolha_hora;
        if (escolha_hora > 1 || escolha_hora <= 0){
          cout << "\nNão existe esse horário, tente novamente";
        }
      }
      escolha_horario(escolha_hora, opcao);
      //system("cls");
      break;
    default:
      cout << "\nSessão não existe, Tente novamente!";
      break;
    }
    loop_sessao = 0;
  }
}
void escolha_horario(int escolha_hora, int opcao){
  setlocale(LC_ALL, "Portuguese_Brazil");
  //system("cls");
  //  Horário selecionado da opcao 1
  if (escolha_hora == 1 && opcao == 1 || escolha_hora == 2 && opcao == 1){
    cout << "\nSessão " << opcao << ":" << " SELECIONADA" << "!" << endl;
    cout << "Filme: " << sessao1.filme.titulo << endl;
    if (escolha_hora == 1 && opcao == 1){
      cout << "Horário: " << "15:00" << endl;
    }
    if (escolha_hora == 2 && opcao == 1){
      cout << "Horário: " << "17:20" << endl;
    }
    cout << "Sala: " << sessao1.sala << endl;
    cout << "Gênero: " << sessao1.filme.genero << endl;
    cout << "Classificação: " << filme1.classi << endl;
  }
  // Horário selecionado da opcao 2
  if (escolha_hora == 1 && opcao == 2 || escolha_hora == 2 && opcao == 2 || escolha_hora == 3 && opcao == 2){
    cout << "\nSessão " << opcao << ":" << " SELECIONADA" << "!" << endl;
    cout << "Filme: " << sessao2.filme.titulo << endl;
    if (escolha_hora == 1 && opcao == 2){
      cout << "Horário: " << "16:00" << endl;
    }
    if (escolha_hora == 2 && opcao == 2){
      cout << "Horário: " << "18:30" << endl;
    }
    if (escolha_hora == 3 && opcao == 2){
      cout << "Horário: " << "21:00" << endl;
    }
    cout << "Sala: " << sessao2.sala << endl;
    cout << "Gênero: " << sessao2.filme.genero << endl;
    cout << "Classificação: " << filme3.classi << endl;
  }
  // Horário selecionado da opcao 3
  if (escolha_hora == 1 && opcao == 3 || escolha_hora == 2 && opcao == 3){
    cout << "\nSessão " << opcao << ":" << " SELECIONADA" << "!" << endl;
    cout << "Filme: " << sessao3.filme.titulo << endl;
    if (escolha_hora == 1 && opcao == 3){
      cout << "Horário: "
           << "15:30" << endl;
    }
    if (escolha_hora == 2 && opcao == 3){
      cout << "Horário: " << "20:30" << endl;
    }
    cout << "Sala: " << sessao3.sala << endl;
    cout << "Gênero: " << sessao3.filme.genero << endl;
    cout << "Classificação: " << filme2.classi << endl;
  }
  // Horário selecionado da opcao 4
  if (escolha_hora == 1 && opcao == 4){
    cout << "\nSessão " << opcao << ":" << " SELECIONADA" << "!" << endl;
    cout << "Filme: " << sessao4.filme.titulo << endl;
    cout << "Horário: " << "20:15" << endl;
    cout << "Sala: " << sessao4.sala << endl;
    cout << "Gênero: " << sessao4.filme.genero << endl;
    cout << "Classificação: " << filme1.classi << endl;
  }
}

void mostrar_sala(){
  if (opcao == 1 && escolha_hora == 1){
    escolha_horario(escolha_hora, opcao);
    sessao_1();
  }
  if (opcao == 1 && escolha_hora == 2){
    escolha_horario(escolha_hora, opcao);
    sessao_1();
  }
  if (opcao == 2 && escolha_hora == 1){
    escolha_horario(escolha_hora, opcao);
    sessao_2();
  }
  if (opcao == 2 && escolha_hora == 2){
    escolha_horario(escolha_hora, opcao);
    sessao_2();
  }
  if (opcao == 2 && escolha_hora == 3){
    escolha_horario(escolha_hora, opcao);
    sessao_2();
  }
  if (opcao == 3 && escolha_hora == 1){
    escolha_horario(escolha_hora, opcao);
    sessao_3();
  }
  if (opcao == 3 && escolha_hora == 2){
    escolha_horario(escolha_hora, opcao);
    sessao_3();
  }
  if (opcao == 4 && escolha_hora == 1){
    escolha_horario(escolha_hora, opcao);
    sessao_4();
  }
}
void sessao_1(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int escolha1, escolha2;
  char reserva_polt, guarda_polt;
  int i, j;
  reserva_polt = 's', 'S';
  guarda_polt = 0;
  escolha1 = 0;
  escolha2 = 0;
  i = 0;
  j = 0;
  cout << endl;
  
  if(guarda_sessao > 0){
  for (i = 0; i < 10; i++){
      for (j = 0; j < 5; j++){
        if (cadeiras1[i][j] == "[//]"){
          cadeiras1[i][j] = "[--]";
        }
      }
    }
  }
  guarda_sessao = 0;
  for (i = 0; i < 10; i++){
    for (j = 0; j < 5; j++){
      if (cadeiras1[i][j] == "[--]"){
        cout << "[--] ";
      }
      else{
        cout << "[" << i << j << "] ";
      }
    }
    cout << endl;
  }
  cout << endl;
  cout << endl;
  cout << "\n         TELA";
  cout << "\n--------------------------";
  cout << endl;
  cout << "\n[ ] Disponivel      [B]Bloqueado";
  cout << "\n[/] Selecionado     [C]Cadeirante";
  cout << "\n[-] Ocupados";       
  
 
  cout << endl;

  if (loop_sessao == 0){
    loop_hora();
  }
  if (loop_sessao == 1){
    while (reserva_polt == 's' || reserva_polt == 'S'){
      do{
        do{
          cout << "\nSelecionar assentos: ";
          cin >> escolha1 >> escolha2;
          //system("cls");
          cout << endl;
          for (i = 0; i < 10; i++){
            for (j = 0; j < 5; j++){
              if (cadeiras1[i][j] == "[//]" || cadeiras1[i][j] == "[--]"){
                if (cadeiras1[i][j] == "[//]"){
                  cout << "[//] ";
                }
                if (cadeiras1[i][j] == "[--]"){
                  cout << "[--] ";
                }
              }
              else{
                cout << "[" << i << j << "] ";
              }
            }
            cout << endl;
          }
          cout << endl;
          cout << endl;
          cout << "\n          TELA";
          cout << "\n--------------------------";
          cout << "\n[ ] Disponivel";
          cout << "\n[/] Selecionado";
          cout << "\n[-] Ocupados";
          cout << "\n[B] Bloqueado";
          cout << "\n[C] Cadeirante";
          cout << endl;
          if (escolha1 > 9 || escolha2 > 4){
            cout << "\nNão existe, Tente novamente!";
            cout << endl;
          }
        } while (escolha1 > 9 || escolha2 > 4);
        if (cadeiras1[escolha1][escolha2] == "[--]"){
          cout << "\nEstá ocupado!";
          cout << endl;
        }
      } while (cadeiras1[escolha1][escolha2] == "[--]");
      if (cadeiras1[escolha1][escolha2] == "[//]"){
        cadeiras1[escolha1][escolha2] = "[ ]";
      }
      else{
        cadeiras1[escolha1][escolha2] = "[//]";
      }
      if (cadeiras1[escolha1][escolha2] != "[--]" && cadeiras1[escolha1][escolha2] != "[ ]"){
        cadeiras1[escolha1][escolha2] = "[//]";
      }
      //system("cls");
      for (i = 0; i < 10; i++){
        for (j = 0; j < 5; j++){
          if (cadeiras1[i][j] == "[//]" || cadeiras1[i][j] == "[--]"){
            if (cadeiras1[i][j] == "[//]"){
              cout << "[//] ";
            }
            if (cadeiras1[i][j] == "[--]"){
              cout << "[--] ";
            }
          }
          else{
            cout << "[" << i << j << "] ";
          }
        }
        cout << endl;
      }
        cout << endl;
        cout << endl;
        cout << "\n          TELA";
        cout << "\n--------------------------";
        cout << endl;
        cout << "\n[ ] Disponivel      [B]Bloqueado";
        cout << "\n[/] Selecionado     [C]Cadeirante";
        cout << "\n[-] Ocupados";       
        cout << endl;
        
      cout << "\nAssentos selecionados: ";
      for (i = 0; i < 10; i++){
        for (j = 0; j < 5; j++){
          if (cadeiras1[i][j] == "[//]"){
            cout << i << j << ", ";
          }
        }
      }
      cout << endl;
      reserva_polt = 't';
      while (reserva_polt != 'S' && reserva_polt != 's' && reserva_polt != 'n' && reserva_polt != 'N'){
        cout << endl;
        cout << "\nSe deseja selecionar mais";
        cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
        cin >> reserva_polt;
      }
    }
  }
  cout << endl;
  //system("cls");
  if (reserva_polt == 'n' || reserva_polt == 'N'){
    for (i = 0; i < 10; i++){
      for (j = 0; j < 5; j++){
        if (cadeiras1[i][j] == "[//]"){
          guarda_polt++;
        }
      }
    }
    polt_selecionada();
    if (guarda_polt > 0){
      compra_ing(guarda_polt);
    }
    else{
      cout << "\nNenhum assento foi selecionado!" << endl;
    }
    cout << endl;
    // system("cls");
  }
}
void sessao_2(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int escolha1, escolha2;
  char reserva_polt, guarda_polt;
  int i, j;
  reserva_polt = 's','S';
  guarda_polt = 0;
  escolha1 = 0;
  escolha2 = 0;
  i = 0;
  j = 0;
  cout << endl;
  
  if(guarda_sessao > 0){
  for (i = 0; i < 10; i++){
      for (j = 0; j < 5; j++){
        if (cadeiras1[i][j] == "[//]"){
          cadeiras1[i][j] = "[--]";
        }
      }
    }
  }
  guarda_sessao = 0;
  for (i = 0; i < 12; i++){
    for (j = 0; j < 6; j++){
      if (cadeiras2[i][j] == "[--]"){
        cout << "[--] ";
      }
      else{
        cout << "[" << i << j << "] ";
      }
    }
    cout << endl;
  }
  cout << endl;
  cout << "\n                 TELA";
  cout << "\n-----------------------------------------";
  cout << endl;
  cout << "\n[ ] Disponivel      [B]Bloqueado";
  cout << "\n[/] Selecionado     [C]Cadeirante";
  cout << "\n[-] Ocupados";       
  cout << endl;
  if (loop_sessao == 0){
    loop_hora();
  }
  if (loop_sessao == 1){
    while (reserva_polt == 's' || reserva_polt == 'S'){
      do{
        do{
          cout << "\nSelecionar assentos: ";
          cin >> escolha1 >> escolha2;
          //system("cls");
          if (cadeiras2[escolha1][escolha2] == "[--]"){
            cout << "\nEstá ocupado!" << endl;
          }
          for (i = 0; i < 12; i++){
            for (j = 0; j < 6; j++){
              if (cadeiras2[i][j] == "[//]" || cadeiras2[i][j] == "[--]"){
                if (cadeiras2[i][j] == "[//]"){
                  cout << "[//] ";
                }
                if (cadeiras2[i][j] == "[--]"){
                  cout << "[--] ";
                }
              }
              else{
                cout << "[" << i << j << "] ";
              }
            }
            cout << endl;
          }
          cout << endl;
          cout << "\n               TELA";
          cout << "\n-----------------------------------------";
          cout << endl;
          cout << "\n[ ] Disponivel      [B]Bloqueado";
          cout << "\n[/] Selecionado     [C]Cadeirante";
          cout << "\n[-] Ocupados";       
          cout << endl;
          if (escolha1 > 11 || escolha2 > 5){
            cout << "\nNão existe, Tente novamente!";
            cout << endl;
          }
        } while (escolha1 > 11 || escolha2 > 5);
      } while (cadeiras2[escolha1][escolha2] == "[--]");
      if (cadeiras2[escolha1][escolha2] == "[//]"){
        cadeiras2[escolha1][escolha2] = "[ ]";
      }
      else{
        cadeiras2[escolha1][escolha2] = "[//]";
      }
      if (cadeiras2[escolha1][escolha2] != "[--]" && cadeiras2[escolha1][escolha2] != "[ ]"){
        cadeiras2[escolha1][escolha2] = "[//]";
      }
      //system("cls");
      for (i = 0; i < 12; i++){
        for (j = 0; j < 6; j++){
          if (cadeiras2[i][j] == "[//]" || cadeiras2[i][j] == "[--]"){
            if (cadeiras2[i][j] == "[//]"){
              cout << "[//] ";
            }
            if (cadeiras2[i][j] == "[--]"){
              cout << "[--] ";
            }
          }
          else{
            cout << "[" << i << j << "] ";
          }
        }
        cout << endl;
      }
          cout << endl;
          cout << "\n               TELA";
          cout << "\n-----------------------------------------";
          cout << endl;
          cout << "\n[ ] Disponivel      [B]Bloqueado";
          cout << "\n[/] Selecionado     [C]Cadeirante";
          cout << "\n[-] Ocupados";       
          cout << endl;
      
      cout << "\nAssentos selecionados: ";
      for (i = 0; i < 12; i++){
        for (j = 0; j < 6; j++){
          if (cadeiras2[i][j] == "[//]"){
            cout << i << j << ", ";
          }
        }
      }
      reserva_polt = 't';
      while (reserva_polt != 'S' && reserva_polt != 's' && reserva_polt != 'n' && reserva_polt != 'N'){
        cout << endl;
        cout << "\nSe deseja selecionar mais";
        cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
        cin >> reserva_polt;
      }
    }
  }
  cout << endl;

  //system("cls");
  if (reserva_polt == 'n' || reserva_polt == 'N'){
    for (i = 0; i < 10; i++){
      for (j = 0; j < 5; j++){
        if (cadeiras2[i][j] == "[//]"){
          guarda_polt++;
        }
      }
    }
    polt_selecionada();
    if (guarda_polt > 0){
      compra_ing(guarda_polt);
    }
    else{
      cout << "\nNenhum assento foi selecionado!" << endl;
    }
    if(total_ingresso > 0){
      for (i = 0; i < 10; i++){
        for (j = 0; j < 5; j++){
          if (cadeiras2[i][j] == "[//]"){
            cadeiras2[i][j] = "[--]";
          }
        }
      }
    }
  }
}
void sessao_3(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int escolha1, escolha2;
  char reserva_polt, guarda_polt;
  int i, j;

  reserva_polt = 's', 'S';
  guarda_polt = 0;
  escolha1 = 0;
  escolha2 = 0;
  i = 0;
  j = 0;
  cout << endl;
  
  if(guarda_sessao > 0){
  for (i = 0; i < 10; i++){
      for (j = 0; j < 5; j++){
        if (cadeiras1[i][j] == "[//]"){
          cadeiras1[i][j] = "[--]";
        }
      }
    }
  }
  guarda_sessao = 0;
  for (i = 0; i < 10; i++){
    for (j = 0; j < 6; j++){
      if (cadeiras3[i][j] == "[--]"){
        cout << "[--] ";
      }
      else{
        cout << "[" << i << j << "] ";
      }
    }
    cout << endl;
  }
  cout << endl;
  cout << "\n            TELA";
  cout << "\n-----------------------------";
  cout << endl;
  cout << "\n[ ] Disponivel      [B]Bloqueado";
  cout << "\n[/] Selecionado     [C]Cadeirante";
  cout << "\n[-] Ocupados";       
  cout << endl;

  if (loop_sessao == 0){
    loop_hora();
  }
  if (loop_sessao == 1){
    while (reserva_polt == 's' || reserva_polt == 'S'){
      do{
        do{
          cout << "\nSelecionar assentos: ";
          cin >> escolha1 >> escolha2;
          //system("cls");
          cout << endl;
          for (i = 0; i < 10; i++){
            for (j = 0; j < 6; j++){
              if (cadeiras3[i][j] == "[//]" || cadeiras3[i][j] == "[--]"){
                if (cadeiras3[i][j] == "[//]"){
                  cout << "[//] ";
                }
                if (cadeiras3[i][j] == "[--]"){
                  cout << "[--] ";
                }
              }
              else{
                cout << "[" << i << j << "] ";
              }
            }
            cout << endl;
          }
          cout << "\n         TELA";
          cout << "\n--------------------------";
          cout << endl;
          cout << "\n[ ] Disponivel      [B]Bloqueado";
          cout << "\n[/] Selecionado     [C]Cadeirante";
          cout << "\n[-] Ocupados";       
          cout << endl;
          if (escolha1 > 9 || escolha2 > 5){
            cout << "\nNão existe, Tente novamente!";
            cout << endl;
          }
        } while (escolha1 > 9 || escolha2 > 5);
        if (cadeiras3[escolha1][escolha2] == "[--]"){
          cout << "\nEstá ocupado!";
          cout << endl;
        }
      } while (cadeiras3[escolha1][escolha2] == "[--]");
      if (cadeiras3[escolha1][escolha2] == "[//]"){
        cadeiras3[escolha1][escolha2] = "[ ]";
      }
      else{
        cadeiras3[escolha1][escolha2] = "[//]";
      }
      if (cadeiras3[escolha1][escolha2] != "[--]" && cadeiras3[escolha1][escolha2] != "[ ]"){
        cadeiras3[escolha1][escolha2] = "[//]";
      }

      //system("cls");
      for (i = 0; i < 10; i++){
        for (j = 0; j < 6; j++){
          if (cadeiras3[i][j] == "[//]" || cadeiras3[i][j] == "[--]"){
            if (cadeiras3[i][j] == "[//]"){
              cout << "[//] ";
            }
            if (cadeiras3[i][j] == "[--]"){
              cout << "[--] ";
            }
          }
          else{
            cout << "[" << i << j << "] ";
          }
        }
        cout << endl;
      }
        cout << endl;
        cout << "\n                  TELA";
        cout << "\n-----------------------------------------";
        cout << endl;
        cout << "\n[ ] Disponivel      [B]Bloqueado";
        cout << "\n[/] Selecionado     [C]Cadeirante";
        cout << "\n[-] Ocupados";       
        cout << endl;
      
      cout << "\nAssentos selecionados: ";
      for (i = 0; i < 10; i++){
        for (j = 0; j < 6; j++){
          if (cadeiras3[i][j] == "[//]"){
            cout << i << j << ", ";
          }
        }
      }
      cout << endl;
      reserva_polt = 't';
      while (reserva_polt != 'S' && reserva_polt != 's' && reserva_polt != 'n' && reserva_polt != 'N'){
        cout << endl;
        cout << "\nSe deseja selecionar mais";
        cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
        cin >> reserva_polt;
      }
    }
  }
  cout << endl;
  //system("cls");
  if (reserva_polt == 'n' || reserva_polt == 'N'){
    for (i = 0; i < 10; i++){
      for (j = 0; j < 5; j++){
        if (cadeiras3[i][j] == "[//]"){
          guarda_polt++;
        }
      }
    }
    polt_selecionada();
    if (guarda_polt > 0){
      compra_ing(guarda_polt);
    }
    else{
      cout << "\nNenhum assento foi selecionado!" << endl;
    }
    if(total_ingresso > 0){
      for (i = 0; i < 10; i++){
        for (j = 0; j < 5; j++){
          if (cadeiras3[i][j] == "[//]"){
            cadeiras3[i][j] = "[--]";
          }
        }
      }
    }
  }
}
void sessao_4(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int escolha1, escolha2;
  char reserva_polt, guarda_polt;
  int i, j;

  reserva_polt = 's', 'S';
  guarda_polt = 0;
  escolha1 = 0;
  escolha2 = 0;
  i = 0;
  j = 0;
  cout << endl;
  for (i = 0; i < 12; i++){
    for (j = 0; j < 6; j++){
      if (cadeiras4[i][j] == "[--]"){
        cout << "[--] ";
      }
      else{
        cout << "[" << i << j << "] ";
      }
    }
    cout << endl;
  }
  cout << endl;
  cout << "\n             TELA";
  cout << "\n---------------------------------";
  cout << endl;
  cout << "\n[ ] Disponivel      [B]Bloqueado";
  cout << "\n[/] Selecionado     [C]Cadeirante";
  cout << "\n[-] Ocupados";       
  cout << endl;

  if (loop_sessao == 0){
    loop_hora();
  }
  if (loop_sessao == 1){
    while (reserva_polt == 's' || reserva_polt == 'S'){
      do{
        do{
          cout << "\nSelecionar assentos: ";
          cin >> escolha1 >> escolha2;
          //system("cls");
          if (cadeiras4[escolha1][escolha2] == "[--]"){
            cout << "\nEstá ocupado!" << endl;
          }
          for (i = 0; i < 12; i++){
            for (j = 0; j < 6; j++){
              if (cadeiras4[i][j] == "[//]" || cadeiras4[i][j] == "[--]"){
                if (cadeiras4[i][j] == "[//]"){
                  cout << "[//] ";
                }
                if (cadeiras4[i][j] == "[--]"){
                  cout << "[--] ";
                }
              }
              else{
                cout << "[" << i << j << "] ";
              }
            }
            cout << endl;
          }
          cout << endl;
          cout << "\n             TELA";
          cout << "\n---------------------------------";
          cout << endl;
          cout << "\n[ ] Disponivel      [B]Bloqueado";
          cout << "\n[/] Selecionado     [C]Cadeirante";
          cout << "\n[-] Ocupados";       
          cout << endl;

          if (escolha1 > 11 || escolha2 > 5){
            cout << "\nNão existe, Tente novamente!";
            cout << endl;
          }
        } while (escolha1 > 11 || escolha2 > 5);
      } while (cadeiras4[escolha1][escolha2] == "[--]");
      if (cadeiras4[escolha1][escolha2] == "[//]"){
        cadeiras4[escolha1][escolha2] = "[ ]";
      }
      else{
        cadeiras4[escolha1][escolha2] = "[//]";
      }
      if (cadeiras4[escolha1][escolha2] != "[--]" && cadeiras4[escolha1][escolha2] != "[ ]"){
        cadeiras4[escolha1][escolha2] = "[//]";
      }
      //system("cls");
      for (i = 0; i < 12; i++){
        for (j = 0; j < 6; j++){
          if (cadeiras4[i][j] == "[//]" || cadeiras4[i][j] == "[--]"){
            if (cadeiras4[i][j] == "[//]"){
              cout << "[//] ";
            }
            if (cadeiras4[i][j] == "[--]"){
              cout << "[--] ";
            }
          }
          else{
            cout << "[" << i << j << "] ";
          }
        }
        cout << endl;
      }
        cout << endl;
        cout << endl;
        cout << "\n             TELA";
        cout << "\n---------------------------------";
        cout << endl;
        cout << "\n[ ] Disponivel      [B]Bloqueado";
        cout << "\n[/] Selecionado     [C]Cadeirante";
        cout << "\n[-] Ocupados";       
        cout << endl;
     
      cout << "\nAssentos selecionados: ";
      for (i = 0; i < 12; i++){
        for (j = 0; j < 6; j++){
          if (cadeiras4[i][j] == "[//]"){
            cout << i << j << ", ";
          }
        }
      }
      reserva_polt = 't';
      while (reserva_polt != 'S' && reserva_polt != 's' && reserva_polt != 'n' && reserva_polt != 'N'){
        cout << endl;
        cout << "\nSe deseja selecionar mais";
        cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
        cin >> reserva_polt;
      }
    }
  }
  cout << endl;
  //system("cls");
  if (reserva_polt == 'n' || reserva_polt == 'N'){
    for (i = 0; i < 10; i++){
      for (j = 0; j < 5; j++){
        if (cadeiras4[i][j] == "[//]"){
            guarda_polt++;
        }
      }
    }
    
    polt_selecionada();
    
    if (guarda_polt > 0){
      compra_ing(guarda_polt);
    }
    else{
      cout << "\nNenhum assento foi selecionado!" << endl;
    }
    if(total_ingresso > 0){
      for (i = 0; i < 10; i++){
        for (j = 0; j < 5; j++){
          if (cadeiras4[i][j] == "[//]"){
            cadeiras4[i][j] = "[--]";
          }
        }
      }
    }
  }
}

void loop_hora(){
  loop_sessao = 2;
  while (loop_sessao != 1 && loop_sessao != 0){
    cout << endl;
    cout << "\n      SESSÂO FILME                SELECIONAR POLTRONAS";
    cout << "\n <- Digite 0 para voltar <-   ->Digite 1 para prosseguir->  ";
    cout << endl << "                            ";
    cin >> loop_sessao;
  }
  if (loop_sessao == 0){
    sessao_filme();
    sessao_escolha();
    mostrar_sala();
    escolher_tipo_bc();
    //system("cls");
    main();
  }
}

void polt_selecionada(){
setlocale(LC_ALL, "Portuguese_Brazil");
int i, j;
i = 0;
j = 0;     

cout << "\nAssentos selecionados: ";
  // assentos selecionados da sessao 1
  for (i = 0; i < 10; i++){
    for (j = 0; j < 5; j++){
     if (cadeiras1[i][j] == "[//]"){
        cout << i << j << ", ";
      }
    }
  }
  // assentos selecionados da sessao 2
  for (i = 0; i < 12; i++){
    for (j = 0; j < 6; j++){
      if (cadeiras2[i][j] == "[//]"){
        cout << i << j << ", ";
      }
    }
  }
  // assentos selecionados da sessao 3
  for (i = 0; i < 10; i++){
    for (j = 0; j < 6; j++){
      if (cadeiras3[i][j] == "[//]"){
       cout << i << j << ", ";
      }
    }
  }   
  // assentos selecionados da sessao 4
  for (i = 0; i < 12; i++){
    for (j = 0; j < 6; j++){
      if (cadeiras4[i][j] == "[//]"){
        cout << i << j << ", ";
      }
    }
  }  
}

float compra_ing(int guarda_polt){
  setlocale(LC_ALL, "Portuguese_Brazil");
  ing_int = 30;
  ing_meia = 15;
  mostra_ing = 0;
  guarda_ingresso = 0;
  total_ingresso = 0;
  sele_ingresso = 't';
  loop_tela = 0; 
  for(i = 0; i < 2; i++){
    qtd_ingresso[i] = 0;
  }
  while (sele_ingresso != 's' && sele_ingresso != 'S' && sele_ingresso != 'n' && sele_ingresso != 'N'){
    cout << endl;
    cout << "\n[1]Ingresso inteiro R$" << ing_int;
    cout << "\n[2]Ingresso meio R$" << ing_meia;
    cout << endl;
    cout << "\nSe deseja selecionar algum ingresso";
    cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
    cin >> sele_ingresso;
    //system("cls");
  }
  if (sele_ingresso == 's' || sele_ingresso == 'S'){
    while (loop_tela == 0){
      //system("cls");
      do{
        polt_selecionada();
        cout << endl;
        cout << "\n[1]Ingresso inteiro R$" << ing_int;
        cout << "\n[2]Ingresso meio R$" << ing_meia;
        cout << endl;
        cout << "\nSelecione o numero: ";
        cin >> compra_ingresso;
        cout << endl;
      while (compra_ingresso > 2 || compra_ingresso <= 0){
          //system("cls");
          cout << endl;
          cout << "\n[1]Ingresso inteiro R$" << ing_int;
          cout << "\n[2]Ingresso meio R$" << ing_meia;
          cout << endl;
          cout << "\nSelecione o numero: ";
          cin >> compra_ingresso;
          cout << endl;
        }
        if (compra_ingresso == 1){
          cout << "\n[" << mostra_ing << "]Qtd ";
          cout << "\nQuantidade de ingresso(inteiro):  ";
          cin >> guarda_ingresso;
          //system("cls");
          while (guarda_ingresso < 0){
            if (guarda_ingresso < 0){
              cout << "\nQuantidade inválida!";
            }
            cout << "\n[" << mostra_ing << "]Qtd ";
            cout << "\nQuantidade de ingresso(inteiro):  ";
            cin >> guarda_ingresso;
          }
          mostra_ing = mostra_ing + guarda_ingresso;
          if (mostra_ing > guarda_polt || mostra_ing == 0 || mostra_ing < 0){
            mostra_ing = 0;
            guarda_ingresso = 0;
            guarda_ingresso = 0;
            cout << "\nErro, foram " << guarda_polt << " assentos selecionados!" << endl;
          }
          guarda_ingresso = guarda_ingresso * ing_int;
          qtd_ingresso[0] = qtd_ingresso[0] + guarda_ingresso;
        }
        if (compra_ingresso == 2){
          cout << "\n[" << mostra_ing << "]Qtd ";
          cout << "\nQuantidade de ingresso(meia):  ";
          cin >> guarda_ingresso;
          //system("cls");
          while (guarda_ingresso < 0){
            if (guarda_ingresso < 0){
              cout << "\nQuantida inválida!";
            }
            cout << "\n[" << mostra_ing << "]Qtd ";
            cout << "\nQuantidade de ingresso(meia):  ";
            cin >> guarda_ingresso;
          }
          mostra_ing = mostra_ing + guarda_ingresso;
          if (mostra_ing > guarda_polt || mostra_ing == 0 || mostra_ing < 0){
            mostra_ing = 0;
            guarda_ingresso = 0;
            guarda_ingresso = 0;
            cout << "\nErro, foram " << guarda_polt << " assentos selecionados!" << endl;
          }
          guarda_ingresso = guarda_ingresso * ing_meia;
          qtd_ingresso[1] = qtd_ingresso[1] + guarda_ingresso;
        }
        if (mostra_ing == guarda_polt){
          cout << "\nAtenção! É necessário comprovar este ingresso para entrar na sessão.";
        }
      } while (mostra_ing < guarda_polt || mostra_ing > guarda_polt || mostra_ing == 0);
      if (mostra_ing < guarda_polt || mostra_ing == 0){
        cout << "\nErro, foram " << guarda_polt << " assentos selecionados!";
      }
      loop_tela = 2;
      while (loop_tela != 0 && loop_tela != 1){
        cout << endl;
        cout << "\n     TROCAR INGRESSOS                COMIDAS E BEBIDAS";
        cout << "\n <- Digite 0 para voltar <-   -> Digite 1 para proseguir ->  ";
        cout << endl << "                            ";
        cin >> loop_tela;
      }
      if (loop_tela == 0){
        mostra_ing = 0;
        guarda_ingresso = 0;
        qtd_ingresso[0] = 0;
        qtd_ingresso[1] = 0;
      }
    }
  }
    for(i = 0; i < 2; i++){
      total_ingresso = total_ingresso + qtd_ingresso[i];
    }
  cout << "\nTOTAL R$: " << total_ingresso;
  guarda_sessao = guarda_sessao + total_ingresso;
  
  return 0;
}

void finalizar_compra(){
setlocale(LC_ALL, "Portuguese_Brazil");
float total2, dinheiro2;
dinheiro = 0;
troco = 0;
total2 = 0;
dinheiro2 = 0;
total2 = total_final;
dinheiro2 = dinheiro; 

cout << endl;
  if(total_final > 0){
    cout << "\nTotal da compra R$: " <<  total_final;
    dinheiro = -1;
  while(dinheiro < 0){
    cout << "\nDinheiro recebido: ";
    cin >> dinheiro;
    if(dinheiro < 0){
    cout << "\nValor inválido!" << endl;
  }
}
  troco = dinheiro - total_final;
  if(troco < 0){
    while (troco < 0){
    cout << "\nDinheiro insuficiente. Faltam R$" << troco * (-1) << " REAIS" <<endl;
    total2 = troco * (-1); 
    cout << endl;
    cout << "\nQuanto sera o pagamento: ";
    cin >> dinheiro2;
    if(dinheiro2 < 0){
      cout << "\nValor inválido!" << endl;
      dinheiro2 = 0;
    }
    troco = dinheiro2 - total2;
    dinheiro = dinheiro + dinheiro2; 
    }
  }
  nota_fiscal();
  }
}

void nota_fiscal(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  
  if(total_ingresso > 0){
    escolha_horario(escolha_hora, opcao);
    polt_selecionada();
  }
  if(total_final > 0){
  cout << endl;
  cout << "\nTOTAL DA COMPRA...............................................R$ " << total_final;
  cout << "\nDINHEIRO RECEBIDO.............................................R$ " << dinheiro;
  cout << "\nTROCO.........................................................R$ " << troco;
  cout << endl;
  cout << "\nCOMPRA FINALIZADA, VOLTE SEMPRE!";
  cout << endl;
  }
}

float escolha_tipo_comida(int escolha_comida){
  setlocale(LC_ALL, "Portuguese_Brazil");
  float total_comida, total[6];
  int i;
  i = 0;
  total_comida = 0;
  for (i = 0; i < 6; i++){
    total[i] = 0;
  }
  switch (escolha_comida){
  case 1:
    cout << comida1.aperit << comida1.preco << endl;
    cout << comida2.aperit << comida2.preco << endl;
    cout << comida3.aperit << comida3.preco << endl;
    escolha_pipoca = escolher_tam_bc();
    total[0] = soma_pipoca(escolha_pipoca);
    break;
  case 2:
    cout << comida4.aperit << comida4.preco << endl;
    cout << comida5.aperit << comida5.preco << endl;
    cout << comida6.aperit << comida6.preco << endl;
    cout << comida7.aperit << comida7.preco << endl;
    escolha_fand = escolher_tam_bc();
    total[1] = soma_fandangos(escolha_fand);
    break;
  case 3:
    cout << comida8.aperit << comida8.preco << endl;
    cout << comida9.aperit << comida9.preco << endl;
    cout << comida10.aperit << comida10.preco << endl;
    cout << comida11.aperit << comida11.preco << endl;
    escolha_dori = escolher_tam_bc();
    total[2] = soma_doritos(escolha_dori);
    break;
  case 4:
    cout << comida12.aperit << comida12.preco << endl;
    cout << comida13.aperit << comida13.preco << endl;
    cout << comida14.aperit << comida14.preco << endl;
    cout << comida15.aperit << comida15.preco << endl;
    escolha_ruffles = escolher_tam_bc();
    total[3] = soma_ruffles(escolha_dori);
    break;
  case 5:
    cout << comida16.aperit << comida16.preco << endl;
    cout << comida17.aperit << comida17.preco << endl;
    cout << comida18.aperit << comida18.preco << endl;
    cout << comida19.aperit << comida19.preco << endl;
    escolha_cheetos = escolher_tam_bc();
    total[4] = soma_cheetos(escolha_cheetos);
    break;
  case 6:
    cout << comida20.aperit << comida20.preco << endl;
    cout << comida21.aperit << comida21.preco << endl;
    cout << comida22.aperit << comida22.preco << endl;
    cout << comida23.aperit << comida23.preco << endl;
    escolha_choc = escolher_tam_bc();
    total[5] = soma_chocolate(escolha_choc);
    break;
  default:
    cout << endl;
    cout << "\nNumero inválido, Tente novamente" << endl;
    break;
  }

  for (i = 0; i < 6; i++){
    total_comida = total_comida + total[i];
  }
  return total_comida;
}
float escolha_tipo_bebida(int escolha_bebida){
  setlocale(LC_ALL, "Portuguese_Brazil");
  float total[4], total_bebida;
  int i;
  for (i = 0; i < 4; i++){
    total[i] = 0;
  }
  switch (escolha_bebida){
  case 1:
    cout << bebida1.refri << bebida1.preco << endl;
    cout << bebida2.refri << bebida2.preco << endl;
    cout << bebida3.refri << bebida3.preco << endl;
    cout << bebida4.refri << bebida4.preco << endl;
    escolha_coca = escolher_tam_bc();
    total[0] = soma_coca(escolha_coca);
    break;
  case 2:
    cout << bebida5.refri << bebida5.preco << endl;
    cout << bebida6.refri << bebida6.preco << endl;
    cout << bebida7.refri << bebida7.preco << endl;
    cout << bebida8.refri << bebida8.preco << endl;
    escolha_uva = escolher_tam_bc();
    total[1] = soma_fanta_uva(escolha_uva);
    break;
  case 3:
    cout << bebida9.refri << bebida9.preco << endl;
    cout << bebida10.refri << bebida10.preco << endl;
    cout << bebida11.refri << bebida11.preco << endl;
    cout << bebida12.refri << bebida12.preco << endl;
    escolha_laran = escolher_tam_bc();
    total[2] = soma_fanta_laran(escolha_laran);
    break;
  case 4:
    cout << bebida13.refri << bebida13.preco << endl;
    cout << bebida14.refri << bebida14.preco << endl;
    cout << bebida15.refri << bebida15.preco << endl;
    cout << bebida16.refri << bebida16.preco << endl;
    escolha_guara = escolher_tam_bc();
    total[3] = soma_fanta_guara(escolha_guara);
    break;
  default:
    cout << endl;
    cout << "\nNumero não existe, Tente novamente!" << endl;
    break;
  }
  for (i = 0; i < 4; i++){
    total_bebida = total_bebida + total[i];
  }
  return total_bebida;
}

void escolher_tipo_bc(){
  total_final = 0;
  total_bc = 0;
  soma_comida = 0;
  guarda_comida = 0,
  soma_bebida = 0;
  guarda_bebida = 0;
  loop_tela = 0;
  sele_comida = 't';
  sele_comida = 't';
  
  cout << "\nOpções comidas: " << endl;
  cout << "[1]-> Pipocas" << endl;
  cout << "[2]-> Fandangos" << endl;
  cout << "[3]-> Doritos" << endl;
  cout << "[4]-> Ruffles" << endl;
  cout << "[5]-> Cheetos" << endl;
  cout << "[6]-> Barras de chocolate" << endl;

  cout << "\nOpções bebidas:" << endl;
  cout << "[1]-> Coca-cola" << endl;
  cout << "[2]-> Fanta uva" << endl;
  cout << "[3]-> Fanta laranja" << endl;
  cout << "[4]-> Fanta guarana" << endl;
  cout << endl;

  while (sele_comida != 'n' && sele_comida != 'N' && sele_comida != 's' && sele_comida != 'S'){
    cout << "\nDeseja entrar na opções de comidas";
    cout << "\nDigite 'S' para SIM ou 'N' para 'NÂO': ";
    cin >> sele_comida;
  }
  // system("cls");
  if (sele_comida == 'S' || sele_comida == 's'){
    while (loop_tela == 0){
      // system("cls");
      escolha_comida = 7;
      while (escolha_comida > 6 || escolha_comida < 0){
        cout << "\nOpçoes comidas: " << endl;
        cout << "[1]-> Pipocas" << endl;
        cout << "[2]-> Fandangos" << endl;
        cout << "[3]-> Doritos" << endl;
        cout << "[4]-> Ruffles" << endl;
        cout << "[5]-> Cheetos" << endl;
        cout << "[6]-> Barras de chocolate" << endl;
        cout << "\nDigite o numero: ";
        cin >> escolha_comida;
        if (escolha_comida > 6 || escolha_comida <= 0){
          cout << "\nValor inválido, Tente novamente!" << endl;
        }
      }
      // system("cls");
      soma_comida = escolha_tipo_comida(escolha_comida);
      guarda_comida = guarda_comida + soma_comida;
      loop_tela = 2;
      while (loop_tela != 1 && loop_tela != 0){
        cout << endl;
        cout << "    OPÇÕES COMIDAS                   OPÇÕES BEBIDAS";
        cout << "\n<- Digite 0 para voltar <-   -> Digite 1 para proseguir ->";
        cout << endl << "                           ";
        cin >> loop_tela;
      }
    }
  }
  if(loop_tela == 0){
    loop_tela = 1;
  }
  if(loop_tela == 1 && sele_comida == 'n' || sele_comida == 'N'){
    if(sele_bebida == 'n'){
      sele_bebida = 't';
    }
    while (sele_bebida != 'n' && sele_bebida != 'N' && sele_bebida != 's' && sele_bebida != 'S'){
      cout << "\nDeseja entrar na opções de bebidas";
      cout << "\nDigite 'S' para SIM ou 'N' para 'NÂO': ";
      cin >> sele_bebida;
    }
  }

  if(loop_tela == 1 && sele_bebida == 's' || sele_bebida == 'S'){
    if (sele_bebida == 's' || sele_bebida == 'S'){
      loop_tela = 0;
      while (loop_tela == 0){
        escolha_bebida = 5;
        while (escolha_bebida > 4 || escolha_bebida < 0){
        // system("cls");
        cout << "\nOpções bebidas:" << endl;
        cout << "[1]-> Coca-cola" << endl;
        cout << "[2]-> Fanta uva" << endl;
        cout << "[3]-> Fanta laranja" << endl;
        cout << "[4]-> Fanta guarana" << endl;
        cout << "\nDigite o numero: ";
        cin >> escolha_bebida;
      if (escolha_bebida > 4 || escolha_bebida < 0){
          cout << "\nValor inválido, Tente novamente!";
        }
      }
        soma_bebida = escolha_tipo_bebida(escolha_bebida);
        guarda_bebida = guarda_bebida + soma_bebida;

        loop_tela = 2;
      while (loop_tela != 1 && loop_tela != 0){
        cout << endl;
        cout << "       OPÇÕES BEBIDAS                  FINALIZAR COMPRA";
        cout << "\n <- Digite 0 para voltar <-   -> Digite 1 para proseguir ->  ";
        cout << endl << "                            ";
        cin >> loop_tela;
        }
      }
    }
  }
  
  total_bc = total_bc + (guarda_comida + guarda_bebida);
  total_final = total_final + total_bc + total_ingresso;
}
int escolher_tam_bc(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  char sele_opcao;
  int escolha_opcao;
  escolha_opcao = 0;
  sele_opcao = 't';
  while (sele_opcao != 'N' && sele_opcao != 'n'){
    cout << "\nSe deseja selecionar um numero";
    cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
    cin >> sele_opcao;
    if (sele_opcao == 's' || sele_opcao == 'S'){
      cout << "\nDigite o numero: ";
      cin >> escolha_opcao;
      return escolha_opcao;
    }
  }
  return 0;
}

float soma_pipoca(int escolha_pipoca){
  setlocale(LC_ALL, "Portuguese_Brazil");

  int i, qtd_pipoca[3];
  float total;
  i = 0;
  total = 0;
  guarda_pipoca = -1;
  for (i < 0; i < 3; i++){
    qtd_pipoca[i] = 0;
  }
  switch (escolha_pipoca){
  case 1:
    while (guarda_pipoca < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_pipoca;
      // system("cls");
      if (guarda_pipoca < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_pipoca = guarda_pipoca * comida1.preco;
    qtd_pipoca[0] = qtd_pipoca[0] + guarda_pipoca;
    break;
  case 2:
    while (guarda_pipoca < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_pipoca;
      if (guarda_pipoca < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_pipoca = guarda_pipoca * comida2.preco;
    qtd_pipoca[1] = qtd_pipoca[1] + guarda_pipoca;
    break;
  case 3:
    while (guarda_pipoca < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_pipoca;
      if (guarda_pipoca < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_pipoca = guarda_pipoca * comida3.preco;
    qtd_pipoca[2] = qtd_pipoca[2] + guarda_pipoca;
    break;
  default:
    cout << endl;
    if (escolha_pipoca < 0 || escolha_pipoca > 3){
      cout << "\nValor inválido, tente novamente!" << endl;
      break;
    }
  }

  for (i = 0; i < 3; i++){
    total = total + qtd_pipoca[i];
  }
  return total;
}
float soma_fandangos(int escolha_fand){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i, qtd_fand[4];
  float total;
  i = 0;
  total = 0;
  guarda_fand = -1;
  for (i < 0; i < 4; i++){
    qtd_fand[i] = 0;
  }
  switch (escolha_fand){
  case 1:
    while (guarda_fand < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_fand;
      if (guarda_fand < 0){
        cout << "\nQuantidade inválida, tente novamente!";
      }
    }
    guarda_fand = guarda_fand * comida4.preco;
    qtd_fand[0] = qtd_fand[0] + guarda_fand;
    break;
  case 2:
    while (guarda_fand < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_pipoca;
      if (guarda_pipoca < 0){
        cout << "\nQuantidade inválida, tente novamente!";
      }
    }
    guarda_fand = guarda_fand * comida5.preco;
    qtd_fand[1] = qtd_fand[1] + guarda_fand;
    break;
  case 3:
    while (guarda_fand < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_fand;
      if (guarda_fand < 0){
        cout << "\nQuantidade inválida, tente novamente!";
      }
    }
    guarda_fand = guarda_fand * comida6.preco;
    qtd_fand[2] = qtd_fand[2] + guarda_fand;
    break;
  case 4:
    while (guarda_fand < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_fand;
      if (guarda_fand < 0){
        cout << "\nQuantidade inválida, tente novamente!";
      }
    }
    guarda_fand = guarda_fand * comida7.preco;
    qtd_fand[3] = qtd_fand[3] + guarda_fand;
    break;
  default:
    cout << endl;
    if (escolha_fand < 0 || escolha_fand > 4){
      cout << "\nValor inválido, tente novamente!" << endl;
      break;
    }
  }

  for (i = 0; i < 4; i++){
    total = total + qtd_fand[i];
  }
  return total;
}
float soma_doritos(int escolha_doritos){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i, qtd_dori[4];
  float total;
  i = 0;
  total = 0;
  guarda_dori = -1;
  for (i < 0; i < 4; i++){
    qtd_dori[i] = 0;
  }
  switch (escolha_dori){
  case 1:
    while (guarda_dori < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_dori;
      if (guarda_dori < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_dori = guarda_dori * comida8.preco;
    qtd_dori[0] = qtd_dori[0] + guarda_dori;
    break;
  case 2:
    while (guarda_dori < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_dori;
      if (guarda_dori < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_dori = guarda_dori * comida9.preco;
    qtd_dori[1] = qtd_dori[1] + guarda_dori;
    break;
  case 3:
    while (guarda_dori < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_dori;
      if (guarda_fand < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_dori = guarda_dori * comida10.preco;
    qtd_dori[2] = qtd_dori[2] + guarda_dori;
    break;
  case 4:
    while (guarda_dori < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_dori;
      if (guarda_dori < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_dori = guarda_dori * comida11.preco;
    qtd_dori[3] = qtd_dori[3] + guarda_dori;
    break;
  default:
    cout << endl;
    if (escolha_doritos < 0 || escolha_doritos > 4){
      cout << "\nValor inválido, tente novamente!" << endl;
      break;
    }
  }

  for (i = 0; i < 4; i++){
    total = total + qtd_dori[i];
  }
  return total;
}
float soma_ruffles(int escolha_ruffles){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i, qtd_ruffles[4];
  float total;
  i = 0;
  total = 0;
  guarda_ruffles = -1;

  for (i < 0; i < 4; i++){
    qtd_ruffles[i] = 0;
  }
  switch (escolha_ruffles){
  case 1:
    while (guarda_ruffles < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_ruffles;
      if (guarda_ruffles < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_ruffles = guarda_ruffles * comida12.preco;
    qtd_ruffles[0] = qtd_ruffles[0] + guarda_ruffles;
    break;
  case 2:
    while (guarda_ruffles < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_ruffles;
      if (guarda_ruffles < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_ruffles = guarda_ruffles * comida13.preco;
    qtd_ruffles[1] = qtd_ruffles[1] + guarda_ruffles;
    break;
  case 3:
    while (guarda_ruffles < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_ruffles;
      if (guarda_ruffles < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_ruffles = guarda_ruffles * comida14.preco;
    qtd_ruffles[2] = qtd_ruffles[2] + guarda_ruffles;
    break;
  case 4:
    while (guarda_ruffles < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_ruffles;
      if (guarda_ruffles < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_ruffles = guarda_ruffles * comida15.preco;
    qtd_ruffles[3] = qtd_ruffles[3] + guarda_ruffles;
    break;
  default:
    cout << endl;
    if (escolha_ruffles < 0 || escolha_ruffles > 4){
      cout << "\nValor inválido, tente novamente!" << endl;
      break;
    }
  }

  for (i = 0; i < 4; i++){
    total = total + qtd_ruffles[i];
  }
  return total;
}
float soma_cheetos(int escolha_cheetos){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i, qtd_cheetos[4];
  float total;
  i = 0;
  total = 0;
  guarda_cheetos = -1;
  for (i < 0; i < 4; i++){
    qtd_cheetos[i] = 0;
  }
  switch (escolha_cheetos){
  case 1:
    while (guarda_cheetos < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_cheetos;
      if (guarda_cheetos < 0){
        cout << "\nQuantidade inválida, tente novamente!";
      }
    }
    guarda_cheetos = guarda_cheetos * comida16.preco;
    qtd_cheetos[0] = qtd_cheetos[0] + guarda_cheetos;
    break;
  case 2:
    while (guarda_cheetos < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_cheetos;
      if (guarda_cheetos < 0){
        cout << "\nQuantidade inválida, tente novamente!";
      }
    }
    guarda_cheetos = guarda_cheetos * comida17.preco;
    qtd_cheetos[1] = qtd_cheetos[1] + guarda_cheetos;
    break;
  case 3:
    while (guarda_cheetos < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_cheetos;
      if (guarda_cheetos < 0){
        cout << "\nQuantidade inválida, tente novamente!";
      }
    }
    guarda_cheetos = guarda_cheetos * comida18.preco;
    qtd_cheetos[2] = qtd_cheetos[2] + guarda_cheetos;
    break;
  case 4:
    while (guarda_cheetos < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_cheetos;
      if (guarda_cheetos < 0){
        cout << "\nQuantidade inválida, tente novamente!";
      }
    }
    guarda_cheetos = guarda_cheetos * comida19.preco;
    qtd_cheetos[3] = qtd_cheetos[3] + guarda_cheetos;
    break;
  default:
    cout << endl;
    if (escolha_cheetos < 0 || escolha_cheetos > 4){
      cout << "\nValor inválido, tente novamente!" << endl;
      break;
    }
  }

  for (i = 0; i < 4; i++){
    total = total + qtd_cheetos[i];
  }
  return total;
}
float soma_chocolate(int escolha_choc){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i, qtd_choc[4];
  float total;
  i = 0;
  total = 0;
  guarda_choc = -1;

  for (i < 0; i < 4; i++){
    qtd_choc[i] = 0;
  }
  switch (escolha_choc){
  case 1:
    while (guarda_choc < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_choc;
      if (guarda_choc < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_choc = guarda_choc * comida20.preco;
    qtd_choc[0] = qtd_choc[0] + guarda_choc;
    break;
  case 2:
    while (guarda_choc < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_choc;
      if (guarda_choc < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_choc = guarda_choc * comida21.preco;
    qtd_choc[1] = qtd_choc[1] + guarda_choc;
    break;
  case 3:
    while (guarda_choc < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_choc;
      if (guarda_choc < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_choc = guarda_choc * comida22.preco;
    qtd_choc[2] = qtd_choc[2] + guarda_choc;
    break;
  case 4:
    while (guarda_choc < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_choc;
      if (guarda_choc < 0){
        cout << "\nQuantidade inválida, tente novamente!" << endl;
      }
    }
    guarda_choc = guarda_choc * comida23.preco;
    qtd_choc[3] = qtd_choc[3] + guarda_choc;
    break;
  default:
    cout << endl;
    if (escolha_choc < 0 || escolha_choc > 4){
      cout << "\nValor inválido, tente novamente!" << endl;
      break;
    }
  }

  for (i = 0; i < 4; i++){
    total = total + qtd_choc[i];
  }
  return total;
}

float soma_coca(int escolha_coca){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i, qtd_coca[4];
  float total;
  i = 0;
  total = 0;
  guarda_coca = -1;
  for (i < 0; i < 4; i++){
    qtd_coca[i] = 0;
  }
  switch (escolha_coca){
  case 1:
    while (guarda_coca < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_coca;
      if (guarda_coca < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    } 
    guarda_coca = guarda_coca * bebida1.preco;
    qtd_coca[0] = qtd_coca[0] + guarda_coca;
    break;
  case 2:
    while (guarda_coca < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_coca;
      if (guarda_coca < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    } 
    guarda_coca = guarda_coca * bebida2.preco;
    qtd_coca[1] = qtd_coca[1] + guarda_coca;
    break;
  case 3:
    while (guarda_coca < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_coca;
      if (guarda_coca < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_coca = guarda_coca * bebida3.preco;
    qtd_coca[2] = qtd_coca[2] + guarda_coca;
    break;
  case 4:
    while (guarda_coca < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_coca;
      if (guarda_coca < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_coca = guarda_coca * bebida4.preco;
    qtd_coca[3] = qtd_coca[3] + guarda_coca;
    break;
  default:
    cout << endl;
    if (escolha_coca < 0 || escolha_coca > 4){
      cout << "\nValor inválido, tente novamente!" << endl;
      break;
    }
  }
  for (i = 0; i < 4; i++){
    total = total + qtd_coca[i];
  }
  return total;
}
float soma_fanta_uva(int escolha_uva){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i, qtd_uva[4];
  float total;
  i = 0;
  total = 0;
  guarda_uva = -1;
  for (i < 0; i < 4; i++){
    qtd_uva[i] = 0;
  }
  switch (escolha_uva){
  case 1:
    while (guarda_uva < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_uva;
      if (guarda_uva < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_uva = guarda_uva * bebida5.preco;
    qtd_uva[0] = qtd_uva[0] + guarda_uva;
    break;
  case 2:
    while (guarda_uva < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_uva;
      if (guarda_uva < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_uva = guarda_uva * bebida6.preco;
    qtd_uva[1] = qtd_uva[1] + guarda_uva;
    break;
  case 3:
    while (guarda_uva < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_uva;
      if (guarda_uva < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_uva = guarda_uva * bebida7.preco;
    qtd_uva[2] = qtd_uva[2] + guarda_uva;
    break;
  case 4:
    while (guarda_uva < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_uva;
      if (guarda_uva < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_uva = guarda_uva * bebida8.preco;
    qtd_uva[3] = qtd_uva[3] + guarda_uva;
    break;
  default:
    cout << endl;
    if (escolha_uva < 0 || escolha_uva > 4){
      cout << "\nValor inválido, tente novamente!" << endl;
      break;
    }
  }
  for (i = 0; i < 4; i++){
    total = total + qtd_uva[i];
  }
  return total;
}
float soma_fanta_laran(int escolha_laran){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i, qtd_laran[4];
  float total;
  i = 0;
  total = 0;
  guarda_laran = -1;
  for (i < 0; i < 4; i++){
    qtd_laran[i] = 0;
  }
  switch (escolha_laran){
  case 1:
    while (guarda_laran < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_laran;
      if (guarda_laran < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_laran = guarda_laran * bebida9.preco;
    qtd_laran[0] = qtd_laran[0] + guarda_laran;
    break;
  case 2:
    while (guarda_laran < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_laran;
      if (guarda_laran < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_laran = guarda_laran * bebida10.preco;
    qtd_laran[1] = qtd_laran[1] + guarda_laran;
    break;
  case 3:
    while (guarda_laran < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_laran;
      if (guarda_laran < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_laran = guarda_laran * bebida11.preco;
    qtd_laran[2] = qtd_laran[2] + guarda_laran;
    break;
  case 4:
    while (guarda_laran < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_laran;
      if (guarda_laran < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_laran = guarda_laran * bebida12.preco;
    qtd_laran[3] = qtd_laran[3] + guarda_laran;
    break;
  default:
    cout << endl;
    if (escolha_laran < 0 || escolha_laran > 4){
      cout << "\nValor inválido, tente novamente!" << endl;
      break;
    }
  }
  for (i = 0; i < 4; i++){
    total = total + qtd_laran[i];
  }
  return total;
}
float soma_fanta_guara(int escolha_guara){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i, qtd_guara[4];
  float total;
  i = 0;
  total = 0;
  guarda_guara = -1;
  for (i < 0; i < 4; i++){
    qtd_guara[i] = 0;
  }
  switch (escolha_guara){
  case 1:
    while (guarda_guara < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_guara;
      if (guarda_guara < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_guara = guarda_guara * bebida5.preco;
    qtd_guara[0] = qtd_guara[0] + guarda_guara;
    break;
  case 2:
    while (guarda_guara < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_guara;
      if (guarda_guara < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_guara = guarda_guara * bebida6.preco;
    qtd_guara[1] = qtd_guara[1] + guarda_guara;
    break;
  case 3:
    while (guarda_guara < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_guara;
      if (guarda_guara < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_guara = guarda_guara * bebida7.preco;
    qtd_guara[2] = qtd_guara[2] + guarda_guara;
    break;
  case 4:
    while (guarda_guara < 0){
      cout << "\nQuantidade: ";
      cin >> guarda_guara;
      if (guarda_guara < 0){
        cout << "\nQuantidade inválida, tente novamente! ";
      }
    }
    guarda_guara = guarda_guara * bebida8.preco;
    qtd_guara[3] = qtd_guara[3] + guarda_guara;
    break;
  default:
    cout << endl;
    if (escolha_guara < 0 || escolha_guara > 4){
      cout << "\nValor inválido, tente novamente!" << endl;
      break;
    }
  }
  for (i = 0; i < 4; i++){
    total = total + qtd_guara[i];
  }
  return total;
}
