#include<iostream>
using namespace std;

class BankingSystem {
    private:
        long int accountNumber, mobileNumber, balance, newBalance, amount;
        string name, address, email;
        char choice, continueChoice;
    public:
        void openNewAccount(int totalAccounts, BankingSystem *accountList);
        void displayAccountInfo();
        void withdrawAmount();
        void depositAmount();
        void displayBalanceInfo();
        int checkAccountExistence(long int accountNumber, BankingSystem *accountList, int totalAccounts); 
        int getAccountNumber();
};

void BankingSystem::openNewAccount(int totalAccounts, BankingSystem *accountList) {
    newBalance = 0;
    balance = 0;
    int flag = 0;
    cout << "HEY YOU ARE OUR " << (totalAccounts + 1) << " CUSTOMER" << endl << endl;
    cout << "ENTER THE DESIRED ACCOUNT NUMBER" << endl;
    do {
        cin >> accountNumber;
        if (accountNumber == checkAccountExistence(accountNumber, accountList, totalAccounts)) {
            cout << "ACCOUNT NUMBER ALREADY EXISTS. ENTER A UNIQUE ONE" << endl;
            flag = 1;
        } else {
            flag = 0;
        }
    } while (flag == 1);
    cin.ignore();
    cout << "YOUR NAME PLEASE" << endl;
    getline(cin, name);
    cout << "YOUR ADDRESS" << endl;
    getline(cin, address);
    cout << "YOUR MOBILE NUMBER" << endl;
    cin >> mobileNumber;
    cin.ignore();
    cout << "ENTER YOUR VALID EMAIL ID" << endl;
    getline(cin, email);
    cout << "DO YOU WANT TO DEPOSIT AMOUNT Y/N" << endl;
    cin >> choice;
    do {
        if (toupper(choice) == 'Y') {
            cout << "ENTER THE AMOUNT" << endl;
            cin >> newBalance;
            balance += newBalance;
        } else if (toupper(choice) == 'N') {
            cout << "NO WORRIES, YOU CAN ALSO HAVE A ZERO BALANCE ACCOUNT" << endl;
            break;
        } else {
            cout << "ENTER VALID CHOICE PLEASE" << endl;
        }
        cout << "WANT TO ADD MORE DEPOSIT? Y/N" << endl;
        cin >> continueChoice;
    } while (toupper(continueChoice) == 'Y');
    cout << endl;
    cout << "HELLO " << name << " YOUR ACCOUNT NUMBER " << accountNumber << " HAS BALANCE -> " << balance << endl << endl;
}

int BankingSystem::checkAccountExistence(long int x, BankingSystem *accountList, int totalAccounts) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accountList[i].getAccountNumber() == x)
            return x;
    }
    return 0;
}

int BankingSystem::getAccountNumber() {
    return accountNumber;
}

void BankingSystem::displayAccountInfo() {
    cout << "HELLO " << name << " YOUR ACCOUNT NUMBER " << accountNumber << " HAS BALANCE -> " << balance << endl;
}

void BankingSystem::withdrawAmount() {
    cout << "HELLO " << name << " HAS BALANCE -> " << balance << endl << "ENTER THE AMOUNT TO BE WITHDRAWN" << endl;
    do {
        cin >> amount;
        if (balance < amount)
            cout << "INSUFFICIENT BALANCE" << endl;
        else
            balance -= amount;
        cout << "DO YOU WANT TO CONTINUE WITHDRAWING -Y/N" << endl;
        cin >> continueChoice;
    } while (toupper(continueChoice) == 'Y');
    cout << "NEW BALANCE IS " << balance << endl;
}

void BankingSystem::depositAmount() {
    cout << "HELLO " << name << " HAS BALANCE -> " << balance << endl << "ENTER THE AMOUNT TO DEPOSIT" << endl;
    do {
        cin >> amount;
        balance += amount;
        cout << "DO YOU WANT TO CONTINUE DEPOSITING -Y/N" << endl;
        cin >> continueChoice;
    } while (toupper(continueChoice) == 'Y');
    cout << "NEW BALANCE IS " << balance << endl;
}

void BankingSystem::displayBalanceInfo() {
    cout << "HELLO " << name << " YOU HAVE BALANCE -> " << balance << endl;
}

int main() {
    int userChoice, i = 0, totalAccounts = 0, found = 0;
    char continueBanking;
    BankingSystem accountList[100];
    long int tempAccountNumber = accountList[0].getAccountNumber();
    do {
        found = 0;
        cout << "\t\t\tWELCOME TO SECTION C BANK " << endl << endl;
        cout << "PRESS 1 TO OPEN NEW ACCOUNT" << endl;
        cout << "PRESS 2 TO CHECK YOUR ACCOUNT INFO" << endl;
        cout << "PRESS 3 TO WITHDRAW AMOUNT" << endl;
        cout << "PRESS 4 TO DEPOSIT AMOUNT" << endl;
        cout << "PRESS 5 TO CHECK YOUR BALANCE INFO" << endl;
        cout << "PRESS 6 TO EXIT" << endl << endl;
        cout << "ENTER YOUR CHOICE" << endl;
        cin >> userChoice;
        switch (userChoice) {
            case 1:
                accountList[i].openNewAccount(totalAccounts, accountList);
                totalAccounts++;
                i++;
                break;
            case 2:
                do {
                    cout << "ENTER YOUR ACCOUNT NUMBER" << endl;
                    cin >> tempAccountNumber;
                    for (int j = 0; j < totalAccounts; j++) {
                        if (tempAccountNumber == accountList[j].getAccountNumber()) {
                            accountList[j].displayAccountInfo();
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0)
                        cout << "INVALID ACCOUNT NUMBER" << endl;
                    cout << "DO YOU WANT TO CHECK OTHER ACCOUNT DETAILS -Y/N" << endl;
                    cin >> continueBanking;
                } while (toupper(continueBanking) == 'Y');
                break;
            case 3:
                cout << "ENTER YOUR ACCOUNT NUMBER" << endl;
                cin >> tempAccountNumber;
                for (int j = 0; j < totalAccounts; j++) {
                    if (tempAccountNumber == accountList[j].getAccountNumber()) {
                        accountList[j].withdrawAmount();
                        found = 1;
                        break;
                    }
                }
                if (found == 0)
                    cout << "INVALID ACCOUNT NUMBER" << endl;
                break;
            case 4:
                cout << "ENTER YOUR ACCOUNT NUMBER" << endl;
                cin >> tempAccountNumber;
                for (int j = 0; j < totalAccounts; j++) {
                    if (tempAccountNumber == accountList[j].getAccountNumber()) {
                        accountList[j].depositAmount();
                        found = 1;
                        break;
                    }
                }
                if (found == 0)
                    cout << "INVALID ACCOUNT NUMBER" << endl;
                break;
            case 5:
                do {
                    cout << "ENTER YOUR ACCOUNT NUMBER" << endl;
                    cin >> tempAccountNumber;
                    for (int j = 0; j < totalAccounts; j++) {
                        if (tempAccountNumber == accountList[j].getAccountNumber()) {
                            accountList[j].displayBalanceInfo();
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0)
                        cout << "INVALID ACCOUNT NUMBER" << endl;
                    cout << "DO YOU WANT TO CHECK OTHER ACCOUNT DETAILS -Y/N" << endl;
                    cin >> continueBanking;
                } while (toupper(continueBanking) == 'Y');
                break;
            case 6:
                cout << "THANK YOU" << endl;
                continueBanking = 'N';
                break;
            default:
                cout << "INVALID CHOICE" << endl;
                break;
        }
        cout << "DO YOU WANT TO CONTINUE BANKING -Y/N" << endl;
        cin >> continueBanking;
    } while (toupper(continueBanking) == 'Y');
}
