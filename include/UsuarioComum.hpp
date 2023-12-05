#pragma once

#include <string>
#include <map>
#include <set>

#include "Livro.hpp"
#include "Usuario.hpp"

/// @brief Estrutura de dados utilizada para salvar as datas como dia, mês e ano
struct Data{
    unsigned dia;
    unsigned mes;
    unsigned ano;
};

/// @brief Classe referente à usuários comuns de biblioteca, para solicitar empréstimo de livros, realizar devoluções...
class UsuarioComum : public  Usuario {
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

    /// @brief Retorna se o usuario tem pendências
    /// @return pendência do usuario
    bool getPendencia() const;
    
    /// @brief Verifica se o usuário tem algum livro emprestado
    /// @return True se o usuário tiver algum livro emprestado, false caso contrário
    bool temLivroEmprestado() const;

    std::map<CodISBN, Data> livrosEmprestados;


private:
    
    bool _comPendencia = false;
    std::set<std::string> _grusAPagar;
    
};
