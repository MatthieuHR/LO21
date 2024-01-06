# Toutes les fonctions

----
Dans cette partie, vous pourrez retrouver toutes les fonctions implémenter en C et ainsi que leurs usages et déclarations.

Cette partie sera traitée en fonctions des fichiers `.h` et chaque fichier succédant inclus tous les fichiers précédent.
>[!NOTE]
>
>Il vous suffit donc d'inclure le fichier `ExpertSys.h` pour faire fonctionner le tout.


## Fichier `Properties.h`

---
`Bool isUndefinedProperty(void* prop)` : dit si un fait (`prop`) est vide, c'est-à-dire pointe sur `NULL`. Renvoie `True` si est vide, `False` sinon.


## Fichier `FactList.h`

---
`FactList createFactList(Bool (*cmpValue)(void*, void*))` : revoie un objet de type `FactList` avec tous ses champs `NULL` sauf `cmpValue` qui est remplie avec le paramètre `cmpValue` et `last_id` qui vaut `-1`. Sert à créer un objet utilisable pour les autres fonctions.

`Bool isAlreadyInFactList(FactList list, void* fact)` : permet de savoir si un fait (`fact`) est deja dans `list` en se basant sur le pointeur de fonction contenue dans le champ `cmpValue` de `list`. Renvoi `True` si `cmpValue()` renvoie `True` pour une comparaison et `False` sinon. La fonction est récursive.

`Bool isPresentInFactList(FactList list, void* fact)` : permet de savoir si un fait (`fact`) est deja dans `list` en se basant sur l'adresse mémoire des faits (ex : `fact`). Renvoi `True` si les adresses mémoire sont identiques et `False` sinon. La fonction est récursive.

`FactList addFact(FactList list, void* fact)` : ajoute un fait (`fact`) à une liste de fait à condition qu'un autre fait ne renvoie pas `True` quand il est comparé avec `fact` à l'aide de la fonction `cmpValue()` dans le champ du même nom dans `list`. La fonction renvoie quoi qu'il arrive la même `list` avec un élément en plus ou non.

`FactList removeAllFactsAndFree(FactList list)` : permet de vider une liste de fait, mais ne vide pas le champ `cmpValue` intact. Cette fonction `free()` tous les fait de `list`. Renvoie une `Factlist` semblable à celle créée par la fonction `createFactList()`.

`void* getFactById(FactList list, long id)` : permet d'obtenir un pointeur sur le fait souhaité en fonction de son champ `id`. Le paramètre `id` est celui qui doit matcher le champ `id`. Renvoi un fait s'il est trouvé sinon `NULL`.

`FactList freeFactList(FactList list)` : permet de libérer la mémoire allouée à une liste de fait. Renvoie `NULL`. La fonction `free()` tous les fait de `list`.


## Fichier `Rules.h`

---
`Rule createEmptyRule(FactList facts)` : renvoie un objet de type `Rules` avec tous ces champs `NULL` sauf `facts` qui vaut le paramètre `facts`.

`Rule addFactInPremise(Rule rule, void* premise)` : permet d'ajouter un fait (`premise`) dans le champ `premise` d'une règle (`rule`). Le fait n'est pas ajouté s'il n'est pas dans la liste de fait. La fonction renvoie quoi qu'il arrive `rule` modifier ou non.

`Rule setConclusion(Rule rule, void* conclusion)` : permet de définir une conclusion (`conclusion`) dans le champ `conclusion` d'une règle (`rule`). La fonction renvoie quoi qu'il arrive `rule` modifier ou non. Le fait n'est pas ajouté s'il n'est pas dans la liste de fait ou vide (`NULL`).

`Rule removeFromPremise(Rule rule, void* premise)` : permet de supprimer un fait (`premise`) dans le champ `premise` d'une règle (`rule`). La fonction renvoie quoi qu'il arrive `rule` modifier ou non.

`Bool factInPremise(Premise premise, void* prop)` : permet de savoir si un fait (`prop`) est dans une prémise (`premise`). La fonction renvoie `True` si le fait est dans la prémise et `False` sinon. La fonction est récursive.

`Bool isPremiseEmpty(Rule rule)` : permet de savoir si une `prémise` d'une règle (`rule`) est vide. La fonction renvoie `True` si la prémise est vide et `False` sinon. La fonction est récursive.

`ElmOfPremise* getHeadOfPremise(Rule rule)` : permet d'obtenir le premier élément de la prémise d'une règle (`rule`). La fonction renvoie un pointeur sur le premier élément de la prémise de type `ElmOfPremise*`.

`ElmOfPremise* nextOfPremise(ElmOfPremise* elm)` : permet d'obtenir l'élément suivant d'un élément de prémise (`elm`). La fonction renvoie un pointeur sur l'élément suivant de type `ElmOfPremise*`. Renvoie `NULL` si `elm` est `NULL`.

`void* getPremise(ElmOfPremise* elm)` : permet d'obtenir le fait d'un élément de prémise (`elm`). La fonction renvoie un pointeur sur le fait de type `void*`. Renvoie `NULL` si `elm` est `NULL`.

`void* getConclusion(Rule rule)` : permet d'obtenir la conclusion d'une règle (`rule`). La fonction renvoie un pointeur sur la conclusion de type `void*`.

`FactList getFactListOfRule(Rule rule)` : permet d'obtenir la liste de fait associée à une règle (`rule`). La fonction renvoie un pointeur sur la liste de fait de type `FactList`.

`FactList freeRule(Rule rule)` : permet de libérer la mémoire allouée à une règle. La fonction `free()` tous les éléments de la prémise et la conclusion. Renvoie la liste de fait associée à la règle. Revoie `NULL` si la mèmoire n'a pas pu être libérée.

## Fichier `DB.h`

`DB createEmptyDB(FactList facts)` : permet de créer une base de connaissance vide avec une liste de fait associée (`facts`). La fonction renvoie un pointeur sur la base de connaissance de type `DB`.

`DB addRule(DB db, Rule rule)` : permet d'ajouter une règle (`rule`) à une base de connaissance (`db`). La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée.

`ElmOfDB* getHeadRule(DB db)` : permet d'obtenir la première règle (`Rule`) de la base de connaissance (`db`). La fonction renvoie un pointeur sur le premier élément de la base de connaissance de type `ElmOfDB*`.

`ElmOFDB* getNextRule(ElmOfDB* rule)` : permet d'obtenir la règle suivante (`Rule`) d'une règle (`rule`). La fonction renvoie un pointeur sur la règle suivante de type `ElmOfDB*`. Renvoie `NULL` si `rule` est `NULL`.

`Rule getRule(ElmOfDB* rule)` : permet d'obtenir la règle (`Rule`) d'un élément de base de connaissance (`rule`). La fonction renvoie un pointeur sur la règle de type `Rule`. Renvoie `NULL` si `rule` est `NULL`.

`DB copyDB(DB db)` : permet de copier une base de connaissance (`db`). La fonction renvoie un pointeur sur la base de connaissance de type `DB`. La fonction ne copie pas la liste de fait associée à la base de connaissance.

`FactList freeDB(DB db)` : permet de libérer la mémoire allouée à une base de connaissance. La fonction `free()` tous les éléments de la base de connaissance. Renvoie la liste de fait associée à la base de connaissance.

`FactList getFactListOfDB(DB db)` : permet d'obtenir la liste de fait associée à une base de connaissance (`db`). La fonction renvoie un pointeur sur la liste de fait de type `FactList`.