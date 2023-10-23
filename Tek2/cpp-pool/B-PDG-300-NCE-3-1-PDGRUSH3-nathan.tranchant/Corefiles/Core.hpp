/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <thread>
    #include <chrono>
    #include <fstream>
    #include <sstream>
    #include <unistd.h>
    #include <map>
    #include <vector>
    #include <sys/utsname.h>
    #include <sys/sysinfo.h>

    class Core {
        public:
            Core();
            ~Core();
            double getCoreUsage();
            std::vector<double> getCoreUsagePerCore();
            struct sysinfo getSysInfo();
            std::string getCpuModel();
            float getCpuFrequency();
            int getCpuCores();
            std::map<std::string, std::pair<unsigned long long, unsigned long long>> getNetworkLoad();
        protected:
        private:
    };



#endif /* !CORE_HPP_ */
