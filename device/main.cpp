#include <ioStream>
#include <random>
#include <chrono>
#include <string>

int main () {
    std::string deviceId = "ECU_001";
    //random number generation
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> tempDistribution(20, 80);
    std::uniform_int_distribution<int> cpuDistribution(1,100);
    int randomTemp = tempDistribution(gen);
    int randomCpu = cpuDistribution(gen);
    std::cout << randomTemp << randomCpu << std::endl;

    auto now = std::chrono::system_clock::now();
    std::time_t timeStamp = std::chrono::system_clock::to_time_t(now);
    std::cout << timeStamp << std::endl;

    //safety thresholds
    std::string status;

    if (randomTemp >= 70) {
        status = "CRITICAL";
    } else if (randomTemp >= 50){
        status = "WARNING";
    } else {
        status = "OK";
    }
    std::cout << status << std::endl;
}