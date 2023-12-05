#pragma once

#include "Usuario.hpp"
#include "Livro.hpp"

struct LivroDB;
class SistemaLivros;

class Administracao : public  Usuario{
public:

    /// @brief Construtor da classe de usuários da administração do sistema de bibliotecas 
    /// @param nome Nome de usuário (apenas letras) - Max 20 char
    /// @param senha Senha do usuário (apenas números)
    Administracao(std::string nome, int senha);

    /// @brief Adciona livro no banco de dados e do sistema de livros
    /// @details Esta função apenas chama a função de mesmo nome da classe SistemaLivros.
    /// @param livro Instância de Livro
    /// @return True se foi adicionado com sucesso e False caso haja falha
    void adcionarLivro(Livro livro);


    /// @brief Remove livro do bando de dados e do sistema de livros
    /// @details Esta função apenas chama a função de mesmo nome da classe SistemaLivros.
    /// @param livro Instância de Livro
    /// @return True se foi removido com sucesso e False caso haja falha
    void removerLivro(Livro livro);


private:

    SistemaLivros *_sl;  ///< Intância de sistema livros.

};
