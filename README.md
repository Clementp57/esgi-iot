# Objets Communicants


### Installation

* Installation de l'IDE Arduino
* Récupération du lien sur le wiki smt32 contenant le fichier de conf pour la board utilisée
* Référencement du lien dans l'IDE et téléchargement de la configuration de la board
 (https://raw.githubusercontent.com/stm32duino/BoardManagerFiles/master/STM32/package_stm_index.json)

## Feux Tricolores

### Réalisation du montage

![alt text](./Images/montage_feux.jpeg "Montage Feux Tricolores")

### Ecriture du programme

* Références les pins des leds connectées
* Dans la loop, allumer successivement les feux pour qu'il soient synchronisés
* Attention, pendant qu'une feu est rouge l'autre doit passer à l'orange

### Résultat

![alt text](./Images/gif_feux.gif "2 Feux tricolors qui fonctionnent ensembles")
