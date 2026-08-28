/* =============================================================================================
 * Function      : LCD
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements LCD.
 * RELATED FILE  : src/lcd.c
 * DEPENDENCIES  : See file includes.
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * Uses the types and variables visible in the function signature.
 * POINTER MANAGEMENT :
 * Validates pointers when received by the function.
 * =============================================================================================
 * Expected Result:
 * The function performs its task without affecting other parts of the program.
 * =============================================================================================
 */
#include "lcd.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// Mapping physique des broches LCD sur GPIOB.
#define RS_Pin GPIO_PIN_9
#define RW_Pin GPIO_PIN_10
#define EN_Pin GPIO_PIN_11
#define D4_Pin GPIO_PIN_12
#define D5_Pin GPIO_PIN_13
#define D6_Pin GPIO_PIN_14
#define D7_Pin GPIO_PIN_15

#define LCD_DATA_MASK (D4_Pin | D5_Pin | D6_Pin | D7_Pin)

#define LCD_RS_HIGH() (GPIOB->BSRR = RS_Pin)
#define LCD_RS_LOW()  (GPIOB->BRR  = RS_Pin)

#define LCD_RW_HIGH() (GPIOB->BSRR = RW_Pin)
#define LCD_RW_LOW()  (GPIOB->BRR  = RW_Pin)

#define LCD_EN_HIGH() (GPIOB->BSRR = EN_Pin)
#define LCD_EN_LOW()  (GPIOB->BRR  = EN_Pin)

// Delai logiciel tres simple.
// Correct pour un petit projet labo, moins ideal qu'un timer.
#define LCD_DELAY_LOOP_PER_MS 8000U
/* =============================================================================================
 * Fonction     : LCD_DelayMs
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Attend un nombre de millisecondes pour respecter le LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
static void LCD_DelayMs(uint32_t ms){
  for(volatile uint32_t i = 0; i < (ms * LCD_DELAY_LOOP_PER_MS); i++);
}

static void LCD_DelayShort(void){
  for(volatile uint32_t i = 0; i < 50U; i++);
}
/* =============================================================================================
 * Fonction     : LCD_EnablePulse
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Genere l impulsion Enable du LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
static void LCD_EnablePulse(void){
  // Le LCD valide les 4 bits sur le front EN.
  LCD_EN_HIGH();
  LCD_DelayShort();
  LCD_EN_LOW();
  LCD_DelayShort();
}
/* =============================================================================================
 * Fonction     : LCD_Send4Bits
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Place quatre bits de donnees sur le bus du LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
static void LCD_Send4Bits(uint8_t data){
  // Mode 4 bits : on pousse seulement le nibble faible.
  GPIOB->BRR = LCD_DATA_MASK;
  GPIOB->BSRR = ((uint32_t)(data & 0x0FU) << 12);

  LCD_EnablePulse();
}
/* =============================================================================================
 * Fonction     : LCD_SendCommand
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Envoie une commande au controleur LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_SendCommand(uint8_t data){
  // RS=0 -> commande.
  LCD_RS_LOW();
  LCD_RW_LOW();

  LCD_Send4Bits(data >> 4);
  LCD_Send4Bits(data & 0x0F);
}
/* =============================================================================================
 * Fonction     : LCD_SendChar
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Envoie un caractere affichable au LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_SendChar(char data){
  // RS=1 -> donnee utilisateur.
  LCD_RS_HIGH();
  LCD_RW_LOW();

  LCD_Send4Bits(data >> 4);
  LCD_Send4Bits(data & 0x0F);
}
/* =============================================================================================
 * Fonction     : LCD_SendString
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Affiche une chaine de caracteres sur le LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_SendString(const char *str){
  if(str == NULL) return;

  while(*str){
    LCD_SendChar(*str++);
  }
}
/* =============================================================================================
 * Fonction     : LCD_SetCursor
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Positionne le curseur du LCD a une colonne et une ligne.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_SetCursor(uint8_t col, uint8_t row){
  static const uint8_t RowAddress[4] = {0x80, 0xC0, 0x94, 0xD4};

  // Garde-fous simples.
  if(row > 3U) return;
  if(col > 19U) return;

  LCD_SendCommand(RowAddress[row] + col);
}
/* =============================================================================================
 * Fonction     : LCD_Printf
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Formate du texte puis l affiche sur le LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_Printf(const char *fmt, ...){
  char buffer[81];
  uint8_t row = 0U;
  uint8_t col = 0U;
  va_list args;

  if(fmt == NULL) return;

  va_start(args, fmt);
  (void)vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);

  // Ecrit sur l'ecran complet avec retour de ligne simple.
  LCD_SetCursor(0, 0);
  for(size_t i = 0; (buffer[i] != '\0') && (row < 4U); i++){
    if(buffer[i] == '\n'){
      row++;
      col = 0U;
      if(row < 4U) LCD_SetCursor(0, row);
      continue;
    }

    LCD_SendChar(buffer[i]);
    col++;
    if(col >= 20U){
      row++;
      col = 0U;
      if(row < 4U) LCD_SetCursor(0, row);
    }
  }
}
/* =============================================================================================
 * Fonction     : LCD_ClearLine
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Efface une ligne complete du LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_ClearLine(uint8_t row){
  if(row > 3U) return;

  LCD_SetCursor(0, row);
  // Efface exactement 20 caracteres.
  for(uint8_t i = 0; i < 20U; i++) LCD_SendChar(' ');
  LCD_SetCursor(0, row);
}
/* =============================================================================================
 * Fonction     : LCD_ScrollText
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Fait defiler un texte trop long sur le LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_ScrollText(const char *text){
  char window[21];
  size_t len;
  size_t stream_len;

  if(text == NULL) return;

  len = strlen(text);
  // 20 espaces avant + texte + 20 espaces apres.
  // Comme ca le texte entre et sort proprement.
  stream_len = len + 40U;
  if(len == 0U){
    LCD_ClearLine(0);
    return;
  }

  if(len <= 20U){
    LCD_ClearLine(0);
    LCD_SetCursor(0, 0);
    LCD_SendString(text);
    return;
  }

  for(size_t step = 0; step <= (stream_len - 20U); step++){
    for(uint8_t i = 0; i < 20U; i++){
      size_t idx = step + i;
      if(idx < 20U){
        window[i] = ' ';
      } else if(idx < (20U + len)){
        window[i] = text[idx - 20U];
      } else {
        window[i] = ' ';
      }
    }
    window[20] = '\0';

    LCD_SetCursor(0, 0);
    LCD_SendString(window);
    LCD_DelayMs(250U);
  }
}
/* =============================================================================================
 * Fonction     : LCD_Init
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Initialise le LCD en mode 4 bits.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_Init(void){
  // Sequence standard HD44780 en mode 4 bits.
  LCD_DelayMs(50U);
  
  LCD_SendCommand(0x33);
  LCD_SendCommand(0x32);
  
  LCD_SendCommand(0x28);
  LCD_SendCommand(0x0C);
  LCD_SendCommand(0x06);
  LCD_SendCommand(0x01);
  LCD_DelayMs(2U);
 
}
/* =============================================================================================
 * Fonction     : LCD_Clear
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Efface tout l ecran LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_Clear(void){
  LCD_SendCommand(0x01);
  LCD_DelayMs(2U);
}
/* =============================================================================================
 * Fonction     : LCD_WriteAt
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Ecrit une chaine a une position precise du LCD.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_WriteAt(uint8_t col, uint8_t row, const char *str){
  if(str == NULL) return;

  LCD_SetCursor(col, row);
  LCD_SendString(str);
}

/* =============================================================================================
 * Fonction     : LCD_PrintfAt
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Formate du texte puis l ecrit a une position precise.
 * FICHIER EN LIEN: Logiciel/STM32/EnCours/Core/Src/LCD.c
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
void LCD_PrintfAt(uint8_t col, uint8_t row, const char *fmt, ...){
  char buffer[81];
  va_list args;

  if(fmt == NULL) return;

  va_start(args, fmt);
  (void)vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);

  LCD_SetCursor(col, row);
  LCD_SendString(buffer);
}
