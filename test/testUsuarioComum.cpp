#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include "lib/doctest.hpp"
#include "UsuarioComum.hpp"

TEST_CASE("Teste UsuarioComum") {

    UsuarioComum usuario("Dante", 1234);

    SUBCASE("Teste de Emprestimo e Devolucao") {
        // empréstimo de um livro
        CodISBN isbnLivro = "1234567890123";  
        CHECK(usuario.solicitarEmprestimo(isbnLivro) == true);

        // Teste de devolução do livro
        CHECK(usuario.devolverLivro(isbnLivro) == true);
    }

    SUBCASE("Teste de Pagamento de GRU") {
        // Teste de solicitação de empréstimo sem livro disponível
        CodISBN isbnLivro = "9876543210987";  
        CHECK(usuario.solicitarEmprestimo(isbnLivro) == false);

        // Teste de pagamento de GRU
        std::string gru = "1234569090900003";
        CHECK(usuario.pagarGRU(gru) == true);
    }

}
