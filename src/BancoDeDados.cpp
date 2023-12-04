#include "BancoDeDados.hpp"

BancoDeDados::BancoDeDados(bool readFirst, std::string path, SistemaLivros &sl) {
    
    _setFolderPath(path);

    if (readFirst){
        lerBancoDeDados(sl);
    }
}

void BancoDeDados::lerBancoDeDados(SistemaLivros &sl){
    
    // Lê o arquivo referente à cada uma das listas
    sl.biblioteca = _lerAcervo(_folderPath, FILE_ACERVO);
    sl.livrosEmprestados = _lerEmprestimos(_folderPath, FILE_EMPRESTIMOS);
    sl.byAutor = _lerCategoria(_folderPath, FILE_AUTOR);
    sl.byAssunto = _lerCategoria(_folderPath, FILE_ASSUNTO);
    sl.byAno = _lerCategoria(_folderPath, FILE_ANO);

    return;
}


void BancoDeDados::salvarAcervo(SistemaLivros &sl){
    
    // Abertura e escrita  do arquivo do acervo FILE_ACERVO
    std::string nomeArquivo = _folderPath + FILE_ACERVO;
    std::ofstream arquivo(nomeArquivo, std::ofstream::trunc);   // Apagará o arquivo antes de escrever
    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    for(std::pair<CodISBN, LivroDB> pair : sl.biblioteca){
        std::string dado = (
            pair.first.append(",") + \
            pair.second.nome.append(",") + \
            pair.second.autor.append(",") + \
            pair.second.assunto.append(",") + \
            pair.second.anoPublicacao.append(",") + \
            std::to_string(pair.second.copias).append("\n")
        );
        arquivo << dado;
    }

    // Abertura e escrita do arquivo do acervo FILE_EMPRESTIMOS
    std::string nomeArquivo = _folderPath + FILE_EMPRESTIMOS;
    std::ofstream arquivo(nomeArquivo, std::ofstream::trunc);   // Apagará o arquivo antes de escrever
    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    for(std::pair<CodISBN, std::string> pair : sl.livrosEmprestados){
        std::string dado = (
            pair.first.append(",") + \
            pair.second.append("\n")
        );
        arquivo << dado;
    }

    arquivo.close();

    return;
}


void BancoDeDados::salvarCategorias(SistemaLivros &sl){

    // Abertura e escrita  do arquivo do acervo FILE_AUTOR
    std::string nomeArquivo = _folderPath + FILE_AUTOR;
    std::ofstream arquivo(nomeArquivo, std::ofstream::trunc);   // Apagará o arquivo antes de escrever
    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    for(auto categoria : sl.byAutor){
        arquivo << categoria.first;
        for(auto isbn : categoria.second){
            arquivo << ',' << isbn;
        }
        arquivo << '\n';
    }

    arquivo.close();

    // Abertura e escrita  do arquivo do acervo FILE_ASSUNTO
    std::string nomeArquivo = _folderPath + FILE_ASSUNTO;
    std::ofstream arquivo(nomeArquivo, std::ofstream::trunc);   // Apagará o arquivo antes de escrever
    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    for(auto categoria : sl.byAssunto){
        arquivo << categoria.first;
        for(auto isbn : categoria.second){
            arquivo << ',' << isbn;
        }
        arquivo << '\n';
    }

    arquivo.close();

    // Abertura e escrita  do arquivo do acervo FILE_ANO
    std::string nomeArquivo = _folderPath + FILE_ANO;
    std::ofstream arquivo(nomeArquivo, std::ofstream::trunc);   // Apagará o arquivo antes de escrever
    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    for(auto categoria : sl.byAno){
        arquivo << categoria.first;
        for(auto isbn : categoria.second){
            arquivo << ',' << isbn;
        }
        arquivo << '\n';
    }

    arquivo.close();

    return;
}


std::map<CodISBN, LivroDB> BancoDeDados::_lerAcervo(std::string path, std::string nome){
    
    // Abertura do arquivo
    std::string nomeArquivo = path + nome;
    std::ifstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    std::map<CodISBN, LivroDB> dados;
    std::string linha;
    
    // Salva cada linha do arquivo
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

    // Abertura do arquivo
    std::string nomeArquivo = path + nome;
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    std::vector<std::pair<CodISBN, std::string>> dados;
    std::string linha;
    
    // Salva cada linha do arquivo
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

    // Abertura do arquivo
    std::string nomeArquivo = path + nome;
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) throw std::runtime_error("Erro ao abrir o arquivo!");

    std::map<std::string, std::set<CodISBN>> dados;
    std::string linha;
    
    // Salva cada linha do arquivo
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

    return;
}
