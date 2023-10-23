/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCE-4-1-zappy-noah.cherel
** File description:
** libc
*/

#ifndef LIBC_HPP_
    #define LIBC_HPP_

    #include <unistd.h>
    #include <getopt.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>

    namespace LibC {

        static int close(int fd) {
            return ::close(fd);
        }

        static int getopt(int argc, char * const argv[], const char *optstring) {
            return ::getopt(argc, argv, optstring);
        }

        static int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
            return ::connect(sockfd, addr, addrlen);
        }

        static int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen) {
            return ::getsockopt(sockfd, level, optname, optval, optlen);
        }

        static int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen) {
            return ::setsockopt(sockfd, level, optname, optval, optlen);
        }

        static ssize_t send(int sockfd, const void *buf, size_t len, int flags) {
            return ::send(sockfd, buf, len, flags);
        }

        static ssize_t recv(int sockfd, void *buf, size_t len, int flags) {
            return ::recv(sockfd, buf, len, flags);
        }

        static int socket(int domain, int type, int protocol) {
            return ::socket(domain, type, protocol);
        }

        static uint16_t htons(int hostshort) {
            return ::htons(hostshort);
        }

        static int inet_pton(int af, const char *src, void *dst) {
            return ::inet_pton(af, src, dst);
        }

    }


#endif /* !LIBC_HPP_ */
