# Fonctionnement du système expert

---
Dans cette section nous allons vous explicitée le fonctionnement de notre **système expert** en détaillant chaque étape de son fonctionnement.


## Préliminaire

---
Avant de faire fonctionner notre système expert, il faut créer deux choses éssentiels :
* une **liste de fait**
* une **base de connaisances**


Regardons alors quels sont leurs roles et comment les créer.

---
### La **liste de fait**

Une liste de fait est la base de tout système expert, elle permet de définir les données utilisées par les conclusions et prémises des règles. 

Dans notre système expert toutes les conclusions et prémises sont tirée de cette liste de fait et doit donc **être créer en premier**. Le type de la liste de fait est `FactList`.

Pour vous aider à sa création vous avez à votre dispositions plusieurs fonctions :
* `createFactList()` pour créer une liste de fait vide (sans éléments).
*  `addFact(FactList list,Properties fact)` pour ajouter une propriétée(`fact`) a une lsite de fait(`list`). Vous pouver utiliser la meme variable `fact` en changent ça valeur sans soucis.
*  `remouveAllFacts(FactList list)` pour supprimer tous les fait d'une lsite de fait.

Il y a aussi des fonctions qui intéragissent avec le type `FactList` :
* `isInFactList(FactList list, Properties* fact)` qui vérifie si l'élément est dans la liste de fait et revoie un `Bool`. 

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

---
### La **base de connaissance**

Une fois notre liste de fait créer il nous faut établir des relations entre les différents faits. Nous alons alors réaliser des règles que nous allons ensuite stocker dans une base de connaissance.

Commençons par créer une règle. Le type d'une **règle** est `Rules` et ces fonctions sont disponibles pour aider à les créer :
* `createEmptyRule()` qui créer une règle vide.
* `addPremise(Rules* rules,Properties* premise)` qui ajoute une prémise à la liste de prémises.
* `createConclusion(Rules* rule, Properties* conclusion)` qui permet de définir une conclusion.
* `remouvePremise(Rules* rule,Properties* premise)` qui retire une prémise si elle est présente.

Il y a aussi des fonctions qui intéragissent avec le type `Rules` :
* `PropertiesInPremise(Premise premise, Properties* prop)` qui vérifie si un fait(`prop`) est dans la prémise et renvoie un `Bool`.
* `isPremiseEmpty(Rules* rule)` qui renvoie un `Bool` et dit si la prémise est vide.
* `getHeadOfPremise(Rules* rule)` qui renvoie le première élément de la prémise de type `ElmOfPremise*`.
* `getConclusion(Rules* rule)` qui renvoie la conclusion de type `Properties*`.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

Une fois notre règle créer il ne reste plus qu'a ajouter cette règle a une base de connaissance. Regardons comment créer une base de connaissance de type `BC`.

Voici les fonctions qui permets sa conception :
* `createEmptyBC()` pour créer une base de connaissance vide.
* `addRuleToBC(BC bc,Rules* rule)` pour ajouter une règle à la base de connaissance.

Il y a aussi des fonctions qui intéragissent avec le type `BC` :
* `getHeadRule(BC bc)` qui donne la première règle d'une base de connaissance.