#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Patient {
public:
    int id;
    string name, disease;

    Patient(int i, string n, string d) {
        id = i;
        name = n;
        disease = d;
    }
};

class Hospital {
    vector<Patient> patients;

public:
    void addPatient() {
        int id;
        string name, disease;

        cout << "Enter Patient ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Patient Name: ";
        getline(cin, name);

        cout << "Enter Disease: ";
        getline(cin, disease);

        patients.push_back(Patient(id, name, disease));
        cout << " Patient added successfully!\n\n";
    }

    void viewPatients() {
        if (patients.empty()) {
            cout << "⚠ No patient records found!\n\n";
            return;
        }

        cout << left << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(20) << "Disease" << endl;
        cout << "-----------------------------------------\n";

        for (auto &p : patients) {
            cout << left << setw(10) << p.id
                 << setw(20) << p.name
                 << setw(20) << p.disease << endl;
        }
        cout << endl;
    }

    void searchPatient() {
        int id;
        cout << "Enter Patient ID to search: ";
        cin >> id;

        for (auto &p : patients) {
            if (p.id == id) {
                cout << "\nPatient Found!\n";
                cout << "ID: " << p.id << endl;
                cout << "Name: " << p.name << endl;
                cout << "Disease: " << p.disease << endl << endl;
                return;
            }
        }
        cout << " Patient not found!\n\n";
    }

    void deletePatient() {
        int id;
        cout << "Enter Patient ID to delete: ";
        cin >> id;

        for (auto it = patients.begin(); it != patients.end(); it++) {
            if (it->id == id) {
                patients.erase(it);
                cout << "🗑 Patient record deleted successfully!\n\n";
                return;
            }
        }
        cout << " Patient not found!\n\n";
    }
};

int main() {
    Hospital h;
    int choice;

    while (true) {
        cout << "===== Hospital Management System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Delete Patient\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: h.addPatient(); break;
            case 2: h.viewPatients(); break;
            case 3: h.searchPatient(); break;
            case 4: h.deletePatient(); break;
            case 5: cout << "Exiting... Thank you!\n"; return 0;
            default: cout << "⚠ Invalid choice! Try again.\n\n";
        }
    }
}
