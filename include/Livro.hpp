#include <string>
using namespace std;

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
    string nomeLivro, 
    string assunto, 
    string autor, 
    unsigned ano
  );

  /// @brief Retorna o ISBN do livro
  /// @return Código ISBN do livro
  unsigned long getISBN();

  /// @brief Retorna o nome do livro
  /// @return Nome do livro
  string getNome();

  /// @brief Retorna o assunto do livro
  /// @return Assunto do livro
  string getAssunto();

  /// @brief Retorna o nome do autor do livro
  /// @return Nome do autor do livro
  string getAutor();

  /// @brief Retorna o ano de publicação do livro
  /// @return Ano de publicação do livro
  unsigned getAno();

private:

  /// @brief Configura o ISBN do livro, seguindo modelo de 13 dígitos "XXX-XX-XXX-XXXX-X"
  /// @param isbn Código ISBN do livro
  /// @return True se bem sucedido, False se falhou
  bool _setISBN(unsigned long isbn);

  /// @brief Configura o ano de publicação do livro
  /// @param ano Ano de publicação do livro
  /// @return True se bem sucedido, False se falhou
  bool _setAnoPublicacao(unsigned ano);  // Configura o ano de publicação do livro


  /// @brief Código ISBN do livro
  unsigned long _isbn;
  /// @brief Nome do livro
  string _nomeLivro;
  /// @brief Assunto do livro
  string _assunto;
  /// @brief Nome do autor do livro
  string _autor;
  /// @brief Ano de publicação do livro
  unsigned _anoPublicacao;
};