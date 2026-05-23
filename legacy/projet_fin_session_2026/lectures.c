/* =============================================================================================
 * FICHIER     : lectures.c
 * PROJET      : Projet-de-fin-de-session-2026
 * CHEMIN      : Logiciel/STM32/EnCours/Core/Src/lectures.c
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * CRÉATION    : 2026-04-29
 * COMPILATEUR : VSCode avec extension Makefile et ARM GCC et extension QuickCommand 
 * LICENCE     : Usage scolaire / interne
 * =============================================================================================
 * DESCRIPTION :
 * Regroupe les lectures du PC, de l ADC et des entrees utilisateur.
 * Convertit la mesure ADC en temperature.
 * Traite les commandes clavier du terminal.
 * MATÉRIEL    : USART1, ADC1 et entrees du systeme.
 * DÉPENDANCES : fonctions.h, adc.h, math.h, stdio.h.
 * =============================================================================================
 * SPÉCIFICATIONS TECHNIQUES :
 *
 * * TYPES DE DONNÉES & VARIABLES :
 * Utilise UC pour les commandes, modes et etats.
 * Utilise USI pour les valeurs ADC brutes et float pour la temperature.
 *
 * * GESTION DES POINTEURS :
 * Utilise des pointeurs pour modifier mode, consignes, ADC et historique.
 *
 * * AUTRES MÉCANISMES :
 * Lecture UART non bloquante pour les commandes PC.
 * Calcul de temperature base sur la thermistance NTC.
 * =============================================================================================
 * NOTES :
 * 1. Garder le ADC brut en USI avant la conversion.
 * 2. Les commandes manuelles passent par les fonctions d actions.
 * =============================================================================================
 * HISTORIQUE DES RÉVISIONS :
 * Date        Ver   Auteur    Notes
 * ----------  ----  --------  ----------------------------------------------------------------
 * VOIR SUR LE GITHUB 
 * =============================================================================================
 */
#include "fonctions.h"
#include "adc.h"

#include <math.h>
#include <stdio.h>
/* =============================================================================================
 * Fonction     : xAfficherConfirmationMode
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Affiche dans le terminal le mode qui vient d etre choisi.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/lectures.c
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
static void xAfficherConfirmationMode(UC ucMode) // Affiche le mode choisi dans le terminal
{
  if (ucMode == AUTOMATIQUE) //    Si le mode est automatique, affiche
  {
    printf("\r\nMode automatique actif.\r\n"); //    "Mode automatique actif." dans le terminal
  }
  else
  {
    printf("\r\nMode manuel actif.\r\n"); // Sinon, affiche "Mode manuel actif." dans le terminal
  }
}
/* =============================================================================================
 * Fonction     : xAfficherConfirmationSortie
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Affiche dans le terminal l etat ON/OFF d une sortie.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/lectures.c
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
static void xAfficherConfirmationSortie(const char *cNomSortie, UC ucEtat)
{
  printf("\r\n%s -> %s\r\n", cNomSortie, (ucEtat == ON) ? "ON" : "OFF");
}
/* =============================================================================================
 * Fonction     : xEstCaractereIgnorable
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Reconnait les caracteres UART qui ne sont pas des commandes.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/lectures.c
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
static UC xEstCaractereIgnorable(UC ucTouche) // Verifie si le caractere lu est un retour chariot, saut de ligne ou espace
{
  if ((ucTouche == '\r') || (ucTouche == '\n') || (ucTouche == ' ')) // Si le caractere est un retour chariot,
  {
    return VRAI; // un saut de ligne ou un espace, retourne VRAI
  }

  return FAUX; // Sinon, retourne FAUX 
}
/* =============================================================================================
 * Fonction     : LireLesEntree
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Reserve une entree commune pour la lecture des entrees du projet.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/lectures.c
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
void LireLesEntree(UC *ucpTab) // Lit les entrees du projet (PC, ADC, etc.)
{
  (void)ucpTab; // Parametre inutilise pour le moment, mais reserve pour les entrees futures
}
/* =============================================================================================
 * Fonction     : LireADC
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Lit la valeur brute du convertisseur ADC.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/lectures.c
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
void LireADC(USI *usipADC) 
{
  ADC_ChannelConfTypeDef sConfig = {0};
  UI uiSommeADC = 0U;
  UC ucIndex = 0U;

  if (usipADC == NULL)
  {
    return;
  }

  sConfig.Channel = ADC_TEMP_CHANNEL;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_TEMP_SAMPLE_TIME;

  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    return;
  }

  for (ucIndex = 0U; ucIndex < NB_LECTURES_ADC; ucIndex++)
  {
    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, ADC_POLL_TIMEOUT) != HAL_OK)
    {
      HAL_ADC_Stop(&hadc1);
      return;
    }

    uiSommeADC += (UI)HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);
  }

  *usipADC = (USI)(uiSommeADC / NB_LECTURES_ADC);
}

/* =============================================================================================
 * Fonction     : ConversionADCVersTemperature
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Convertit une valeur ADC brute en temperature Celsius.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/lectures.c
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
float ConversionADCVersTemperature(USI usAdc)
{
  float fRntc = 0.0f;
  float fTemperatureK = 0.0f;

  if ((usAdc == 0U) || (usAdc >= ADC_MAX_VALUE))
  {
    return 0.0f;
  }

  fRntc = RESISTANCE_DIVISEUR_OHM * ((ADC_MAX_VALUE / (float)usAdc) - 1.0f);
  fTemperatureK = 1.0f /
                  ((1.0f / TEMPERATURE_REF_K) +
                  ((1.0f / TEMPERATURE_BETA) * logf(fRntc / RESISTANCE_NTC_REF_OHM)));

  return fTemperatureK - TEMPERATURE_OFFSET_C;
}
/* =============================================================================================
 * Fonction     : fCalculTemperature
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Retourne la temperature calculee a partir de l ADC.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/lectures.c
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
float fCalculTemperature(USI usAdc)
{
  return ConversionADCVersTemperature(usAdc);
}
/* =============================================================================================
 * Fonction     : LireCaractereduPC
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Traite une touche recue du PC et modifie le systeme au besoin.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/lectures.c
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
void LireCaractereduPC(UC ucTouche,
                       UC *ucpMode,
                       UC *ucpArretUrgence,
                       UC *ucpAffichageLuminosite,
                       UC *ucpTab,
                       UC *ucpConsigneBasse,
                       UC *ucpConsigneHaute,
                       UI *uspPositionDansTableauHistorique)
{
  if ((ucpMode == NULL) ||
      (ucpArretUrgence == NULL) ||
      (ucpAffichageLuminosite == NULL) ||
      (ucpTab == NULL) ||
      (ucpConsigneBasse == NULL) ||
      (ucpConsigneHaute == NULL) ||
      (uspPositionDansTableauHistorique == NULL))
  {
    return;
  }

  if (xEstCaractereIgnorable(ucTouche) == VRAI)
  {
    return;
  }

  if ((ucTouche == 'X') || (ucTouche == 'x'))
  {
    *ucpArretUrgence = ARRET_URGENCE_ACTIF;
    *ucpMode = MANUEL;
    ArretUrgence(ucpTab);
    AfficheMenuUrgence();
    return;
  }

  if (*ucpArretUrgence == ARRET_URGENCE_ACTIF)
  {
    switch (ucTouche)
    {
      case 'A':
      case 'a':
        *ucpArretUrgence = ARRET_URGENCE_INACTIF;
        *ucpMode = AUTOMATIQUE;
        printf("\r\nSortie de l'arret d'urgence -> mode automatique.\r\n");
        AfficheMenuDeDebut();
        return;

      case 'M':
      case 'm':
        *ucpArretUrgence = ARRET_URGENCE_INACTIF;
        *ucpMode = MANUEL;
        printf("\r\nSortie de l'arret d'urgence -> mode manuel.\r\n");
        AfficheMenuDeDebut();
        return;

      case 'H':
      case 'h':
        AfficheMenuUrgence();
        return;

      default:
        return;
    }
  }

  switch (ucTouche)
  {
    case 'A':
    case 'a':
      *ucpMode = AUTOMATIQUE;
      ucpTab[DELAICHAUF] = 0U;
      ucpTab[DELAIVENT] = 0U;
      ucpTab[DELAILUM] = 0U;
      xAfficherConfirmationMode(*ucpMode);
      break;

    case 'M':
    case 'm':
      *ucpMode = MANUEL;
      xAfficherConfirmationMode(*ucpMode);
      break;

    case 'C':
    case 'c':
      if (*ucpMode == AUTOMATIQUE)
      {
        if (*ucpConsigneBasse > 0U)
        {
          (*ucpConsigneBasse)--;
        }
      }
      else
      {
        FermeChauffage(ucpTab);
        xAfficherConfirmationSortie("Chauffage", ucpTab[ETATCHAUF]);
      }
      break;

    case 'D':
    case 'd':
      if (*ucpMode == AUTOMATIQUE)
      {
        if (*ucpConsigneBasse < 255U)
        {
          (*ucpConsigneBasse)++;
        }
      }
      else
      {
        AllumeChauffage(ucpTab);
        xAfficherConfirmationSortie("Chauffage", ucpTab[ETATCHAUF]);
      }
      break;

    case 'V':
    case 'v':
      if (*ucpMode == AUTOMATIQUE)
      {
        if (*ucpConsigneHaute > 0U)
        {
          (*ucpConsigneHaute)--;
        }
      }
      else
      {
        FermeVentilation(ucpTab);
        xAfficherConfirmationSortie("Ventilation", ucpTab[ETATVENT]);
      }
      break;

    case 'F':
    case 'f':
      if (*ucpMode == AUTOMATIQUE)
      {
        if (*ucpConsigneHaute < 255U)
        {
          (*ucpConsigneHaute)++;
        }
      }
      else
      {
        AllumeVentilation(ucpTab);
        xAfficherConfirmationSortie("Ventilation", ucpTab[ETATVENT]);
      }
      break;

    case 'L':
    case 'l':
      if (*ucpMode == AUTOMATIQUE)
      {
        AllumeLumiere(ucpTab);
        ucpTab[DELAILUM] = DELAI_PRISE_CONTROLE_AUTO;
      }
      else
      {
        AllumeLumiere(ucpTab);
        xAfficherConfirmationSortie("Lumiere", ucpTab[ETATLUM]);
      }
      break;

    case 'K':
    case 'k':
      if (*ucpMode == AUTOMATIQUE)
      {
        FermeLumiere(ucpTab);
        ucpTab[DELAILUM] = DELAI_PRISE_CONTROLE_AUTO;
      }
      else
      {
        FermeLumiere(ucpTab);
        xAfficherConfirmationSortie("Lumiere", ucpTab[ETATLUM]);
      }
      break;

    case 'T':
    case 't':
      TransfertHistoriqueVersLePC(*uspPositionDansTableauHistorique);
      break;

    case 'J':
    case 'j':
      *ucpAffichageLuminosite = (*ucpAffichageLuminosite == ON) ? OFF : ON;
      printf("\r\nAffichage periodique Jour/Nuit: %s\r\n",
             (*ucpAffichageLuminosite == ON) ? "ON" : "OFF");
      break;

    case '0':
      *uspPositionDansTableauHistorique = 0U;
      printf("\r\nHistorique remis a zero.\r\n");
      break;

    case 'H':
    case 'h':
      AfficheMenuDeDebut();
      break;

    default:
      break;
  }
}
