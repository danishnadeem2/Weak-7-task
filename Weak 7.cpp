#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM_CHARITIES = 3;

// Structure to store charity information
struct Charity 
{
    string name;
    int totalDonation;
};

// Function prototypes
void setupCharities(vector<Charity>& charities)
{
    for (int i = 0; i < NUM_CHARITIES; ++i)
    {
        cout << "Enter the name of Charity " << i + 1 << ": ";
        getline(cin, charities[i].name);
        charities[i].totalDonation = 0;
    }
}
void displayCharities(const vector<Charity>& charities)
{
    cout << "Choose a charity (1, 2, 3) or enter -1 to show totals:" << endl;
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << i + 1 << ". " << charities[i].name << endl;
    }
}

int getCharityChoice() 
{
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    return choice;
}

double getShoppingBill()
{
    double shoppingBill;
    cout << "Enter the shopping bill amount: $";
    cin >> shoppingBill;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    return shoppingBill;
}

double calculateDonation(double shoppingBill) 
{
    return 0.01 * shoppingBill;
}

void recordAndTotalDonation(vector<Charity>& charities, int choice, double donation) 
{
    charities[choice - 1].totalDonation += donation;
}

void showTotals(const vector<Charity>& charities) 
{
    cout << "Charity Totals:" << endl;
    for (const auto& charity : charities) 
    {
        cout << charity.name << ": $" << fixed << setprecision(2) << charity.totalDonation << endl;
    }
}

void displayGrandTotal(const vector<Charity>& charities) 
{
    double grandTotal = 0;
    for (const auto& charity : charities) 
    {
        grandTotal += charity.totalDonation;
    }

    cout << "GRAND TOTAL DONATED TO CHARITY: $" << fixed << setprecision(2) << grandTotal << endl;
}


int main() 
{
    vector<Charity> charities(NUM_CHARITIES);
    setupCharities(charities);

    int choice;
    do {
        displayCharities(charities);
        choice = getCharityChoice();

        if (choice >= 1 && choice <= NUM_CHARITIES) {
            double shoppingBill = getShoppingBill();
            double donation = calculateDonation(shoppingBill);

            recordAndTotalDonation(charities, choice, donation);

            cout << "Donation of $" << fixed << setprecision(2) << donation << " recorded for " << charities[choice - 1].name << " charity." << endl;
        }
        else if (choice != -1) {
            cout << "Invalid choice. Please enter 1, 2, 3, or -1." << endl;
        }
    } while (choice != -1);

    showTotals(charities);
    displayGrandTotal(charities);

    return 0;
}


