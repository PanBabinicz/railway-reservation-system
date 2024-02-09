#include "AdminData.h"

AdminData::AdminData() {
  aLogin  = {};
  aPass   = {};
}

void AdminData::LoginPass() {
  string in{};

  cout << "Login: ";
  cin >> in;
  aLogin = in;

  cout << "Password: ";
  cin >> in;
  aPass = in;
}

int AdminData::CheckData() {
  string line{};

  fstream AdminFile("");
  if(AdminFile.is_open()) {
    getline(AdminFile, line);
    if (line == aLogin) {
      getline(AdminFile, line);
      if (line == aPass) {
        AdminFile.close();
        return 1;
      } else {
        AdminFile.close();
        return 0;
      }
    } else {
      AdminFile.close();
      return 0;
    }
  }
  else{
    cout << "File has not been opened!" << endl;
    return 0;
  }

}
int AdminData::AdminMenu() {
  int option{};

  cout << "\n------------------------" << endl;
  cout << "-------ADMIN MENU-------" << endl;
  cout << "------------------------" << endl;

  cout << "1. View booked tickets" << endl;
  cout << "2. Exit" << endl;
  cout << "Select option: ";
  cin >> option;

  if(option == 1)
    return 1;
  else
    return 0;
}
int AdminData::BookedTickets() {
  string line{};

  fstream TicketFile("path");
  if(TicketFile.is_open()){
    cout << "\n";
    while(getline(TicketFile, line)) {
      if (line == "next") {
        cout << "\n";
        continue;
      }
      cout << line << endl;
    }
    TicketFile.close();
    return 1;
  }
  else
  return 0;
}
