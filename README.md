# UFMG-PDS2-ProjetoFinal

Projeto para sistema para biblioteca (busca, reserva, empréstimo, etc) simples em C++ - Disciplina de PDS2/UFMG

## Documentação

Uma documentação detalhada sobre as classes, métodos e atributos utilizados se encontra em na [página de documentação](https://dantepedrosa.github.io/UFMG-PDS2-ProjetoFinal/).

## Descrição do sistema e código

A descrição do projeto solicitado se encontra aqui: [`projeto-final-descritivo`](projeto-final-descritivo).


## Sobre o projeto

Foi desenvolvido um sistema de bibliotecas que permite que:
- Usuários solicitem empréstimos e devolvam livros
- Bibliotecários mediem e adiministrem emprestimos e devoluções
- Adiministradores incluam, excluam e editem livros
- Salvar e abrir o sistema com um banco de dados separado para persistência de dados
- Livros sejam separados por categoria

### Categorização

Os livros incluídos no sistema são salvos no banco de dados e automaticamente categorizados em listas separadas de ano de publicação, assunto e autor. Estas listas possuem os códigos dos livros para que possam ser pesquisados no banco de dados central de forma a ter as características completas do código.

### Empréstimo e devolução

Usuários podem realizar até 5 empréstimos de livros, não podendo atrasar. Caso haja atraso, no momento da devolução o bibliotecário irá gerar uma GRU com multa proporcional ao período do atraso. O Usuário só poderá solicitar mais livros quando tiver pago a multa e estiver livre de pendências.

### Inclusão, exclusão e edição de livros

Todos os livros são acessíveis pelo adiministrador para editar o acervo e incluir novos modelos de livro. Caso o livro já exista na biblioteca, não é realizado categorização repetida e apenas será incrementado o número de cópias da obra.

### Persistência de dados

Todos os dados podem ser salvos (por meio de comando não automatizado) em arquivos de tabela CSV contendo todas as informações necessárias do banco, como categorizações, livros atualmente emprestados a usuários e livros em acervo na biblioteca.

## Estrutura de arquivos do projeto

```
.
├── Fluxograma da Biblioteca.pdf
├── Makefile
├── README.md
├── bin
├── cartoes_CRC.pdf
├── config
│   ├── Doxyfile
│   └── media
|       └── ...
├── doc
│   └── html
|       └── ...
├── include
│   ├── Administracao.hpp
│   ├── BancoDeDados.hpp
│   ├── Bibliotecario.hpp
│   ├── Livro.hpp
│   ├── SistemaLivros.hpp
│   ├── Usuario.hpp
│   └── UsuarioComum.hpp
├── lib
│   └── doctest.hpp
├── obj
│   ├── Administracao.o
│   ├── BancoDeDados.o
│   ├── Bibliotecario.o
│   ├── Livro.o
│   ├── SistemaLivros.o
│   ├── Usuario.o
│   └── UsuarioComum.o
├── projeto-final-descritivo.md
├── src
│   ├── Administracao.cpp
│   ├── BancoDeDados.cpp
│   ├── Bibliotecario.cpp
│   ├── Livro.cpp
│   ├── SistemaLivros.cpp
│   ├── Usuario.cpp
│   └── UsuarioComum.cpp
└── test
    ├── testAdministracao.cpp
    ├── testBancoDeDados.cpp
    ├── testBibliotecario.cpp
    ├── testLivro.cpp
    ├── testSistemaLivros.cpp
    └── testUsuarioComum.cpp
```

- [bin](bin) - Pasta com os arquivos executáveis gerados na compilação
- [doc](doc) - Pasta com os arquivos Doxygen de documentação
- [config](config) - Pasta com arquivos de configuração do projeto (apenas documentação)
- [include](include) - Pasta com os headers `*.hpp`
- [lib](lib) - Pasta com as bibliotecas utilizadas no programa
- [obj](obj) - Pasta com os arquivos objeto `*.o` gerados na compilação
- [src](src) - Pasta com os códigos fonte `*.cpp`
- [test](test) - Pasta com os arquivos de teste
