#include <Wt/Auth/Login.h>
#include <Wt/Auth/UserDatabase.h>

#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/ptr.h>

#include "User.h"

namespace dbo = Wt::Dbo;

using UserDatabase = Wt::Auth::Dbo::UserDatabase<AuthInfo>;


class Session : public dbo::Session
{
public:
  Session(const std::string& sqliteDb);

  Wt::Auth::AbstractUserDatabase& users();
  Wt::Auth::Login& login() { return login_; }

  ...

private:
  std::unique_ptr<UserDatabase> users_;
  Wt::Auth::Login login_;
};