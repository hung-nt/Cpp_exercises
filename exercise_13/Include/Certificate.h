#ifndef _CERTIFICATE_H_
#define _CERTIFICATE_H_

#include <string>
#include <chrono>

class Certificate {
private:
    std::string id;
    std::string name;
    std::string rank;
    std::chrono::system_clock::time_point date;

public:
    Certificate();
    Certificate(std::string id, std::string name, std::string rank, std::chrono::system_clock::time_point date);

    std::string getId() const;
    void setId(const std::string& id);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getRank() const;
    void setRank(const std::string& rank);

    std::chrono::system_clock::time_point getDate() const;
    void setDate(const std::chrono::system_clock::time_point& date);
};

#endif  /* _CERTIFICATE_H_ */
