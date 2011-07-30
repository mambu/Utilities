#include <MultiGrep.h>

MultiGrep::MultiGrep(Filter& filter, std::size_t numLines)
  : filter_(filter)
  , buffer_(numLines + 1)
  , numLines_(numLines)
  , print_(false)
  , count_(0)
{
}

bool MultiGrep::process(const std::string& line)
{
  bool match = filter_.process(line);
  buffer_.add(line);
  if (match)
  {
    count_ = numLines_ + buffer_.size();
    print_ = true;
  }
  return match;
}

bool MultiGrep::hasNext() const
{
  return buffer_.size() != 0 && print_;
}

void MultiGrep::getNext(std::string& line)
{
  if (print_)
  {
    line = buffer_.get();
    --count_;
    print_ = print_ && count_;
    buffer_.shift();
  }
  else
    line = "";
}
