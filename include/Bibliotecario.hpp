#pragma once

#include "Usuario.hpp"
#include "Livro.hpp"

class Bibliotecario : Usuario{
public:

    /// @brief Consolida empréstimo no sistema de livros
    /// @details Caso possua algum livro atrasado ou pendência, bloqueia o usuário.
    /// @param u Instância de usuário solicitando serviço 
    /// @param isbn Código ISBN do livro
    /// @return True se bem sucedido e false se falhou
    bool liberarEmprestimo(Usuario &u, CodISBN isbn);

    /// @brief Consolida devolução no sistema de livros. 
    /// @details Caso esteja atrasado, bloqueia o usuário e gera GRU.
    /// @param u Instância de usuário solicitando serviço 
    /// @param isbn Código ISBN do livro
    /// @return True se bem sucedido e false se falhou
    bool liberarDevolucao(Usuario &u, CodISBN isbn);

private:
    
    /// @brief Gera uma GRU respectiva ao período de atraso (1 real por dia)
    /// @param dias Número de dias de atraso.
    /// @return Código de GRU formato "12345690909" + "00003" (número de dias atrasados)
    std::string gerarGRU(unsigned dias);
    
    std::string _dataEmprestimo;
};
