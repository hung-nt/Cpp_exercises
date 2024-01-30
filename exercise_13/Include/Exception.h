#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>

class NameException : public std::runtime_error {
public:
    NameException() noexcept;
    explicit NameException(const char* message) noexcept;
};

class BirthdayException : public std::runtime_error {
public:
    BirthdayException() noexcept;
    explicit BirthdayException(const char* message) noexcept;
};

class PhoneException : public std::runtime_error {
public:
    PhoneException() noexcept;
    explicit PhoneException(const char* message) noexcept;
};

class EmailException : public std::runtime_error {
public:
    EmailException() noexcept;
    explicit EmailException(const char* message) noexcept;
};

#endif // EXCEPTION_H
