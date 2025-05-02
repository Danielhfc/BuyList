#include <iostream>

using namespace std;

class item
{
public:
    string name;
    float price;
    int priority;
    string details;
    string url;

    item(const string &name, float price, int priority, string details, string url) : name(name), price(price), priority(priority), details(details), url(url) {}
};

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