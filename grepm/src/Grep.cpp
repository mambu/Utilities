#include <Grep.h>

Grep::Grep(const std::string& expr)
  : expr_(expr)
{
}

bool Grep::process(const std::string& line)
{
  return line.find(expr_) != std::string::npos;
}
