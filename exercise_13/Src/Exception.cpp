#include "../Include/Exception.h"

NameException::NameException() noexcept : std::runtime_error("Name exception") {}

NameException::NameException(const char* message) noexcept : std::runtime_error(message) {}

BirthdayException::BirthdayException() noexcept : std::runtime_error("Birthday exception") {}

BirthdayException::BirthdayException(const char* message) noexcept : std::runtime_error(message) {}

PhoneException::PhoneException() noexcept : std::runtime_error("Phone exception") {}

PhoneException::PhoneException(const char* message) noexcept : std::runtime_error(message) {}

EmailException::EmailException() noexcept : std::runtime_error("Email exception") {}

EmailException::EmailException(const char* message) noexcept : std::runtime_error(message) {}
