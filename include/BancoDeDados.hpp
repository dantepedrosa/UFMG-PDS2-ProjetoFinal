#pragma once

#include "SistemaLivros.hpp"

#define FILE_ACERVO         "acervo.bibdb"
#define FILE_EMPRESTIMOS    "emprestimos.bibdb"
#define FILE_AUTOR          "by_autor.bibdb"
#define FILE_ASSUNTO        "by_assunto.bibdb"
#define FILE_ANO            "by_ano.bibdb"

// TODO - Criar namespace bib_sis

class BancoDeDados {
public:

    /// @brief Construtor da classe.
    /// @param readFirst Caso true, o sistema irá ler o arquivo existente e configurar. 
    /// Caso false, cria arquivos do zero.
    /// @param path Caminho para pasta que serão salvos os arquivos.
    BancoDeDados(bool readFirst, std::string path);

    bool lerAcervo(SistemaLivros &sl);
    bool lerCategorias(SistemaLivros &sl);

    bool salvarAcervo(SistemaLivros &sl);
    bool salvarCategorias(SistemaLivros &sl);


private:

    std::string _folderPath;

};
