/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();
        
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();
        void ping();
        void locateSquad();
    private:
        int m_serial;
        int x;
        int y;
        KreogCom *next;
};

#endif /* !KREOGCOM_HPP_ */
