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
    int priority;
    string details;
    string url;

    Item(const string &name, float price, int priority, string details, string url) : name(name), price(price), priority(priority), details(details), url(url) {}
};

class WishList
{
private:
    vector<Item> itens;

public:
    void addItem(const string &name, float price, int priority, string details, string url)
    {
        itens.emplace_back(name, price, priority, details, url);
    }

    void removeItem(int priority)
    {
        auto it = std::find_if(itens.begin(), itens.end(), [&priority](const Item &item)
                               { return item.priority == priority; });

        if (it != itens.end())
        {
            itens.erase(it);
            cout << "Item '" << priority << "' removido da lista.\n";
        }
        else
        {
            cout << "Item '" << priority << "' nao encontrado.\n";
        }
    }

    void showList()
    {
        for (const auto &item : itens)
        {
            cout << item.priority << " - " << item.name << " - R$" << item.price << endl;
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
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

    int option = 1, deletePos;

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
            cout << "Prioridade" << endl;
            cin >> priority;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Detalhes" << endl;
            getline(cin, details);
            cout << "URL" << endl;
            getline(cin, url);

            buyList.addItem(name, price, priority, details, url);
            break;

        case 4:
            cout << "Digite a posicao do item o qual deseja remover" << endl;
            cin >> deletePos;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            buyList.removeItem(deletePos);

        default:
            break;
        }
    }
}