#include "Administracao.hpp"
#include "SistemaLivros.hpp"

Administracao::Administracao(std::string nome, int senha) : Usuario(nome, senha) {}


void Administracao::adcionarLivro(Livro livro){

    _sl->adicionarLivro(livro);

    return;
}

void Administracao::removerLivro(Livro livro){
    
    _sl->removerLivro(livro);

    return;
}
