#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <chrono>
#include <thread>

using std::cout, std::cin, std::endl, std::string, std::to_string, std::map, std::fstream, std::vector;

class UserData{
private:
  string uName;
  string uSurname;
  string uTelNumber;
  string uEmail;
  string uFrom;
  string uTo;
  string uDate;
  string uTime;
  string uTrain;
  float  uDiscount;
public:
  /* Default constructor */
  UserData();

  /**
   * Setters unused 
   * void set_name       (string name);
   * void set_surname    (string surname);
   * void set_telnumber  (string telnumber);
   * void set_email      (string email);
   * void set_from       (string from);
   * void set_to         (string to);
   * void set_date       (string date);
   * void set_time       (string time);
   * void set_train      (string train);
   * void set_discount   (float discount);
   **/

  /**
   * Getters unused 
   * string get_name         () const;
   * string get_surname      () const;
   * string get_telnumber    () const;
   * string get_email        () const;
   * string get_name         () const;
   * string get_surname      () const;
   * string get_telnumber    () const;
   * string get_email        () const;
   * float  get_discount     () const;
   **/

  string get_from         () const;
  string get_to           () const;
  string get_date         () const;
  string get_time         () const;
  string get_train        () const;

  /* Methods */
  int SelectStation(map<int,string>& road_info);
  int SelectDate();                                                   /* FromToDate method (starting station, end station, date, time) */
  int TrainSelect();                                                  /* TrainSelect method (selecting type of the train) */ 
  map<int, string> Schedule(map<string,vector<string>>& schedule);    /* Schedule method is used to display schedule */
  int TimeSelect(map<int,string> m);                                  /* TimeSelect() method is used to select available time from schedule */
  int DiscountSelect();                                               /* DiscountSelect() method is used to select discount */
  void TravelerData();                                                /* TravelerData method (name, surname, telephone number, email address) */
  int FinalData();                                                    /* FinalData() method writes the final to file */
};
