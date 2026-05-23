#include "fonctions.h"
/* =============================================================================================
 * Fonction     : xLireEtatDepuisPin
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale & AFLC
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Lit une pin de feedback et retourne ON ou OFF.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
static UC xLireEtatDepuisPin(GPIO_TypeDef *xPort,  
                             uint16_t usPin,
                             GPIO_PinState xEtatActif,
                             UC ucEtatDefaut)
{
  if (UTILISER_FEEDBACKS_REELS == 0U) // Utilisation d'états par défaut sans lire les pins de feedback
  {
    return ucEtatDefaut; // Retourne l'état par défaut défini pour l'élément (chauffage, ventilation, lumière)
  }

  return (HAL_GPIO_ReadPin(xPort, usPin) == xEtatActif) ? ON : OFF; // Lit l'état réel depuis la pin de feedback et le convertit en ON/OFF
}

/* =============================================================================================
 * Fonction     : xImpulsionCommande
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Envoie une impulsion sur une pin de commande.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
static void xImpulsionCommande(GPIO_TypeDef *xPortCommande, // Port GPIO de la commande (chauffage, ventilation, lumière)
                               uint16_t usPinCommande,  // Pin GPIO de la commande
                               GPIO_PinState xEtatActif, // État actif à appliquer pour déclencher la commande (généralement GPIO_PIN_RESET ou GPIO_PIN_SET selon le circuit de commande)
                               GPIO_PinState xEtatRepos) // État de repos à appliquer après l'impulsion (généralement l'inverse de l'état actif)
{
  HAL_GPIO_WritePin(xPortCommande, usPinCommande, xEtatRepos); // Assure que la commande est au repos avant de commencer l'impulsion
  HAL_GPIO_WritePin(xPortCommande, usPinCommande, xEtatActif); // Applique l'état actif pour déclencher la commande
  HAL_Delay(PULSE_TOGGLE_MS); // Maintient l'état actif pendant une durée définie pour assurer que la commande est prise en compte (50 ms dans ce cas)
  HAL_GPIO_WritePin(xPortCommande, usPinCommande, xEtatRepos); // Remet la commande à l'état de repos après l'impulsion
  HAL_Delay(PULSE_STABILISATION_MS); // 
}
/* =============================================================================================
 * Fonction     : xAppliquerEtatElement
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Compare l etat reel a l etat voulu et commande si necessaire.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
static void xAppliquerEtatElement(UC *ucpTab, // Tableau des états actuels des éléments (chauffage, ventilation, lumière)
                                  UC ucIndexEtat,  // Index dans le tableau pour l'élément concerné (ETATCHAUF, ETATVENT, ETATLUM)
                                  GPIO_TypeDef *xPortCommande, // Port GPIO de la commande pour l'élément concerné
                                  uint16_t usPinCommande, // Pin GPIO de la commande pour l'élément concerné
                                  GPIO_PinState xEtatCommandeActif, // État actif à appliquer pour déclencher la commande de l'élément (généralement GPIO_PIN_RESET ou GPIO_PIN_SET selon le circuit de commande)
                                  GPIO_PinState xEtatCommandeRepos, // État de repos à appliquer après l'impulsion de commande (généralement l'inverse de l'état actif)
                                  GPIO_TypeDef *xPortEtat, // Port GPIO de la pin de feedback pour l'élément concerné
                                  uint16_t usPinEtat, // Pin GPIO de la pin de feedback pour l'élément concerné
                                  GPIO_PinState xEtatFeedbackActif, // État actif à lire depuis la pin de feedback pour déterminer si l'élément est considéré comme ON ou OFF.
                                  UC ucEtatDefaut, // État par défaut à utiliser si la lecture de la pin de feedback n'est pas utilisée (ON ou OFF)
                                  UC ucEtatVoulu) // État souhaité pour l'élément (ON ou OFF)
{
  UC ucEtatReel = OFF; // Variable pour stocker l'état réel lu depuis la pin de feedback

  if (ucpTab == NULL) // Vérifie que le pointeur vers le tableau des états n'est pas NULL avant de continuer
  {
    return; // Si le pointeur est NULL, la fonction ne peut pas continuer et retourne immédiatement pour éviter des accès mémoire invalides
  }

  ucpTab[ucIndexEtat] = xLireEtatDepuisPin(xPortEtat, // Lit l'état réel de l'élément depuis la pin de feedback et le stocke dans le tableau des états à l'index correspondant
                                           usPinEtat, // Pin GPIO de la pin de feedback pour l'élément concerné
                                           xEtatFeedbackActif, // État actif à lire depuis la pin de feedback pour déterminer si l'élément est considéré comme ON ou OFF.
                                           ucEtatDefaut); // Si la lecture de la pin de feedback n'est pas utilisée, utilise l'état par défaut défini pour l'élément (ON ou OFF)

  ucEtatReel = ucpTab[ucIndexEtat]; // Stocke l'état réel lu depuis la pin de feedback dans la variable ucEtatReel pour une comparaison ultérieure avec l'état souhaité

  if (ucEtatReel != ucEtatVoulu) // Compare l'état réel de l'élément avec l'état souhaité. Si les deux états sont différents, cela signifie que l'élément n'est pas dans l'état désiré et qu'une action doit être prise pour le changer.
  {
    xImpulsionCommande(xPortCommande, // Applique une impulsion sur la pin de commande pour tenter de changer l'état de l'élément (chauffage, ventilation, lumière) vers l'état souhaité
                       usPinCommande, // Pin GPIO de la commande pour l'élément concerné
                       xEtatCommandeActif, // État actif à appliquer pour déclencher la commande de l'élément (généralement GPIO_PIN_RESET ou GPIO_PIN_SET selon le circuit de commande)
                       xEtatCommandeRepos); // État de repos à appliquer après l'impulsion de commande (généralement l'inverse de l'état actif)

    ucpTab[ucIndexEtat] = xLireEtatDepuisPin(xPortEtat, // Après l'impulsion de commande, lit à nouveau l'état réel de l'élément depuis la pin de feedback pour vérifier si la commande a réussi à changer l'état de l'élément vers l'état souhaité
                                             usPinEtat, // Pin GPIO de la pin de feedback pour l'élément concerné
                                             xEtatFeedbackActif, // État actif à lire depuis la pin de feedback pour déterminer si l'élément est considéré comme ON ou OFF.
                                             ucEtatDefaut); // Si la lecture de la pin de feedback n'est pas utilisée, utilise l'état par défaut défini pour l'élément (ON ou OFF)
  }
}
/* =============================================================================================
 * Fonction     : InitCommandesBascule
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Place les commandes chauffage, ventilation et lumiere au repos.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void InitCommandesBascule(void) // Initialise les pins de commande pour le chauffage, la ventilation et la lumière à leur état de repos (généralement OFF) au démarrage du système
{
  HAL_GPIO_WritePin(CMD_CHAUF_GPIO_Port, CMD_CHAUF_Pin, CMD_CHAUFFAGE_REPOS); // Initialise la pin de commande du chauffage à son état de repos (OFF)
  HAL_GPIO_WritePin(CMD_VENT_GPIO_Port, CMD_VENT_Pin, CMD_VENTILATION_REPOS); // Initialise la pin de commande de la ventilation à son état de repos (OFF)
  HAL_GPIO_WritePin(CMD_LUM_GPIO_Port, CMD_LUM_Pin, CMD_LUMIERE_REPOS); // Initialise la pin de commande de la lumière à son état de repos (OFF)
}
/* =============================================================================================
 * Fonction     : LireEtatsReels
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Lit les feedbacks reels des trois sorties.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void LireEtatsReels(UC *ucpChauffage, UC *ucpVentilation, UC *ucpLumiere) // Lit les états réels du chauffage, de la ventilation et de la lumière depuis les pins de feedback et les stocke dans les variables pointées par ucpChauffage, ucpVentilation et ucpLumiere
{
  if ((ucpChauffage == NULL) || (ucpVentilation == NULL) || (ucpLumiere == NULL)) 
  {
    return;
  }

  *ucpChauffage = xLireEtatDepuisPin(ETAT_CHAUF_GPIO_Port,
                                     ETAT_CHAUF_Pin,
                                     FEEDBACK_CHAUFFAGE_ACTIVE,
                                     FEEDBACK_CHAUFFAGE_DEFAUT);
  *ucpVentilation = xLireEtatDepuisPin(ETAT_VENT_GPIO_Port,
                                       ETAT_VENT_Pin,
                                       FEEDBACK_VENTILATION_ACTIVE,
                                       FEEDBACK_VENTILATION_DEFAUT);
  *ucpLumiere = xLireEtatDepuisPin(ETAT_LUM_GPIO_Port,
                                   ETAT_LUM_Pin,
                                   FEEDBACK_LUMIERE_ACTIVE,
                                   FEEDBACK_LUMIERE_DEFAUT);
}
/* =============================================================================================
 * Fonction     : LireEtatsLuminosite
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Lit les comparateurs de luminosite jour et nuit.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void LireEtatsLuminosite(UC *ucpEtatJour, UC *ucpEtatNuit)
{
  GPIO_PinState xLumBas = GPIO_PIN_RESET;
  GPIO_PinState xLumHaut = GPIO_PIN_RESET;

  if ((ucpEtatJour == NULL) || (ucpEtatNuit == NULL))
  {
    return;
  }

  xLumBas = HAL_GPIO_ReadPin(LUM_BAS_GPIO_Port, LUM_BAS_Pin);
  xLumHaut = HAL_GPIO_ReadPin(LUM_HAUT_GPIO_Port, LUM_HAUT_Pin);

  *ucpEtatJour = ((xLumBas != LUM_JOUR_ACTIF) && (xLumHaut != LUM_NUIT_ACTIF)) ? VRAI : FAUX;
  *ucpEtatNuit = ((xLumBas == LUM_JOUR_ACTIF) && (xLumHaut == LUM_NUIT_ACTIF)) ? VRAI : FAUX;
}
/* =============================================================================================
 * Fonction     : SynchroniseEtatsReels
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Copie les etats reels dans le tableau ucTab.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void SynchroniseEtatsReels(UC *ucpTab)
{
  UC ucChauffage = OFF;
  UC ucVentilation = OFF;
  UC ucLumiere = OFF;

  if (ucpTab == NULL)
  {
    return;
  }

  LireEtatsReels(&ucChauffage, &ucVentilation, &ucLumiere);
  ucpTab[ETATCHAUF] = ucChauffage;
  ucpTab[ETATVENT] = ucVentilation;
  ucpTab[ETATLUM] = ucLumiere;
}
/* =============================================================================================
 * Fonction     : AppliquerEtatChauffage
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Demande l etat voulu pour le chauffage.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void AppliquerEtatChauffage(UC *ucpTab, UC ucEtatVoulu)
{
  xAppliquerEtatElement(ucpTab,
                        ETATCHAUF,
                        CMD_CHAUF_GPIO_Port,
                        CMD_CHAUF_Pin,
                        CMD_CHAUFFAGE_ACTIVE,
                        CMD_CHAUFFAGE_REPOS,
                        ETAT_CHAUF_GPIO_Port,
                        ETAT_CHAUF_Pin,
                        FEEDBACK_CHAUFFAGE_ACTIVE,
                        FEEDBACK_CHAUFFAGE_DEFAUT,
                        ucEtatVoulu);
}
/* =============================================================================================
 * Fonction     : AppliquerEtatVentilation
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Demande l etat voulu pour la ventilation.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void AppliquerEtatVentilation(UC *ucpTab, UC ucEtatVoulu)
{
  xAppliquerEtatElement(ucpTab,
                        ETATVENT,
                        CMD_VENT_GPIO_Port,
                        CMD_VENT_Pin,
                        CMD_VENTILATION_ACTIVE,
                        CMD_VENTILATION_REPOS,
                        ETAT_VENT_GPIO_Port,
                        ETAT_VENT_Pin,
                        FEEDBACK_VENTILATION_ACTIVE,
                        FEEDBACK_VENTILATION_DEFAUT,
                        ucEtatVoulu);
}
/* =============================================================================================
 * Fonction     : AppliquerEtatLumiere
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Demande l etat voulu pour la lumiere.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void AppliquerEtatLumiere(UC *ucpTab, UC ucEtatVoulu)
{
  xAppliquerEtatElement(ucpTab,
                        ETATLUM,
                        CMD_LUM_GPIO_Port,
                        CMD_LUM_Pin,
                        CMD_LUMIERE_ACTIVE,
                        CMD_LUMIERE_REPOS,
                        ETAT_LUM_GPIO_Port,
                        ETAT_LUM_Pin,
                        FEEDBACK_LUMIERE_ACTIVE,
                        FEEDBACK_LUMIERE_DEFAUT,
                        ucEtatVoulu);
}
/* =============================================================================================
 * Fonction     : AllumeChauffage
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Demande l allumage du chauffage.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void AllumeChauffage(UC *ucpTab)
{
  AppliquerEtatChauffage(ucpTab, ON);
}
/* =============================================================================================
 * Fonction     : FermeChauffage
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Demande l extinction du chauffage.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void FermeChauffage(UC *ucpTab)
{
  AppliquerEtatChauffage(ucpTab, OFF);
}
/* =============================================================================================
 * Fonction     : AllumeVentilation
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Demande l allumage de la ventilation.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void AllumeVentilation(UC *ucpTab)
{
  AppliquerEtatVentilation(ucpTab, ON);
}
/* =============================================================================================
 * Fonction     : FermeVentilation
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Demande l extinction de la ventilation.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void FermeVentilation(UC *ucpTab)
{
  AppliquerEtatVentilation(ucpTab, OFF);
}
/* =============================================================================================
 * Fonction     : AllumeLumiere
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Demande l allumage de la lumiere.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void AllumeLumiere(UC *ucpTab) 
{
  AppliquerEtatLumiere(ucpTab, ON);
}
/* =============================================================================================
 * Fonction     : FermeLumiere
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Demande l extinction de la lumiere.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void FermeLumiere(UC *ucpTab)
{
  AppliquerEtatLumiere(ucpTab, OFF);
}
/* =============================================================================================
 * Fonction     : ArretUrgence
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Remet les delais a zero et ferme toutes les sorties.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/actions.c
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
void ArretUrgence(UC *ucpTab)
{
  if (ucpTab == NULL)
  {
    return;
  }

  ucpTab[DELAICHAUF] = 0U;
  ucpTab[DELAIVENT] = 0U;
  ucpTab[DELAILUM] = 0U;

  FermeChauffage(ucpTab);
  FermeVentilation(ucpTab);
  FermeLumiere(ucpTab);
}
