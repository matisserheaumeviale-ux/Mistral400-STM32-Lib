/* =============================================================================================
 * FICHIER     : fonctions.h
 * PROJET      : Projet-de-fin-de-session-2026
 * CHEMIN      : Logiciel/STM32/EnCours/Core/Inc/fonctions.h
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * CRÉATION    : 2026-04-29
 * COMPILATEUR : VSCode avec extension Makefile et ARM GCC et extension QuickCommand
 * LICENCE     : Usage scolaire / interne
 * =============================================================================================
 * DESCRIPTION :
 * Contient les constantes communes et les prototypes du programme.
 * Sert de point de reference pour les modules STM32 du projet.
 * Regroupe aussi la configuration materielle utilisee par le code.
 * MATÉRIEL    : STM32F103, UART1, ADC1, TIM2, GPIO et sorties de commande.
 * DÉPENDANCES : stdint.h, main.h.
 * =============================================================================================
 * SPÉCIFICATIONS TECHNIQUES :
 * TYPES DE DONNÉES & VARIABLES : macros de mode, etats, delais, ADC et hardware.
 * GESTION DES POINTEURS : prototypes avec pointeurs pour modifier les valeurs appelees.
 * AUTRES MÉCANISMES : constantes de polarite, periodes et limites de tableau.
 * =============================================================================================
 * NOTES :
 * 1. Changer les constantes ici quand une polarite materielle est differente.
 * 2. Garder ce fichier pour les declarations communes, pas pour la logique.
 * =============================================================================================
 */ 
#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdint.h>
#include "main.h"

#define OFF 0
#define ON  1

#define MANUEL      0
#define AUTOMATIQUE 1
#define ARRET_URGENCE_ACTIF 1
#define ARRET_URGENCE_INACTIF 0

#define ETATCHAUF  0
#define DELAICHAUF 1
#define ETATVENT   2
#define DELAIVENT  3
#define ETATLUM    4
#define DELAILUM   5

#define NOMBRE_DEBORDEMENTS_1SEC 100U // TIM2 deborde aux 10 ms: 100 x 10 ms = 1 seconde.

/*==================== CONFIGURATION TEST / HARDWARE ====================*/

#define ADC_TEMP_CHANNEL             ADC_CHANNEL_9 // PB1
#define ADC_TEMP_PORT                ADC_TEMP_GPIO_Port // GPIOB
#define ADC_TEMP_PIN                 ADC_TEMP_Pin // GPIO_PIN_1 du GPIOB
#define ADC_TEMP_SAMPLE_TIME         ADC_SAMPLETIME_239CYCLES_5 // Stabilisation du signal de l'ADC pour la lecture de la température.


#define UART_DEBUG                   (&huart1)
#define UART_RX_TIMEOUT              10U // Timeout en ms pour la lecture de la console série
#define NB_LECTURES_ADC              1U // Une conversion ADC par tick logiciel; evite de relancer inutilement des conversions.
#define ADC_POLL_TIMEOUT             2U // Timeout en ms pour la lecture de l'ADC
#define PERIODE_AFFICHAGE_200MS      20U // Nombre de debordements TIM2 pour atteindre 200 ms: 20 x 10 ms.
#define PERIODE_AFFICHAGE_500MS      50U // Nombre de debordements TIM2 pour atteindre 500 ms: 50 x 10 ms.
#define PERIODE_AFFICHAGE_1SEC       NOMBRE_DEBORDEMENTS_1SEC  // Nombre de débordements de (TIM2) pour atteindre 1 seconde.
#define PERIODE_AFFICHAGE            PERIODE_AFFICHAGE_1SEC // 
#define PERIODE_HISTORIQUE           2U
#define HISTORIQUE_MAX               0x1000U
#define DELAI_PRISE_CONTROLE_AUTO    10U

#define CONSIGNE_BASSE_DEFAUT        20U
#define CONSIGNE_HAUTE_DEFAUT        25U

#define ADC_MAX_VALUE                4095U
#define TEMPERATURE_BETA             4570.0f
#define TEMPERATURE_REF_K            298.15f
#define TEMPERATURE_OFFSET_C         273.15f
#define RESISTANCE_NTC_REF_OHM       470000.0f
#define RESISTANCE_DIVISEUR_OHM      470000.0f

#define UTILISER_FEEDBACKS_REELS     1U
#define FEEDBACK_CHAUFFAGE_DEFAUT    OFF
#define FEEDBACK_VENTILATION_DEFAUT  OFF
#define FEEDBACK_LUMIERE_DEFAUT      OFF

#define PULSE_TOGGLE_MS              50U
#define PULSE_STABILISATION_MS       20U
// Les feedbacks ETAT_* valent 1 quand la sortie est reellement allumee.
#define FEEDBACK_CHAUFFAGE_ACTIVE    GPIO_PIN_SET
#define FEEDBACK_VENTILATION_ACTIVE  GPIO_PIN_SET
#define FEEDBACK_LUMIERE_ACTIVE      GPIO_PIN_SET

// Sorties des comparateurs de luminosite.
// Si le materiel est inverse, changer seulement ces deux constantes.
#define LUM_JOUR_ACTIF               GPIO_PIN_RESET
#define LUM_NUIT_ACTIF               GPIO_PIN_RESET

#define CMD_CHAUFFAGE_ACTIVE         GPIO_PIN_RESET
#define CMD_VENTILATION_ACTIVE       GPIO_PIN_RESET
#define CMD_LUMIERE_ACTIVE           GPIO_PIN_RESET
#define CMD_CHAUFFAGE_REPOS          GPIO_PIN_SET
#define CMD_VENTILATION_REPOS        GPIO_PIN_SET
#define CMD_LUMIERE_REPOS            GPIO_PIN_SET

#define ETAT_JOUR_DEFAUT             OFF
#define ETAT_NUIT_DEFAUT             OFF
#define PERIODE_AFFICHAGE_LUM_SEC    2U
/*======================================================================*/

// action.c
void InitCommandesBascule(void); // Initialise les pins de commande pour le chauffage, la ventilation et la lumière à leur état de repos (généralement OFF) au démarrage du système
void LireEtatsReels(UC *ucpChauffage, UC *ucpVentilation, UC *ucpLumiere); // Lit les états réels du chauffage, de la ventilation et de la lumière depuis les pins de feedback et les stocke dans les variables pointées par ucpChauffage, ucpVentilation et ucpLumiere
void LireEtatsLuminosite(UC *ucpEtatJour, UC *ucpEtatNuit); // Lit les états de luminosité jour et nuit depuis les pins de feedback et les stocke dans les variables pointées par ucpEtatJour et ucpEtatNuit
void SynchroniseEtatsReels(UC *ucpTab); // Lit les états réels du chauffage, de la ventilation et de la lumière depuis les pins de feedback et les stocke dans le tableau ucpTab aux indices ETATCHAUF, ETATVENT et ETATLUM respectivement. Cette fonction est utilisée pour synchroniser les états réels avec les états stockés dans le tableau de contrôle, notamment au démarrage du système ou après un arrêt d'urgence.
void AppliquerEtatChauffage(UC *ucpTab, UC ucEtatVoulu);  // Applique l'état voulu (ON ou OFF) au chauffage en utilisant la fonction xAppliquerEtatElement. Cette fonction gère à la fois la commande de la sortie (en écrivant sur la pin de commande) et la mise à jour de l'état dans le tableau ucpTab, ainsi que la lecture du feedback pour vérifier que l'état réel correspond à l'état voulu.
void AppliquerEtatVentilation(UC *ucpTab, UC ucEtatVoulu); // Applique l'état voulu (ON ou OFF) à la ventilation en utilisant la fonction xAppliquerEtatElement. Cette fonction gère à la fois la commande de la sortie (en écrivant sur la pin de commande) et la mise à jour de l'état dans le tableau ucpTab, ainsi que la lecture du feedback pour vérifier que l'état réel correspond à l'état voulu.
void AppliquerEtatLumiere(UC *ucpTab, UC ucEtatVoulu); // Applique l'état voulu (ON ou OFF) à la lumière en utilisant la fonction xAppliquerEtatElement. Cette fonction gère à la fois la commande de la sortie (en écrivant sur la pin de commande) et la mise à jour de l'état dans le tableau ucpTab, ainsi que la lecture du feedback pour vérifier que l'état réel correspond à l'état voulu.
void AllumeChauffage(UC *ucpTab); // Allume le chauffage en appelant la fonction AppliquerEtatChauffage avec l'état voulu ON.
void FermeChauffage(UC *ucpTab); // Éteint le chauffage en appelant la fonction AppliquerEtatChauffage avec l'état voulu OFF.
void AllumeVentilation(UC *ucpTab); // Allume la ventilation en appelant la fonction AppliquerEtatVentilation avec l'état voulu ON.
void FermeVentilation(UC *ucpTab); // Éteint la ventilation en appelant la fonction AppliquerEtatVentilation avec l'état voulu OFF.
void AllumeLumiere(UC *ucpTab); // Allume la lumière en appelant la fonction AppliquerEtatLumiere avec l'état voulu ON.
void FermeLumiere(UC *ucpTab); // Éteint la lumière en appelant la fonction AppliquerEtatLumiere avec l'état voulu OFF.
void ArretUrgence(UC *ucpTab); // Arrête l'urgence en appelant les fonctions appropriées pour éteindre tous les éléments.
// affichage.c
void AfficheMenuDeDebut(void);
void AfficheMenuUrgence(void);
void AfficheEtat(UC *ucpTab,
                 UC ucMode,
                 USI usADC,
                 float fTemperatureC,
                 UC ucConsigneBasse,
                 UC ucConsigneHaute,
                 UC ucEtatJour,
                 UC ucEtatNuit);
// lectures.c
void LireLesEntree(UC *ucpTab);
void LireADC(USI *usipADC);
float ConversionADCVersTemperature(USI usAdc);
float fCalculTemperature(USI usAdc);
void LireCaractereduPC(UC ucTouche,
                       UC *ucpMode,
                       UC *ucpArretUrgence,
                       UC *ucpAffichageLuminosite,
                       UC *ucpTab,
                       UC *ucpConsigneBasse,
                       UC *ucpConsigneHaute,
                       UI *uspPositionDansTableauHistorique);

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
                           UC *ucpCommandeLogicielleLum);
void ModeAutomatique(UC *ucpTab,
                     float fTemperatureC,
                     UC ucConsigneBasse,
                     UC ucConsigneHaute,
                     UC ucEtatJour,
                     UC ucEtatNuit);
void ModeManuel(UC *ucpTab);

void EnregistreHistorique(US usTemperature, UI *uipPositionHisto);
void TransfertHistoriqueVersLePC(UI uiPositionDansTableau);

void AjusterLesCompteurs(UC *ucpTab,
                         UC *ucpCompteurDe1Sec,
                         UC *ucpDelaiEnregisHistorique);
void TIM2_IRQHandler(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);



extern volatile UC ucgFlagTM2;
extern US usgTabHisto[HISTORIQUE_MAX];

#endif
