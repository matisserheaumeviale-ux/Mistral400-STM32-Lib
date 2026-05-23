/* =============================================================================================
 * FICHIER     : controle.c
 * PROJET      : Projet-de-fin-de-session-2026
 * CHEMIN      : Logiciel/STM32/EnCours/Core/Src/controle.c
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * CRÉATION    : 2026-04-29
 * COMPILATEUR : VSCode avec extension Makefile et ARM GCC et extension QuickCommand 
 * LICENCE     : Usage scolaire / interne
 * =============================================================================================
 * DESCRIPTION :
 * Contient la logique de controle automatique et manuel.
 * Compare les entrees, les consignes et les etats reels.
 * Demande les actions chauffage, ventilation et lumiere.
 * MATÉRIEL    : Sorties chauffage, ventilation, lumiere et feedbacks associes.
 * DÉPENDANCES : fonctions.h.
 * =============================================================================================
 * SPÉCIFICATIONS TECHNIQUES :
 *
 * * TYPES DE DONNÉES & VARIABLES :
 * Utilise UC pour le mode, les delais et lexfs etats de sortie.
 * Utilise float pour comparer la temperature aux consignes.
 *
 * * GESTION DES POINTEURS :
 * Recoit ucTab par pointeur pour modifier les etats du systeme.
 *
 * * AUTRES MÉCANISMES :
 * Mode automatique selon temperature et luminosite.
 * Mode manuel synchronise les etats reels avec le tableau.
 * =============================================================================================
 * NOTES :
 * 1. Les delais evitent que le mode automatique reprenne trop vite.
 * 2. Les fonctions Allume/Ferme restent dans actions.c.
 * =============================================================================================
 * HISTORIQUE DES RÉVISIONS :
 * Date        Ver   Auteur    Notes
 * ----------  ----  --------  ----------------------------------------------------------------
 * VOIR SUR LE GITHUB 
 * =============================================================================================
 */
#include "fonctions.h"

static void xTraiteChangementFeedback(UC ucMode,
                                       UC *ucpTab,
                                       UC ucIndexEtat,
                                       UC ucIndexDelai,
                                       UC ucEtatLu,
                                       UC ucAncienEtatLu,
                                       UC *ucpCommandeLogicielle)
{
  if (ucEtatLu == ucAncienEtatLu)
  {
    return;
  }

  ucpTab[ucIndexEtat] = ucEtatLu;

  if ((ucpCommandeLogicielle != NULL) && (*ucpCommandeLogicielle == ON))
  {
    *ucpCommandeLogicielle = OFF;
    return;
  }

  if (ucMode == AUTOMATIQUE)
  {
    ucpTab[ucIndexDelai] = DELAI_PRISE_CONTROLE_AUTO;
  }
}

/* =============================================================================================
 * Fonction     : CompareEntreesSorties
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Detecte si une sortie reelle ne correspond plus a l etat voulu.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/controle.c
 * DÉPENDANCES : Voir les includes du fichier.
 * =============================================================================================
 * TYPES DE DONNÉES & VARIABLES :
 * Utilise les types et variables visibles dans la signature de la fonction.
 * GESTION DES POINTEURS :
 * Verifie les pointeurs quand la fonction en recoit.
 * =============================================================================================
 * Resulats attendu:
 * La fonction fait son action sans modifier les autres parties du programme.
 * ============================================================================================
 */
void CompareEntreesSorties(UC ucMode,
                           UC *ucpTab,
                           UC ucChauffageLu,
                           UC ucVentilationLu,
                           UC ucLumiereLu,
                           UC ucAncienChauffageLu,
                           UC ucAncienVentilationLu,
                           UC ucAncienLumiereLu,
                           UC *ucpCommandeLogicielleChauf,
                           UC *ucpCommandeLogicielleVent,
                           UC *ucpCommandeLogicielleLum)
{
  if ((ucpTab == NULL) || (UTILISER_FEEDBACKS_REELS == 0U))
  {
    return;
  }

  xTraiteChangementFeedback(ucMode,
                            ucpTab,
                            ETATCHAUF,
                            DELAICHAUF,
                            ucChauffageLu,
                            ucAncienChauffageLu,
                            ucpCommandeLogicielleChauf);

  xTraiteChangementFeedback(ucMode,
                            ucpTab,
                            ETATVENT,
                            DELAIVENT,
                            ucVentilationLu,
                            ucAncienVentilationLu,
                            ucpCommandeLogicielleVent);

  xTraiteChangementFeedback(ucMode,
                            ucpTab,
                            ETATLUM,
                            DELAILUM,
                            ucLumiereLu,
                            ucAncienLumiereLu,
                            ucpCommandeLogicielleLum);
}
/* =============================================================================================
 * Fonction     : ModeAutomatique
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Applique les decisions automatiques selon temperature et luminosite.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/controle.c
 * DÉPENDANCES : Voir les includes du fichier.
 * =============================================================================================
 * TYPES DE DONNÉES & VARIABLES :
 * Utilise les types et variables visibles dans la signature de la fonction.
 * GESTION DES POINTEURS :
 * Verifie les pointeurs quand la fonction en recoit.
 * =============================================================================================
 * Resulats attendu:
 * La fonction fait son action sans modifier les autres parties du programme.
 * ============================================================================================
 */
void ModeAutomatique(UC *ucpTab,
                     float fTemperatureC,
                     UC ucConsigneBasse,
                     UC ucConsigneHaute,
                     UC ucEtatJour,
                     UC ucEtatNuit)
{
  if (ucpTab == NULL)
  {
    return;
  }

  if (ucpTab[DELAICHAUF] == 0U)
  {
    if (fTemperatureC < (float)ucConsigneBasse)
    {
      AllumeChauffage(ucpTab);
    }
    else if (fTemperatureC > (float)ucConsigneBasse)
    {
      FermeChauffage(ucpTab);
    }
  }

  if (ucpTab[DELAIVENT] == 0U)
  {
    if (fTemperatureC > (float)ucConsigneHaute)
    {
      AllumeVentilation(ucpTab);
    }
    else if (fTemperatureC < (float)ucConsigneHaute)
    {
      FermeVentilation(ucpTab);
    }
  }

  if (ucpTab[DELAILUM] == 0U)
  {
    if (ucEtatJour == VRAI)
    {
      FermeLumiere(ucpTab);
    }
    else if (ucEtatNuit == VRAI)
    {
      AllumeLumiere(ucpTab);
    }
  }
}
/* =============================================================================================
 * Fonction     : ModeManuel
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Synchronise le tableau avec les etats reels en mode manuel.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/controle.c
 * DÉPENDANCES : Voir les includes du fichier.
 * =============================================================================================
 * TYPES DE DONNÉES & VARIABLES :
 * Utilise les types et variables visibles dans la signature de la fonction.
 * GESTION DES POINTEURS :
 * Verifie les pointeurs quand la fonction en recoit.
 * =============================================================================================
 * Resulats attendu:
 * La fonction fait son action sans modifier les autres parties du programme.
 * ============================================================================================
 */
void ModeManuel(UC *ucpTab)
{
  if (ucpTab == NULL)
  {
    return;
  }

  SynchroniseEtatsReels(ucpTab);
}
