/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Textmain
*/

#include "TextClass.hpp"
#include "../Corefiles/Core.hpp"

void printStatName(WINDOW *win, int y, int x, std::string name)
{
    wattron(win, COLOR_PAIR(1));
    wattron(win, A_BOLD);
    mvwprintw(win, y, x, "%s", name.c_str());
    wattroff(win, A_BOLD);
    wattroff(win, COLOR_PAIR(1));
}

void printStatValue(WINDOW *win, int y, int x, std::string value)
{
    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, y, x, "%s", value.c_str());
    wattroff(win, COLOR_PAIR(2));
}

void printStatNameAndValue(WINDOW *win, int y, int x, std::string name, std::string value)
{
    printStatName(win, y, x, name);
    printStatValue(win, y, x + name.length(), value);
}

void printBox(WINDOW *win, int y, int x, int width, int height, std::string name)
{
    y++;
    wattron(win, COLOR_PAIR(4));
    wattron(win, A_BOLD);
    mvwprintw(win, y + 1, (x + width / 2) - name.length() / 2, "%s", name.c_str());
    for (int i = x + 1; i < x + width; i++)
        mvwprintw(win, y - 1, i, "_");
    for (int i = x; i < x + width; i++)
        mvwprintw(win, y + height, i, "_");
    for (int i = y; i <= y + height; i++)
        mvwprintw(win, i, x, "|");
    for (int i = y; i <= y + height; i++)
        mvwprintw(win, i, x + width, "|");
    wattroff(win, A_BOLD);
    wattroff(win, COLOR_PAIR(4));
}

void printSystemInfo(WINDOW *win, int y, int x, Core *core)
{
    char hostname[1024];
    gethostname(hostname, 512);
    std::string username = std::getenv("USER");
    struct utsname unameData;
    uname(&unameData);
    time_t now = time(0);
    char *dt = ctime(&now);
    printStatName(win, y + 2, x, "Operating System: ");
    printStatValue(win, y + 2, x + 18, unameData.sysname);
    printStatNameAndValue(win, y + 3, x, "Kernel version: ", unameData.release);
    printStatNameAndValue(win, y + 4, x, "Hostname: ", hostname);
    printStatNameAndValue(win, y + 5, x, "Username: ", username);
    printStatNameAndValue(win, y + 6, x, "Global Core usage: ", std::to_string(core->getCoreUsage()) + "%");
    printStatNameAndValue(win, y + 7, x, "Date and Time: ", dt);
    printBox(win, y - 2, x - 2, 56, 9, "SYSTEM INFO");
}

void printRAMConsumption(WINDOW *win, int y, int x, Core *core)
{
    if (core->getSysInfo().totalram - core->getSysInfo().freeram > 1024 * 1024 * 1024)
        printStatNameAndValue(win, y + 2, x, "RAM usage: ", std::to_string(((core->getSysInfo().totalram - core->getSysInfo().freeram) / 1024) / 1024 / 1024) + " GB (" + std::to_string(core->getSysInfo().totalram / 1024 / 1024 / 1024) + " GB total)");
    else
        printStatNameAndValue(win, y + 2, x, "RAM usage: ", std::to_string(((core->getSysInfo().totalram - core->getSysInfo().freeram) / 1024) / 1024) + " MB (" + std::to_string(core->getSysInfo().totalram / 1024 / 1024) + " MB total)");
    if (core->getSysInfo().totalswap - core->getSysInfo().freeswap > 1024 * 1024 * 1024)
        printStatNameAndValue(win, y + 3, x, "Swap usage: ", std::to_string(((core->getSysInfo().totalswap - core->getSysInfo().freeswap) / 1024) / 1024 / 1024) + " GB (" + std::to_string(core->getSysInfo().totalswap / 1024 / 1024 / 1024) + " GB total)");
    else
        printStatNameAndValue(win, y + 3, x, "Swap usage: ", std::to_string(((core->getSysInfo().totalswap - core->getSysInfo().freeswap) / 1024) / 1024) + " MB (" + std::to_string(core->getSysInfo().totalswap / 1024 / 1024) + " MB total)");
    printBox(win, y - 2, x - 2, 56, 5, "RAM CONSUMPTION");
}

void printCPUInfo(WINDOW *win, int y, int x, Core *core)
{
    printStatNameAndValue(win, y + 2, x, "CPU model: ", core->getCpuModel());
    printStatNameAndValue(win, y + 3, x, "Frequency: ", std::to_string(core->getCpuFrequency()) + " MHz");
    printStatNameAndValue(win, y + 4, x, "Number of cores: ", std::to_string(core->getCpuCores()) + " cores");
    printBox(win, y - 2, x - 2, 56, 6, "CPU INFO");
}

void printNetworkLoad(WINDOW *win, int y, int x, Core *core)
{
    struct ifaddrs *ifaddr, *ifa;
    getifaddrs(&ifaddr);
    std::string interface_name;
    std::map<std::string, std::pair<unsigned long long, unsigned long long>> network_load = core->getNetworkLoad();
    int line = y;
    line++;
    for (auto& interface : network_load) {
        interface_name = interface.first;
        wattron(win, COLOR_PAIR(1));
        wattron(win, A_BOLD);
        mvwprintw(win, line, x, "Network load (interface: %s): \n", interface_name.c_str());
        wattroff(win, A_BOLD);
        wattroff(win, COLOR_PAIR(1));
        wattron(win, COLOR_PAIR(2));
        if (interface.second.first > 1024 * 1024 * 1024)
            mvwprintw(win, line, x + 28 + interface_name.length(), "%llu GB/s\n", interface.second.first / 1024 / 1024 / 1024);
        else if (interface.second.first > 1024 * 1024)
            mvwprintw(win, line, x + 28 + interface_name.length(), "%llu MB/s\n", interface.second.first / 1024 / 1024);
        else if (interface.second.first > 1024)
            mvwprintw(win, line, x + 28 + interface_name.length(), "%llu KB/s\n", interface.second.first / 1024);
        else
            mvwprintw(win, line, x + 28 + interface_name.length(), "%llu B/s\n", interface.second.first);
        wattroff(win, COLOR_PAIR(2));
        line++;
    }
    printBox(win, y - 3, x - 2, 56, line - y + 2, "NETWORK");
    freeifaddrs(ifaddr);
}

void printDiskInfo(WINDOW *win, int y, int x, Core *core)
{
    struct statvfs buf;
    statvfs("/", &buf);
    printStatNameAndValue(win, y + 2, x, "Total disk space: ", std::to_string((buf.f_blocks * buf.f_frsize) / 1024 / 1024 / 1024) + " GB");
    printStatNameAndValue(win, y + 3, x, "Used disk space: ", std::to_string(((buf.f_blocks - buf.f_bfree) * buf.f_frsize) / 1024 / 1024 / 1024) + " GB");
    printStatNameAndValue(win, y + 4, x, "Free disk space: ", std::to_string((buf.f_bfree * buf.f_frsize) / 1024 / 1024 / 1024) + " GB");
    printBox(win, y - 2, x - 2, 56, 6, "DISK INFO");
}

void printCPUs(WINDOW *win, int y, int x, Core *core, int maxcols)
{
    std::vector<double> cpu_load = core->getCoreUsagePerCore();
    int left = x;
    int line = y;
    int maxperline;
    maxperline = maxcols / 30;
    line++;
    for (int i = 0; i < cpu_load.size(); i++) {
        printBox(win, line - 1, x - 2, 26, 4, "CORE " + std::to_string(i));
        printStatNameAndValue(win, line + 3, x, "Usage: ", std::to_string(cpu_load[i]) + "%");
        if ((i + 1) % maxperline == 0) {
            line += 6;
            x = left;
        } else
            x += 30;
    }
}

void TextClass::dispText(WINDOW *win)
{
    int rows, cols;
    getmaxyx(win, rows, cols);
    int minrows = 47;
    if (cols > 179)
        minrows = 34;
    if (rows < minrows || cols < 100) {
        wattron(win, COLOR_PAIR(1));
        wattron(win, A_BOLD);
        mvwprintw(win, rows / 2, cols / 2 - 10, "Window too small!");
        wattroff(win, A_BOLD);
        wattroff(win, COLOR_PAIR(1));
        wrefresh(win);
        return;
    }
    printSystemInfo(win, 2, 3, core);
    printRAMConsumption(win, 13, 3, core);
    printCPUInfo(win, 2, 63, core);
    printNetworkLoad(win, 11, 63, core);
    if (cols > 177)
        printDiskInfo(win, 2, 123, core);
    else
        printDiskInfo(win, 19, 63, core);
    std::vector<double> cpu_load = core->getCoreUsagePerCore();
    int pCPUsY = (float)cpu_load.size() / (float)((cols + 1) / 30);
    std::floor(pCPUsY);
    if (pCPUsY != (float)cpu_load.size() / (float)((cols + 1) / 30))
        pCPUsY++;
    pCPUsY *= 6;
    pCPUsY += 4;
    printCPUs(win, rows - pCPUsY, 3, core, cols + 1);
    mvwprintw(win, rows - 2, 1, "Press 'Q' or 'Esc' to quit...\n");
    wrefresh(win);
    wclear(win);
}

void TextClass::initNCurses()
{
    initscr();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
}

TextClass::TextClass()
{
    core = new Core();
    initNCurses();
    int row, col;
    getmaxyx(stdscr, row, col);
    WINDOW *win = newwin(row, col, 0, 0);
    nodelay(stdscr, true);
    wrefresh(win);
    keypad(stdscr, true);
    while (true) {
        dispText(win);
        int c = getch();
        if (c != ERR && (c == 'q' || c == 27)) {
            break;
        }
    }
    nodelay(stdscr, false);
    endwin();
}

TextClass::~TextClass()
{
}
