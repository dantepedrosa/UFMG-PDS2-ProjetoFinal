#pragma once

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

#include "UsuarioComum.hpp"
#include "Livro.hpp"
#include "BancoDeDados.hpp"

class BancoDeDados;

/// @brief Estrutuda de dado utilizada para salvar livros no banco de dados.
struct LivroDB{
    std::string nome;
    std::string autor;
    std::string assunto;
    std::string anoPublicacao;
    unsigned copias;
};

/// @brief Sistema de livros, utilizado para acesso e cadastro de informações sobre do acervo.
class SistemaLivros {
public:

    /// @brief Construtor da classe sistema livros
    /// @param readFirst Define se haverá leitura inicial ou não
    /// @param path Caminho para a pasta de arquivos
    SistemaLivros(bool readFirst, std::string path);

    /// @brief Inclui livro nas listas e adciona ao banco de dados.
    /// @details Esta função adciona às listas da própria classe 
    /// (_biblioteca, _byAno, etc) e salva as informações no banco de dados.
    /// @param livro Instancia de Livro
    /// @return True se bem sucedido e False caso haja falha
    bool adicionarLivro(Livro livro);

    /// @brief Cria uma cópia do livro ter que incluir tudo
    /// @details Esta função incrementa o número de cópias à 
    /// lista _biblioteca e salva as informações no banco de dados.
    /// @param isbn Código de livro
    /// @return True se bem sucedido e False caso haja falha
    bool adicionarLivro(CodISBN isbn);

    /// @brief Edita as informações de um livro já existente no sistema
    /// @details Esta função edita as informações de um livro já existente em 
    /// lista _biblioteca e salva as informações no banco de dados.
    /// @param isbn Código ISBN do livro
    /// @param livro Parâmetros do livro
    /// @return True se bem sucedido e False caso haja falha
    bool editarLivro(CodISBN isbn, LivroDB livro);

    /// @brief Remove livro das listas e do banco de dados
    /// @details Esta função remove o livro das listas da classe
    /// (_biblioteca, _byAno, etc) e salva as informações no banco de dados 
    /// @param livro Instância de Livro
    /// @return True se bem sucedido e False caso haja falha
    bool removerLivro(Livro livro);

    /// @brief Salva todas as listas do sistema de biblioteca no banco de dados.
    /// @details Salva as listas _biblioteca, _byAno, _byAssunto e _byAutor 
    /// chamando as respectivas funções de BancoDeDados para cada.
    /// @return True se bem sucedido e False caso haja falha
    bool salvarListas();

    /// @brief Retira um livro do sistema de biblioteca
    /// @param isbn Código ISBN do livro
    /// @return True se bem sucedido e False caso haja falha 
    bool emprestarLivro(CodISBN isbn, UsuarioComum &u);

    /// @brief Retorna um livro ao sistema de biblioteca
    /// @param isbn Código ISBN do livro
    /// @return True se bem sucedido e False caso haja falha 
    bool devolverLivro(CodISBN isbn);

    /// @brief Armazena os livros da biblioteca (por ISBN) e o suas características.
    std::map<CodISBN, LivroDB> biblioteca;

    /// @brief Livros emprestados por código ISBN e nome de usuário que o possui
    std::vector<std::pair<CodISBN, std::string>> livrosEmprestados;
    
    /// @brief Armazena os ISBN dos livros por ano.
    /// @details O formato está a seguir:
    /// {
    ///     2020:       [9781234567897, 9781234567847],
    /// }
    std::map<std::string, std::set<CodISBN>> byAno;

    /// @brief Armazena os ISBN dos livros por assunto.
    /// @details O formato está a seguir:
    /// {
    ///     "Letras":   [9781234567897, 9781234567847],
    /// }
    std::map<std::string, std::set<CodISBN>> byAssunto;
    
    /// @brief Armazena os ISBN dos livros por assunto.
    /// @details O formato está a seguir:
    /// {
    ///     "John Doe": [9781234567897, 9781234567847],
    /// }
    std::map<std::string, std::set<CodISBN>> byAutor;
    
private:

    /// @brief Instância de BancoDeDados para armazenar listas em arquivo.
    BancoDeDados *bd;

};
