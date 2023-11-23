//TODO - Incluir colaborações
#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "Livro.hpp"


class BancoDeDados {
public:
    // TODO - Incluir métodos de usuário
    void adicionarLivros(Livro &livro);
    void mostrarTodosLivros();
    std::vector<Livro> obterLivrosPorEstado(std::string _estado);

private:
    // TODO - Incluir atributos de usuário
std::map<std::string, Livro> _livros;
};
