#include <iostream>
#include <cmath>
#include <iomanip>
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
  float preco;
};

struct Bebida{
  string refri;
  float preco;
};
int main(){
  int opcao, escolha, sessao, fin_compra;
  int i, qtd_pipoca[3], qtd_bebida[4], qtd_ingresso;
  int  compra_pipoca, compra_bebida, compra_ingresso; 
  int  ingresso_poltrona, guarda_ingresso, guarda_pipoca, guarda_bebida;
  char opcao_bebida, opcao_pipoca, opcao_ingresso;
  float ing_int, ing_meia, total_ingresso, total_pipoca, total_bebida;
  ing_int = 30;
  ing_meia = 15;
  i = 0;
  ingresso_poltrona = 0;
  guarda_ingresso = 0;
  guarda_pipoca = 0;
  total_ingresso = 0;
  total_pipoca = 0;
  qtd_ingresso = 0;
  qtd_bebida[0] = 0;
  qtd_bebida[1] = 0;
  qtd_bebida[2] = 0;
  qtd_bebida[0] = 0;
  qtd_pipoca[1] = 0;
  qtd_pipoca[2] = 0;
  qtd_pipoca[3] = 0;
  do{
    cout << "--------------------------------";
    cout << "\nBem vindo ao nosso cinema!";
    cout << "\n--------------------------------";
    cout << endl;

    cout << "\n[1]-> Opcoes de filme";
    cout << "\n[2]-> Valores dos ingressos";
    cout << "\n[3]-> Selecionar as poltronas";
    cout << "\n[4]-> Comidas e bebidas";
    cout << endl;
    cin >> escolha;

    if (escolha == 1){
      Filme filme1 = {"O Senhor dos Aneis", "Fantasia", 180};
      Filme filme2 = {"Interestelar", "Ficcao Cientifica", 169};
      Filme filme3 = {"Invocacao do mal", "Terror", 111};
      // Criando sessões
      Sessao sessao1 = {"15:00", "Sala 1", filme1};
      Sessao sessao2 = {"18:30", "Sala 2", filme2};
      Sessao sessao3 = {"20:00", "Sala 3", filme3};
      // Exibindo informações das sessões
      cout << "Sessao 1:" << endl;
      cout << "Horario: " << sessao1.horario << endl;
      cout << "Sala: " << sessao1.sala << endl;
      cout << "Filme: " << sessao1.filme.titulo << endl;
      cout << "Genero: " << sessao1.filme.genero << endl;

      cout << endl;

      cout << "Sessoo 2:" << endl;
      cout << "Horario: " << sessao2.horario << endl;
      cout << "Sala: " << sessao2.sala << endl;
      cout << "Filme: " << sessao2.filme.titulo << endl;
      cout << "Genero: " << sessao2.filme.genero << endl;
    
      cout << endl;

      cout << "Sessoo 3:" << endl;
      cout << "Horario: " << sessao3.horario << endl;
      cout << "Sala: " << sessao3.sala << endl;
      cout << "Filme: " << sessao3.filme.titulo << endl;
      cout << "Genero: " << sessao3.filme.genero << endl;
    
    do{
        cout << endl;
        cout << "\nSeleione a sessao: ";
        cin >> opcao;
        if (opcao > 3){
          cout << "\nSessao invalida, Tente novamente!";
        }
      } while (opcao > 3 || opcao < 0);
      cout << "\nSESSAO SELECIONADA!";
      cout << endl;
      cout << "\nDigite 0 para voltar a tela inical: ";
      cin >> opcao;
    }
    
    if (escolha == 2){
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
          ingresso_poltrona = ingresso_poltrona+ qtd_ingresso;
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
      
      if(ingresso_poltrona == 0){
        cout << "\nNao teve nenhuma compra de ingresso!";
        cout << "\nSe deseja reservar poltronas volte ao menu incial!";
        cout << endl;
        cout << "\nDigite 0 para voltar ao menu inicial: ";
        cin >> opcao;
      }
      else{
      while(reserva_polt <= ingresso_poltrona){
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
          cout <<"\nReservar a cadeira: ";
          cin >> escolha1 >> escolha2;
          if (escolha1 > 9 || escolha2 > 4){
            cout << "\nCadeira nao existe, Tente novamente!";
            cout << endl;
          }
        }while (escolha1 > 9 || escolha2 > 4);
        if (cadeiras[escolha1][escolha2] == true){
          cout << "\nCADEIRA OCUPADA\n";
        }
        else{
           cadeiras[escolha1][escolha2] = true;
            cout << "\nA cadeira " << escolha1 << escolha2 << " foi RESERVADA\n";
            reserva_polt++;
          }
        if(reserva_polt > ingresso_poltrona){
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
      for(i = 0; i < 3; i++){
      total_pipoca = total_pipoca + qtd_pipoca[i];
      }
      
      cout << "\nDeseja comprar bebida[S/N]: ";
      cin >> opcao_bebida;
      while(opcao_bebida == 's' || opcao_bebida == 'S'){
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
      for(i = 0; i < 4; i++){
        total_bebida = total_bebida + qtd_bebida[i];
      }
      cout << "\nDigite 0 para voltar a tela inical: ";
      cin >> opcao;
    }

  } while (opcao == 0);
  return 0;
}



