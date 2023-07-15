#include <iostream>
#include <fstream>
#include "TRLS.h"
#include "functions.h"

using namespace std;

int main() {

    cout << "Radio Location System!\n";

    double t0, t1, dt, x, y, r;
    int amount;
    ofstream outfile("..\\output.txt");
    ofstream outcsv("..\\output.csv");

    cout << "Select an option:\n";
    {
        cout << "1. Manual entering targets data.\n";
        cout << "2. Randomly generating targets data.\n";
    }
    int option;
    cin >> option;

    switch (option) {
        case 1: {
            cout << "Targets will fill from file\n";
            string infile = "..\\input.txt";
            console_initialization(t0, t1, dt, x, y, r);
            amount = get_amount_target_from_file(infile);
            TRLS rls(infile, x, y, r, t0, amount);
            rls.Peleng(outfile, outcsv, t0, t1, dt);
            break;
        }
        case 2: {
            cout << "Targets will randomly spawn in the range from " << MIN_TARGETS << " to " << MAX_TARGETS << endl;
            amount = int(randomaizer(MIN_TARGETS, MAX_TARGETS));
            console_initialization(t0, t1, dt, x, y, r);
            TRLS rls(amount, x, y, r, t0);
            rls.Peleng(outfile, outcsv, t0, t1, dt);
            break;
        }
        default:
            cout << "Error: wrong option selected";
            system("pause");
            exit(1);
    }

    outfile.close();
    outcsv.close();
    cout << "\n ALL DONE! Check output.txt and output.csv file\n";
    system("pause");
    return 0;

}
