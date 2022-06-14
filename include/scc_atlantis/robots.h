#include <string>

class Robot
{
 public:
  Robot();
 private:
  float battery_;
  std::string state;
};

class Sense : public Robot
{
 public:
  Sense();
};

class Crow : public Robot
{
	public:
  Sense();
};

class Raven : public Robot
{
	public:
  Sense();
};