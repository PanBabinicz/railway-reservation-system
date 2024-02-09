#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <chrono>
#include <thread>

using std::cout, std::cin, std::endl, std::string, std::map, std::fstream, std::vector;

class AdminData{
private:
  string aLogin;
  string aPass;
public:
  /* Default constructor */
  AdminData();

  /**
   * Setters
   * void set_login  (string login);
   * void set_pass   (string password);
   **/

  /**
   * Getters 
   * string get_login    (void) const;
   * string get_pass     (void) const;
   **/

  /* Methods */
  void LoginPass();             /* LoginPass method is used to enter login and password */
  int CheckData();              /* CheckData method is used to check the correctness of login data */
  static int AdminMenu();       /* AdminMenu method is used to display and select admin options */
  static int BookedTickets();   /* BookedTickets method is used to display all booked tickets */
};
