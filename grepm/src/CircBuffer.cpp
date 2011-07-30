#include <CircBuffer.h>
#include <cassert>
#include <stdexcept>

CircBuffer::CircBuffer(std::size_t capacity)
  : capacity_(capacity)
{
  assert(capacity > 0);
  if (capacity == 0)
    throw std::invalid_argument("CircBuffer: capacity must be > 0");
}

bool CircBuffer::empty() const
{
  return deque_.empty();
}

std::size_t CircBuffer::size() const
{
  return deque_.size();
}

void CircBuffer::add(const std::string& value)
{
  if (deque_.size() == capacity_)
    deque_.pop_front();
  deque_.push_back(value);
}

bool CircBuffer::shift()
{
  deque_.pop_front();
  return !deque_.empty();
}

const std::string& CircBuffer::get(std::size_t index) const
{
  return deque_[index];
}

const std::string& CircBuffer::get() const
{
  return deque_.front();
}
