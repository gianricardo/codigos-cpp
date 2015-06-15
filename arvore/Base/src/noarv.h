#ifndef NOARV_H
#define NOARV_H

template<class TStorage>
class NoArv {
public:
    NoArv() {
        _esquerda = _direita = nullptr;
    }
    NoArv(TStorage val) :
            _conteudo(val) {
        _esquerda = _direita = nullptr;
    }
    virtual ~NoArv(){}
    NoArv* left(){
        return _esquerda;
    }
    NoArv* right(){
        return _direita;
    }
    void left(NoArv* ne){
        _esquerda = ne;
    }
    void right(NoArv* nd){
        _direita = nd;
    }
    TStorage value(){
        return _conteudo;
    }
    void value(const TStorage& nc){
        _conteudo = nc;
    }

protected:
private:
    TStorage _conteudo;
    NoArv<TStorage> *_esquerda, *_direita;
};

#endif // NOARV_H
