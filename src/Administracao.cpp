#include "Administracao.hpp"

bool Administracao::adcionarLivro(Livro livro){

bool sucesso = SistemaLivros::adicionarLivro(livro);

    if (sucesso) {
        std::cout << "Livro adicionado com sucesso pela Administração." << std::endl;
    } else {
        std::cout << "Falha ao adicionar o livro pela Administração." << std::endl;
    }
    return sucesso;
}

bool Administracao::removerLivro(Livro livro){
    bool sucesso = SistemaLivros::removerLivro(livro);

    if (sucesso) {
        std::cout << "Livro removido com sucesso pela Administração." << std::endl;
    } else {
        std::cout << "Falha ao remover o livro pela Administração." << std::endl;
    }
    return sucesso;
}
