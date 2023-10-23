/*
** EPITECH PROJECT, 2023
** Marc-Olivier KOBAN
** File description:
** main.cpp
*/

#include "../include/game.hpp"
#include "../include/libc.hpp"

void help()
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

int main(int ac, char *av[]) {
    if (ac == 2 && av[1] == std::string("--help")) {
        help();
        return 0;
    }
    if (!(ac == 3 && av[1] == std::string("-p")) && !(ac == 5 && av[1] == std::string("-p") && av[3] == std::string("-h")) && !(ac == 5 && av[1] == std::string("-h") && av[3] == std::string("-p"))) {
        std::cerr << "Missing argument" << std::endl;
        help();
        return 84;
    }
    Server_info server;
    server.setServerName("127.0.0.1");
    server.setServerPort(0);
    for (int i = 0; i < ac; i++) {
        if (av[i] == std::string("-p"))
            server.setServerPort(std::atoi(av[i + 1]));
        if (av[i] == std::string("-h")) {
            if (av[i + 1] != std::string("localhost"))
                server.setServerName(av[i + 1]);
        }
    }
    CommandServer cmdServ;
    if (server.servConnection(server.getServerName(), server.getServerPort()) == 1) {
        return 84;
    }
    cmdServ = server.getCmdServ();
    Game game;
    game.game(1920, 1080, "Zappy", server, cmdServ);
    LibC::close(server.getSock());
    return 0;
}
