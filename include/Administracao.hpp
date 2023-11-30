#pragma once

#include "Usuario.hpp"
#include "Livro.hpp"
#include "SistemaLivros.hpp"

class Administracao : Usuario{
public:

    /// @brief Adciona livro no banco de dados e do sistema de livros
    /// @details Esta função apenas chama a função de mesmo nome da classe SistemaLivros.
    /// @param livro Instância de Livro
    /// @return True se foi adicionado com sucesso e False caso haja falha
    bool adcionarLivro(Livro livro);


    /// @brief Remove livro do bando de dados e do sistema de livros
    /// @details Esta função apenas chama a função de mesmo nome da classe SistemaLivros.
    /// @param livro Instância de Livro
    /// @return True se foi removido com sucesso e False caso haja falha
    bool removerLivro(Livro livro);


private:

};
