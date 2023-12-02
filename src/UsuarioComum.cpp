#include <cctype>
#include <iostream>

#include "UsuarioComum.hpp"

class ExcecaoDeNomeInvalido {}
class ExcecaoLivroJaEmprestado{}

UsuarioComum::UsuarioComum(std::string nome, int senha){
    for (auto c : nome) {
        if (!isalpha(c)) {
            std::cout << "Nome inválido! Utilize apenas letras." << std::endl;
            throw ExcecaoDeNomeInvalido();
        }
    }
    this->nome = nome;
    this->senha = senha;
};



bool UsuarioComum::solicitarEmprestimo(CodISBN isbn){
    if (_comPendencia) {
    std::cout << "Usuário com pendência. Não é possível realizar empréstimo." << std::endl;
    return false;
  }
    if (_livrosEmprestados.find(isbn) != _livrosEmprestados.end()) {
    std::cout << "Livro já emprestado pelo usuário." << std::endl;
    throw ExcecaoLivroJaEmprestado();
  }
    return true;
};


bool UsuarioComum::devolverLivro(CodISBN isbn){
    auto it = _livrosEmprestados.find(isbn);
    if (it == _livrosEmprestados.end()) {
        std::cout << "O livro não foi emprestado por este usuário." << std::endl;
        return false;
    }
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
