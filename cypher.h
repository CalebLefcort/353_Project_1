#include "common.h"

class Cypher
{
public:
  virtual ~Cypher() = default;

  virtual std::string encrypt(std::string str) = 0;

  // virtual std::string decrypt(std::string str) {}
};

class Caesar : public Cypher
{
public:
  Caesar(char key) : key(key) {}

  std::string encrypt(std::string str) override
  {
    int keyVal = find_index(key);
    for (int i = 0; i < str.length(); i++)
    {
      str[i] = ALPHA[(find_index(toupper(str[i])) + keyVal) % 27];
    }
    return str;
  }

private:
  char key;
};

class Vigenere : public Cypher
{
public:
  Vigenere(std::string key) : key(key) {}

  std::string encrypt(std::string str) override
  {
    if (key.length() >= str.length())
    {
      throw std::invalid_argument("Key length too long");
    }
    for (int i = 0; i < str.length(); i++)
    {
      str[i] = ALPHA[(find_index(toupper(str[i])) + find_index(key[i % key.length()])) % 27];
    }
    return str;
  }

private:
  std::string key;
};

class OneTimePad : public Cypher
{
public:
  OneTimePad(std::string key) : key(key) {}

  std::string encrypt(std::string str) override
  {
    if (key.length() != str.length())
    {
      throw std::invalid_argument("Key and string must be the same length");
    }
    for (int i = 0; i < str.length(); i++)
    {
      str[i] = ALPHA[(find_index(toupper(str[i])) + find_index(key[i])) % 27];
    }
    return str;
  }

private:
  std::string key;
};