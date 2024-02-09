#include <iostream>
#include <map>
#include <vector>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>
#include "UserData.h"
#include "AdminData.h"

using std::cout, std::cin, std::endl, std::map, std::fstream, std::vector;

static int main_menu(){
  int option{};

  cout << "\n\n|-------------------------------------------|" << endl;
  cout << "|---------------- MAIN MENU ----------------|" << endl;
  cout << "|-------------------------------------------|" << endl;

  cout << "\n1. Customer" << endl;
  cout << "2. Admin" << endl;
  cout << "3. Road info" << endl;
  cout << "4. Exit" << endl;

  cout << "\nSelect one option: ";
  cin >> option;

  return option;
}


static int user_menu(map<int,string>& road_info_km, map<string,vector<string>>& schedule_km, map<int,string>& road_info_ic, map<string,vector<string>>& schedule_ic){
  UserData traveler;
  std::chrono::milliseconds timespan(3000);
  int condition;

  /* this block supports the TrainSelect() method */
  while (true) {
    if ( (condition = traveler.TrainSelect()) <= 1 ) {
      char answer{};

      if(condition == -1){
        cout << "Would you like to repeat this step? (y/n): ";
        cin >> answer;

        if(answer == 'y')
          continue;
        else {
          cout << "Returning to main menu..." << endl;
          std::this_thread::sleep_for(timespan);
          return 0;
        }
      }
      else {
        cout << "Next (y/n): ";
        cin >> answer;

        if (answer == 'y') {
          break;
        } else if (answer == 'n') {
          cout << "Would you like to repeat this step? (y/n): ";
          cin >> answer;

          if (answer == 'y')
            continue;
          else {
            cout << "Returning to main menu..." << endl;
            std::this_thread::sleep_for(timespan);
            return 0;
          }
        } else {
          cout << "Incorrect option, returning to main menu..." << endl;
          std::this_thread::sleep_for(timespan);
          return 0;
        }
      }
    }
  }


  map<int,string> road_info{};
  if(traveler.get_train() == "Intercity")
    road_info = road_info_ic;
  else
    road_info = road_info_km;

  /* this block supports the SelectStation() method */
  while (true){
    if ( (traveler.SelectStation(road_info)) < 0 ) {
      char answer{};

      cout << "Would you like to repeat this step? (y/n): ";
      cin >> answer;
      if (answer == 'y')
        continue;
      else {
        cout << "Returning to main menu..." << endl;
        std::this_thread::sleep_for(timespan);
        return 0;
      }
    }
    else {
      char answer{};
      cout << "Next (y/n): ";
      cin >> answer;

      if (answer == 'y') {
        break;
      } else if (answer == 'n') {
        cout << "Would you like to repeat this step? (y/n): ";
        cin >> answer;

        if (answer == 'y')
          continue;
        else {
          cout << "Returning to main menu..." << endl;
          std::this_thread::sleep_for(timespan);
          return 0;
        }
      }
      else {
        cout << "Incorrect option, returning to main menu..." << endl;
        std::this_thread::sleep_for(timespan);
        return 0;
      }
    }
  }

  /* this block supports the SelectDate() method */
  while (true) {
    if ( (condition = traveler.SelectDate()) <= 1 ) {
      char answer{};

      if (condition == -2)
        return 0;
      if (condition == -1) {
        cout << "Would you like to repeat this step? (y/n): ";
        cin >> answer;

        if (answer == 'y')
          continue;
        else {
          cout << "Returning to main menu..." << endl;
          std::this_thread::sleep_for(timespan);
          return 0;
        }
      } else {
        cout << "Next (y/n): ";
        cin >> answer;

        if (answer == 'y') {
          break;
        } else if (answer == 'n') {
          cout << "Would you like to repeat this step? (y/n): ";
          cin >> answer;

          if (answer == 'y')
            continue;
          else {
            cout << "Returning to main menu..." << endl;
            std::this_thread::sleep_for(timespan);
            return 0;
          }
        } else {
          cout << "Incorrect option, returning to main menu..." << endl;
          std::this_thread::sleep_for(timespan);
          return 0;
        }
      }
    }
  }

  /* this block is used to display selected attributes: from, to, date and time */
  cout << "\n|" << traveler.get_from() << "  ---->  " << traveler.get_to() << "|";
  cout << "\t\t|Date: " << traveler.get_date() << "|\t\t|Time: " << traveler.get_time() << "|" << endl;

  map<string,vector<string>> schedule{};
  if(traveler.get_train() == "Intercity")
    schedule = schedule_ic;
  else
    schedule = schedule_km;

  /* available hours shown in the timetable are entered on the map in this block */
  map<int, string> time_map{};
  time_map = traveler.Schedule(schedule);

  /* this block supports the TimeSelect() method */
  while (true) {
    if ( (condition = traveler.TimeSelect(time_map)) <= 1 ) {
      char answer{};

      if(condition == -1){
        cout << "Would you like to repeat this step? (y/n): ";
        cin >> answer;

        if(answer == 'y')
          continue;
        else {
          cout << "Returning to main menu..." << endl;
          std::this_thread::sleep_for(timespan);
          return 0;
        }
      }
      else {
        cout << "Next (y/n): ";
        cin >> answer;

        if (answer == 'y') {
          break;
        } else if (answer == 'n') {
          cout << "Would you like to repeat this step? (y/n): ";
          cin >> answer;

          if (answer == 'y')
            continue;
          else {
            cout << "Returning to main menu..." << endl;
            std::this_thread::sleep_for(timespan);
            return 0;
          }
        } else {
          cout << "Incorrect option, returning to main menu..." << endl;
          std::this_thread::sleep_for(timespan);
          return 0;
        }
      }
    }
  }

  /* this block supports the DiscountSelect() method */
  while (true) {
    if ( (condition = traveler.DiscountSelect()) <= 1 ) {
      char answer{};

      if (condition == -2)
        return 0;
      if(condition == -1){
        cout << "Would you like to repeat this step? (y/n): ";
        cin >> answer;

        if(answer == 'y')
          continue;
        else {
          cout << "Returning to main menu..." << endl;
          std::this_thread::sleep_for(timespan);
          return 0;
        }
      }
      else {
        cout << "Next (y/n): ";
        cin >> answer;

        if (answer == 'y') {
          break;
        } else if (answer == 'n') {
          cout << "Would you like to repeat this step? (y/n): ";
          cin >> answer;

          if (answer == 'y')
            continue;
          else {
            cout << "Returning to main menu..." << endl;
            std::this_thread::sleep_for(timespan);
            return 0;
          }
        } else {
          cout << "Incorrect option, returning to main menu..." << endl;
          std::this_thread::sleep_for(timespan);
          return 0;
        }
      }
    }
  }

  /* this block is used to enter the customer's name, surname, email and telephone number */
  traveler.TravelerData();

  /* this block is used to save whole data into the ticket file. it also displays this data on the screen */
  if (traveler.FinalData() == 0) {
    std::this_thread::sleep_for(timespan);
    return 0;
  }

  cout << "\nThank you for using our service,\nHave a nice journey!" << endl;

  std::this_thread::sleep_for(timespan);
  return 0;
}

static int admin_menu(){
  AdminData admin{};

  admin.LoginPass();
  if( admin.CheckData() == 0 ) {
    cout << "Incorrect login data!";
    return 0;
  }

  while(AdminData::AdminMenu() != 0) {

    if (AdminData::BookedTickets() == 0) {
      cout << "File has not been opened, exiting...";
      break;
    }

    char answer{};
    cout << "Continue? (y/n):";
    cin >> answer;

    if(answer == 'y')
      continue;
    else if (answer == 'n')
      break;
    else{
      cout << "Incorrect option, returning to main menu...";
      break;
    }
  }

  return 0;
}

static void schedule_fill(map<string,vector<string>>& schedule_km, map<string,vector<string>>& schedule_ic){
  string in{};
  string key{};
  vector<string> v{};
  int condition{};

  fstream Schedule_km("path");
  if(Schedule_km.is_open()){
    while(getline(Schedule_km, in)){
      if(condition) {
        schedule_km[key] = v;
        key = in;
        v.clear();
        condition = 0;
      }
      if(in == "next")
        condition = 1;

      if(in != "next" && in != key)
        v.push_back(in);
    }
    Schedule_km.close();
  }
  else{
    cout << "File has not been opened" << endl;
  }

  v.clear();
  condition = 0;

  fstream Schedule_ic("path");
  if(Schedule_ic.is_open()){
    while(getline(Schedule_ic, in)){
      if(condition) {
        schedule_ic[key] = v;
        key = in;
        v.clear();
        condition = 0;
      }
      if(in == "next")
        condition = 1;

      if(in != "next" && in != key)
        v.push_back(in);
    }
    Schedule_ic.close();
  }
  else{
    cout << "File has not been opened" << endl;
  }
}

static void road_info_fill(map<int,string>& road_info_km, map<int,string>& road_info_ic){
  string in{};
  int number = 1;

  fstream StationFile_km("path");
  if(StationFile_km.is_open()) {
    while (getline(StationFile_km, in)) {
      road_info_km[number] = in;
      number++;
    }
    StationFile_km.close();
  }
  else{
    cout << "File has not been opened" << endl;
  }

  number = 1;

  fstream StationFile_ic("path");
  if(StationFile_ic.is_open()) {
    while (getline(StationFile_ic, in)) {
      road_info_ic[number] = in;
      number++;
    }
    StationFile_ic.close();
  }
  else{
    cout << "File has not been opened" << endl;
  }
}

static int road_info_display(map<int,string>& road_info_km, map<int,string>& road_info_ic){
  std::chrono::milliseconds timespan(3000);

  cout << "KM:" << endl;

  for(const auto& element : road_info_km){
    int number = element.first;
    string station_name = element.second;

    cout << number << ": " << station_name << endl;
  }

  cout << "\nIntercity:" << endl;

  for(const auto& element : road_info_ic){
    int number = element.first;
    string station_name = element.second;

    cout << number << ": " << station_name << endl;
  }

  std::this_thread::sleep_for(timespan);
  return 1;
}


int main(){
  std::chrono::milliseconds timespan(3000);

  map<string,vector<string>> schedule_km{};
  map<string,vector<string>> schedule_ic{};
  schedule_fill(schedule_km, schedule_ic);

  map<int,string> road_info_km{};
  map<int,string> road_info_ic{};
  road_info_fill(road_info_km, road_info_ic);

  while(true) {
    int condition;

    switch (main_menu()) {
      case 1:
        condition = user_menu(road_info_km, schedule_km, road_info_ic, schedule_ic);
        break;
      case 2:
        condition = admin_menu();
        break;
      case 3:
        condition = road_info_display(road_info_km, road_info_ic);
        break;
      case 4:
        cout << "Exiting..." << endl;
        std::this_thread::sleep_for(timespan);
        condition = -1;
        break;
      default:
        cout << "Incorrect option, exiting..." << endl;
        std::this_thread::sleep_for(timespan);
        condition = -1;
        break;
    }

    if(condition == 0){
      cout << "\n\n\n";
      continue;
    }
    if(condition == -1)
      break;
  }

  return 1;
}
