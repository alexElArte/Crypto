# Crypto
Une librairie arduino qui inclue de simple méthode de cryptographie.

Vous trouverez les informations nécessaires à la compréhension dans la doc à l'intérieur du dossier et sur une publication plus ancienne. Les codes sont les mêmes à quelques exceptions près.

## Info
Si vous utilisez les fonctions toutes seules, les données seront facilement accéssibles. Par contre si vous les utilisez en même temps c'est d'un meilleur inrérêt, exemple:
```c
  /* **Définir la librairie au-dessus** */
  // Encodage
  cryp.encodeC(msg, keyC); // Cette couche ne peut s'utiliser qu'une seule fois au tout début sous peine de détruire des données
  cryp.encodeB(msg); // Utiliser cette fonction le plus souvent possible après une autre cela renforcera la sécurité
  cryp.encodeM(msg, keyM); // Vous pouvez utiliser cette fonction plusieurs fois pour augmenter la sécurité (astuce: utiliser des clés différentes)
  cryp.encodeB(msg); // A toujours utiliser pour être sûre qu'un voleur ne puisse pas décoder le message plus facilement
  
  // Décodage
  // Le même code dans le sens inverse
  cryp.decodeB(msg);
  cryp.decodeM(msg, keyM);
  cryp.decodeB(msg);
  cryp.decodeC(msg, keyC);
```
Si vous testez le code au-dessus vous trouverez la même chose au début comme à la fin.

## Attention : limite fonction encodeC()
La taille de la clé dépend du nombre d'information à encoder:
  * Si vous voulez encoder 32 nombres votre clé aura une taille de 32 octets
  * Si vous voulez encoder 64 nombres votre clé aura une taille de 64 octets

Vous ne pouvez pas encoder n'importe quelle valeur
Imaginons un tableau de 16 valeur, on ne peut encoder que les valeurs de 1 à 16 (compris).
La valeur 0 est considérée comme nul et donc changé par une valeur aléatoire
Les autres valeurs sont également changées par des valeurs aléatoires
