#ifndef MEKANO_H
#define MEKANO_H

#include "../destinLib/perso.h"

class Mekano : public IPerso
{
    Q_OBJECT
public:
    explicit Mekano(QWidget *parent = nullptr);

    virtual void GenererPersos();

signals:

public slots:
};

#endif // MEKANO_H
