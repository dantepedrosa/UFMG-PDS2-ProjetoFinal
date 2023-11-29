//TODO - Incluir colaborações
#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "Livro.hpp"


class BancoDeDados {
public:
    // TODO - Incluir métodos de BancoDeDados

    void adicionaLivro();
    void removeLivro(unsigned long isbn);
    std::vector<Livro> obterLivrosPorEstado(std::string _estado);

private:

    // TODO - arquivo com armazenamento geral de livros em acervo
    // TODO - arquivo com armazenamento de livros por ISBN
    // TODO - arquivo para armazenar cada categorização
    std::map<std::string, Livro> _livros;

};
