#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int searchSymbol(vector<char> symbol, char k)
{
    for (int i = 0; i < symbol.size(); i++)
    {
        if (symbol[i] == k)
        {
            return i;
        }
    }
    return -1;
}

void viewTable(vector<char> symbol)
{
    vector<int> address;
    vector<string> type;
    for (int i = 0; i < symbol.size(); i++)
    {
        address.push_back(rand());
        int k = int(symbol.at(i));
        if ((k >= 65 && k <= 90) || (k >= 97 && k <= 122))
        {
            type.push_back("Identifier");
        }
        else if (k >= 48 && k <= 57)
        {
            type.push_back("Constant");
        }
        else if (k <= 38)
        {
            type.push_back("Special symbol");
        }
        else
        {
            type.push_back("Operator");
        }
    }
    cout << "Symbol\tAddress\tType" << endl;
    for (int i = 0; i < symbol.size(); i++)
    {
        cout << symbol.at(i) << "  " << address.at(i) << "   " << type.at(i) << endl;
    }
}

int main()
{
    // identifier, operators, special symbols,constants
    vector<char> symbol;
    int n = 1;
    while (n > 0)
    {
        int choice;
        cout << "\n1. Create table.\n2. Search table.\n3. Enter symbol.\n4. Remove symbol.\n5. View table.\n6. Exit";
        cout << "\nEnter your choice:" << endl;
        cin >> choice;
        char ele;
        string s;
        switch (choice)
        {
        case 1:
            int l;
            cout << "length:";
            cin >> l;
            cout << "Enter the expression: ";
            cin >> s;

            for (int i = 0; i < l; i++)
            {
                symbol.push_back(s[i]);
            }
            break;

        case 2:
            cout << "Enter the symbol to be searched: ";
            cin >> ele;
            if (searchSymbol(symbol, ele) >= 0)
                cout << "Symbol " << ele << " found at position: " << searchSymbol(symbol, ele);
            else
                cout << "Symbol not found";
            break;

        case 3:
            cout << "Enter the symbol:";
            cin >> ele;
            symbol.push_back(ele);
            break;

        case 4:
            cout << "Enter the symbol to be removed: ";
            cin >> ele;
            // int index=searchSymbol(symbol,ele);
            symbol.erase(symbol.begin() + searchSymbol(symbol, ele));
            cout << "The symbol '" << ele << "' is successfully removed." << endl;
            break;

        case 5:
            viewTable(symbol);
            break;

        case 6:
            n = 0;
            break;
        }
    }

    return 0;
}
