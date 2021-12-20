#include "projeto1.h"

list<dados_cliente> lista_classe;

void menu_atendente(list<dados_cliente> list)
{

    int horas;
    timeval horario_chamada;
    gettimeofday(&horario_chamada, NULL);
    horas = horario_chamada.tv_sec;
    int difereca;

    list = lista_classe;

    for (auto & x : list)
    {
        //difereca = (horas - x.senha.horario)/60;
        difereca = 4;
        if (difereca >= x.classe.tempo)
        {
           for(auto &y:list)
           {
               y.classe.nivel_prio = y.classe.nivel_prio +1;
           }
            x.classe.nivel_prio = 1;
        }

    }

    if (list.size()== 0)
    {
        cout << "-------------------------------------------------" << endl;
        cout << "Não há senhas à serem chamadas!" << endl;
        cout << "-------------------------------------------------" << endl;
    }

    list.sort(prioridade);
    dados_cliente aux = list.front();
    cout << "-------------------------------------------------" << endl;
    cout  << "Senha chamada: " << aux.senha.cod_Senha << endl;
    cout << "-------------------------------------------------" << endl;


    for(auto &teste: list)
    {
        cout << teste.senha.cod_Senha << endl;
    }
    list.pop_front();
    lista_classe = list;

}

void gerar_senha(dados_cliente dados_aux)
{
    cout << dados_aux.classe.codigo << endl;

  for(auto & x: lista_classe)
  {
      if(x.classe.codigo == dados_aux.classe.codigo)
      {
          dados_aux.classe.cont++;
      }

  }

    dados_aux.senha.cod_Senha = dados_aux.classe.codigo + to_string(dados_aux.classe.cont);
    timeval  horario_cliente;
    gettimeofday(&horario_cliente, NULL);
    dados_aux.senha.horario = horario_cliente.tv_sec;

    cout << "-------------------------------------------------" << endl;
    cout << "Sua senha é: " << dados_aux.senha.cod_Senha << endl;
    cout << "-------------------------------------------------" << endl;

    lista_classe.push_back(dados_aux);
}




