#include <string>


typedef unsigned long CodISBN;

class Livro {
public:

  /// @brief Construtor da classe livro
  /// @param isbn Código ISBN do livro
  /// @param nomeLivro Nome do livro
  /// @param assunto Assunto do livro 
  /// @param autor Autor do livro
  /// @param ano Ano de publicação
  Livro(
    unsigned long isbn, 
    std::string nomeLivro, 
    std::string assunto, 
    std::string autor, 
    unsigned ano
  );

  /// @brief Retorna o ISBN do livro
  /// @return Código ISBN do livro
  unsigned long getISBN();

  /// @brief Retorna o nome do livro
  /// @return Nome do livro
  std::string getNome();

  /// @brief Retorna o assunto do livro
  /// @return Assunto do livro
  std::string getAssunto();

  /// @brief Retorna o nome do autor do livro
  /// @return Nome do autor do livro
  std::string getAutor();

  /// @brief Retorna o ano de publicação do livro
  /// @return Ano de publicação do livro
  unsigned getAno();

private:

  /// @brief Configura o ISBN do livro, seguindo modelo de 13 dígitos "XXX-XX-XXX-XXXX-X"
  /// @param isbn Código ISBN do livro
  /// @return True se bem sucedido, False se falhou
  bool _setISBN(CodISBN isbn);

  /// @brief Configura o ano de publicação do livro
  /// @param ano Ano de publicação do livro
  /// @return True se bem sucedido, False se falhou
  bool _setAnoPublicacao(unsigned ano);


  /// @brief Código ISBN do livro
  CodISBN _isbn;
  /// @brief Nome do livro
  std::string _nomeLivro;
  /// @brief Assunto do livro
  std::string _assunto;
  /// @brief Nome do autor do livro
  std::string _autor;
  /// @brief Ano de publicação do livro
  unsigned _anoPublicacao;
};