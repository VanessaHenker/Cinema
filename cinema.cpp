#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <locale.h>
using namespace std;

int selecionar_poltronas();

void sessao_escolha();
void sessao_filme();
void escolha_horario(int escolha_hora, int opcao);

int escolher_tam_bebida();

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

Filme filme1 = {"O Senhor dos An�is", "Fant�sia", "12 anos", 180};
Filme filme2 = {"Interestelar", "Fic��o Cient�fica", "12 anos", 169};
Filme filme3 = {"Invoca��o do mal", "Terror", "14 anos", 111};

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

Bebida bebida9  = {"[1]Fanta laranja        237ml R$ ", 4};
Bebida bebida10 = {"[2]Fanta laranja        350ml R$ ", 6};
Bebida bebida11 = {"[3]Fanta laranja ZERO   350ml R$ ", 6.50};
Bebida bebida12 = {"[4]Fanta laranja        600ml R$", 8};

Bebida bebida13 = {"[1]Fanta guaran�        237ml R$ ", 4};
Bebida bebida14 = {"[2]Fanta guaran�        350ml R$ ", 6};
Bebida bebida15 = {"[3]Fanta guaran� ZERO   350ml R$ ", 6.50};
Bebida bebida16 = {"[4]Fanta guaran�        600ml R$ ", 8};

Comida comida1 = {"[1]Pipoca pequena R$ ", 10};
Comida comida2 = {"[2]Pipoca m�dia   R$ ", 12.50};
Comida comida3 = {"[3]Pipoca grande  R$ ",15.50};

Comida comida4 = {"[1]Fandangos 37g  R$ ", 4};
Comida comida5 = {"[2]Fandangos 45g  R$ ", 6};
Comida comida6 = {"[3]Fandangos 90g  R$ ", 9};
Comida comida7 = {"[4]Fangangos 140g R$ ",12};

Comida comida8 = {"[1]Doritos 37g   R$ ", 4};
Comida comida9 = {"[2]Doritos 45g   R$ ", 6};
Comida comida10 = {"[3]Doritos 90g  R$ ", 9};
Comida comida11 = {"[4]Doritos 140g R$ ",12};

Comida comida12 = {"[1]RufFles 37g  R$ ", 4.50};
Comida comida13 = {"[2]RufFles 45g  R$ ", 6};
Comida comida14 = {"[3]RufFles 90g  R$ ", 9};
Comida comida15 = {"[4]RufFles 140g R$ ",15};

Comida comida16 = {"[1]Cheetos 37g  R$ ", 5};
Comida comida17 = {"[2]Cheetos 45g  R$ ", 6};
Comida comida18 = {"[3]Cheetos 90g  R$ ", 9};
Comida comida19 = {"[4]Cheetos 140g R$ ",15};

Comida comida20 = {"[1]Chocolate Garoto Castanha de Caju 90g R$ ",7.50};
Comida comida21 = {"[2]Chocalate Garoto Negresco 90g         R$ ", 7.50};
Comida comida22 = {"[3]Chocolate Garoto Crocante 90g         R$ ", 7.50};
Comida comida23 = {"[4]Chocalate Garoto ao Leite 90g         R$ ", 7.50};

int escolha, sessao, fin_compra;
int i, qtd_ingresso;
int ingresso_poltrona, guarda_ingresso, compra_ingresso;
char opcao_ingresso;
float ing_int, ing_meia, total_ingresso;

// variaveis de escolha de sessao e filme
int qtd_filme = 4;
char sele_sessao;
int opcao = 0, escolha_hora = 0;

// vari�veis de escolha comidas e bebidas;
int escolha_bebida = 0, escolha_comida = 0, escolha_coca = 0, escolha_uva = 0, escolha_laran, escolha_guara = 0;
int loop_bebida = 1, guarda_coca, guarda_uva, guarda_laran, guarda_guara;
char sele_bebida, sele_comida, sele_coca, sele_uva, sele_laran, sele_guara;

int main(){
  int qtd_guara[4];
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
  while (opcao == 0){
    setlocale(LC_ALL, "Portuguese_Brazil");
    cout << "\n[1]-> Op��es de filme e sess�es";
    cout << "\n[2]-> Comprar ingressos";
    cout << "\n[3]-> Selecionar poltronas";
    cout << "\n[4]-> Comidas e bebidas";
    cout << endl;
    cin >> escolha;
    // system("cls");
    if (escolha == 1){
      sessao_filme();
      cout << endl;
      do{
        cout << "Se deseja selecionar alguma sess�o";
        cout << "\nDigite 'S' para SIM ou 'N' para N�O: ";
        cin >> sele_sessao;
        if (sele_sessao == 'S' || sele_sessao == 's'){
          sessao_escolha();
        }
      } while (sele_sessao != 'N' && sele_sessao != 'n');
      cout << endl;
      // system("cls");
    }

    if (escolha == 2){
      setlocale(LC_ALL, "Portuguese_Brazil");
      cout << "\n[1]Ingresso inteiro R$" << ing_int;
      cout << "\n[2]Ingresso meio R$" << ing_meia;
      cout << endl;
      do{
        cout << "\nSelecione a op��o de ingressos: ";
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
      float total_bebidas, total_coca, total_uva, total_laran, total_guara;
      total_bebidas = 0;
      total_coca = 0;
      total_uva = 0;
      total_laran = 0;
      total_guara = 0;

      cout << "Op�oes comidas: " << endl;
      cout << "[1]-> Pipocas" << endl;
      cout << "[2]-> Fandangos" << endl;
      cout << "[3]-> Doritos" << endl;
      cout << "[4]-> Ruffles" << endl;
      cout << "[5]-> Cheetos" << endl;
      cout << "[6]-> Barras de chocolate" << endl; 
      cout << endl;
      cout << "\nOp��es bebidas:" << endl;
      cout << "[1]-> Coca-cola" << endl;
      cout << "[2]-> Fanta uva" << endl;
      cout << "[3]-> Fanta laranja" << endl;
      cout << "[4]-> Fanta guarana" << endl;
      cout << endl;
      cout << "Deseja entrar na op��es de comidas";
      cout << "\nDigite 'S' para SIM ou 'N' para 'N�O': ";
      cin >> sele_comida;
      if(sele_comida == 'S' || sele_comida == 's'){
        cout << "\nDigite o numero: ";
        cin >> escolha_comida;
        switch (escolha_comida){
        case 1:
          cout << comida1.aperit << comida1.preco << endl;
          cout << comida2.aperit << comida2. preco << endl;
          cout << comida3.aperit << comida3.preco << endl;
          break;
        case 2: 
          cout << comida4.aperit << comida4.preco << endl;
          cout << comida5.aperit << comida5.preco << endl;
          cout << comida6.aperit << comida6.preco << endl;
          cout << comida7.aperit << comida7.preco << endl;
          break;
        case 3:
          cout << comida8.aperit << comida8.preco << endl;
          cout << comida9.aperit << comida9.preco << endl;
          cout << comida10.aperit << comida10.preco << endl;
          cout << comida11.aperit << comida11.preco << endl;
          break;
        case 4:
          cout << comida12.aperit << comida12.preco << endl;
          cout << comida13.aperit << comida13.preco << endl;
          cout << comida14.aperit << comida14.preco << endl;
          cout << comida15.aperit << comida15.preco << endl;
          break;
        case 5:
          cout << comida16.aperit << comida16.preco << endl;
          cout << comida17.aperit << comida17.preco << endl;
          cout << comida18.aperit << comida18.preco << endl;
          cout << comida19.aperit << comida19.preco << endl;
          break;
        case 6:
          cout << comida20.aperit << comida20.preco << endl;
          cout << comida21.aperit << comida21.preco << endl;
          cout << comida22.aperit << comida22.preco << endl;
          cout << comida23.aperit << comida23.preco << endl;
        default:
          cout << "\nNumero inv�lido, Tente novamente";
          break;
        }
      }
      do{
        cout << "Deseja entrar na op��es de bebidas";
        cout << "\nDigite 'S' para SIM ou 'N' para 'N�O': ";
        cin >> sele_bebida;
        if (sele_bebida == 's' || sele_bebida == 'S'){
          cout << "\nDigite o numero: ";
          cin >> escolha_bebida;
          switch (escolha_bebida){
          case 1:
            cout << bebida1.refri << bebida1.preco << endl;
            cout << bebida2.refri << bebida2.preco << endl;
            cout << bebida3.refri << bebida3.preco << endl;
            cout << bebida4.refri << bebida4.preco << endl;
            escolha_coca = escolher_tam_bebida();
            total_coca = soma_coca(escolha_coca);
            break;
          case 2:
            cout << bebida5.refri << bebida5.preco << endl;
            cout << bebida6.refri << bebida6.preco << endl;
            cout << bebida7.refri << bebida7.preco << endl;
            cout << bebida8.refri << bebida8.preco << endl;
            escolha_uva = escolher_tam_bebida();
            total_uva = soma_fanta_uva(escolha_uva);
            break;
          case 3:
            cout << bebida9.refri << bebida9.preco << endl;
            cout << bebida10.refri << bebida10.preco << endl;
            cout << bebida11.refri << bebida11.preco << endl;
            cout << bebida12.refri << bebida12.preco << endl;
            escolha_laran = escolher_tam_bebida();
            total_laran = soma_fanta_laran(escolha_laran);
            break;
          case 4:
            cout << bebida13.refri << bebida13.preco << endl;
            cout << bebida14.refri << bebida14.preco << endl;
            cout << bebida15.refri << bebida15.preco << endl;
            cout << bebida16.refri << bebida16.preco << endl;
            escolha_guara = escolher_tam_bebida();
            total_guara = soma_fanta_guara(escolha_guara);
            break;
          default:
            cout << endl;
            cout << "\nNumero n�o existe, Tente novamente!";
            break;
          }
        }
        opcao = 0;
      } while (sele_bebida == 's' || sele_bebida == 'S');
    }
  }
  return 0;
}

void sessao_filme(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  // Exibindo informa��es das sess�es
  cout << "----------------------------------------------" << endl;
  cout << "Sess�o 1:" << endl;
  cout << "Filme: " << sessao1.filme.titulo << endl;
  cout << "Hor�rios: " << sessao1.horario << endl;
  cout << "Sala: " << sessao1.sala << endl;
  cout << "G�nero: " << sessao1.filme.genero << endl;
  cout << "Classifica��o: " << filme1.classi << endl;
  cout << "----------------------------------------------" << endl;
  cout << endl;

  cout << "----------------------------------------------" << endl;
  cout << "Sess�o 2:" << endl;
  cout << "Filme: " << sessao2.filme.titulo << endl;
  cout << "Hor�rios: " << sessao2.horario << endl;
  cout << "Sala: " << sessao2.sala << endl;
  cout << "G�nero: " << sessao2.filme.genero << endl;
  cout << "Classifica��o: " << filme3.classi << endl;
  cout << "----------------------------------------------" << endl;
  cout << endl;

  cout << "----------------------------------------------" << endl;
  cout << "Sess�o 3:" << endl;
  cout << "Filme: " << sessao3.filme.titulo << endl;
  cout << "Hor�rios: " << sessao3.horario << endl;
  cout << "Sala: " << sessao3.sala << endl;
  cout << "G�nero: " << sessao3.filme.genero << endl;
  cout << "Classifica��o: " << filme2.classi << endl;
  cout << "----------------------------------------------" << endl;
  cout << endl;

  cout << "----------------------------------------------" << endl;
  cout << "Filme: " << sessao4.filme.titulo << endl;
  cout << "Sess�o 4" << endl;
  cout << "Hor�rios: " << sessao4.horario << endl;
  cout << "Sala: " << sessao4.sala << endl;
  cout << "G�nero: " << sessao4.filme.genero << endl;
  cout << "Classifica��o: " << filme1.classi << endl;
  cout << "----------------------------------------------" << endl;
}
void sessao_escolha(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  do{
    cout << "\nSelecione a sess�o: ";
    cin >> opcao;
    switch (opcao){
    case 1:
      do{
        // system("cls");
        cout << "\nEscolha o hor�rio:" << endl;
        cout << "[1]-> 15:00" << endl;
        cout << "[2]-> 17:20" << endl;
        cin >> escolha_hora;
        if (escolha_hora > 2 || escolha_hora <= 0)
        {
          cout << "\nN�o existe esse hor�rio, tente novamente";
        }
      } while (escolha_hora > 2 || escolha_hora <= 0);
      escolha_horario(escolha_hora, opcao);
      break;
    case 2:
      do{
        // system("cls");
        cout << "\nEscolha o hor�rio:" << endl;
        cout << "[1]-> 16:00" << endl;
        cout << "[2]-> 18:30" << endl;
        cout << "[3]-> 21:00" << endl;
        cin >> escolha_hora;
      } while (escolha_hora > 3 || escolha_hora <= 0);
      escolha_horario(escolha_hora, opcao);
      break;
    case 3:
      do{
        // system("cls");
        cout << "\nEscolha o hor�rio:" << endl;
        cout << "[1]-> 15:30" << endl;
        cout << "[2]-> 20:30" << endl;
        cin >> escolha_hora;
      } while (escolha_hora > 2 || escolha_hora <= 0);
      escolha_horario(escolha_hora, opcao);
      break;
    case 4:
      do{
        // system("cls");
        cout << "\nEscolha o hor�rio:" << endl;
        cout << "[1]-> 20:15" << endl;
        cin >> escolha_hora;
        if (escolha_hora > 1 || escolha_hora <= 0){
          cout << "\nN�o existe esse hor�rio, tente novamente";
        }
      } while (escolha_hora > 2 || escolha_hora <= 0);
      escolha_horario(escolha_hora, opcao);
      break;
    default:
      cout << "\nSess�o n�o existe, Tente novamente!";
      break;
    }
  } while (opcao > qtd_filme || opcao <= 0);
}
void escolha_horario(int escolha_hora, int opcao){
  setlocale(LC_ALL, "Portuguese_Brazil");
  // Hor�rio selecionado da opcao 1
  if (escolha_hora == 1 && opcao == 1 || escolha_hora == 2 && opcao == 1){
    cout << "\nSess�o " << opcao << ":" << " SELECIONADA" << "!" << endl;
    cout << "Filme: " << sessao1.filme.titulo << endl;
    if (escolha_hora == 1 && opcao == 1){
      cout << "Hor�rio: "
           << "15:00" << endl;
    }
    if (escolha_hora == 2 && opcao == 1){
      cout << "Hor�rio: "
           << "17:20" << endl;
    }
    cout << "Sala: " << sessao1.sala << endl;
    cout << "G�nero: " << sessao1.filme.genero << endl;
    cout << "Classifica��o: " << filme1.classi << endl;
  }
  // Hor�rio selecionado da opcao 2
  if (escolha_hora == 1 && opcao == 2 || escolha_hora == 2 && opcao == 2 || escolha_hora == 3 && opcao == 2){
    cout << "\nSess�o " << opcao << ":" << " SELECIONADA" << "!" << endl;
    cout << "Filme: " << sessao2.filme.titulo << endl;
    if (escolha_hora == 1 && opcao == 2){
      cout << "Hor�rio: "
           << "16:00" << endl;
    }
    if (escolha_hora == 2 && opcao == 2){
      cout << "Hor�rio: "
           << "18:30" << endl;
    }
    if (escolha_hora == 3 && opcao == 2){
      cout << "Hor�rio: "
           << "21:00" << endl;
    }
    cout << "Sala: " << sessao2.sala << endl;
    cout << "G�nero: " << sessao2.filme.genero << endl;
    cout << "Classifica��o: " << filme3.classi << endl;
  }
  // Hor�rio selecionado da opcao 3
  if (escolha_hora == 1 && opcao == 3 || escolha_hora == 2 && opcao == 3){
    cout << "\nSess�o " << opcao << ":"
         << " SELECIONADA"
         << "!" << endl;
    cout << "Filme: " << sessao3.filme.titulo << endl;
    if (escolha_hora == 1 && opcao == 3){
      cout << "Hor�rio: "
           << "15:30" << endl;
    }
    if (escolha_hora == 2 && opcao == 3){
      cout << "Hor�rio: "
           << "20:30" << endl;
    }
    cout << "Sala: " << sessao3.sala << endl;
    cout << "G�nero: " << sessao3.filme.genero << endl;
    cout << "Classifica��o: " << filme2.classi << endl;
  }
  // Hor�rio selecionado da opcao 4
  if (escolha_hora == 1 && opcao == 4){
    cout << "\nSess�o " << opcao << ":"
         << " SELECIONADA"
         << "!" << endl;
    cout << "Filme: " << sessao4.filme.titulo << endl;
    cout << "Hor�rio: "
         << "20:15" << endl;
    cout << "Sala: " << sessao4.sala << endl;
    cout << "G�nero: " << sessao4.filme.genero << endl;
    cout << "Classifica��o: " << filme1.classi << endl;
  }
}

int escolher_tam_bebida(){
  char sele_bebida;
  cout << "\nSe deseja selecionar um numero";
  cout << "\nDigite 'S' para SIM ou 'N' para N�O: ";
  cin >> sele_bebida;
  if (sele_bebida == 's' || sele_bebida == 'S'){
    cout << endl;
    cout << "\nSelecione um numero: ";
    cin >> escolha_bebida;
    return escolha_bebida;
  }

  return 0;
}

float soma_coca(int escolha_coca){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i, qtd_coca[4];
  float total;
  i = 0;
  total = 0;

  for (i < 0; i < 4; i++){
    qtd_coca[i] = 0;
  }
  switch (escolha_coca){
  case 1:
    do{
      cout << "\nQuantidade: ";
      cin >> guarda_coca;
      if (guarda_coca < 0){
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_coca < 0);
    guarda_coca = guarda_coca * bebida1.preco;
    qtd_coca[0] = qtd_coca[0] + guarda_coca;
    break;
  case 2:
    do{
      cout << "\nQuantidade: ";
      cin >> guarda_coca;
      if (guarda_coca < 0){
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_coca < 0);
    guarda_coca = guarda_coca * bebida2.preco;
    qtd_coca[1] = qtd_coca[1] + guarda_coca;
    break;
  case 3:
    do{
      cout << "\nQuantidade: ";
      cin >> guarda_coca;
      if (guarda_coca < 0){
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_coca < 0);
    guarda_coca = guarda_coca * bebida3.preco;
    qtd_coca[2] = qtd_coca[2] + guarda_coca;
    break;
  case 4:
    do{
      cout << "\nQuantidade: ";
      cin >> guarda_coca;
      if (guarda_coca < 0){
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_coca < 0);
    guarda_coca = guarda_coca * bebida4.preco;
    qtd_coca[3] = qtd_coca[3] + guarda_coca;
    break;
  default:
    if (escolha_coca != 0){
      cout << "\nValor inv�lido, tente novamente!";
    }
    break;
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

  for (i < 0; i < 4; i++){
    qtd_uva[i] = 0;
  }
  switch (escolha_uva){
  case 1:
    do{
      cout << "\nQuantidade: ";
      cin >> guarda_uva;
      if (guarda_uva < 0){
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_uva < 0);
    guarda_uva = guarda_uva * bebida5.preco;
    qtd_uva[0] = qtd_uva[0] + guarda_uva;
    break;
  case 2:
    do{
      cout << "\nQuantidade: ";
      cin >> guarda_uva;
      if (guarda_uva < 0){
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_uva < 0);
    guarda_uva = guarda_uva * bebida6.preco;
    qtd_uva[1] = qtd_uva[1] + guarda_uva;
    break;
  case 3:
    do{
      cout << "\nQuantidade: ";
      cin >> guarda_uva;
      if (guarda_uva < 0){
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_uva < 0);
    guarda_uva = guarda_uva * bebida7.preco;
    qtd_uva[2] = qtd_uva[2] + guarda_uva;
    break;
  case 4:
    do{
      cout << "\nQuantidade: ";
      cin >> guarda_uva;
      if (guarda_uva < 0){
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_uva < 0);
    guarda_uva = guarda_uva * bebida8.preco;
    qtd_uva[3] = qtd_uva[3] + guarda_uva;
    break;
  default:
    cout << "\nValor inv�lido, tente novamente!";
    break;
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

  for (i < 0; i < 4; i++)
  {
    qtd_laran[i] = 0;
  }
  switch (escolha_laran)
  {
  case 1:
    do
    {
      cout << "\nQuantidade: ";
      cin >> guarda_laran;
      if (guarda_uva < 0)
      {
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_laran < 0);
    guarda_laran = guarda_laran * bebida9.preco;
    qtd_laran[0] = qtd_laran[0] + guarda_laran;
    break;
  case 2:
    do
    {
      cout << "\nQuantidade: ";
      cin >> guarda_laran;
      if (guarda_laran < 0)
      {
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_laran < 0);
    guarda_laran = guarda_laran * bebida10.preco;
    qtd_laran[1] = qtd_laran[1] + guarda_laran;
    break;
  case 3:
    do
    {
      cout << "\nQuantidade: ";
      cin >> guarda_laran;
      if (guarda_laran < 0)
      {
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_laran < 0);
    guarda_laran = guarda_laran * bebida11.preco;
    qtd_laran[2] = qtd_laran[2] + guarda_laran;
    break;
  case 4:
    do
    {
      cout << "\nQuantidade: ";
      cin >> guarda_laran;
      if (guarda_laran < 0)
      {
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_laran < 0);
    guarda_laran = guarda_laran * bebida12.preco;
    qtd_laran[3] = qtd_laran[3] + guarda_laran;
    break;
  default:
    cout << "\nValor inv�lido, tente novamente!";
    break;
  }

  for (i = 0; i < 4; i++)
  {
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

  for (i < 0; i < 4; i++)
  {
    qtd_guara[i] = 0;
  }
  switch (escolha_guara)
  {
  case 1:
    do
    {
      cout << "\nQuantidade: ";
      cin >> guarda_guara;
      if (guarda_guara < 0)
      {
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_guara < 0);
    guarda_guara = guarda_guara * bebida5.preco;
    qtd_guara[0] = qtd_guara[0] + guarda_guara;
    break;
  case 2:
    do
    {
      cout << "\nQuantidade: ";
      cin >> guarda_guara;
      if (guarda_guara < 0)
      {
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_guara < 0);
    guarda_guara = guarda_guara * bebida6.preco;
    qtd_guara[1] = qtd_guara[1] + guarda_guara;
    break;
  case 3:
    do
    {
      cout << "\nQuantidade: ";
      cin >> guarda_guara;
      if (guarda_guara < 0)
      {
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_guara < 0);
    guarda_guara = guarda_guara * bebida7.preco;
    qtd_guara[2] = qtd_guara[2] + guarda_guara;
    break;
  case 4:
    do
    {
      cout << "\nQuantidade: ";
      cin >> guarda_guara;
      if (guarda_guara < 0)
      {
        cout << "\nQuantidade inv�lida, tente novamente! ";
      }
    } while (guarda_guara < 0);
    guarda_guara = guarda_guara * bebida8.preco;
    qtd_guara[3] = qtd_guara[3] + guarda_guara;
    break;
  default:
    cout << "\nValor inv�lido, tente novamente!";
    break;
  }

  for (i = 0; i < 4; i++)
  {
    total = total + qtd_guara[i];
  }
  return total;
}
