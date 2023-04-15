#include "urna.h"

int mostrarOpcoes()
{

 int votado;
 cout << "\n\n*** Bem vindo ao Sistema de Votação ***" << endl;
 cout << "Escolha seu Candidato: " << endl;
 cout << "Para Votar em Didi, digite 11" << endl;
 cout << "Para votar em Mussum, digite 22" << endl;
 cout << "Para votar em branco, digite 100" << endl;
 cout << "Para finalizar votação e iniciar apuração, digite 99" << endl;

  cin >> votado;

  char confirmacao;
  if (votado == 11 || votado == 22){
    cout << "Você votou no candidato ";
    if (votado == 11){
    cout << "Didi." << endl;
    } else {
      cout << "Mussum." << endl;
    }
  } else if (votado == 100) {
    cout << "Você votou em branco. " << endl;
  } else if (votado != 99){
    cout << "Você votou nulo. " << endl;
  }
  if (votado != 99){
    cout << "Deseja confirmar seu voto? (s/n) ";
  } else {
    cout << "Deseja encerrar a votação? (s/n)";
  }
  
  cin >> confirmacao;
  if (confirmacao == 's' || confirmacao == 'S'){
    return votado;
  } else {
    return 0;
  }

}



int main() {

  Urna didi = Urna("Didi", 0);
  Urna mussum = Urna("Mussum", 0);
  Urna nulo = Urna("Nulos", 0);
  Urna branco = Urna("em Branco", 0);
  Urna total = Urna("Total", 0);

  int choice;
  
  do {
    choice = 0;
    while (choice == 0){
      choice = mostrarOpcoes();
    }
   total.votar();
   switch (choice)
   {
   case 11:
    cout << "Seu voto no candidato Didi foi confirmado." << endl;
    didi.votar();
   break;
   case 22: 
     cout << "Seu voto no candidato Mussum foi confirmado." << endl;
    mussum.votar();
   break;
   case 100: 
     cout << "Seu voto em Branco foi confirmado." << endl;
   branco.votar();
   break;
   case 99: 
   break;
   default: 
   cout << "Seu voto Nulo foi confirmado." << endl;
   nulo.votar();
   break;
   } //end switch
   system("reset");
 
 }while (choice != 99);//end while*/

  cout << "\nFim da votação\n";
  int total_didi = didi.apuracao();
  int total_mussum = mussum.apuracao();
  branco.apuracao();
  nulo.apuracao();
  int totalgeral = total.apuracao();
  float validos = total_didi + total_mussum;
  float percent_didi = (total_didi / validos)*100;
  float percent_mussum = (total_mussum / validos)*100;

  cout << "O candidato Didi obteve " << percent_didi << "% dos votos válidos." << endl;
  cout << "O candidato Mussum obteve " << percent_mussum << "% dos votos válidos." << endl;
}