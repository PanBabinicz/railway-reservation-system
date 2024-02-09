#include "UserData.h"
#include <fstream>

using std::fstream;

UserData::UserData() {
  uName       = {};
  uSurname    = {};
  uTelNumber  = {};
  uEmail      = {};
  uFrom       = {};
  uTo         = {};
  uTrain      = {};
  uDiscount   = {};
}

/**
 * Setters unused
 * void UserData::set_name         (string name)       { uName = name; }
 * void UserData::set_surname      (string surname)    { uSurname = surname; }
 * void UserData::set_telnumber    (string telnumber)  { uTelNumber = telnumber; }
 * void UserData::set_email        (string email)      { uEmail = email; }
 * void UserData::set_from         (string from)       { uFrom = from; }
 * void UserData::set_to           (string to)         { uTo = to; }
 * void UserData::set_date         (string date)       { uDate = date; }
 * void UserData::set_time         (string time)       { uTime = time; }
 * void UserData::set_train        (string train)      { uTrain = train; }
 * void UserData::set_discount     (float discount)    { uDiscount = discount; }
 **/

/** 
 * Getters unused
 * string UserData::get_name()         const { return uName; }
 * string UserData::get_surname()      const { return uSurname; }
 * string UserData::get_telnumber()    const { return uTelNumber; }
 * string UserData::get_email()        const { return uEmail; } 
 * float  UserData::get_discount()     const { return uDiscount; }
 **/

string UserData::get_from()         const { return uFrom; }
string UserData::get_to()           const { return uTo; }
string UserData::get_date()         const { return uDate; }
string UserData::get_time()         const { return uTime; }
string UserData::get_train()        const { return uTrain; }

/* Methods */
int UserData::SelectStation(map<int,string>& road_info){
  string station{};


  cout << "\nStations:" << endl;

  for(const auto& element : road_info){
    int number = element.first;
    string station_name = element.second;

    cout << number << ": " << station_name << endl;
  }


  /* Selecting stations */
  int number{};
  cout << "Select home station: ";
  cin >> number;
  if(( number < 1 || number > road_info.size() )){
    cout << "\nIncorrect option..." << endl;
    return -1;
  }
  uFrom = road_info[number];

  cout << "Select end station: ";
  cin >> number;
  if(( number < 1 || number > road_info.size() )){
    cout << "\nIncorrect option..." << endl;
    return -1;
  }
  uTo = road_info[number];


  if(uFrom == uTo){
    cout << "\nYou can not select two the same stations..." << endl;
    return -1;
  }

  return 0;
}


int UserData::SelectDate() {

  /* Selecting date */
  string date{};
  int day{};
  int month{};
  int year{};

  cout << "\nDate (DD/MM/YYYY)" << endl;
  cout << "DD: ";
  if (!(cin >> day)) {
    cout << "The enter value is not valid, exiting..." << endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return -1;
  }
  if(day <= 9 && day >= 1)
    date += "0" + to_string(day) + "/";
  else
    date += to_string(day) + "/";

  cout << "MM: ";
  if (!(cin >> month)) {
    cout << "The enter value is not valid, exiting..." << endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return -1;
  }
  if(month <= 9 && month >= 1)
    date += "0" + to_string(month) + "/";
  else
    date += to_string(month) + "/";

  cout << "YYYY: ";
  if (!(cin >> year)) {
    cout << "The enter value is not valid, exiting..." << endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return -1;
  }
  date += to_string(year);


  /* Checking if date is valid */
  if(year < 2000 || year > 2030){
    cout << "\nIncorrect year, exiting..." << endl;
    return -1;
  }
  if(month < 1 || month > 12){
    cout << "\nIncorrect month, exiting..." << endl;
    return -1;
  }
  if(month == 2){
    if( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ) {
      if (day > 29 || day < 1) {
        cout << "\nIncorrect day, exiting..." << endl;
        return -1;
      }
    }
  }
  if(month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30 || day < 1) {
      cout << "\nIncorrect day, exiting..." << endl;
      return -1;
    }
  }
  else{
    if(day > 31 || day < 1){
      cout << "\nIncorrect day, exiting..." << endl;
      return -1;
    }
  }
  uDate = date;


  /* Selecting time */
  string time{};
  int hour{};
  int min{};

  cout << "\nTime (HH:MM)" << endl;
  cout << "HH: ";
  if (!(cin >> hour)) {
    cout << "The enter value is not valid, exiting..." << endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return -1;
  }
  if(hour <= 9 && hour >= 0)
    time += "0" + to_string(hour) + ":";
  else
    time += to_string(hour) + ":";

  cout << "MM: ";
  if (!(cin >> min)) {
    cout << "The enter value is not valid, exiting..." << endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return -1;
  }


  /* Checking if time is valid */
  if(min <= 9 && min >= 0)
    time += "0" + to_string(min);
  else
    time += to_string(min);

  if(hour > 23 || hour < 0){
    cout << "\nIncorrect hour, exiting..." << endl;
    return -1;
  }
  if(min > 59 || min < 0){
    cout << "\nIncorrect min, exiting..." << endl;
    return -1;
  }
  uTime = time;


  return 1;
}


int  UserData::TrainSelect() {
  int option{};

  cout << "\nTrains: " << endl;
  cout << "1: Koleje malopolskie" << endl;
  cout << "2: Intercity" << endl;
  cout << "Select your train: ";
  cin >> option;

  switch (option) {
    case 1:
      uTrain = "Koleje malopolskie";
      break;
    case 2:
      uTrain = "Intercity";
      break;
    default:
      cout << "Wrong option..." << endl;
      return -1;
  }
  return 1;
}


map<int, string> UserData::Schedule(map<string,vector<string>>& schedule) {
  string line{};
  int incrementator = 1;
  map<int, string> schedule_time_map{};

  int hour;

  /* This function converts string to int (if you have stoi(08:54) you'll get 8) */
  hour = stoi(uTime);   

  int down = 0;
  int up = 0;

  if(uTrain == "Intercity"){
    down = hour - 3;
    up = hour + 3;
  }
  else{
    down = hour - 1;
    up = hour + 1;
  }


  for(const auto& element : schedule){
    string station = element.first;
    vector<string> time = element.second;

    if(station == uFrom){
      for(const auto& a : time){
        if ((stoi(a) >= down && stoi(a) <= up)) {
          /* Map will be used when the customer chooses an available travel time */
          schedule_time_map[incrementator] = a;
          ++incrementator;
        }
      }
      if(!schedule_time_map.empty())
        break;
    }
  }

  return schedule_time_map;
}


int UserData::TimeSelect(map<int,string> m) {
  int option{};
  string line{};

  cout << "\nDeparture time:" << endl;

  for(const auto& element : m){
    int number = element.first;
    string time = element.second;

    cout << number << ". " << time << endl;
  }

  cout << "Select available time: ";
  cin >> option;
  if( option < 1 || option > m.size() ){
    cout << "\nIncorrect option, exiting..." << endl;
    return -1;
  }

  line = m[option];
  uTime = line;

  return 1;
}


int UserData::DiscountSelect() {
  string line{};
  float discount{};
  int option{};
  int incrementator = 1;

  cout << "\nDiscounts:" << endl;

  fstream Discount ("path");
  if(Discount.is_open()) {
    while (getline(Discount, line)) {
      if (line == "next")
        break;
      cout << line << endl;
      ++incrementator;
    }

    cout << "Select your discount: ";
    cin >> option;
    if(option < 1 || option >= incrementator){
      cout << "\nIncorrect option..." << endl;
      return -1;
    }

    while(getline(Discount, line)){
      if(option == 1) {
        discount = stof(line);
        break;
      }
      --option;
    }
    Discount.close();
  }
  else{
    cout << "File open error!" << endl;
    return -2;
  }

  uDiscount = discount;
  return 1;
}


void UserData::TravelerData() {
  string in{};

  cout << "\nName: ";
  cin >> in;
  uName = in;

  cout << "Surname: ";
  cin >> in;
  uSurname = in;

  cout << "Telephone number: ";
  cin >> in;
  uTelNumber = in;

  cout << "Email address: ";
  cin >> in;
  uEmail = in;
}


int UserData::FinalData() {

  fstream TicketInfo;
  //stream is opened in append-mode so that it does not overwrite the ticket file
  TicketInfo.open("path", fstream::app);
  if(TicketInfo.is_open()) {
    TicketInfo << "Name: " << uName << endl;
    TicketInfo << "Surname: " << uSurname << endl;
    TicketInfo << "Tel: " << uTelNumber << endl;
    TicketInfo << "Email: " << uEmail << endl;
    TicketInfo << "From: " << uFrom << endl;
    TicketInfo << "To: " << uTo << endl;
    TicketInfo << "Train: " << uTrain << endl;
    TicketInfo << "Date: " << uDate << endl;
    TicketInfo << "Time: " << uTime << endl;
    TicketInfo << "Discount: " << (1.0 - uDiscount) * 100 << "%" << endl;
    TicketInfo << " " << endl;
    TicketInfo.close();
  }
  else{
    cout << "File can not be open, returning to main menu..." << endl;
  }

  return 1;
}

