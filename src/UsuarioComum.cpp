#include <cctype>
#include <iostream>
#include <stdexcept>

#include "UsuarioComum.hpp"

class ExcecaoLivroJaEmprestado{}

UsuarioComum::UsuarioComum(std::string nome, int senha){
    //verificador, se contém algo diferente de número e letra na string recebe true
    bool verificador = false;

    for (auto c : nome) {
        if (!isalpha(c) && !isdigit(c)) {
            verificador = true;
            break;
        }
    }

    if (verificador) 
    throw std::invalid_argument("Nome inválido! Utilize apenas números e letras.");
    
    this->nome = nome;
    this->senha = senha;
};



bool UsuarioComum::solicitarEmprestimo(CodISBN isbn){
    if (_comPendencia)
    throw std::invalid_argument("Usuário com pendência. Não é possível realizar o empréstimo.");
        
    if (_livrosEmprestados.find(isbn) != _livrosEmprestados.end()) 
    throw std::invalid_argument("Livro já emprestado pelo usuário.");
    
    return true;
};


bool UsuarioComum::devolverLivro(CodISBN isbn){
auto it = _livrosEmprestados.find(isbn);
    
    if (it == _livrosEmprestados.end())
    throw std::invalid_argument("O livro não foi emprestado por este usuário.");
    
    return true;
}


bool UsuarioComum::pagarGRU(std::string gru){
    if (!_comPendencia) {
        std::cout << "Usuário não possui pendência para pagar." << std::endl;
        return false;
    }

    auto it = _grusAPagar.find(gru);
    if (it == _grusAPagar.end()) {
        std::cout << "GRU não encontrada na lista de pendências." << std::endl;
        return false;
    }

    _grusAPagar.erase(it);
    _comPendencia = _grusAPagar.size() > 0;

    std::cout << "Pagamento da GRU realizado com sucesso." << std::endl;
    return true;
}
bool UsuarioComum::getPendencia() const {
    return _comPendencia;
}

bool UsuarioComum::temLivroEmprestado() const{
    if(!_livrosEmprestados.empty()){
        return true;
    }
    return false;
}
