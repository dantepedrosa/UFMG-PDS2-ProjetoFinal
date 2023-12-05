#pragma once

#include "Usuario.hpp"
#include "Livro.hpp"

class Bibliotecario : public  Usuario{
public: 

    /// @brief Consolida empréstimo no sistema de livros
    /// @details Caso possua algum livro atrasado ou pendência, bloqueia o usuário.
    /// @param u Instância de usuário solicitando serviço
    /// @param data Data da liberação do empréstimo
    /// @param isbn Código ISBN do livro
    /// @return True se bem sucedido e false se falhou
    bool liberarEmprestimo(Usuario &u, CodISBN isbn, const std::string &data);

    /// @brief Consolida devolução no sistema de livros. 
    /// @details Caso esteja atrasado, bloqueia o usuário e gera GRU.
    /// @param u Instância de usuário solicitando serviço 
    /// @param isbn Código ISBN do livro
    /// @return True se bem sucedido e false se falhou
    bool liberarDevolucao(Usuario &u, CodISBN isbn);

    /// @brief Define a data de empréstimo para a instância atual
    /// @param dataEmprestimo Data de empréstimo a ser definida
    void setDataEmprestimo(const std::string &dataEmprestimo);

private:
    
    /// @brief Gera uma GRU respectiva ao período de atraso (1 real por dia)
    /// @param dias Número de dias de atraso.
    /// @return Código de GRU formato "12345690909" + "00003" (número de dias atrasados)
    std::string gerarGRU(unsigned dias);
    
    std::string _dataEmprestimo;
};
