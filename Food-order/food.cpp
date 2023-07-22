#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// Global map to store final order of customer
map<string, int> uni;

// Class for all functions
class foods {
public:
    void NewUser(string a, string b);
    void secure(string c, string b, string x, string y);
    void login();
    void regist();
    void menu();
    void Pizza();
    void burger();
    void SoftDrink();
    void Dess();
    void result();

private:
    bool isUserRegistered(string username);
};

bool foods::isUserRegistered(string username) {
    ifstream file("users.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string name = line.substr(0, pos);
                if (name == username) {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
    }
    return false;
}

void foods::NewUser(string a, string b) {
    string name, pass;
    cout << "Login In\n";
    cout << "Enter Username: ";
    cin >> name;

    if (isUserRegistered(name)) {
        cout << "Username already exists! Please choose a different username.\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> pass;

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << name << "," << pass << "\n";
        file.close();
        cout << "Registration successful!\n";
        secure(a, b, name, pass);
    }
    else {
        cout << "Error: Unable to open file for registration.\n";
    }
}

void foods::regist() {
    string name, pass;
    cout << "\nEnter your Username: ";
    cin >> name;

    if (isUserRegistered(name)) {
        cout << "\n\nUsername already exists! Please choose a different username.\n";
        return;
    }

    cout << "Enter your password: ";
    cin >> pass;
    NewUser(name, pass);
}


void foods::Dess()
{
    map<string, int> m = {
        {"Fruit and Cream", 90},
        {"Ice Cream", 110},
        {"Strawberry Cake", 250},
        {"Chocolate Cake", 240},
        {"Apple Pie", 150}
        // Add more dessert options and prices as needed...
    };

    cout << "Desserts\t\t\t\t\tPrice\n";
    // for each loop to display dessert options and prices
    for (const auto& i : m)
    {
        cout << i.first << "\t\t\t\t\t" << i.second << "\n";
    }
    string des;
    string res;
    do
    {
        cout << "Please Enter your Dessert: ";
        cin.ignore(); // Consume the newline character left in the input stream
        getline(cin, des);

        // Check if the chosen dessert exists in the map and directly insert into "uni" if found
        if (m.find(des) != m.end())
        {
            // uni.insert({des, m.at(des)});
            uni[des] += m.at(des);
        }
        else
        {
            cout << "Invalid Dessert Choice! Please choose from the given options.\n";
        }
        cout << "Would you like to view Desserts menu again (YES/NO): ";
        cin >> res;
        transform(res.begin(), res.end(), res.begin(), ::tolower);

    } while (res == "yes");
}

void foods ::Pizza()
{

    map<string, map<string,int>> pizzaData;

    // Adding pizza data to the nested map
    pizzaData["Margherita"] = {{"Regular", 150}, {"Medium", 200}, {"Large", 250}};
    pizzaData["Pepperoni"] = {{"Regular", 180}, {"Medium", 230}, {"Large", 280}};
    pizzaData["Cheese and Capicorn"] = {{"Regular",199},{"Medium",299},{"Large",399}};
    // Add data for other pizza types and their varieties here...

    cout << "Pizza Varieties\t\t\t\tPrice\n";

    // Display all pizza varieties with prices using nested loops
    for (const auto& pizza : pizzaData)
    {
        for (const auto& variety : pizza.second)
        {
            cout << pizza.first << " " << variety.first << "\t\t\t\t" << variety.second << "\n";
        }
    }

    string res;
    string pizza_type;
    string pizza_variety;

    do
    {
        cout << "Please Enter your Pizza Type: ";
        cin.ignore(); // Consume the newline character left in the input stream
        getline(cin, pizza_type);

        cout << "Please Enter the Pizza Variety (Regular, Medium, or Large): ";
        getline(cin, pizza_variety);

        // Check if the chosen pizza type and variety exist in the pizzaData
        auto it_type = pizzaData.find(pizza_type);
        if (it_type != pizzaData.end())
        {
            auto it_variety = it_type->second.find(pizza_variety);
            if (it_variety != it_type->second.end())
            {
                // If found, add the chosen pizza and its price to the "uni" map
                uni.insert({pizza_type + " " + pizza_variety, it_variety->second});
            }
            else
            {
                cout << "Invalid Pizza Variety! Please choose from Regular, Medium, or Large.\n";
            }
        }
        else
        {
            cout << "Invalid Pizza Type! Please choose from the given options.\n";
        }

        cout << "Would you like to view Pizza menu again (YES/NO): ";
        cin >> res;
        transform(res.begin(), res.end(), res.begin(), ::tolower);

    } while (res == "yes");
}
// For Burger
void foods ::burger()
{
    map<string,int>m;

    m.insert({"Cheese Burger",10});
    m.insert({"Veggie Burger",8});
    m.insert({"Chicken Burger",9});
    m.insert({"Aloo Burger",4});

    cout<<"Burger\t\t\t\t\tPrice\n";
    for(const auto& i : m)
    {
        cout<<i.first<<"\t\t\t\t\t"<<i.second<<"\n";
    }
    bool c = true;
    string res;
    string burgerChoice;
    do
    {
    
        cout << "Please Enter your Burger choice: ";
        cin.ignore();
        getline(cin, burgerChoice);

        auto it = m.find(burgerChoice);
        if (it != m.end())
        {
            uni.insert({it->first, it->second});
        }
        else
        {
            cout<<"Invalid Burger choice!!";
        }
        cout << "Would you like to view Burger menu again (YES/NO): ";
        cin >> res;
        transform(res.begin(), res.end(), res.begin(), ::tolower);

    } while (res == "yes");    
}
void foods::SoftDrink()

{
    map<string, int> m = {
        {"Coca-Cola", 50},
        {"Pepsi", 45},
        {"Sprite", 40},
        {"Fanta", 35},
        {"Redbull",240},
        {"Hell",60}
        // Add more soft drink options and prices as needed...
    };
    //m.insert({"coca-cola",50});

    cout << "Soft Drink Varieties\t\t\t\tPrice\n";
    for (const auto& i : m)
    {
        cout << i.first << "\t\t\t\t" << i.second << "\n";
    }

    string res;
    string drinkChoice;

    do
    {
        cout << "Please Enter your Soft Drink choice: ";
        cin.ignore();
        getline(cin, drinkChoice);

        auto it = m.find(drinkChoice);
        if (it != m.end())
        {
            uni.insert({it->first, it->second});
        }
        else
        {
            cout << "Invalid Soft Drink choice!!\n";
        }

        cout << "Would you like to view soft drink menu again (YES/NO): ";
        cin >> res;
        transform(res.begin(), res.end(), res.begin(), ::tolower);

    } while ( res == "yes");
}
// The rest of your functions remain the same...
// (Dess(), Pizza(), burger(), SoftDrink(), login(), menu(), secure(), and result())
void foods::login() {
    string name, pass;
    cout << "Enter your username: ";
    cin >> name;

    ifstream file("users.txt");
    if (file.is_open()) {
        string line;
        bool userFound = false;
        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string username = line.substr(0, pos);
                string password = line.substr(pos + 1);
                if (username == name) {
                    userFound = true;
                    cout << "Enter your Password: ";
                    cin >> pass;
                    if (password == pass) {
                        cout << "\n\nLogin Successful!\n";
                        file.close();
                        menu();
                        return;
                    }
                    else {
                        cout << "\n\nInvalid Password!\n";
                        file.close();
                        return;
                    }
                }
            }
        }

        if (!userFound) {
            cout << "\n\nUsername not found! Please register or enter a valid username.\n";
        }

        file.close();
    }
    else {
        cout << "Error: Unable to open file for login.\n";
    }
}

void foods ::menu()
{
    int c;
    int n;
    string res;
    do
    {
        std::cout<<"\n\nWhat would you like to have:\n";
        std::cout<<"Choose Order: ";
        std::cout<<"1. Desserts\n2. Pizza\n3. Burger\n4. Soft Drinks\n";
        std::cin>>n;
        switch(n)
        {
            case 1: 
            Dess();
            break;
            case 2:
            Pizza();
            break;
            case 3:
            burger();
            break;
            case 4:
            SoftDrink();
            break;
            default:
            std::cout << "Please consider from menu" ;
        }
        cout<<"Would you like to view menu again: ";
        cin>>res;
        transform(res.begin(), res.end(), res.begin(), ::tolower);
        if(res == "yes")
        {
            c = true;
        }
        else
        {
            c = false;
        }
}while(c);
    if(c!=true)
    {
        result();
    }
}
void foods ::secure(string a,string b,string c,string d)
{
    if(a == c && b == d)
    {
        menu();
    }
}
void foods ::result()
{
    int total = 0;

    std::cout << "\n\nCustomer's Order Summary:\n";
    for (const auto& item : uni)
    {
        std::cout << item.first << "\t\t\t\t" << item.second << "\n";
        total += item.second;
    }

    std::cout << "Total Order Amount: " << total << "\n";
}
int main() {
    int n;
    cout << "\t\t\t\t\t\t\t\tWelcome\n";
    cout << "Press 1 to login account\n";
    cout << "Press 2 for registration of your account\n";
    cin >> n;
    foods obj;
    if (n == 1) {
        obj.login();
    }
    else if (n == 2) {
        obj.regist();
    }
    return 0;
}
