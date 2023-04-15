#include "urna.h"

Urna::Urna(const string&candidato, int votos){
  //cout << "Inserindo os nomes do candidato: " << candidato << endl;
  nome = candidato;
  n_votos = votos;
}

Urna::~Urna() {}

void Urna::votar(){
  n_votos ++;
}

int Urna::apuracao() const
{
  if (nome == "Didi" || nome == "Mussum")
  {
    cout << "O candidato " << nome <<       " teve " << n_votos << " votos."       << endl;
  } else if (nome == "Nulos" || nome == "em Branco"){
  cout << "Os votos " << nome << " foram " << n_votos << "." << endl;
}

if (nome == "Total"){
  cout << "O total votante foi de " << n_votos-1 << " eleitores." << endl;
}

  return n_votos;
  
}
