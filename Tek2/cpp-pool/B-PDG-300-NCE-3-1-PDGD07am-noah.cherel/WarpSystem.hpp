/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
        public:
            bool isStable();
            void setStability(bool stability);
        protected:
            bool _stability = true;
        private:
    };
    class Core {
        public:
            Core(WarpSystem::QuantumReactor *coreReactor);
            QuantumReactor *checkReactor();
        protected:
        private:
            QuantumReactor *_coreReactor;
    };
}

#endif /* !WARPSYSTEM_HPP_ */
