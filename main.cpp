
#include "Wt/Dbo/Dbo.h"
#include "Wt/Dbo/backend/Sqlite3.h"
#include <string>

namespace dbo = Wt::Dbo;

enum class Role {
  Visitor = 0,
  Admin = 1,
  Alien = 42
};

class User {
public:
  std::string name;
  std::string password;
  Role        role;
  int         karma;

  template<class Action>
  void persist(Action& a)
  {
    dbo::field(a, name,     "name");
    dbo::field(a, password, "password");
    dbo::field(a, role,     "role");
    dbo::field(a, karma,    "karma");
  }
};

void run()
{

    //   std::unique_ptr<dbo::backend::Sqlite3> sqlite3{new dbo::backend::Sqlite3(":memory:")};
    // sqlite3->setProperty("show-queries", "true");
    // dbo::Session session;
    // session.setConnection(std::move(sqlite3));
     // std::unique_ptr<dbo::backend::Sqlite3> sqlite3{new dbo::backend::Sqlite3("Test.db")};
//    sqlite3->setProperty("show-queries", "true");
//    dbo::Session session;
//    session.setConnection(std::move(sqlite3));

//   session.mapClass<User>("user");
    
}

int main()//int argc, char **argv)
{
  run();
  return 1;
}
