/* =============================================================================================
 * FICHIER     : affichage.c
 * PROJET      : Projet-de-fin-de-session-2026
 * CHEMIN      : Logiciel/STM32/EnCours/Core/Src/affichage.c
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * CRÉATION    : 2026-04-29
 * COMPILATEUR : VSCode avec extension Makefile et ARM GCC et extension QuickCommand 
 * LICENCE     : Usage scolaire / interne
 * =============================================================================================
 * DESCRIPTION :
 * Regroupe les affichages envoyes au PC par UART.
 * Affiche les menus et l etat courant du systeme.
 * Sert a suivre le mode, la temperature et les sorties.
 * MATÉRIEL    : USART1 relie au terminal PC.
 * DÉPENDANCES : fonctions.h, usart.h, stdio.h, string.h.
 * =============================================================================================
 * SPÉCIFICATIONS TECHNIQUES :
 *
 * * TYPES DE DONNÉES & VARIABLES :
 * Utilise des chaines constantes, UC, USI et float.
 * Lit le tableau ucTab pour afficher les etats.
 *
 * * GESTION DES POINTEURS :
 * Verifie le pointeur ucTab avant de lire les etats.
 *
 * * AUTRES MÉCANISMES :
 * Utilise printf et HAL_UART_Transmit pour envoyer le texte.
 * Respecte le format attendu par le projet.
 * =============================================================================================
 * NOTES :
 * 1. Garder les lignes courtes et faciles a lire dans le terminal.
 * 2. Ne pas ajouter de delai bloquant dans les fonctions d affichage.
 * =============================================================================================
 * HISTORIQUE DES RÉVISIONS :
 * Date        Ver   Auteur    Notes
 * ----------  ----  --------  ----------------------------------------------------------------
 * VOIR SUR LE GITHUB 
 * =============================================================================================
 */
#include "fonctions.h"
#include "usart.h"

#include <stdio.h>
#include <string.h>
/* =============================================================================================
 * Fonction     : AfficheMenuDeDebut
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Affiche le menu principal des commandes PC.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/affichage.c
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
void AfficheMenuDeDebut(void)
{
  static const char cMenu[] =
    "\r\nProjet Final Session 2\r\n"
    "Domotique de base avec Historique de la temperature\r\n"
    "\r\n"
    "Sur le PC:\r\n"
    "A = Mode Automatique\r\n"
    "M = Mode Manuel\r\n"
    "X = Arret d'urgence\r\n"
    "ESC = Arret d'urgence\r\n"
    "H = Affiche le menu principal\r\n"
    "T = Transfert de l'historique\r\n"
    "J = Active/desactive l'affichage Jour/Nuit aux 4 secondes\r\n"
    "0 = Mise a zero de l'historique\r\n"
    "\r\n"
    "Mode Automatique:\r\n"
    "C = Decremente la consigne Basse\r\n"
    "D = Incremente la consigne Basse\r\n"
    "V = Decremente la consigne Haute\r\n"
    "F = Incremente la consigne Haute\r\n"
    "L = Lumiere ON\r\n"
    "K = Lumiere OFF\r\n"
    "\r\n"
    "Mode Manuel:\r\n"
    "D = Chauffage ON\r\n"
    "C = Chauffage OFF\r\n"
    "F = Ventilation ON\r\n"
    "V = Ventilation OFF\r\n"
    "L = Lumiere ON\r\n"
    "K = Lumiere OFF\r\n";

  HAL_UART_Transmit(UART_DEBUG, (uint8_t *)cMenu, strlen(cMenu), HAL_MAX_DELAY);
}

void AfficheMenuUrgence(void)
{
  static const char cMenuUrgence[] =
    "\r\n==============================\r\n"
    "     ETAT D'URGENCE ACTIF\r\n"
    "==============================\r\n"
    "Toutes les sorties sont forcees a OFF.\r\n"
    "A = Quitter l'urgence et aller en automatique\r\n"
    "M = Quitter l'urgence et aller en manuel\r\n"
    "H = Reafficher ce menu d'urgence\r\n"
    "X = Refaire l'arret d'urgence\r\n";

  HAL_UART_Transmit(UART_DEBUG,
                    (uint8_t *)cMenuUrgence,
                    strlen(cMenuUrgence),
                    HAL_MAX_DELAY);
}

void AfficheEtat(UC *ucpTab,
                 UC ucMode,
                 USI usADC,
                 float fTemperatureC,
                 UC ucConsigneBasse,
                 UC ucConsigneHaute,
                 UC ucEtatJour,
                 UC ucEtatNuit)
{
  USI usTemperature = 0U;

  if (ucpTab == NULL)
  {
    return;
  }

  (void)usADC;
  (void)ucEtatJour;
  (void)ucEtatNuit;

  if (fTemperatureC > 0.0f)
  {
    usTemperature = (USI)(fTemperatureC + 0.5f);
  }

  printf("%c: Temp = 0x%02X %u, "
         "T.Max=%u, T.Min=%u, "
         "Chauf= %s %u, "
         "Vent= %s %u, "
         "Lum= %s %u.\r\n",
         (ucMode == AUTOMATIQUE) ? 'A' : 'M',
         (unsigned int)usTemperature,
         (unsigned int)usTemperature,
         (unsigned int)ucConsigneHaute,
         (unsigned int)ucConsigneBasse,
         (ucpTab[ETATCHAUF] == ON) ? "ON" : "OFF",
         (unsigned int)ucpTab[DELAICHAUF],
         (ucpTab[ETATVENT] == ON) ? "ON" : "OFF",
         (unsigned int)ucpTab[DELAIVENT],
         (ucpTab[ETATLUM] == ON) ? "ON" : "OFF",
         (unsigned int)ucpTab[DELAILUM]);
}
