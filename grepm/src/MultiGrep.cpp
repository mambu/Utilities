#include <MultiGrep.h>

MultiGrep::MultiGrep(StringProcessor& stringProcessor, std::ostream& os, std::size_t numLines)
  : stringProcessor_(stringProcessor)
  , buffer_(numLines + 1)
  , numLines_(numLines)
  , ostream_(os)
  , print_(false)
  , count_(0)
{
}

bool MultiGrep::process(const std::string& line)
{
  bool match = stringProcessor_.process(line);
  buffer_.add(line);
  if (match)
  {
    for (std::size_t i = 0; i < buffer_.size(); ++i)
      ostream_ << buffer_.get(i);
    buffer_.clear();
    count_ = numLines_;
    print_ = true;
  }
  else if (print_)
  {
    ostream_ << line;
    --count_;
  }
  print_ = print_ && count_;
  return match;
}
