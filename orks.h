#ifndef ORKS_H
#define ORKS_H

#include <QMainWindow>
#include "../destinLib/aventure.h"

enum HistoireOrk {
    eh_VieDUnMekano
};

class Orks : public Aventure
{
    Q_OBJECT
private:
    HistoireOrk m_HistoireOrk;

    static QVector<QString> m_NomsOrks;
    static QVector<QString> m_NomsGretchins;
    static QVector<QString> m_NomsArmes;
    static QVector<QString> m_NomsPartiesArmes;

    void GenererListesObjets();

protected:
    // pour les aventrues qui n'utilisent pas le json mais du code :surclasser aventure et développer cette fonction
    virtual void GenererAventure();
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();

public:
    Orks(HistoireOrk themeHistoire, QWidget *parent = nullptr, QString premierEvt = "", QString premierEffet = "");
    ~Orks();

    static QString GenerationNomOrk();
    static QString GenerationNomGretchin();
    static QString GenerationNomPartieArme();
    static QString GenerationNomArme();
};

#endif // ORKS_H
