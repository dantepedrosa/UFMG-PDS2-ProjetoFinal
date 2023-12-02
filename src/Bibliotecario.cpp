#include "Bibliotecario.hpp"
#include <stdexcept>

bool Bibliotecario::liberarEmprestimo(Usuario &u, CodISBN isbn){
    // TODO - Implementar função
    if(u.getPendencia()){
        throw std::invalid_argument("Usuário com pendência, não é possível liberar o empréstimo.");
    }
    
    if(u.temLivroEmprestado()){
        throw std::invalid_argument("Usuário já tem livro emprestado, não é possível liberar o empréstimo.");
    }
    
    std::cout << "Empréstimo realizado com sucesso." << std::endl;
    return true;
}


bool Bibliotecario::liberarDevolucao(Usuario &u, CodISBN isbn){
    // TODO - Implementar função
}


std::string Bibliotecario::gerarGRU(unsigned dias){
    // TODO - Implementar função
}
