#ifndef VIEDUNMEKANO_H
#define VIEDUNMEKANO_H

#include "../destinLib/histoire.h"

class VieDunMekano : public Histoire
{
    Q_OBJECT
public:
    explicit VieDunMekano(QWidget *parent = nullptr);

    virtual void GenererHistoire();

    // callbacks spécifiques :
    //static void TempPasse(QString nbJoursStr);
    static QString competence_armement;
    static QString competence_vehicule;
    static QString competence_bionique;
    static QString nb_esclaves_gretchins;
    static QString nb_esclaves_snotlings;
    static QString clan;
    static QString ferraille;
    static QString gadget;
    static QString jours;

private:
    void GenererEvtsAccueil();
    void GenererEvtRandomJournalier();

    // sous événements aléatoires
    void MedikoBionique();

signals:

public slots:
};

#endif // VIEDUNMEKANO_H
