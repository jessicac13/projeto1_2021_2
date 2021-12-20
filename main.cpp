#include "projeto1.h"

int main(int argc, char * argv[]) {


    while (true) {
        int resposta;

        cout << "Você é Atendente ou Cliente?" << endl;
        cout << "1- Atendente." << endl << "2- Cliente." << endl;
        cout << "Resposta: " << endl;
        cin >> resposta;
        list<dados_cliente> lista;

        switch (resposta) {
            case 1:
                menu_atendente(lista);
                break;
            case 2:
                menu_cliente(preenche_opcoes(argv[1]));
                break;
            default:
                cout << "Resposta inválida!" << endl;
        }

    }
}

