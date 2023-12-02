#include <string>


typedef std::string CodISBN;

class Livro {
public:

  /// @brief Construtor da classe livro
  /// @param isbn Código ISBN do livro
  /// @param nomeLivro Nome do livro
  /// @param assunto Assunto do livro 
  /// @param autor Autor do livro
  /// @param ano Ano de publicação
  Livro(
    CodISBN isbn, 
    std::string nomeLivro, 
    std::string assunto, 
    std::string autor, 
    unsigned ano
  );

  /// @brief Retorna o ISBN do livro
  /// @return Código ISBN do livro
  CodISBN getISBN();

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

  /// @brief Configura o ISBN do livro, seguindo modelo de 13 dígitos "XXXXXXXXXXXX-X"
  /// @details O código deve ser conferido a partir da fórmula a seguir, onde o último character deve bater com o calculado.
  /// \f[ x_{13}=10-((x_1+x_2+x_3+...+x_{11}+x_{12}) \text{ mod }10 ) \f]
  /// @param isbn Código ISBN do livro
  /// @return True se bem sucedido, False se falhou
  bool _setISBN(std::string isbn);

  /// @brief Configura o ano de publicação do livro
  /// @param ano Ano de publicação do livro
  /// @return True se bem sucedido, False se falhou
  bool _setAnoPublicacao(unsigned ano);

  /// @brief Calcula o dígito verificador do ISBN e compara com o original
  /// @param isbn Código ISBN do livro
  /// @return True se dígitos batem
  bool _cmpDigitoVerificador(std::string isbn);


  CodISBN _isbn;            ///< Código ISBN do livro
  std::string _nomeLivro;   ///< Nome do livro
  std::string _assunto;     ///< Assunto do livro
  std::string _autor;       ///< Nome do autor do livro
  unsigned _anoPublicacao;  ///< Ano de publicação do livro

};
