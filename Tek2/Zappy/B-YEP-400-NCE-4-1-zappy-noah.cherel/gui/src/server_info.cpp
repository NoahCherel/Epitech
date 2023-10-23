/*
** EPITECH PROJECT, 2023
** Marc-Olivier KOBAN
** File description:
** server_info.cpp
*/

#include "../include/game.hpp"
#include "../include/libc.hpp"

CommandServer cmdServ;

int LOG = 0; // 0 = no log, 1 = log

int getSocketReceiveBufferSize(int sock) {
    int bufferSize;
    socklen_t bufferSizeLen = sizeof(bufferSize);
    if (LibC::getsockopt(sock, SOL_SOCKET, SO_RCVBUF, &bufferSize, &bufferSizeLen) != 0) {
        std::cerr << "Failed to get socket receive buffer size." << std::endl;
        return -1;
    }
    return bufferSize;
}

void Server_info::sendCommand(int sock, const std::string& command) {
    if (LOG == 1) std::cout << "Sending command: " << command;
    LibC::send(sock, command.c_str(), command.length(), 0);
}

std::string Server_info::receiveResponse(int sock) {
    int bufferSize = getSocketReceiveBufferSize(sock);
    if (bufferSize < 0) {
        return "";
    }

    std::vector<char> buffer(bufferSize, '\0');
    std::string response;

    // Set a timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = 0;  // Adjust the timeout value as needed
    timeout.tv_usec = 5000;
    if (LibC::setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        std::cout << "Error setting socket timeout." << std::endl;
        return response;
    }

    int bytesRead;
    while ((bytesRead = LibC::recv(sock, buffer.data(), bufferSize, 0)) > 0) {
        response.append(buffer.data(), bytesRead);
    }
    if (LOG == 1) {
        std::cout << "Received response: " << response << std::endl;
    }

    return response;
}

std::vector<std::string> splitByNewLine(const std::string& input) {
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type end = input.find('\n', start);
    while (end != std::string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find('\n', start);
    }
    if (start < input.length())
        result.push_back(input.substr(start));

    return result;
}

CommandServer Server_info::affectedValue(std::string str, CommandServer cmdServ)
{
    std::string delimiter = " ";
    std::string token = str.substr(0, str.find(delimiter));
    std::string token2 = str.substr(str.find(delimiter) + 1, str.length());
    if (token == "msz") {
        std::string delimiter2 = " ";
        std::string token3 = token2.substr(0, token2.find(delimiter2));
        std::string token4 = token2.substr(token2.find(delimiter2) + 1, token2.length());
        try {
            cmdServ.msz.push_back(std::stoi(token3));
            cmdServ.msz.push_back(std::stoi(token4));
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    if (token == "sgt") {
        try {
            cmdServ.sgt = std::stoi(token2);
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    if (token == "bct") {
        cmdServ.bct.push_back(token2);
    }
    if (token == "tna") {
        cmdServ.tna.push_back(token2);
    }
    if (token == "pnw") {
        // divide token2 by space
        std::istringstream iss(token2);
        std::vector<std::string> parsed_cmd(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());

        for (const auto& mot : parsed_cmd) {
            cmdServ.pnw.push_back(mot);
        }
    }
    if (token == "pdi") {
        std::istringstream iss(token2);
        std::vector<std::string> parsed_cmd(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());
        for (const auto& mot : parsed_cmd) {
            cmdServ.pdi.push_back(mot);
        }
    }
    if (token == "ppo") {
        std::istringstream iss(token2);
        std::vector<std::string> parsed_cmd(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());

        for (const auto& mot : parsed_cmd) {
            cmdServ.ppo.push_back(mot);
        }
    }
    if (token == "plv") {
        std::istringstream iss(token2);
        std::vector<std::string> parsed_cmd(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());

        for (const auto& mot : parsed_cmd) {
            cmdServ.plv.push_back(mot);
        }
    }
    if (token == "pin") {
        std::istringstream iss(token2);
        std::vector<std::string> parsed_cmd(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());

        for (const auto& mot : parsed_cmd) {
            cmdServ.pin.push_back(mot);
        }
    }
    if (token == "pdr") {
        std::istringstream iss(token2);
        std::vector<std::string> parsed_cmd(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());

        for (const auto& mot : parsed_cmd) {
            cmdServ.pdr.push_back(mot);
        }
    }
    if (token == "pgt") {
        std::istringstream iss(token2);
        std::vector<std::string> parsed_cmd(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());

        for (const auto& mot : parsed_cmd) {
            cmdServ.pgt.push_back(mot);
        }
    }
    if (token == "enw") {
        std::istringstream iss(token2);
        std::vector<std::string> parsed_cmd(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());

        for (const auto& mot : parsed_cmd) {
            cmdServ.enw.push_back(mot);
        }
    }
    if (token == "pbc") {
        std::istringstream iss(token2);
        std::vector<std::string> parsed_cmd(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());

        for (const auto& mot : parsed_cmd) {
            cmdServ.pbc.push_back(mot);
        }
    }
    return cmdServ;
}

CommandServer Server_info::updateBct(CommandServer cmdServ)
{
    static std::chrono::steady_clock::time_point lastCallTime = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
    std::chrono::steady_clock::duration elapsed = currentTime - lastCallTime;
    std::chrono::milliseconds interval(0); // to replace with actual server tick rate
    if (elapsed >= interval) {
        //cmdServ.bct.clear();
        sendCommand(getSock(), "mct\n");

        std::string response = receiveResponse(getSock());

        if (response.substr(0, 3) == "bct") {
            cmdServ.bct.clear();
        }

        std::vector<std::string> lines = splitByNewLine(response);
        for (const std::string& line : lines) {
            cmdServ = affectedValue(line, cmdServ);
        }
        lastCallTime = currentTime;
    }
    return cmdServ;
}

CommandServer Server_info::getCmdServ()
{
    return cmdServ;
}

int Server_info::servConnection(std::string serverIP, int serverPort)
{
    setSock(LibC::socket(AF_INET, SOCK_STREAM, 0));
    if (getSock() == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return 1;
    }
    // Set up server address
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = LibC::htons(serverPort);
    if (LibC::inet_pton(AF_INET, serverIP.c_str(), &(serverAddress.sin_addr)) <= 0) {
        std::cerr << "Invalid address/Address not supported." << std::endl;
        return 84;
    }
    // Connect to the server
    if (LibC::connect(getSock(), (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Connection failed." << std::endl;
        return 84;
    }
    // Example commands
    sendCommand(getSock(), "GRAPHIC\n");
    std::string response;
    while (response.empty()) {
        response = receiveResponse(getSock());
    }
    printf("response = %s\n", response.c_str());
    std::vector<std::string> lines = splitByNewLine(response);
    for (const std::string& line : lines) {
        cmdServ = affectedValue(line, cmdServ);
        std::cout << line << std::endl;
    }
    return 0;
}
