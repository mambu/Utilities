#include <BoostGrep.h>
#include <boost/regex.hpp>

class BoostGrep::BoostGrepImpl
{
public:
  BoostGrepImpl(const std::string& str)
    : r_(str.c_str())
  {}

  boost::regex r_;
};

BoostGrep::BoostGrep(const std::string& regexp)
  : impl_(*new BoostGrepImpl(regexp.c_str()))
{
}

BoostGrep::~BoostGrep()
{
  delete &impl_;
}

bool BoostGrep::process(const std::string& line)
{
  boost::smatch match;
  return boost::regex_search(line, match, impl_.r_);
}
