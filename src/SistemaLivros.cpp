#include "SistemaLivros.hpp"


SistemaLivros::SistemaLivros(bool readFirst, std::string path) : bd(readFirst, path, *this){
    if(readFirst){
        bd.lerBancoDeDados(*this);
    }
}

bool SistemaLivros::adicionarLivro(Livro livro){
    
    std::string isbn = livro.getISBN();

    // Se existe um livro soma o numero de copias
    auto find = biblioteca.find(isbn);
	if (find != biblioteca.end()) {
        find->second.copias++;
        return true;
    }

    // Salva no acervo
    LivroDB dbLivro;
    
    dbLivro.nome = livro.getNome();
    dbLivro.autor = livro.getAutor();
    dbLivro.assunto = livro.getAutor();
    dbLivro.anoPublicacao = std::to_string(livro.getAno());
    dbLivro.copias = 0;

    biblioteca[isbn] = dbLivro;

    // Salva nas listas de categorias
    byAno[dbLivro.anoPublicacao].insert(isbn);
    byAssunto[dbLivro.assunto].insert(isbn);
    byAutor[dbLivro.autor].insert(isbn);

    this->salvarListas();

    return true;
}


bool SistemaLivros::editarLivro(CodISBN isbn, LivroDB livro){

    auto it = biblioteca.find(isbn);
    if (it == biblioteca.end()) {
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
    byAno[livro.anoPublicacao].insert(isbn);
    byAssunto[livro.assunto].insert(isbn);
    byAutor[livro.autor].insert(isbn);

    std::cout << "Livro editado com sucesso." << std::endl;
    return true;
}


bool SistemaLivros::removerLivro(Livro livro){

    CodISBN isbn = livro.getISBN();
    auto it = biblioteca.find(isbn);
    if (it == biblioteca.end()) {
        std::cout << "Livro não encontrado na biblioteca." << std::endl;
        return false;
    }

    std::string ano = std::to_string(livro.getAno());
    std::string assunto = livro.getAssunto();
    std::string autor = livro.getAutor();

    biblioteca.erase(it);
    byAno[ano].erase(isbn);
    byAssunto[assunto].erase(isbn);
    byAutor[autor].erase(isbn);

    std::cout << "Livro removido com sucesso." << std::endl;
    return true;
}


bool SistemaLivros::salvarListas(){
    bd.salvarAcervo(*this);
    bd.salvarCategorias(*this);
}


bool SistemaLivros::emprestarLivro(CodISBN isbn, UsuarioComum &u){

    auto it = biblioteca.find(isbn);
    if (it == biblioteca.end()) {
        std::cerr << "Livro não encontrado na biblioteca." << std::endl;
        return false;
    }

	if(u.livrosEmprestados.size() >= 5){
		std::cerr << "O usuário já alcançou o limite de livros emprestados" << std::endl;
		return false;
	}

    std::pair<CodISBN, std::string> dado;
    dado.first = isbn;
    dado.second = u.getNome();

    livrosEmprestados.push_back(dado);

    std::cout << "Livro emprestado com sucesso." << std::endl;
    return true;

}
