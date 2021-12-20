#include "projeto1.h"

list<string> separa(const string & texto, const string & sep)
{
    int pos1 , pos2= 0;
    list<string> lista;

    pos1 = texto.find_first_not_of(sep, pos2);
    if(texto.empty() || pos1 == string::npos)return lista;

    while(true){

        pos2 = texto.find_first_of(sep, pos1);
        if(pos2 == string::npos)
        {
            lista.push_back(texto.substr(pos1));
            break;
        }
        lista.push_back(texto.substr(pos1, pos2 - pos1));
        pos1 = texto.find_first_not_of(sep, pos2);
    }
    return lista;
}

list<dados_cliente>  preenche_opcoes(string arquivo)
{
    list<dados_cliente> list_opc;
    ifstream arq_empresa(arquivo);

    if (!arq_empresa.is_open())
    {
        perror("Ao abrir o arquivo");
    }

    dados_cliente dados;
    list<string> lista;
    string linha;

    while (getline(arq_empresa, linha))
    {
        string resposta;

        lista = separa(linha, ",");

        dados.classe.codigo = lista.front();
        lista.pop_front();
        dados.classe.tempo = stoi(lista.front());
        lista.pop_front();
        dados.classe.descricao = lista.front();
        lista.pop_front();
        dados.classe.nivel_prio = stoi(lista.front());
        lista.pop_back();

        list_opc.push_back(dados);

    }
    return list_opc ;
}

bool prioridade(const dados_cliente & s1, const dados_cliente & s2)
{
    return s1.classe.nivel_prio < s2.classe.nivel_prio;
}
