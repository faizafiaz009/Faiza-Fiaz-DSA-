#include <iostream>
using namespace std;

class Product
{
public:
    string name;
    int code;
    float price;
};

int main()
{
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    Product *p = new Product[n];

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details of product " << i + 1 << endl;

        cout << "Enter name: ";
        cin >> p[i].name;

        cout << "Enter code: ";
        cin >> p[i].code;

        cout << "Enter price: ";
        cin >> p[i].price;
    }

    cout << "\n--- Product Details ---\n";

    for(int i = 0; i < n; i++)
    {
        cout << "\nProduct Name: " << p[i].name << endl;
        cout << "Product Code: " << p[i].code << endl;
        cout << "Product Price: " << p[i].price << endl;
    }

    delete[] p;

    p = nullptr;

    return 0;
}