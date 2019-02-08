#include "bubble.h"

        void Bubble::sort(Container* container) {
            int flag = 1;
            int numLength = container->size();
            for (int i = 1; (i <= numLength) && flag; i++) {
                flag = 0;
                for (int j = 0; j < (numLength - 1); j++) {
                    if (container->at(j+1)->evaluate() < container->at(j)->evaluate()) {
			container->swap(j+1, j);
                        flag = 1;
                    }
                }
            }
        }        

