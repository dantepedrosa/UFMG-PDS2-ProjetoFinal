# UFMG-PDS2-ProjetoFinal

Projeto para sistema para biblioteca (busca, reserva, empréstimo, etc) simples em C++ - Disciplina de PDS2/UFMG

## Descrição do projeto

A descrição do projeto solicitado se encontra aqui: [`projeto-final-descritivo`](projeto-final-descritivo)
Uma documentação sobre as classes, métodos e atributos utilizados se encontra em na [página de documentação](https://dantepedrosa.github.io/UFMG-PDS2-ProjetoFinal/)

## Estrutura de arquivos do projeto

```
.
├── Fluxograma da Biblioteca.pdf
├── Makefile
├── README.md
├── bin
│   └── temp.txt
├── cartoes_CRC.pdf
├── doc
│   └── temp.txt
├── include
│   ├── Administracao.hpp
│   ├── Alugar.hpp
│   ├── BancoDeDados.hpp
│   ├── Bibliotecario.hpp
│   ├── Livro.hpp
│   ├── Locacao.hpp
│   ├── SistemaLivros.hpp
│   └── Usuario.hpp
├── lib
│   └── doctest.hpp
├── obj
│   └── temp.txt
├── projeto-final-descritivo.md
├── src
│   ├── Administracao.cpp
│   ├── Alugar.cpp
│   ├── BancoDeDados.cpp
│   ├── Bibliotecario.cpp
│   ├── Livro.cpp
│   ├── Locacao.cpp
│   └── Usuario.cpp
└── test
    ├── test.BancoDeDados.cpp
    ├── testAdministracao.cpp
    ├── testAlugar.cpp
    ├── testBibliotecario.cpp
    ├── testLivro.cpp
    ├── testLocacao.cpp
    └── testUsuario.cpp
```

- [bin](bin) - Pasta com os arquivos executáveis gerados na compilação
- [doc](doc) - Pasta com os arquivos Doxygen de documentação
- [include](include) - Pasta com os headers `*.hpp`
- [lib](lib) - Pasta com as bibliotecas utilizadas no programa
- [obj](obj) - Pasta com os arquivos objeto `*.o` gerados na compilação
- [src](src) - Pasta com os códigos fonte `*.cpp`
- [test](test) - Pasta com os arquivos de teste
