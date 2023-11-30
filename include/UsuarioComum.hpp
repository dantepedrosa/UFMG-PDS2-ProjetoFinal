//TODO - Incluir colaborações
#pragma once

#include <string>
#include <map>
#include <set>
#include "Livro.hpp"

struct Data{
    unsigned dia;
    unsigned mes;
    unsigned ano;
};

class UsuarioComum {
public:
    
    /// @brief Construtor da classe Usuário
    /// @param nome nome de usuário (aceito apenas nomes sem espaço)
    /// @param senha senha do usuário (apenas números)
    /// @param tipoUsuario Tipo do usuário: Usuário comum, adm e bibliotecário 
    UsuarioComum(std::string nome, int senha);
    
    /// @brief Solicita empréstimo do livro para bibliotecario
    /// @param isbn Código do livro
    /// @return True se bem sucedido e False caso haja falha
    bool solicitarEmprestimo(CodISBN isbn);
    
    /// @brief Apresenta devolução para bibliotecario
    /// @param isbn Código do livro
    /// @return True se bem sucedido e False caso haja falha
    bool devolverLivro(CodISBN isbn);
    
    /// @brief Paga a respectiva GRU.
    /// @details Exclui a GRU da lista _grusAPagar e, caso esteja vazia, a pendência desaparece.
    /// @param gru Código de GRU formato "12345690909" + "00003" (número de dias atrasados)
    /// @return True se bem sucedido e False caso haja falha
    bool pagarGRU(std::string gru);

    // FIXME - bool solicitarEmprestimo(this, isbn); // Tirar dúvida se usuário pode chamar bibliotecario enviando ele mesmo
    // FIXME - Professor vai tirar ponto por não cumprir entrega parcial
    // FIXME - Perguntar pro professor se deve ser criado mais classes que já existem
private:
    
    std::map<CodISBN, Data> _livrosEmprestados;
    bool _comPendencia = false;
    std::set<std::string> _grusAPagar;
    
};
