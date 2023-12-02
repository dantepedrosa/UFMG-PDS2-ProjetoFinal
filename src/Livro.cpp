#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Livro.hpp"


Livro::Livro(CodISBN isbn, std::string nomeLivro, std::string assunto, std::string autor, unsigned ano)
    : _nomeLivro(nomeLivro), _assunto(assunto), _autor(autor) {
        _setAnoPublicacao(ano);
        _setISBN(isbn);
    }


CodISBN Livro::getISBN(){
    return _isbn;
}


std::string Livro::getNome(){
    return _nomeLivro;
}


std::string Livro::getAssunto(){
    return _assunto;
}


std::string Livro::getAutor(){
    return _autor;
}


unsigned Livro::getAno(){
    return _anoPublicacao;
}


bool Livro::_setISBN(CodISBN isbn){

    // Confere se o número de dígitos está correto
    if (isbn.size() != 14 || isbn[isbn.size() - 2] != '-') throw std::invalid_argument("Formato de ISBN inválido! O formato do ISBN deve ser 'XXXXXXXXXXXX-X'.");

    // Confere se dígito verificador bate
    if (!(_cmpDigitoVerificador(isbn))) throw std::invalid_argument("Dígito verificador não bate com código ISBN!");
    
    return true;
}


bool Livro::_setAnoPublicacao(unsigned ano){
    
    if (ano <= 0) throw std::invalid_argument("O ano de publicação não pode ser zero ou negativo!");

    this->_anoPublicacao = ano;

    return true;
}


bool Livro::_cmpDigitoVerificador(std::string isbn){

    std::istringstream stream(isbn);
    std::string codigo, digito;

    std::getline(stream, codigo, '-');
    std::getline(stream, digito);

    int soma = 0;

    for(auto num : codigo){
        int num_int = num - '0';
        soma += num_int;
    }

    int digito_int = isbn.back() - '0';
    int digito_calc = 10 - (soma % 10);
    

    return (digito_calc == digito_int);


}
