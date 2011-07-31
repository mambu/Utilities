#include <LineNumber.h>
#include <sstream>

LineNumber::LineNumber()
  : lineNum_(0)
{
}

void LineNumber::process(std::string& line)
{
  std::ostringstream os;
  os << ++lineNum_ << ":" << line;
  line = os.str();
}