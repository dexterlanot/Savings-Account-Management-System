#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
static int n=0;
using namespace std;

struct Bank {
  int accountnum, balance=0, deposit=0, withdraw;
  string name;
public:
  void createAcc();
  void userDeposit();
  void userWithdraw();
  void viewReciept();
  void viewBalance();
} account[10];

int menu(int choice){
  system("cls");
//  cout << "======================================";
//  cout << "\n\n\tSIMPLE BANKING SYSTEM ";
//  cout << "\n\n======================================";
  cout << "\n\n\t[1] Create account ";
  cout << "\n\t[2] Deposit ";
  cout << "\n\t[3] Withdraw ";
  cout << "\n\t[4] View Receipt ";
  cout << "\n\t[5] View Balance ";
  cout << "\n\t[6] Exit";
  cout << "\n\n======================================";
  cout << "\n\nEnter option: ";
  cin >> choice;
  return choice;
}

void Bank::createAcc(){
  input:system("cls");
  cout << "======================================";
  cout << "\n\n\tCREATE ACCOUNT ";
  cout << "\n\n======================================";
      cout << "\n\nEnter account no.: ";
      cin >> account[n].accountnum;
      //no duplication
      for (int x = 0; x < n; x++) {
          if (account[n].accountnum == account[x].accountnum) {
              cout << "\nYou already used this account no.\n Press any key again.\n\n";
              _getch();
              goto input;
          }
      }
      cin.ignore();
      cout << "Enter name: ";
      getline(cin, account[n].name);
      cout << "\nAccount has been created";
      n++;
}

  void Bank::userDeposit(){
    int accNum, counter=0, k=0;
    system("cls");
    cout << "======================================";
    cout << "\n\n\t\tDEPOSIT ";
    cout << "\n\n======================================";
    cout << "\n\nEnter account no.: ";
    cin >> accNum;
    for (int j=0; j<10; j++){
    if (accNum == account[j].accountnum){
      cout << "\nName: " << account[j].name;
      cout << "\nAccount no.: " << account[j].accountnum;
      counter++;
    }
  }
  if (counter == 0){
      cout << "\nAccount not found!";
      _getch();
  } else {
    cout << "\n\nEnter amount to deposit: ";
    cin >> account[k].deposit;

    if (account[k].deposit == 0){
      cout << "\nPlease enter more than 0";
    }
    else {
      cout << "\nSuccessful!";
      account[k].balance = account[k].balance+account[k].deposit;
      cout << "\nDeposited amount: Php " << account[k].deposit;
    }
  }

    k++;
  }

  void Bank::userWithdraw() {
    int accNum, counter=0;
    system("cls");
    cout << "======================================";
    cout << "\n\n\t\tWITHDRAW ";
    cout << "\n\n======================================";
    cout << "\n\nEnter accountnum: ";
    cin >> accNum;
    for (int j=0; j<10; j++){
    if (accNum == account[j].accountnum){
      cout << "\nName: " << account[j].name;
      cout << "\nAccount no.: " << account[j].accountnum;
      //account[j].balance = account[j].deposit;
      cout << "\nRemaining balance : Php " << account[j].balance;
      counter++;
      cout << "\n\nEnter amount to widthdraw: Php ";
      cin >> account[j].withdraw;
      if (account[j].balance != 0) {
      account[j].balance = account[j].balance - account[j].withdraw;
      cout << "\nWithdrew amount : Php " << account[j].withdraw;
      cout << "\nRemaining balance : Php " << account[j].balance;
    } else {
      cout << "======================================";
      cout << "\n\nSorry! you can't withdraw this amount. ";
    }
    }
  }
  if (counter == 0){
      cout << "\nAccount not found!";
      _getch();
  }
  }

  void Bank::viewReciept(){
    int accNum, counter=0;
    system("cls");
    cout << "======================================";
    cout << "\n\n\tVIEW YOUR RECIEPT ";
    cout << "\n\n======================================";
    cout << "\n\nEnter accountnum: ";
    cin >> accNum;
    for (int j=0; j<10; j++){
    if (accNum == account[j].accountnum){
      counter++;
      cout << "\n\n======================================";
      cout << "\n\n\t\tReceipt";
      cout << "\n\n======================================";
      cout << "\n\nName: " << account[j].name;
      cout << "\nAccount no.: " << account[j].accountnum;
      cout << "\nDeposited amount: Php " << account[j].deposit;
      cout << "\nWithdrew amount: Php " << account[j].withdraw;
      cout << "\n\nRemaining balance: Php " << account[j].balance;
      cout << "\n\n======================================";
    }
  }
  if (counter == 0){
      cout << "\nAccount not found!";
      _getch();
  }
  }

  void Bank::viewBalance() {
    system("cls");
    int accNum, counter=0;
    cout << "======================================";
    cout << "\n\n\tVIEW REMAINING BALANCE ";
    cout << "\n\n======================================";
    cout << "\n\nEnter accountnum: ";
    cin >> accNum;
    for (int j=0; j<10; j++){
    if (accNum == account[j].accountnum){
      cout << "\nName: " << account[j].name;
      cout << "\nAccount no.: " << account[j].accountnum;
      counter++;
      //account[j].balance = account[j].balance+account[j].deposit;
      cout << "\nRemaining balance : Php " << account[j].balance;
    }
  }
  if (counter == 0){
      cout << "\nAccount not found!";
      _getch();
  }
  }

int main ()
{
    main:
    int menuchoice, i=0;
    menuchoice = menu(menuchoice);
    switch (menuchoice){
      case 1:
      account[i].createAcc();
      cout << "\n\nPress any key to continue...";
            _getch();
            goto main;
      break;
      case 2:
      account[i].userDeposit();
      cout << "\n\nPress any key to continue...";
            _getch();
            goto main;
      break;
      case 3:
      account[i].userWithdraw();
      cout << "\n\nPress any key to continue...";
            _getch();
            goto main;
      break;
      case 4:
      account[i].viewReciept();
      cout << "\n\nPress any key to continue...";
            _getch();
            goto main;
      goto main;
      break;
      case 5:
      account[i].viewBalance();
      cout << "\n\nPress any key to continue...";
            _getch();
            goto main;
      break;

      case 6:
      exit(0);
      break;
    }

  return 0;
}
