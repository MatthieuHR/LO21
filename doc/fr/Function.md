# Toutes les fonctions

----
Dans cette partie, vous pourrez retrouver toutes les fonctions implémenter en C et ainsi que leurs usages et déclarations.

Cette partie sera traitée en fonctions des fichiers `.h` et chaque fichier succédant inclus tous les fichiers précédent.
>[!NOTE]
>
>Il vous suffit donc d'inclure le fichier `ExpertSys.h` pour faire fonctionner le tout.


## Fichier `Properties.h`

---
`Bool isEmptyProperty(void* prop)` : dit si un fait (`prop`) est vide, c'est-à-dire pointe sur `NULL`. Renvoie `True` si est vide, `False` sinon.


## Fichier `FactList.h`

---
`FactList createFactList(Bool (*cmpValue)(void*, void*))` : revoie un objet de type `FactList` avec tous ses champs `NULL` sauf `cmpValue` qui est remplie avec le paramètre `cmpValue` et `last_id` qui vaut `-1`. Sert à créer un objet utilisable pour les autres fonctions.

`Bool isAlreadyInFactList(FactList list, void* fact)` : permet de savoir si un fait (`fact`) est deja dans `list` en se basant sur le pointeur de fonction contenue dans le champ `cmpValue` de `list`. Renvoi `True` si `cmpValue()` renvoie `True` pour une comparaison et `False` sinon. La fonction est récursive.

`Bool isPresentInFactList(FactList list, void* fact)` : permet de savoir si un fait (`fact`) est deja dans `list` en se basant sur l'adresse mémoire des faits (ex : `fact`). Renvoi `True` si les adresses mémoire sont identiques et `False` sinon. La fonction est récursive.

`FactList addFact(FactList list, void* fact)` : ajoute un fait (`fact`) à une liste de fait à condition qu'un autre fait ne renvoie pas `True` quand il est comparé avec `fact` à l'aide de la fonction `cmpValue()` dans le champ du même nom dans `list`. La fonction renvoie quoi qu'il arrive la même `list` avec un élément en plus ou non.

`FactList removeAllFacts(FactList list)` : permet de vider une liste de fait, mais ne vide pas le champ `cmpValue` intact. Cette fonction `free()` tous les fait de `list`. Renvoie une `Factlist` semblable à celle créée par la fonction `createFactList()`.

`void* getById(FactList list, long id)` : permet d'obtenir un pointeur sur le fait souhaité en fonction de son champ `id`. Le paramètre `id` est celui qui doit matcher le champ `id`. Renvoi un fait s'il est trouvé sinon `NULL`.


## Fichier `Rules.h`

---
`Rule* createEmptyRule(FactList facts)` : renvoie un objet de type `Rules` avec tous ces champs `NULL` sauf `facts` qui vaut le paramètre `facts`.

`Rule* addPremise(Rule* rule, void* premise)` : permet d'ajouter un fait (`premise`) dans le champ `premise` d'une règle (`rule`). Le fait n'est pas ajouté s'il n'est pas dans la liste de fait. La fonction renvoie quoi qu'il arrive `rule` modifier ou non.