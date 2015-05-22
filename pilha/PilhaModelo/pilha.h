#ifndef PILHA_H
#define PILHA_H

#include <iostream>

template <class Tipo>
class Pilha {
public:
	Pilha(int capacidade = 10);
	virtual ~Pilha();
	void push(Tipo v1);
	void pop();
	Tipo top();
	bool vazio();
	bool cheio();
	void mostra();

protected:
private:
	int _topo, _capacidade;
	Tipo *v;

};

template <class Tipo>
Pilha<Tipo>::Pilha(int capacidade) {
    _topo = -1;
    v = new Tipo[capacidade];
    _capacidade = capacidade;
}

template<class Tipo>
Pilha<Tipo>::~Pilha() {
    delete[] v;
}

template<class Tipo>
void Pilha<Tipo>::push(Tipo v1) {
    if (!cheio()) {
        _topo += 1;
        v[_topo] = v1;
    }
}

template<class Tipo>
void Pilha<Tipo>::pop() {
    if (!vazio()) {
        _topo--;
    }
}

template<class Tipo>
void Pilha<Tipo>::mostra() {
    int i;
    for (i = 0; i <= _topo; i++) {
        std::cout << " " << v[i];
    }
    std::cout << "*" << std::endl;
}

template<class Tipo>
Tipo Pilha<Tipo>::top() {
    if (!vazio()) {
        return v[_topo];
    }
}

template<class Tipo>
bool Pilha<Tipo>::vazio() {
    if (_topo < 0) {
        return true;
    }
    return false;
}

template<class Tipo>
bool Pilha<Tipo>::cheio() {
    if (_topo == _capacidade - 1) {
        return true;
    }
    return false;

}


#endif // PILHA_H
