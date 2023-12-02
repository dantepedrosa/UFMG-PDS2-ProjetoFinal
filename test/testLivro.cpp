#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS


#include "lib/doctest.hpp"
#include "Livro.hpp"

TEST_CASE("Incluir livro informações corretas"){
    CHECK_NOTHROW(Livro("978156884614-9", "C++ For Dummies", "Programação", "Stephen R. Davis", 1996));
}

TEST_CASE("Incluir livro com ano errado"){
    CHECK_THROWS_AS(Livro("978156884614-9", "C++ For Dummies", "Programação", "Stephen R. Davis", -1996), std::invalid_argument);
}


TEST_CASE("Incluir livro com ISBN errado"){
    SUBCASE("Dígito verificador errado"){
        CHECK_THROWS_AS(Livro("978156884234-9", "C++ For Dummies", "Programação", "Stephen R. Davis", 1996), std::invalid_argument);
    }

    SUBCASE("Número insuficiente de dígitos"){
        CHECK_THROWS_AS(Livro("97865688429", "Learning Python", "Programação", "David Archer", 1999), std::invalid_argument);
    }
    SUBCASE("Formato inválido"){
        CHECK_THROWS_AS(Livro("9781568842349", "Learning Python", "Programação", "David Archer", 1999), std::invalid_argument);
    }
}

TEST_CASE("Conferir informações com getters"){

    // Definição de parâmetros
    std::string isbn = "978059600281-7";
    std::string nome = "Learning Python";
    std::string assunto = "Programação";
    std::string autor = "David Archer";
    unsigned ano = 1999;

    Livro l1(isbn, nome, assunto, autor, ano);
    
    //Teste de comparação
    CHECK_FALSE(l1.getISBN().compare(isbn));
    CHECK_FALSE(l1.getNome().compare(nome));
    CHECK_FALSE(l1.getAssunto().compare(assunto));
    CHECK_FALSE(l1.getAutor().compare(autor));
    CHECK_EQ(l1.getAno(), ano);
}
