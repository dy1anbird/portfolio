#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "split.h"

using namespace std;

// ---------- Struct Definitions ----------
struct Customer {
    int id;
    string name;
    string street;
    string city;
    string state;
    string zip;
    string phone;
    string email;
};

struct Item {
    int id;
    string description;
    double price;
};

// ---------- Global Data ----------
vector<Customer> customers;
vector<Item> items;

// ---------- Function Declarations ----------
void read_customers(const string& filename);
void read_items(const string& filename);
int find_cust_idx(int cust_id);
int find_item_idx(int item_id);
void one_customer_order();

// ---------- Function Implementations ----------

// Reads all customers from file and loads into global vector
void read_customers(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: could not open " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(infile, line)) {
        auto fields = split(line, ',');
        if (fields.size() != 8) continue; // skip malformed lines

        Customer c;
        c.id = stoi(fields[0]);
        c.name = fields[1];
        c.street = fields[2];
        c.city = fields[3];
        c.state = fields[4];
        c.zip = fields[5];
        c.phone = fields[6];
        c.email = fields[7];
        customers.push_back(c);
    }

    cout << "Loaded " << customers.size() << " customers." << endl;
}

// Reads all items from file and loads into global vector
void read_items(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: could not open " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(infile, line)) {
        auto fields = split(line, ',');
        if (fields.size() != 3) continue;

        Item i;
        i.id = stoi(fields[0]);
        i.description = fields[1];
        i.price = stod(fields[2]);
        items.push_back(i);
    }

    cout << "Loaded " << items.size() << " items." << endl;
}

// Find index of customer by ID
int find_cust_idx(int cust_id) {
    for (size_t i = 0; i < customers.size(); ++i)
        if (customers[i].id == cust_id)
            return static_cast<int>(i);
    return -1;
}

// Find index of item by ID
int find_item_idx(int item_id) {
    for (size_t i = 0; i < items.size(); ++i)
        if (items[i].id == item_id)
            return static_cast<int>(i);
    return -1;
}

// Process one customer's grocery order
void one_customer_order() {
    cout << "\nEnter customer number: ";
    int cust_id;
    cin >> cust_id;

    int cust_idx = find_cust_idx(cust_id);
    if (cust_idx == -1) {
        cout << "Customer not found. Exiting program." << endl;
        return;
    }

    cout << "Customer: " << customers[cust_idx].name << endl;
    cout << "Enter item numbers to purchase (0 to finish):" << endl;

    int item_id;
    int item_count = 0;
    double total_cost = 0.0;

    while (true) {
        cout << "Item number: ";
        cin >> item_id;

        if (item_id == 0) break;

        int item_idx = find_item_idx(item_id);
        if (item_idx == -1) {
            cout << "Item not found. Try again." << endl;
            continue;
        }

        cout << "  " << items[item_idx].description
             << " - $" << fixed << setprecision(2) << items[item_idx].price << endl;

        total_cost += items[item_idx].price;
        item_count++;
    }

    cout << "\nSummary:" << endl;
    cout << "  Items purchased: " << item_count << endl;
    cout << "  Total cost: $" << fixed << setprecision(2) << total_cost << endl;
}

// ---------- Main ----------
int main() {
    read_customers("customers.txt"); // Step 1
    read_items("items.txt");         // Step 2
    one_customer_order();            // Steps 3–7
    return 0;
}