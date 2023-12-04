#include "SistemaLivros.hpp"


bool SistemaLivros::adcionarLivro(Livro livro){
    
	if (_biblioteca.find(livro.getISBN()) != _biblioteca.end()) {
        std::cout << "Livro já existente na biblioteca." << std::endl;
        return false;
    }

    _biblioteca[livro.getISBN()] = {
        livro.getNome(),
        livro.getAutor(),
        livro.getAssunto(),
        livro.getAno()
    };

    _byAno[livro.getAno()].insert(livro.getISBN());
    _byAssunto[livro.getAssunto()].insert(livro.getISBN());
    _byAutor[livro.getAutor()].insert(livro.getISBN());

    bd.salvarAcervo(*this);

    std::cout << "Livro adicionado com sucesso." << std::endl;
    return true;
}


bool SistemaLivros::adcionarLivro(CodISBN isbn){
    // TODO - Implementar função
}


bool SistemaLivros::editarLivro(CodISBN isbn, LivroDB livro){
    auto it = _biblioteca.find(isbn);
    if (it == _biblioteca.end()) {
        std::cout << "Livro não encontrado na biblioteca." << std::endl;
        return false;
    }

    // atualizando as informacoes do livro
    it->second.nome = livro.nome;
    it->second.autor = livro.autor;
    it->second.assunto = livro.assunto;
    it->second.anoPublicacao = livro.anoPublicacao;
    it->second.copias = livro.copias;

    // atualizando nas listas
    _byAno[livro.anoPublicacao].insert(isbn);
    _byAssunto[livro.assunto].insert(isbn);
    _byAutor[livro.autor].insert(isbn);

    std::cout << "Livro editado com sucesso." << std::endl;
    return true;
}


bool SistemaLivros::removerLivro(Livro livro){

    CodISBN isbn = livro.getISBN();
    auto it = _biblioteca.find(isbn);
    if (it == _biblioteca.end()) {
        std::cout << "Livro não encontrado na biblioteca." << std::endl;
        return false;
    }

    unsigned ano = livro.getAno();
    std::string assunto = livro.getAssunto();
    std::string autor = livro.getAutor();

    _biblioteca.erase(it);
    _byAno[ano].erase(isbn);
    _byAssunto[assunto].erase(isbn);
    _byAutor[autor].erase(isbn);

    std::cout << "Livro removido com sucesso." << std::endl;
    return true;
}


bool SistemaLivros::salvarListas(){
    // TODO - Implementar função
}


bool SistemaLivros::emprestarLivro(CodISBN isbn, UsuarioComum &u){

    auto it = _biblioteca.find(isbn);
    if (it == _biblioteca.end()) {
        std::cerr << "Livro não encontrado na biblioteca." << std::endl;
        return false;
    }

	if(temLivroEmprestado){
		std::cerr << "O usuário já possui um livro emprestado." << std::endl;
		return false;
	}


    _livrosEmprestados.push_back(std::make_pair(isbn, u.getNome()));

    std::cout << "Livro emprestado com sucesso." << std::endl;
    return true;

}


bool SistemaLivros::devolverLivro(CodISBN isbn){
    // TODO - Implementar função
}
