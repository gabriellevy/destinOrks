#include "orks.h"
#include "../destinLib/perso.h"
#include "ui_aventure.h"
#include "mekano.h"
#include "viedunmekano.h"


QVector<QString> Orks::m_NomsOrks = {};
QVector<QString> Orks::m_NomsGretchins = {};
QVector<QString> Orks::m_NomsPartiesArmes = {};
QVector<QString> Orks::m_NomsArmes = {};

Orks::Orks(HistoireOrk themeHistoire, QWidget *parent, QString premierEvt, QString premierEffet)
    : Aventure(parent), m_HistoireOrk(themeHistoire)
{
    // intialisations générales
    GenererListesObjets();

    //
    switch (themeHistoire) {
    case HistoireOrk::eh_VieDUnMekano : {
        m_Perso = new Mekano(ui->persoWidget);
        m_Histoire = new VieDunMekano(ui->histoireWidget);
        this->setWindowTitle("Vie d'un Mékano");

    }break;

    }

    // positionner l'interface
    ui->persoWidget->layout()->addWidget(m_Perso);
    //m_Perso->show();
    ui->histoireWidget->layout()->addWidget(m_Histoire);

    GenererAventure();

    if ( premierEvt != "" )
        m_Histoire->SetCurrentEvtId( premierEvt ) ;
    if ( premierEffet!= "" )
        m_Histoire->SetEffetIndex(m_Histoire->DeterminerIndexEffet(premierEffet) );

    m_EtatPartie = EP_Deroulement;
    LancerEvtEtOuEffetCourant();
}

Orks::~Orks()
{

}

void Orks::GenererAventure()
{
    GenererCaracs();

    (static_cast<Mekano*>(m_Perso))->GenererPersos();

    m_Histoire->GenererHistoire();

    m_Perso->RafraichirAffichage();
}

void Orks::GenererCaracs()
{
    m_Perso->m_Caracs.append(new Carac(VieDunMekano::competence_armement, "Compétence en armes", "0",
                                       "",
                                       "", MODE_AFFICHAGE::ma_Nombre
                                       ));
    m_Perso->m_Caracs.append(new Carac(VieDunMekano::competence_vehicule, "Compétence en véhicules", "0",
                                       "",
                                       "", MODE_AFFICHAGE::ma_Nombre
                                       ));
    m_Perso->m_Caracs.append(new Carac(VieDunMekano::competence_bionique, "Compétence en bionique", "0",
                                       "",
                                       "", MODE_AFFICHAGE::ma_Nombre
                                       ));
    m_Perso->m_Caracs.append(new Carac(VieDunMekano::nb_esclaves_gretchins, "Esclaves gretchins", "3",
                                       ":/esclave gretchin.PNG",
                                       "", MODE_AFFICHAGE::ma_Nombre
                                       ));
    m_Perso->m_Caracs.append(new Carac(VieDunMekano::nb_esclaves_snotlings, "Esclaves snotlings", "0",
                                       ":/esclave snotling.PNG",
                                       "", MODE_AFFICHAGE::ma_Nombre
                                       ));
    m_Perso->m_Caracs.append(new Carac(VieDunMekano::clan, "Clan", "0",
                                       ":/bloodaxes.jpg",
                                       "", MODE_AFFICHAGE::ma_Img
                                       ));
    m_Perso->m_Caracs.append(new Carac(VieDunMekano::ferraille, "Ferraille", "20",
                                       ":/ferraille.jpg",
                                       "", MODE_AFFICHAGE::ma_Nombre
                                       ));
    m_Perso->m_Caracs.append(new Carac(VieDunMekano::gadget, "Gadget", "0",
                                       ":/gadget.jpg",
                                       "", MODE_AFFICHAGE::ma_Nombre
                                       ));
    m_Perso->m_Caracs.append(new Carac(VieDunMekano::jours, "JOurs passés", "0",
                                       "",
                                       "", MODE_AFFICHAGE::ma_Nombre
                                       ));
}

QString Orks::GenerationNomOrk()
{
    return m_NomsOrks[qrand() % m_NomsOrks.size()];
}

QString Orks::GenerationNomGretchin()
{
    return m_NomsGretchins[qrand() % m_NomsGretchins.size()];
}

QString Orks::GenerationNomPartieArme()
{
    return m_NomsPartiesArmes[qrand() % m_NomsPartiesArmes.size()];
}

QString Orks::GenerationNomArme()
{
    return m_NomsArmes[qrand() % m_NomsArmes.size()];
}


void Orks::GenererListesObjets()
{
    Orks::m_NomsGretchins <<"Zorgob" << "Mirkus"<<"Ari"<<"Makari";

    Orks::m_NomsOrks <<"Nuzzgrond"<< "Hef"<< "Ratgrab"<< "Supur"<< "Nozgrot"<< "Clakgob"
            <<"Urgluk" << "Dragnatz" << "Zorgob" <<"Ugrik" <<"Glug" << "Veg" << "Tik-tak"
           << "Zorg" << "Naffzod" << "Grugrot" << "Snikgut"<<"Arik"<<"Chub";

    Orks::m_NomsPartiesArmes<<"avec viseur laser"<<"à canon scié"<<"à répétition"<<"triple canon"
            <<"à visée intelligente"<<"de poche"<<"lance-missile"<<"d'assaut"<<"lourd"<<"de la mort"
            <<"viseur laser"<<"à pompe"<<"lance-flamme"<<"plasma"<<"automatique"<<"flak"
            <<"gatling"<<"empoisonné"<<"laser"<<"toxique"<<"tête chercheuse"<<"avec lance-grenade"
           <<"nucléaire"<<"foudroyant"<<"énergétique";

    Orks::m_NomsArmes<< "Fling'"<<"Revolver"<<"Mitrailleuse"<<"lance-missile"<<"canon";
}
