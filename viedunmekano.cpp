#include "viedunmekano.h"
#include "orks.h"
#include "../destinLib/perso.h"

QString VieDunMekano::competence_armement = "competence_armement";
QString VieDunMekano::competence_vehicule = "competence_vehicule";
QString VieDunMekano::competence_bionique = "competence_bionique";
QString VieDunMekano::nb_esclaves_gretchins = "nb_esclaves_gretchins";
QString VieDunMekano::nb_esclaves_snotlings = "nb_esclaves_snotlings";
QString VieDunMekano::clan = "clan";
QString VieDunMekano::ferraille = "ferraille";
QString VieDunMekano::gadget = "gadget";
QString VieDunMekano::jours = "jours";

VieDunMekano::VieDunMekano(QWidget *parent):Histoire(parent)
{
}

void VieDunMekano::GenererHistoire()
{
    m_Themes.append("warhammer 40000");
    m_Themes.append("malefique");
    m_Themes.append("journalier");
    m_Themes.append("ork");

    GenererEvtsAccueil();
    GenererEvtRandomJournalier();
}

void VieDunMekano::GenererEvtRandomJournalier()
{
    Evt* UnJourPasse = AjouterEvt("UnJourPasse", "Jour typique");

    Effet* effet_un_jour = UnJourPasse->AjouterEffetAjouteurACarac(VieDunMekano::jours, "1", "effet_UnJourPasse");
    //effet_un_jour->m_GoToEvtId = "RandomJournalier";

    Effet* test_apres_effet_un_jour = UnJourPasse->AjouterEffetNarration("test après effet_UnJourPasse pas dans le else", "test après effet_UnJourPasse");
    test_apres_effet_un_jour->m_Son = "qrc:/alcibiade_mozart23III.mp3";
    test_apres_effet_un_jour->m_GoToEffetId = "YoupiTmp";

    test_apres_effet_un_jour->AjouterCondition( VieDunMekano::jours, Comparateur::c_SuperieurEgal, "5");
    Noeud* elseNoeud = test_apres_effet_un_jour->AjouterElse("effet_UnJourPasse dans le else");
    elseNoeud->m_GoToEffetId = "YoupiTmpElse";

    // tmp test :
    Effet* tmpTest = UnJourPasse->AjouterEffetNarration("NORMAL Youpi Tmp dans la narration", "", "YoupiTmp");
    tmpTest->m_GoToEffetId = "effet_UnJourPasse";

    Effet* tmpTest2 = UnJourPasse->AjouterEffetNarration("ELSE Youpi Tmp dans la narration", "", "YoupiTmpElse");
    tmpTest2->m_GoToEffetId = "effet_UnJourPasse";

    EvtAleatoire* RandomJournalier = AjouterEvtAleatoire("RandomJournalier", "Jour typique");

    MedikoBionique();
    Effet * MedikoBionique = RandomJournalier->AjouterEffetVide();
    MedikoBionique->AjouterConditionProba(0.04); // moduler cette proba en fonction de la réputation du mékano en bionique ?
    MedikoBionique->m_GoToEvtId = "MedikoBionique";


}

void VieDunMekano::MedikoBionique()
{
    Evt* UnJourPasse = AjouterEvt("MedikoBionique", "Visite d'un médiko");
    Effet* effet = UnJourPasse->AjouterEffetNarration(
           "Le médiko " + Orks::GenerationNomOrk() + " vous rend visite. Il a besoin d'aide pour installer une prothèse bionique sur un malade. \n======> pas fait");
    effet->m_GoToEvtId = "UnJourPasse";
}

 void VieDunMekano::GenererEvtsAccueil()
 {
     Evt* Debut = AjouterEvt("Debut", "Installation d'un mékano");
     Effet* intro = Debut->AjouterEffetNarration("Youpi vous êtes un mékano.");
     //intro->m_GoToEvtId = "RandomJournalier";
     intro->m_GoToEvtId = "UnJourPasse";

     /*Effet* effetAtterrissage = Debut->AjouterEffetNarration("Le vaisseau où vous étiez en hibernation depuis un temps indéterminé, des siècles peut-être, vient enfin de s'écraser sur une planête inconnue. Votre organisme sort de l'hibernation, vos muscles s'étirent, il est temps de se mettre en chasse. La faim vous taraude déjà. Mais un autre instinct s'y mélange, presque aussi fort : celui de créer un nid, de s'y réfugier et de s'y reproduire. \nPour l'heure une seule pensée vous obséde : que ce soit pour l'un ou l'autre de ces buts il vous faut découvrir si cette planète est habitée par des êtres vivants, qui pourront satisfaire tous vos instincts primitifs.",
                       ":/Aventures/Warhammer 40000/Tyranides/Genestealers_atterissage.jpg",
                       "" );
     effetAtterrissage->AjouterChoixGoToEffet(
                 "Chercher une proie aux alentours", "chasse_genestealer");
     effetAtterrissage->AjouterChoixGoToEffet(
                 "Essayer de s'approcher de la montagne de métal visible à l'horizon", "approche_ruche_lamos");
     effetAtterrissage->AjouterChoixGoToEffet(
                 "Chercher dans l'épave si il y d'autres genestealers", "fouille_epave_genestealers");*/
 }
