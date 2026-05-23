/* =============================================================================================
 * FICHIER     : temps.c
 * PROJET      : Projet-de-fin-de-session-2026
 * CHEMIN      : Logiciel/STM32/EnCours/Core/Src/temps.c
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * CRÉATION    : 2026-04-29
 * COMPILATEUR : VSCode avec extension Makefile et ARM GCC et extension QuickCommand 
 * LICENCE     : Usage scolaire / interne
 * =============================================================================================
 * DESCRIPTION :
 * Gere les compteurs de temps du projet.
 * Ajuste les delais des sorties a chaque periode de 1 seconde.
 * Transforme l interruption TIM2 en flag simple pour la boucle principale.
 * MATÉRIEL    : Timer TIM2 du STM32.
 * DÉPENDANCES : fonctions.h, tim.h.
 * =============================================================================================
 * SPÉCIFICATIONS TECHNIQUES :
 *
 * * TYPES DE DONNÉES & VARIABLES :
 * Utilise UC pour les compteurs, delais et flags.
 * Utilise TIM_HandleTypeDef pour identifier le timer.
 *
 * * GESTION DES POINTEURS :
 * Recoit les compteurs par pointeur pour les mettre a jour.
 *
 * * AUTRES MÉCANISMES :
 * Gestion non bloquante avec interruption timer.
 * Le callback HAL leve seulement ucgFlagTM2.
 * =============================================================================================
 * NOTES :
 * 1. Eviter les HAL_Delay dans cette logique de cadence.
 * 2. La boucle principale consomme le flag et fait le vrai travail.
 * =============================================================================================
 * HISTORIQUE DES RÉVISIONS :
 * Date        Ver   Auteur    Notes
 * ----------  ----  --------  ----------------------------------------------------------------
 * VOIR SUR LE GITHUB 
 * =============================================================================================
 */
#include "fonctions.h"
#include "tim.h"
/* =============================================================================================
 * Fonction     : AjusterLesCompteurs
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Met a jour les compteurs de temps et les delais des sorties.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/temps.c
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
void AjusterLesCompteurs(UC *ucpTab,
                         UC *ucpCompteurDe1Sec,
                         UC *ucpDelaiEnregisHistorique)
{
  if ((ucpTab == NULL) || (ucpCompteurDe1Sec == NULL) || (ucpDelaiEnregisHistorique == NULL))
  {
    return;
  }

  (*ucpCompteurDe1Sec)++;

  if (*ucpCompteurDe1Sec >= NOMBRE_DEBORDEMENTS_1SEC)
  {
    *ucpCompteurDe1Sec = 0U;

    if (*ucpDelaiEnregisHistorique < 0xFFU)
    {
      (*ucpDelaiEnregisHistorique)++;
    }

    if (ucpTab[DELAICHAUF] > 0U)
    {
      ucpTab[DELAICHAUF]--;
    }

    if (ucpTab[DELAIVENT] > 0U)
    {
      ucpTab[DELAIVENT]--;
    }

    if (ucpTab[DELAILUM] > 0U)
    {
      ucpTab[DELAILUM]--;
    }
  }
}
/* =============================================================================================
 * Fonction     : TIM2_IRQHandler
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Redirige l interruption TIM2 vers le gestionnaire HAL.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/temps.c
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
void TIM2_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim2);
}
/* =============================================================================================
 * Fonction     : HAL_TIM_PeriodElapsedCallback
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Leve le flag de temps quand TIM2 deborde.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/temps.c
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
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if ((htim != NULL) && (htim->Instance == TIM2))
  {
    /* Le flag sert de compteur de ticks pour garder le temps juste si la boucle principale est occupe. */
    if (ucgFlagTM2 < 0xFFU)
    {
      ucgFlagTM2++;
    }
  }
}
