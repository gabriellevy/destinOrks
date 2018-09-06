#include "mekano.h"
#include "viedunmekano.h"

Mekano::Mekano(QWidget *parent) :
    IPerso(parent)
{

}
void Mekano::GenererPersos()
{
    DPerso mekano;
    mekano.m_Id = "mekano";
    mekano.m_Nom = "Mékano";
    mekano.m_ImagePortrait.load(":/mekano.jpg");
    mekano.m_CaracsAAfficher.append("competence_armement");
    mekano.m_CaracsAAfficher.append("competence_vehicule");
    mekano.m_CaracsAAfficher.append("competence_bionique");
    mekano.m_CaracsAAfficher.append("nb_esclaves_gretchins");
    mekano.m_CaracsAAfficher.append("nb_esclaves_snotlings");
    mekano.m_CaracsAAfficher.append("clan");
    mekano.m_CaracsAAfficher.append("ferraille");
    mekano.m_CaracsAAfficher.append("gadget");
    mekano.m_CaracsAAfficher.append(VieDunMekano::jours);
    m_Persos.push_back(mekano);
}
