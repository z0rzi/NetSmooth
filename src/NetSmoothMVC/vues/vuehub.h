#ifndef VUEHUB_H
#define VUEHUB_H

#include "vueentitee.h"

class VueHub : public VueEntitee
{
    Q_OBJECT
public:
    explicit VueHub(VueEntitee *parent = 0);
};

#endif // VUEHUB_H
