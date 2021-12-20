#include "projeto1.h"

void menu_cliente(const list<dados_cliente> & menuOpc)
{
    string resposta;
    cout << "---------------------------" << endl << "Escolha a opção pelo símbolo da classe :" << endl << endl;

    for (auto &dado : menuOpc)
    {
        cout << dado.classe.codigo << ": " << dado.classe.descricao << endl;
    }

    cout << "Resposta: " << endl;
    cin >> resposta;

    for (auto & dados_aux : menuOpc)
    {
        if (resposta == dados_aux.classe.codigo)
        {
            gerar_senha(dados_aux);

        }
    }
}


