#include "Bibliotecario.hpp"
#include <iostream>
#include <stdexcept>

bool Bibliotecario::liberarEmprestimo(Usuario &u, CodISBN isbn, const std::string &data){
    // TODO - Implementar função
    if(u.getPendencia()){
        try {
            throw std::invalid_argument("Usuário com pendência, não é possível liberar o empréstimo.");
        } catch (const std::exception& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        }
        return false;
    }
    
    if(u.temLivroEmprestado()){
        try {
            throw std::invalid_argument("Usuário já tem livro emprestado, não é possível liberar o empréstimo.");
        } catch (const std::exception& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        }
        return false;
    }
    setDataEmprestimo(data);
    std::cout << "Empréstimo realizado com sucesso." << std::endl;
    return true;
}


bool Bibliotecario::liberarDevolucao(Usuario &u, CodISBN isbn){
    // TODO - Implementar função
}


std::string Bibliotecario::gerarGRU(unsigned dias){
    // TODO - Implementar função
}

void Bibliotecario::setDataEmprestimo(const std::string &dataEmprestimo) {
        _dataEmprestimo = dataEmprestimo;
}
