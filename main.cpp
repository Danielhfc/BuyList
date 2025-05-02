#include <iostream>

using namespace std;

int interface()
{
    int option = 0;

    cout << ("**************************************") << endl;
    cout << ("* LISTA DE COMPRAS *") << endl;
    cout << ("* Digite 1 para ver a lista *") << endl;
    cout << ("* Digite 2 para adicionar itens na lista *") << endl;
    cout << ("* Digite 3 para editar itens da lista *") << endl;
    cout << ("* Digite 4 para remover itens da lista *") << endl;
    cout << ("**************************************") << endl;

    cin >> option;

    return option;
}

int main()
{
    int option = 0;
    option = interface();
    cout << option;
}