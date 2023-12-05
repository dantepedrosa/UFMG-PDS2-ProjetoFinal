#include "Administracao.hpp"

Administracao::Administracao(std::string nome, int senha): Usuario(nome, senha){
    SistemaLivros _sl();
}


void Administracao::adcionarLivro(Livro livro){

    _sl.adicionarLivro(livro);

    return;
}

void Administracao::removerLivro(Livro livro){
    
    _sl.removerLivro(livro);

    return;
}
