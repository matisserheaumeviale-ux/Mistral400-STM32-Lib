#ifndef M400_ACTIONS_H
#define M400_ACTIONS_H

#include "main.h"
#include <stdint.h>

/* ==================== TYPES ==================== */

typedef uint8_t UC;

/* ==================== ETATS ==================== */

#define OFF 0U
#define ON  1U

#define VRAI 1U
#define FAUX 0U

/* ==================== INDEX ==================== */

#define ETATCHAUF  0U
#define DELAICHAUF 1U
#define ETATVENT   2U
#define DELAIVENT  3U
#define ETATLUM    4U
#define DELAILUM   5U

/* ==================== CONFIG ==================== */

#define UTILISER_FEEDBACKS_REELS 1U

#define PULSE_TOGGLE_MS        50U
#define PULSE_STABILISATION_MS 20U

/* ==================== PROTOTYPES ==================== */

void InitCommandesBascule(void);

void LireEtatsReels(UC *ucpChauffage,
                    UC *ucpVentilation,
                    UC *ucpLumiere);

void LireEtatsLuminosite(UC *ucpEtatJour,
                         UC *ucpEtatNuit);

void SynchroniseEtatsReels(UC *ucpTab);

void AppliquerEtatChauffage(UC *ucpTab,
                            UC ucEtatVoulu);

void AppliquerEtatVentilation(UC *ucpTab,
                              UC ucEtatVoulu);

void AppliquerEtatLumiere(UC *ucpTab,
                          UC ucEtatVoulu);

void AllumeChauffage(UC *ucpTab);
void FermeChauffage(UC *ucpTab);

void AllumeVentilation(UC *ucpTab);
void FermeVentilation(UC *ucpTab);

void AllumeLumiere(UC *ucpTab);
void FermeLumiere(UC *ucpTab);

void ArretUrgence(UC *ucpTab);

#endif