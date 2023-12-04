#pragma once

#include <fstream>
#include <array>
#include <sstream>
#include <iostream>

#include "SistemaLivros.hpp"

#define FILE_ACERVO         "acervo.bibdb"          ///< Nome padrão do arquivo de acervo
#define FILE_EMPRESTIMOS    "emprestimos.bibdb"     ///< Nome padrão do arquivo de empréstimos
#define FILE_AUTOR          "by_autor.bibdb"        ///< Nome padrão do arquivo de categorização de autor
#define FILE_ASSUNTO        "by_assunto.bibdb"      ///< Nome padrão do arquivo de categorização de assunto
#define FILE_ANO            "by_ano.bibdb"          ///< Nome padrão do arquivo de categorização de ano

/// @brief Classe referente à manutenção e backup do SistemaLivros em arquivos CSV (*.csv) permanentes.
/// @details Esta classe realiza a operação de leitura e escrita dos arquivos necessários 
/// para evitar a perda de dados do sistema
class BancoDeDados {
public:

    /// @brief Construtor da classe.
    /// @param readFirst Caso true, o sistema irá ler o arquivo existente e configurar. 
    /// Caso false, cria arquivos do zero.
    /// @param path Caminho para pasta que serão salvos os arquivos.
    BancoDeDados(bool readFirst, std::string path, SistemaLivros &sl);

    /// @brief Abre o aquivo de acervo e categorias e salva nas listas em SistemaLivros
    /// @param sl Instância de Sistema Livros
    /// @return True se bem sucedido e False caso haja falha
    bool lerBancoDeDados(SistemaLivros &sl);

    /// @brief Salva a lista referente ao acerto e empréstimo em arquivo de texto
    /// @param sl Instância de Sistema Livros
    /// @return True se bem sucedido e False caso haja falha
    bool salvarAcervo(SistemaLivros &sl);
    
    /// @brief Salva as listas de categorização em arquivo de texto
    /// @param sl Instância de Sistema Livros
    /// @return True se bem sucedido e False caso haja falha
    bool salvarCategorias(SistemaLivros &sl);


private:

    /// @brief Realiza a leitura de um arquivo *.csv do acervo.
    /// @param path Caminho para a pasta com os arquivos
    /// @param nome Nome do arquivo
    /// @return Mapa com informações de acervo
    std::map<CodISBN, LivroDB> _lerAcervo(std::string path, std::string nome);
    
    /// @brief Realiza a leitura de um arquivo *.csv do acervo.
    /// @param path Caminho para a pasta com os arquivos
    /// @param nome Nome do arquivo
    /// @return Vetor com informações dos livros emprestados
    std::vector<std::pair<CodISBN, std::string>> _lerEmprestimos(std::string path, std::string nome);
    
    /// @brief Realiza a leitura de um arquivo *.csv do acervo.
    /// @param path Caminho para a pasta com os arquivos
    /// @param nome Nome do arquivo
    /// @return Mapa com informações da categoria
    std::map<std::string, std::set<CodISBN>> _lerCategoria(std::string path, std::string nome);

    /// @brief Configura o caminho da pasta de arquivos.
    /// @param String Contendo o caminho relativo ou completo para a pasta de arquivos
    void _setFolderPath(std::string path);

    std::string _arquivosCategorias[3] = {FILE_AUTOR, FILE_ASSUNTO, FILE_ANO};  ///< Lista com os tipos de categorização salvos
    std::string _folderPath;    ///< Caminho relativo ou absoluto para a pasta com arquivos CSV (*.csv)

};
