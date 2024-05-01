#include "Time.h"
#include <iostream>
#include <string>

class Bill {
private:
  std::string lastName;
  std::string phoneNumber;
  double minuteRate;
  double discount;
  Time startTime;
  Time endTime;
  double totalAmount;

public:
  // Конструктор
  Bill(const std::string &last_name, const std::string &phone_number,
       double minute_rate, double disc, const Time &start_time,
       const Time &end_time);

  // Методы для извлечения полей
  std::string getLastName() const { return lastName; }
  std::string getPhoneNumber() const { return phoneNumber; }
  double getMinuteRate() const { return minuteRate; }
  double getDiscount() const { return discount; }
  Time getStartTime() const { return startTime; }
  Time getEndTime() const { return endTime; }
  double getTotalAmount() const { return totalAmount; }

  // Методы для изменения полей
  void setLastName(const std::string &last_name) { lastName = last_name; }
  void setPhoneNumber(const std::string &phone_number) {
    phoneNumber = phone_number;
  }
  void setMinuteRate(double minute_rate) { minuteRate = minute_rate; }
  void setDiscount(double disc) { discount = disc; }
  void setStartTime(const Time &start_time) { startTime = start_time; }
  void setEndTime(const Time &end_time) { endTime = end_time; }
  void setTotalAmount(double amount) { totalAmount = amount; }

  // Метод для вычисления времени разговора в минутах
  int calculateCallDuration() const;
};

// Реализация конструктора Bill
Bill::Bill(const std::string &last_name, const std::string &phone_number,
           double minute_rate, double disc, const Time &start_time,
           const Time &end_time)
    : lastName(last_name), phoneNumber(phone_number), minuteRate(minute_rate),
      discount(disc), startTime(start_time), endTime(end_time) {
  totalAmount = 0.0; // Изначально сумма к оплате равна нулю
}

// Реализация метода для вычисления времени разговора в минутах
int Bill::calculateCallDuration() const {
  int start_minutes = startTime.to_minutes();
  int end_minutes = endTime.to_minutes();

  // Вычисляем разницу между временами начала и окончания разговора в минутах
  int duration = end_minutes - start_minutes;

  // Если разговор начался, но не завершился в течение минуты, учитываем
  // дополнительную минуту
  if (endTime.to_minutes() > startTime.to_minutes()) {
    duration++;
  }

  return duration;
}

int main() {
  // Пример использования класса Bill
  Time start_time(10, 15, 0);
  Time end_time(11, 0, 30);

  Bill bill("Smith", "123456789", 0.5, 10.0, start_time, end_time);

  // Вычисляем время разговора в минутах
  int call_duration = bill.calculateCallDuration();
  std::cout << "Call duration: " << call_duration << " minutes" << std::endl;

  return 0;
}
