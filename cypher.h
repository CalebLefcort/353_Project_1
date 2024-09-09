/*
CPSC 353
Group 3(Caleb Lefcort, Madison Spink, Maya Stelzer, Maura Sweeney)
9/8/2024
Project 1

File Purpose: This file defines the base class cypher and the derived classes 
    for each of the cyphers. 
*/

#include "common.h"
#include <cctype>

class Cypher
{
public:
  Cypher(const std::string key) : key_size_(key.length()) { gen_key_val(key); }
  ~Cypher() = default;

  virtual std::string encrypt(std::string str)
  {
    for (int i = 0; i < str.length(); i++)
    {
      str[i] = shift_char(str[i], key_val_[i % key_size_]);
    }
    return str;
  }

  virtual std::string decrypt(std::string str)
  {
    for (int i = 0; i < str.length(); i++)
    {
      char shifted = shift_char(str[i], -key_val_[i % key_size_]);
      str[i] = std::isspace(shifted) ? ' ' : shifted;
    }
    return str;
  }

protected:
  const size_t key_size_;

private:
  char shift_char(char c, int shift_val)
  {
    int shifted = (find_index(toupper(c)) + shift_val) % 27;
    return shifted < 0 ? ALPHA[shifted + 27] : ALPHA[shifted];
  }

  void gen_key_val(std::string key)
  {
    key_val_ = new int[key.length()];

    for (int i = 0; i < key.length(); i++)
    {
      key_val_[i] = find_index(key[i]);
    }
  }

  int *key_val_;
};

class Caesar : public Cypher
{
public:
  Caesar(char key) : Cypher(c_to_string(key)) {}

private:
  std::string c_to_string(char ch)
  {
    return std::string(1, ch);
  }
};

class Vigenere : public Cypher
{
public:
  Vigenere(std::string key) : Cypher(key) {}

  std::string encrypt(std::string str) override
  {
    if (key_size_ >= str.length())
    {
      throw std::invalid_argument("Key length too long");
    }
    return Cypher::encrypt(str);
  }

  std::string decrypt(std::string str) override
  {
    if (key_size_ >= str.length())
    {
      throw std::invalid_argument("Key length too long");
    }
    return Cypher::decrypt(str);
  }
};

class OneTimePad : public Cypher
{
public:
  OneTimePad(std::string key) : Cypher(key) {}

  std::string encrypt(std::string str) override
  {
    if (key_size_ != str.length())
    {
      throw std::invalid_argument("Key and string must be the same length");
    }
    return Cypher::encrypt(str);
  }

  std::string decrypt(std::string str) override
  {
    if (key_size_ != str.length())
    {
      throw std::invalid_argument("Key and string must be the same length");
    }
    return Cypher::decrypt(str);
  }
};