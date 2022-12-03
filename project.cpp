#include <iostream>
#include<istream>
#include <algorithm>
#include <limits>

using namespace std;

void reactions(){
    cout << "Formation of Methanol: CO2 + 3H2 -> CH3OH + H2O" << endl;
    cout << "Formation of Acetic Acid: CO2 + CH4 -> CH3COOH" << endl;
    cout << "Formation of Dimethyl Ether: CO2 + H2 -> CH3OCH3" << endl;
}

void methanol(double mol_CO2, double* mol_methanol, double* mol_hydrogen, double* mol_water, double* price){
    *mol_methanol = mol_CO2;
    *mol_hydrogen = 3 * mol_CO2;
    *mol_water = mol_CO2;
    *price = mol_CO2 * 32.04 * 0.338 / 1000;
}

void acetic(double mol_CO2, double* mol_acetic, double* mol_methane, double* price){
    *mol_acetic = mol_CO2;
    *mol_methane = mol_CO2;
    *price = mol_CO2 * 60.05 * 0.838 / 1000;
}

void DME(double mol_CO2, double* mol_DME, double* mol_hydrogen, double* price){
    *mol_DME = mol_CO2;
    *mol_hydrogen = mol_CO2;
    *price = mol_CO2 * 46.07 * 0.841 / 1000;
}

int main() {
    int choice, measurement, reaction_choice;
    double amount_CO2, mol_CO2;
    double mol_methanol, mol_hydrogen, mol_water, mol_acetic, mol_methane, mol_DME, price;
    double MM_metric = 44.01;
    int control = 1;
    char loop;

    while (control == 1) {
        cout << "What would you like to do today?" << endl;
        cout << endl;
        cout << "1. I am using my Carbon Dioxide to form a certain chemical?" << endl;
        cout << "2. Can I see a list of reactions that use Carbon Dioxide?" << endl;

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');


        if (choice == 1) {
            cout << "How much Carbon Dioxide do you have?" << endl;
            cin >> amount_CO2;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Is this in:" << endl;
            cout << "1. Kilogram (kg)" << endl;
            cout << "2. Pounds (lbs)" << endl;
            cout << "3. Moles (mol)/n" << endl;
            cin >> measurement;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (measurement == 1) {
                mol_CO2 = amount_CO2 * 1000 / MM_metric;
            } else if (measurement == 2) {
                mol_CO2 = amount_CO2 * 454 / MM_metric;
            } else if (measurement == 3) {
                mol_CO2 = amount_CO2;
            }

            cout << "What Product are you making?" << endl;
            cout << "1. Methanol" << endl;
            cout << "2. Acetic Acid" << endl;
            cout << "3. Dimethyl Ether" << endl;
            cout << "4. Can I see the list of reactions?" << endl;

            cin >> reaction_choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (reaction_choice == 1) {
                methanol(mol_CO2, &mol_methanol, &mol_hydrogen, &mol_water, &price);
                cout << "With " << mol_CO2 << " moles of CO2 and " << mol_hydrogen << " moles of Hydrogen you can produce "
                     << mol_methanol << " moles of Methanol and " << mol_water << " moles of Water." << endl;
                cout << " The Methanol can be sold for " << price << " US dollars." << endl;
            } else if (reaction_choice == 2) {
                acetic(mol_CO2, &mol_acetic, &mol_methane, &price);
                cout << "With " << mol_CO2 << " moles of CO2 and " << mol_methane << " moles of Methane you can produce "
                    << mol_acetic << " moles of Acetic Acid." << endl;
                cout << " The Acetic ACid can be sold for " << price << " US dollars." << endl;
            } else if (reaction_choice == 1) {
                DME(mol_CO2, &mol_DME, &mol_hydrogen, &price);
                cout << "With " << mol_CO2 << " moles of CO2 and " << mol_hydrogen << " moles of Hydrogen you can produce "
                     << mol_DME << " moles of Dimethyl Ether." << endl;
                cout << " The Dimethyl Ether can be sold for " << price << " US dollars." << endl;
            }
        } else if (choice == 2) {
            reactions();
        } else {
            cout << "Please enter a correct number." << endl;
        }

        cout << "Would you like to continue Y/N?" << endl;
        cin >> loop;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (loop == 'N') {
            control = 2;
        }

    }

    return 0;
}
