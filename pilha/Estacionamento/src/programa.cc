#include <string>
#include <iostream>
#include "pilha.h"
#include "carro.h"

void entrada(Pilha<Carro*> &estacionar,std::string placa_estacionar);
void saida(Pilha<Carro*> &estacionou,std::string placa_sair);

int main(int argc, char **argv) {
    Pilha<Carro*> estacionamento(10);
    std::string comando,placa;
    std::cout << "Estacionamento!\n";
    do{
        std::cin>>comando;
        if(comando=="FIM"){
            break;
        }
        std::cin>>placa;
        if(comando=="E"){
            entrada(estacionamento,placa);
        }else if(comando=="S"){
            saida(estacionamento,placa);
        }
    }while(comando != "FIM");
    while(!estacionamento.vazio()){
        Carro * cc = estacionamento.top();
        estacionamento.pop();
        delete cc;
    }
}

void entrada(Pilha<Carro*> &estacionar,std::string placa_estacionar){
    if(estacionar.cheio()){
        std::cout << "Estacionamento cheio, carro "<<placa_estacionar<<" foi embora.\n";
    }else{
        estacionar.push(new Carro(placa_estacionar));
        std::cout << "Carro "<<placa_estacionar<<" estacionou.\n";
    }
}

void saida(Pilha<Carro*> &estacionou,std::string placa_sair){
    Pilha<Carro*> manobra(10);
    Carro* temp;
    bool achou=false;
    while(!estacionou.vazio()){
        temp = estacionou.top();
        if(temp->placa()==placa_sair){
            std::cout << "Carro "<<temp->placa()<<" saiu com "<<temp->manobras()<<" manobras.\n";
            estacionou.pop();
            achou=true;
            delete temp;
            break;
        }else{
            manobra.push(temp);
            estacionou.pop();
        }
    }
    if(estacionou.vazio()&&!manobra.vazio()&&!achou){
        std::cout << "Carro não está no estacionamento.\n";
    }else if(estacionou.vazio()&&manobra.vazio()&&!achou){
        std::cout << "Estacionamento vazio.\n";
    }
    while(!manobra.vazio()){
        temp = manobra.top();
        manobra.pop();
        temp->manobrou();
        estacionou.push(temp);
    }
}
