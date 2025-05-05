#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Item
{
public:
    string name;
    float price;
    string details;
    string url;

    Item(const string &name, float price, string details, string url) : name(name), price(price), details(details), url(url) {}
};

class WishList
{
private:
    vector<Item> itens;

public:
    void addItem(const string &name, float price, string details, string url)
    {
        itens.emplace_back(name, price, details, url);
    }

    void removeItem(int priority)
    {
        priority--;
        if (priority <= itens.size())
        {
            itens.erase(itens.begin() + priority);
            cout << "Item '" << priority << "' removido da lista.\n";
        }
        else
        {
            cout << "Item '" << priority << "' nao encontrado.\n";
        }
    }

    void editItem(int priority)
    {
        priority--;

        if (priority <= itens.size())
        {
            string name;
            float price;
            string details;
            string url;

            cout << "Nome" << endl;
            getline(cin, name);
            cout << "Preco" << endl;
            cin >> price;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Detalhes" << endl;
            getline(cin, details);
            cout << "URL" << endl;
            getline(cin, url);

            itens[priority].name = name;
            itens[priority].price = price;
            itens[priority].details = details;
            itens[priority].url = url;
        }
    }

    void showList()
    {
        int priority = 1;
        for (const auto &item : itens)
        {
            cout << priority++ << " - " << item.name << " - R$" << item.price << endl;
            cout << item.details << endl
                 << item.url << endl;
        }
    }
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return option;
}

int main()
{
    WishList buyList;

    string name;
    float price;
    int priority;
    string details;
    string url;

    int option = 1;

    while (option != 0)
    {
        option = interface();

        switch (option)
        {
        case 1:
            buyList.showList();
            break;

        case 2:
            cout << "Nome" << endl;
            getline(cin, name);
            cout << "Preco" << endl;
            cin >> price;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Detalhes" << endl;
            getline(cin, details);
            cout << "URL" << endl;
            getline(cin, url);

            buyList.addItem(name, price, details, url);
            break;

        case 3:
            cout << "Digite a posicao do item o qual deseja editar" << endl;
            cin >> priority;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            buyList.editItem(priority);
            break;

        case 4:
            cout << "Digite a posicao do item o qual deseja remover" << endl;
            cin >> priority;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            buyList.removeItem(priority);
            break;

        default:
            break;
        }
    }
}

// TODO: teste
// Melhorar interface? Imagens, web, etc
// Gravacao em arquivos