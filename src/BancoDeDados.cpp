#include "BancoDeDados.hpp"

BancoDeDados::BancoDeDados(bool readFirst, std::string path, SistemaLivros &sl) {
    
    _setFolderPath(path);

    if (readFirst){
        lerBancoDeDados(sl);
    }
    


}

bool BancoDeDados::lerBancoDeDados(SistemaLivros &sl){
    
    sl.biblioteca = _lerAcervo(_folderPath, FILE_ACERVO);
    sl.livrosEmprestados = _lerEmprestimos(_folderPath, FILE_EMPRESTIMOS);
    sl.byAutor = _lerCategoria(_folderPath, FILE_AUTOR);
    sl.byAssunto = _lerCategoria(_folderPath, FILE_ASSUNTO);
    sl.byAno = _lerCategoria(_folderPath, FILE_ANO);

}

bool BancoDeDados::salvarAcervo(SistemaLivros &sl){
    // TODO - Implementar função
}

bool BancoDeDados::salvarCategorias(SistemaLivros &sl){
    // TODO - Implementar função
}

std::map<CodISBN, LivroDB> BancoDeDados::_lerAcervo(std::string path, std::string nome){
    
    std::string nomeArquivo = path + nome;
    std::ifstream arquivo(nomeArquivo);
    std::map<CodISBN, LivroDB> dados;

    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    std::string linha;
    
    while (std::getline(arquivo, linha)) {
        std::stringstream linhaStream(linha);

        std::pair<CodISBN, LivroDB> parDados;
        LivroDB livro;
        std::string dado;

        // Realiza a leitura dos dados
        std::getline(linhaStream, dado, ',');   // Captura o código ISBN
        parDados.first = dado;
        std::getline(linhaStream, dado, ',');   // Captura o nome
        livro.nome = dado;
        std::getline(linhaStream, dado, ',');   // Captura o nome do autor
        livro.autor = dado;
        std::getline(linhaStream, dado, ',');   // Captura o assunto
        livro.assunto = dado;
        std::getline(linhaStream, dado, ',');   // Captura o ano de publicação
        livro.anoPublicacao = std::stoul(dado);
        std::getline(linhaStream, dado);        // Captura o número de cópias
        livro.copias = std::stoul(dado);

        parDados.second = livro;

        dados.insert(parDados);
    }

    arquivo.close();
    
    return dados;

}


std::vector<std::pair<CodISBN, std::string>> BancoDeDados::_lerEmprestimos(std::string path, std::string nome){

    std::string nomeArquivo = path + nome;
    std::ifstream arquivo(nomeArquivo);
    std::vector<std::pair<CodISBN, std::string>> dados;

    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    std::string linha;
    
    while (std::getline(arquivo, linha)) {
        std::stringstream linhaStream(linha);

        std::pair<CodISBN, std::string> parDados;
        std::string dado;

        // Realiza a leitura dos dados
        std::getline(linhaStream, dado, ',');   // Captura o código ISBN
        parDados.first = dado;
        std::getline(linhaStream, dado);   // Captura o nome do usuário
        parDados.second = dado;

        dados.push_back(parDados);
    }

    arquivo.close();
    
    return dados;

}


std::map<std::string, std::set<CodISBN>> BancoDeDados::_lerCategoria(std::string path, std::string nome){

    std::string nomeArquivo = path + nome;
    std::ifstream arquivo(nomeArquivo);
    std::map<std::string, std::set<CodISBN>> dados;

    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    std::string linha;
    
    while (std::getline(arquivo, linha)) {
        std::stringstream linhaStream(linha);

        std::pair<std::string, std::set<CodISBN>> parDados;
        std::string dado;

        // Realiza a leitura dos dados
        std::getline(linhaStream, dado, ',');   // Captura aa categoria
        parDados.first = dado;

        // Captura todos os ISBNs para o item da categoria
        while(std::getline(linhaStream, dado, ',')){
            parDados.second.insert(dado);
        }
        
        dados.insert(parDados);
        
    }

    arquivo.close();
    
    return dados;



}


void BancoDeDados::_setFolderPath(std::string path){

    if (path.back() != '\\') throw std::invalid_argument("Formato do caminho para pasta de arquivos inválido!");

    _folderPath = path;
}
