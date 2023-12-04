#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include "lib/doctest.hpp"

#include "Administracao.hpp"

TEST_CASE("Adicionar Livro") {
    // TODO: instancia de adm
    Administracao administracao;
    Livro livro("Livro Teste", "Autor Teste", 2023);
    bool resultado = administracao.adicionarLivro(livro);

    CHECK(resultado == true);
}

TEST_CASE("Remover Livro") {

    Administracao administracao;
    Livro livro("Livro Teste", "Autor Teste", 2023);
    administracao.adicionarLivro(livro);
    
    bool resultado = administracao.removerLivro(livro);

    CHECK(resultado == true);
}

TEST_CASE("Remover Livro Inexistente") {

    Administracao administracao;
    Livro livroInexistente("Livro Inexistente", "Autor Inexistente", 2023);

    bool resultado = administracao.removerLivro(livroInexistente);

    CHECK(resultado == false);
}
