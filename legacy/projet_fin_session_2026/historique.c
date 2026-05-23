/* =============================================================================================
 * FICHIER     : historique.c
 * PROJET      : Projet-de-fin-de-session-2026
 * CHEMIN      : Logiciel/STM32/EnCours/Core/Src/historique.c
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * CRÉATION    : 2026-04-29
 * COMPILATEUR : VSCode avec extension Makefile et ARM GCC et extension QuickCommand 
 * LICENCE     : Usage scolaire / interne
 * =============================================================================================
 * DESCRIPTION :
 * Gere l historique des temperatures mesurees.
 * Ajoute les valeurs dans le tableau global autorise.
 * Transfere les donnees vers le PC au besoin.
 * MATÉRIEL    : USART1 pour le transfert vers le terminal PC.
 * DÉPENDANCES : fonctions.h, stdio.h.
 * =============================================================================================
 * SPÉCIFICATIONS TECHNIQUES :
 *
 * * TYPES DE DONNÉES & VARIABLES :
 * Utilise USI pour les valeurs et les positions dans l historique.
 * Utilise usgTabHisto comme zone de stockage du projet.
 *
 * * GESTION DES POINTEURS :
 * Recoit la position par pointeur pour l incrementer apres un ajout.
 *
 * * AUTRES MÉCANISMES :
 * Protege le tableau avec HISTORIQUE_MAX.
 * Envoie les donnees sous forme de lignes numerotees.
 * =============================================================================================
 * NOTES :
 * 1. Ne pas depasser 0x1000 valeurs dans l historique.
 * 2. Le transfert ne modifie pas le contenu du tableau.
 * =============================================================================================
 * HISTORIQUE DES RÉVISIONS :
 * Date        Ver   Auteur    Notes
 * ----------  ----  --------  ----------------------------------------------------------------
 * VOIR SUR LE GITHUB 
 * =============================================================================================
 */
#include "fonctions.h"
extern UART_HandleTypeDef huart1;

#include <stdio.h>
/* =============================================================================================
 * Fonction     : EnregistreHistorique
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Ajoute une valeur dans l historique si la place est disponible.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/historique.c
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
void EnregistreHistorique(US usTemperature, UI *uipPositionHisto)
{
  if (uipPositionHisto == NULL)
  {
    return;
  }

  if (*uipPositionHisto < HISTORIQUE_MAX)
  {
    usgTabHisto[*uipPositionHisto] = usTemperature;
    (*uipPositionHisto)++;
  }
}
/* =============================================================================================
 * Fonction     : TransfertHistoriqueVersLePC
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Transmet les valeurs sauvegardees de l historique vers le PC.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/historique.c
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
static UC LireToucheSerieBloquante(void)
{
    UC ucTouche = 0;

    HAL_UART_Receive(&huart1, &ucTouche, 1, HAL_MAX_DELAY);

    return ucTouche;
}
void TransfertHistoriqueVersLePC(UI uiPositionDansTableau)
{
  UC ucTouche = 0;
  UI uiCompte = 0;

  printf("\n\rVoulez-vous transferer les donnees de l'historique?");
  
  printf("\n\rO/N ? ");

ucTouche = LireToucheSerieBloquante();
printf("%c", ucTouche);

  if ((ucTouche == 'O') || (ucTouche == 'o'))
  {
    printf("\n\rPreparez-vous a enregistrer les donnees de l'historique");
    printf("\n\rvers un ordinateur. Dans Hyper Terminal faites:");
    printf("\n\r'Transfert' -> 'Capturer le texte...' -> 'Parcourir'");
    printf("\n\ret entrez un NomDeFichier.XLS dans un repertoire ou vous");
    printf("\n\rle retrouverez facilement, puis faite 'Demarrer' et");
    printf("\n\rappuyer sur une touche.");

ucTouche = LireToucheSerieBloquante();
printf("%c", ucTouche);

    if (uiPositionDansTableau > HISTORIQUE_MAX)
    {
      uiPositionDansTableau = HISTORIQUE_MAX;
    }

    printf("\n\rTransfert des donnees...");
    printf("\n\rNo\tTemperature");

    for (uiCompte = 0; uiCompte < uiPositionDansTableau; uiCompte++)
    {
      printf("\n\r%u\t%u", uiCompte + 1U, usgTabHisto[uiCompte]);
    }

    printf("\n\rFin du transfert.");
    printf("\n\rFermez le fichier d'enregistrement:");
    printf("\n\r'Transfert' -> 'Capturer le texte...' -> 'Arreter'");
    printf("\n\rVous pouvez ouvrir votre fichier dans Excel");
    printf("\n\rEntrez une touche pour continuer le controle et");
    printf("\n\rn'oubliez pas de faire une mise a zero de l'historique!");

   ucTouche = LireToucheSerieBloquante();
  }
  else
  {
    printf("\n\rTransfert annule.");
  }
}
