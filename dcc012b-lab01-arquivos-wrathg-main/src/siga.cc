#include <string>

using namespace std;

#include "siga.h"

Siga::Siga(string arquivo_dados_estudante)
{

    this->arquivo_nome = arquivo_dados_estudante;
    //  TODO: Implementar abertura de arquivo em modo binário, tanto para leitura e escrita
    // se arquivo ja existir, o conteudo pre existente não deve ser apagado. 
    // this->file_stream = ...
    
    // A função deve imprimir:
    //   SIGA: Inicializado com sucesso
    //  caso o arquivo seja aberto corretamente ou vaso contrário, 
    //   SIGA: Erro ao abrir arquivo
    this->file_stream = fstream(arquivo_dados_estudante, ios::binary | ios::ate | ios::in | ios::out);
    if(this->file_stream.is_open())
    {
        cout << "SIGA: Inicializado com sucesso" << endl;
    }
    else
    {
        cout << "SIGA: Erro ao abrir arquivo" << endl;
        return; 
    }

    // TODO: Obter numero de registros de estudante no arquivo
    // 
    // Lembre-se que o arquivo de dados de estudante é binário e 
    // que já pode conter registros de estudantes.
    // this->n_estudantes = 
    streampos tamanho;
    this->file_stream.seekg(0,ios::end);
    tamanho = file_stream.tellg();
    this->n_estudantes = tamanho/ESTUDANTE_SIZE;
    this->file_stream.seekg(0,file_stream.beg);
    cout << this->n_estudantes << " registros de estudantes" << endl;
}


int  Siga::PesquisaPorMatricula(int matricula)
{
    // TODO: implementar pesquisa por matrícula
    // Posicione o cursor para o inicio do arquivo:
    // Para i = 0 até n_estudante
    //    Ler estudante na posição corrente no arquivo
    //    Testar se é a matricula procurada, se afirmativo
    //    retorne a posiçao i.
    // Fim-Para
    // Coloque o cursor para o final do arquivo
    // retorne -1
    this->file_stream.seekg(0,file_stream.beg);
    for(int i = 0 ; i<this->n_estudantes;i++){
        int leitura = 0;
        this->file_stream.seekg(STR_MAX_SIZE + (i * ESTUDANTE_SIZE),ios::beg);
        this->file_stream.read((char*)&leitura, sizeof(int));
        if(leitura==matricula){
            this->file_stream.seekg(0,ios::end);
            return i;
        };
    }
    this->file_stream.seekg(0,ios::end);
    return -1;
}
        
void Siga::CadastraEstudante(Estudante est)
{
    // TODO: Implementar cadastro de estudante
    // Passos:
    // Testar se est já foi cadastrado
    // Se já cadastrado, saia   
    // Caso Contrário, escreva o estudante no final do arquivo 
    // e incremente o numero de estudantes
    

    this->file_stream.seekp(0,ios::end);
   if(PesquisaPorMatricula(est.ObterMatricula())== -1){
        est.EscreverNoArquivoBinario(file_stream);
        this->n_estudantes++;
   }
}
        
void Siga::ImprimeEstudantePorMatricula(int matricula)
{
    //TODO: implementar impressão de estudante por matricula.
    // Pesquisa aluno por matricula
    // Se o aluno estiver cadastrado, imprima o aluno.
    // caso contrario: Estudante não cadastrado
    if(PesquisaPorMatricula(matricula)== -1){
        cout << "Estudante não cadastrado" << endl;
        return;
    }
    this->file_stream.seekg(0,file_stream.beg);
    
   /* for(int i = 0; i<this->n_estudantes;i++){
        this->file_stream.seekg(i*ESTUDANTE_SIZE);
        int tamanho = file_stream.tellg();
        char *leitura = new char [ESTUDANTE_SIZE];
        this->file_stream.read(leitura,sizeof(char)*STR_MAX_SIZE);
        this->file_stream.seekg(sizeof(char)*STR_MAX_SIZE,ios::cur);
        this->file_stream.read(leitura,sizeof(int));
        if(matricula == (int)*leitura){
            cout << matricula <<endl;
        }
        delete [] leitura;
    }*/

    Estudante est;
    est.LerDoArquivoBinario(file_stream);
    if(matricula == est.ObterMatricula()){
        est.Imprimir();
    }

}
        
void Siga::SalvaListaEstudanteEmTexto(string arquivo_txt)
{
    //TODO: implementar salvar lista de estudantes em texto
    // A saida deve ser a seguinte formatação:
    // Primeira linha conter o cabeçalho:
    // Matricula;Nome;Ano de Ingresso;IRA
    // Demais linhas com as informações dos estudantes.
    // nao use espacos entre os campos!!
    ofstream saida = ofstream(arquivo_txt, ios::trunc);
    saida.seekp(0,saida.end);
  
    saida << "Matricula;Nome;Ano de Ingresso;IRA" << endl;
    this->file_stream.seekg(0,ios::beg);
    Estudante est;
    
    for(int i = 0; i< this->n_estudantes; i++){
        this->file_stream.seekg(i*ESTUDANTE_SIZE,ios::beg);
        est.LerDoArquivoBinario(file_stream);
        saida << est.ObterMatricula() << ";"<<est.ObterNome()<<";"<<est.ObterAnoIngresso()<<";"<<est.ObterIRA()<<endl;
    }
  
    saida.close();
}
        
        
void Siga::AlteraCadastroEstudante(Estudante est)
{
    // TODO: implementar alteração de cadastro de estudante
    // Pesquisa se o aluno com est->matricula está cadastrado
    // Se o aluno estiver cadastrado, reescreva a informação do aluno e 
    // escreva  "Dados Alterados"
    // Caso contrário, escreva: "Estudante não cadastrado"
    if(PesquisaPorMatricula(est.ObterMatricula())== -1){
        cout << "Estudante não cadastrado" << endl;
        return;
    }
    int posicao = PesquisaPorMatricula(est.ObterMatricula());
    
    file_stream.seekg(posicao * ESTUDANTE_SIZE,ios::beg);
    
    est.EscreverNoArquivoBinario(file_stream);
    cout << "Dados Alterados"<<endl;
   
   
}
        
Siga::~Siga()
{
    //TODO: fecha arquivo
    this->file_stream.close();
}

int Siga::ObterNumeroEstudantesArmazenados()
{
    return this->n_estudantes;
}
