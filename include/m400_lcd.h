/* =============================================================================================
 * FICHIER     : LCD.h
 * PROJET      : Projet-de-fin-de-session-2026
 * CHEMIN      : Logiciel/STM32/EnCours/Core/Inc/LCD.h
 * =============================================================================================
 * AUTEUR      : Matisse Rheaume-Viale
 * VERSION     : 1.0
 * CRÉATION    : 2026-04-29
 * COMPILATEUR : VSCode avec extension Makefile et ARM GCC
 * LICENCE     : Usage scolaire / interne
 * =============================================================================================
 * DESCRIPTION :
 * Fichier d'en-tete du module LCD.
 * Declare l'API publique pour initialiser l'ecran, ecrire du texte
 * et utiliser les helpers de positionnement et de formatage.
 * MATÉRIEL    : LCD compatible HD44780 en mode 4 bits
 * DÉPENDANCES : stm32f1xx_hal.h, stdint.h
 * =============================================================================================
 * SPÉCIFICATIONS TECHNIQUES :
 *
 * * TYPES DE DONNÉES & VARIABLES :
 * - Fonctions publiques pour commandes, texte et positionnement
 * - Parametres en uint8_t pour les colonnes, lignes et commandes
 *
 * * GESTION DES POINTEURS :
 * - Les chaines passees a l'API sont des const char *
 * - La fonction printf utilise une liste d'arguments variable
 *
 * * AUTRES MÉCANISMES :
 * - pragma once pour eviter les inclusions multiples
 * - Interface simple separee du driver bas niveau
 * =============================================================================================
 * NOTES :
 * 1. Le detail du cablage n'apparait pas ici, il reste dans LCD.c.
 * 2. L'API vise un ecran 20 colonnes par 4 lignes.
 * =============================================================================================
 * HISTORIQUE DES RÉVISIONS :
 * Date        Ver   Auteur    Notes
 * ----------  ----  --------  ----------------------------------------------------------------
 * 2026-04-29  1.0   Matisse   En-tete rempli pour documenter l'API publique
 * =============================================================================================
 */
#pragma once

#include "stm32f1xx_hal.h"
#include <stdint.h>

/*
 * Module LCD
 * ----------
 * Driver bas niveau d'un LCD type HD44780 en mode 4 bits.
 *
 * Ce module s'occupe du cablage, des delais et de l'envoi des commandes.
 * Il ne sait rien de la logique AFLC.
 */

// API minimale pour l'ecran LCD 20x4.
void LCD_Init(void);
void LCD_Clear(void);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendChar(char data);
void LCD_SendString(const char *str);
void LCD_SetCursor(uint8_t col, uint8_t row);

void LCD_WriteAt(uint8_t col, uint8_t row, const char *str);
void LCD_Printf(const char *fmt, ...);
void LCD_PrintfAt(uint8_t col, uint8_t row, const char *fmt, ...);

// Helpers de confort.
void LCD_ClearLine(uint8_t row);
void LCD_ScrollText(const char *text);
