#include <CircBuffer.h>

CircBuffer::CircBuffer(std::size_t capacity)
  : capacity_(capacity)
{
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

void CircBuffer::clear()
{
  deque_.clear();
}

const std::string& CircBuffer::get(std::size_t index) const
{
  return deque_[index];
}
