#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

string encryptDecrypt(string text, int key) {
    for (char &c : text) c = c ^ key;
    return text;
}

class PasswordEntry {
    string site, username, password;

public:
    PasswordEntry() {}
    PasswordEntry(string s, string u, string p)
        : site(s), username(u), password(p) {}

    string getSite() const { return site; }
    string getUser() const { return username; }
    string getPass() const { return password; }

    void save(ofstream &f, int key) const {
        f << encryptDecrypt(site, key) << ","
          << encryptDecrypt(username, key) << ","
          << encryptDecrypt(password, key) << "\n";
    }

    static PasswordEntry load(const string &line, int key) {
        size_t p1 = line.find(","), p2 = line.rfind(",");
        if (p1 == string::npos || p2 == string::npos) return {};
        string s = line.substr(0, p1);
        string u = line.substr(p1 + 1, p2 - p1 - 1);
        string p = line.substr(p2 + 1);
        return PasswordEntry(encryptDecrypt(s, key),
                             encryptDecrypt(u, key),
                             encryptDecrypt(p, key));
    }

    void display() const {
        cout << left << setw(20) << site
             << setw(20) << username
             << setw(20) << password << endl;
    }
};

class Vault {
    vector<PasswordEntry> entries;
    string vaultFile = "vault.dat";
    string masterFile = "master.key";
    int key = 9;
    string masterPassword;
    bool loggedIn = false;

public:
    void setupMaster() {
        ifstream f(masterFile);
        if (f.good()) {
            string encPass;
            getline(f, encPass);
            masterPassword = encryptDecrypt(encPass, key);
            f.close();
        } else {
            cout << "Set your master password: ";
            cin >> masterPassword;
            ofstream out(masterFile);
            out << encryptDecrypt(masterPassword, key);
            out.close();
            cout << "Master password created!\n";
        }
    }

    bool login() {
        setupMaster();
        string input;
        cout << "\nEnter master password to unlock vault: ";
        cin >> input;
        if (input == masterPassword) {
            cout << "Access granted!\n";
            loggedIn = true;
        } else {
            cout << "Access denied! Wrong password.\n";
            loggedIn = false;
        }
        return loggedIn;
    }

    void load() {
        entries.clear();
        ifstream f(vaultFile);
        string line;
        while (getline(f, line))
            if (!line.empty())
                entries.push_back(PasswordEntry::load(line, key));
        f.close();
    }

    void save() {
        ofstream f(vaultFile);
        for (auto &e : entries) e.save(f, key);
        f.close();
    }

    void addEntry() {
        string site, user, pass;
        cout << "Enter site name: ";
        cin >> site;
        cout << "Enter username: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;

        entries.emplace_back(site, user, pass);
        save();
        cout << "Saved securely!\n";
    }

    void viewAll() {
        if (entries.empty()) {
            cout << "No records.\n";
            return;
        }
        cout << left << setw(20) << "SITE"
             << setw(20) << "USERNAME"
             << setw(20) << "PASSWORD" << endl;
        cout << string(60, '-') << endl;
        for (auto &e : entries) e.display();
    }

    void search() {
        string site;
        cout << "Enter site name: ";
        cin >> site;
        bool found = false;
        for (auto &e : entries) {
            if (e.getSite() == site) {
                cout << "\nFound:\n";
                e.display();
                found = true;
            }
        }
        if (!found) cout << "No record found.\n";
    }

    void deleteEntry() {
        string site;
        cout << "Enter site to delete: ";
        cin >> site;
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if (it->getSite() == site) {
                entries.erase(it);
                save();
                cout << "Deleted successfully.\n";
                return;
            }
        }
        cout << "No record found.\n";
    }

    void menu() {
        if (!login()) return; // Stop if login fails
        load();

        while (true) {
            cout << "\n===== PASSWORD VAULT =====\n";
            cout << "1. Add Password\n";
            cout << "2. View All\n";
            cout << "3. Search by Site\n";
            cout << "4. Delete Entry\n";
            cout << "5. Logout\n";
            cout << "Enter choice: ";

            int ch;
            cin >> ch;

            switch (ch) {
                case 1: addEntry(); break;
                case 2: viewAll(); break;
                case 3: search(); break;
                case 4: deleteEntry(); break;
                case 5: cout << "Logging out...\n"; return;
                default: cout << "Invalid choice!\n";
            }
        }
    }
};

int main() {
    Vault vault;
    vault.menu();
    return 0;
}
