
/* =============================================================================================
 * Fonction     : 
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
    return ucEtatDefaut; // Retourne l'état par défaut défini pour l'élément (chauffage, ventilation, lumière ou autre)
  }

  return (HAL_GPIO_ReadPin(xPort, usPin) == xEtatActif) ? ON : OFF; // Lit l'état réel depuis la pin de feedback et le convertit en ON/OFF
}