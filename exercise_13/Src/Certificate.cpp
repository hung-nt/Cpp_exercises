#include "../include/Certificate.h"

Certificate::Certificate() {}

Certificate::Certificate(std::string id, std::string name, std::string rank, std::chrono::system_clock::time_point date)
    : id(id), name(name), rank(rank), date(date) {}

std::string Certificate::getId() const {
    return id;
}

void Certificate::setId(const std::string& id) {
    this->id = id;
}

std::string Certificate::getName() const {
    return name;
}

void Certificate::setName(const std::string& name) {
    this->name = name;
}

std::string Certificate::getRank() const {
    return rank;
}

void Certificate::setRank(const std::string& rank) {
    this->rank = rank;
}

std::chrono::system_clock::time_point Certificate::getDate() const {
    return date;
}

void Certificate::setDate(const std::chrono::system_clock::time_point& date) {
    this->date = date;
}