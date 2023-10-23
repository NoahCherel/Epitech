/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** MonitorCore
*/

#include "Core.hpp"

Core::Core()
{
}

Core::~Core()
{
}

double Core::getCoreUsage()
{
    std::ifstream stat_file("/proc/stat");
    std::string line;
    std::getline(stat_file, line);
    stat_file.close();

    int user, nice, system, idle, iowait, irq, softirq, steal;
    sscanf(line.c_str(), "cpu %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
    int total = user + nice + system + idle + iowait + irq + softirq + steal;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    stat_file.open("/proc/stat");
    std::getline(stat_file, line);
    stat_file.close();

    int user2, nice2, system2, idle2, iowait2, irq2, softirq2, steal2;
    sscanf(line.c_str(), "cpu %d %d %d %d %d %d %d %d", &user2, &nice2, &system2, &idle2, &iowait2, &irq2, &softirq2, &steal2);
    int total2 = user2 + nice2 + system2 + idle2 + iowait2 + irq2 + softirq2 + steal2;

    int active = total2 - total - (idle2 - idle);
    return (double)active / (total2 - total) * 100;
}

std::vector<double> Core::getCoreUsagePerCore()
{
    std::ifstream stat_file("/proc/stat");
    std::string line;
    std::vector<int> prev_values;
    std::vector<int> curr_values;
    while (std::getline(stat_file, line))
    {
        if (line.find("cpu") == 0 && line.find("cpu ") != 0)
        {
            int user, nice, system, idle, iowait, irq, softirq, steal;
            sscanf(line.c_str(), "cpu%*d %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
            prev_values.push_back(user + nice + system + idle + iowait + irq + softirq + steal);
            prev_values.push_back(idle);
        }
    }
    stat_file.close();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    stat_file.open("/proc/stat");
    while (std::getline(stat_file, line))
    {
        if (line.find("cpu") == 0 && line.find("cpu ") != 0)
        {
            int user, nice, system, idle, iowait, irq, softirq, steal;
            sscanf(line.c_str(), "cpu%*d %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
            curr_values.push_back(user + nice + system + idle + iowait + irq + softirq + steal);
            curr_values.push_back(idle);
        }
    }
    stat_file.close();

    std::vector<double> usage_percentages;
    for (int i = 0; i < curr_values.size(); i += 2)
    {
        int total_time = curr_values[i] - prev_values[i];
        int idle_time = curr_values[i + 1] - prev_values[i + 1];
        double usage_percentage = (double)(total_time - idle_time) / total_time * 100;
        usage_percentages.push_back(usage_percentage);
    }

    return usage_percentages;
}

struct sysinfo Core::getSysInfo()
{
    struct sysinfo info;
    sysinfo(&info);
    return info;
}

std::string Core::getCpuModel()
{
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    std::string model;
    while (std::getline(file, line)) {
        if (line.find("model name") != std::string::npos) {
            model = line.substr(line.find(":") + 2);
            break;
        }
    }
    file.close();
    return model;
}

float Core::getCpuFrequency()
{
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    std::string frequency;
    while (std::getline(file, line)) {
        if (line.find("cpu MHz") != std::string::npos) {
            frequency = line.substr(line.find(":") + 2);
            break;
        }
    }
    file.close();
    return std::stof(frequency);
}

int Core::getCpuCores()
{
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    int cores = 0;
    while (std::getline(file, line)) {
        if (line.find("cpu cores") != std::string::npos) {
            cores = std::stoi(line.substr(line.find(":") + 2));
            break;
        }
    }
    file.close();
    return cores;
}

std::map<std::string, std::pair<unsigned long long, unsigned long long>> Core::getNetworkLoad() {
    std::map<std::string, std::pair<unsigned long long, unsigned long long>> network_load;
    std::ifstream net_file("/proc/net/dev");
    std::string line;
    while (std::getline(net_file, line)) {
        if (line.find(":") != std::string::npos) {
            char interface[100];
            unsigned long long bytes_received, bytes_sent;
            std::sscanf(line.c_str(), "%s %llu %*u %*u %*u %*u %*u %*u %llu", interface, &bytes_received, &bytes_sent);
            std::string interface_name(interface);
            interface_name = interface_name.substr(0, interface_name.size() - 1);
            network_load[interface_name] = std::make_pair(bytes_received, bytes_sent);
        }
    }
    return network_load;
}
