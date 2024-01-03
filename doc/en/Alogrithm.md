# Algorithm des sous programmes

---
Dans cette section, vous pouvez retrouver tous les algorithmes des sous programmes en fonctions des données qu'ils traitent.

>Avant de commencer la fonction `isEmpty(elm:type)` permet de savoir si un élément est vide (`UNDEFINED`) peu importe le type `type`.
> 
> `Type` servira à identifier le type d'un **fait**.

## Les algorithmes avec des `FactList`

---
### Les fonctions de bases
* `createFactList(cmpValue(Type, Type):Function)` renvoie une liste de fait (`FactList`) vide avec la méthode de comparaison (`cmpValue`) choisie.
* `createElmOfFact()` renvoie un élément vide d'une liste de fait (`FactList`).
* `head(elm:FactList)` permet l'accès au premier élément de la liste.
* `last_id(elm:FactList)` permet l'accès au dernier `id` donné de type `LongInteger`.
* `fact(elm:ElmOfFact)` permet l'accession au champ `fact` de `elm`.
* `id(elm:ElmOfFact)` permet l'accès à l'`id` de l'élément.
* `next(elm:ElmOfFact)` permet l'accession au suivant de `elm`.

---
### `addFact`
Cette fonction sert à ajouter un élément dans une `FactList`.
* `list` est la liste de fait où on veut ajouter l'élément.
* `fact` est le fait que l'on souhaite ajouter.
* `newl` est le nouvel élément de la `FactList` `list`.
>La fonction renvoie la liste de fait modifiée.
````
function addFact(list:FactList, fact:Type):FactList
Start
    if not isEmpty(fact) AND isInFactlist(list, fact) == UNDEFINED Then
        newl:ElmOfFact <- createElmOfFact()
        fact(newl) <- fact
        next(newl) <- head(list)
        id(newl) <- last_id(list) + 1
        head(list) = newl;
        last_id(list) = last_id(list) + 1
    EndIf
    addFact <- list
End
````

---
### `removeAllFacts`
Cette fonction permet de libérer la mémoire utilisée par une `FactList` en cas de besoin, par exemple en cas d'erreur.
* `list` est la liste que l'on souhaite vider.
>La fonction renvoie la liste de fait modifiée.
````
function removeAllFacts(list:FactList):FactList
Start
    point:ElmOfFact <- head(list)
    While not isEmpty(point) Do
        head(list) <- point
        point <- next(point)
        free(fact(head(list)))
        free(head(list))
    Done
    head(list) = UNDEFINED
    last_id(list) = -1
    removeAllFacts <- point
End
````

---
### `getById`
Cette fonction permet de récupérer un élément d'une liste de fait en fonction de son `id`.
* `list` est la liste de fait dont on souhaite extraire un élément.
* `id` est l'identifiant unique dont on veut la structure associée.
* `point` est un pointeur pour parcourir la list.
>La fonction renvoie un fait de type `Type`.
````
function getById(list:FactList, id:LongInteger):Type
Start
    If not isEmpty(head(list)) AND id <= last_id(list) Then
        point:ElmOfFact <- head(list)
        While not isEmpty(point) Do
            If id(point) = id Then
                getById <- fact(point)*
            EndIf
        Done
    EndIf
    getById <- UNDEFINED
End
````

---
### `isAlreadyInFactList`
Cette fonction permet de savoir si un élément appartient à une liste de fait (`FactList`) récursivement en fonction de sa valeur.
* `list` est la liste de fait ou l'on cherche notre fait.
* `fact` est le fait que l'on cherche.
>La fonction renvoie un `Bool`
````
function isAlreadyInFactList(list:FactList, fact:Type):Bool
Start
    If isEmpty(head(list)) OR isEmpty(fact) Then
        isAlreadyInFactList <- False
    EndIf
    If isEqual(fact(head(list)),fact,cmpValue(list)) Then
        isAlreadyInFactList <- True
    Else
        next:Factlist <- fact
        head(next) <- next(head(list))
        isAlreadyInFactList <- isAlreadyInFactList(next, fact)
    EndIf
End
````

---
### `isPresentInFactList`
Cette fonction permet de savoir si un élément appartient à une liste de fait (`FactList`) récursivement en fonction de son emplacement mémoire.
* `list` est la liste de fait ou l'on cherche notre fait.
* `fact` est le fait que l'on cherche.
>La fonction renvoie un `Bool`
````
function isPresentInFactList(list:FactList, fact:Type):Bool
Start
    If isEmpty(head(list)) OR isEmpty(fact) Then
        isAlreadyInFactList <- False
    EndIf
    If fact(head(list)) = fact Then
        isAlreadyInFactList <- True
    Else
        next:Factlist <- fact
        head(next) <- next(head(list))
        isPresentInFactList <- isPresentInFactList(next, fact)
    EndIf
End
````

---
### `freeFactList`
Cette fonction permet de libérer la mémoire utilisée par une `FactList` en cas de besoin, par exemple en cas d'erreur ou à la fin du programme.
* `list` est la liste que l'on souhaite vider.
* `point` est un pointeur pour parcourir la list.
>La fonction renvoie la liste de fait vide (`UNDEFINED`).
````
function freeFactList(list:FactList):FactList
Start
    If not isEmpty(list) AND not isEmpty(head(list)) Then
        list <- removeAllFacts(list)
    EndIf
    free(list)
    EndIf
    freeFactList <- UNDEFINED
End
````
## Les algorithmes avec des `Rule`

---

### Les fonctions de bases
* `head(elm:Premise)` permet l'accès au premier élément de la liste.
* `tail(elm:Premise)` permet l'accès au dernier élément de la liste.
* `createElmOfPremise()` Renvoie un élément vide d'une prémisse (`Premise`).
* `premise(elm:ElmOfPremise)` permet l'accession au champ `premise` de `elm`.
* `next(elm:ElmOfPremise)` permet l'accession au suivant de `elm`.
* `createRule()` Renvoie un élément vide d'une règle (`Rule`).
* `premise(elm:Rule)` permet l'accession au champ `premise` de `elm`.
* `conclusion(elm:Rule)` permet l'accession au champ `conclusion` de `elm`.
* `facts(elm:Rule)` permet l'accession à la liste de fait qui a permis de construire la règle. 

---
### `addPremise`
Cette fonction permet d'ajouter un élément à la premise d'une règle.
* `rule` est la règle à laquelle on veut modifier la prémisse.
* `premise` est un fait qui provient d'une liste de fait (`FactList`) et que l'on souhaite ajouter à la prémisse de la règle.
* `newl` est le nouvel élément de la prémisse.
>La fonction renvoie la règle modifiée.
````
function addPremise(rule:Rule, premise:Type):Rule
Stat
    If not isEmpty(premise) AND not isEmpty(rule) AND isPresentInFactList(facts(rule),premise) Then
        newl:ElmOfPremise <- createElmOfPremise()
        premise(newl) <- premise
        next(newl) <- UNDEFINED
        If isEmpty(head(premise(rule))) Then
            head(premise(rule)) = newl
            tail(premise(rule)) = newl
        EndIf
        If isEmpty(premise(rule)) Then
            next(tail(premise(rule))) <- newl
            tail(premise(rule)) <- newl
        EndIf
    EndIf
    addPremise <- rule
End
````

---
### `setConclusion`
Cette fonction permet de mettre à jour la conclusion d'une règle.
* `rule` est la règle à laquelle on veut modifier la conclusion.
* `conclusion` est un fait qui provient d'une liste de fait (`FactList`) et que l'on souhaite utiliser comme conclusion de la règle.
>La fonction renvoie la règle modifiée.
````
function setConclusion(rule:Rule, conclusion:Type):Rule
Start
    If not isEmpty(rule) AND isPresentInFactList(facts(rule), conclusion) Then
        conclusion(rule) <- conclusion
    EndIf
    setConclusion <- rule
End
````

---
### `factInPremise`
Cette fonction sert à définir récursivement si un fait est dans une prémisse de règle.
* `rule` est la règle dont on veut savoir si le fait y est contenu dans la prémisse.
* `prop` est le fait que l'on cherche.
>La fonction renvoie `True` si la propriété est comprise, `False` sinon.
````
function factInPremise(premise:Rule, prop:Type):Bool
Start
    If isEmpty(rule) OR isEmpty(head(premise(rule))) OR isEmpty(prop) Then
        factInPremise <- False
    EndIf
    If premise(head(premise(rule))) = prop Then
        factInPremise <- True
    Endif
    new:Rule <- rule
    head(premise(new) <- next(head(premise(rule)))
    factInPremise <- factInPremise(new, prop)
End
````

---
### `removeFromPremise`
Cette fonction permet de retirer un fait de la prémisse.
* `rule` est la règle à laquelle on veut modifier la prémisse.
* `premise` est un fait qui provient d'une liste de fait (`FactList`) et que l'on souhaite retirer à la prémisse de la règle.
* `now` est l'élément que l'on compare actuellement (sauf pour la tete de liste).
* `prev` est l'élément avant `now`.
>La fonction renvoie la règle modifiée.
````
function removeFromPremise(rule:Rule, premise:Type):Rule
Start
    If not isEmpty(rule) AND not isEmpty(premise) AND not isEmpty(head(premise(rule))) Then
        prev:ElmOfPremise <- head(premise(rule))
        now:ElmOfPremise <- next(prev)
        If premise = premise(prev) Then
            If head(premise(rule)) = tail(premise(rule)) Then
                free(prev)
                head(premise(rule)) = NULL
                tail(premise(rule)) = NULL
            Else
                free(prev)
                head(premise(rule)) <- now
            EndIf
            removeFromPremise <- rule
        Else
            While not isEmpty(now)) Do
                If premise(now) = premise Then
                    next(prev) = next(now)
                    free(now)
                    removeFromPremise <- rule
                EndIf
                prev <- now
                now <- next(now)
            Done
        EndIf
    EndIf
    removeFromPremise <- rule
End
````

---
### `freeRule`
Cette fonction permet de libérer la mémoire utilisée par une règle en cas de besoin, par exemple en cas d'erreur ou à la fin du programme.
* `rule` est la règle que l'on souhaite vider.
* `point` est un pointeur pour parcourir la règle.
* `premise` est un pointeur pour parcourir la prémisse.
> La fonction renvoie la liste de fait (`FactList`) associée.
````
function freeRule(rule:Rule):Rule
Start
    If not isEmpty(rule) AND not isEmpty(head(premise(rule))) Then
        point:ElmOfPremise <- head(premise(rule))
        While not isEmpty(point) Do
            temp:ElmOfPremise <- point
            point <- next(point)
            free(temp)
        Done
        rtn:FactList <- facts(rule)
        free(rule)
        freeRule <- rtn
End
````
## Les algorithmes avec des `DB`

---
### Les fonctions de bases
* `createBC(facts:FactList)` renvoie une base de connaissance avec `facts` comme liste de faits associée.
* `head(elm:DB)` permet l'accès au premier élément de la liste.
* `tail(elm:DB)` permet l'accès au dernier élément de la liste.
* `fact(elm:DB)` permet d'accès à la liste de fait qui a servi à construire la base de connaissance.
* `createElmOfBC()` Renvoie un élément vide d'une base de connaissance (`DB`).
* `rule(elm:ElmOfDB)` permet l'accession au champ `rule` de `elm`.
* `next(elm:ElmOfDB)` permet l'accession au suivant de `elm`.

---
### `addRuleToBC`
Cette fonction permet d'ajouter une règle à une base de connaissance.
* `bc` est la base de connaissance à laquelle on veut ajouter une règle.
* `rule` est une règle que l'on souhaite ajouter.
* `newl` est le nouvel élément de la base de connaissance.
>La fonction renvoie la base de connaissance modifiée.
```
function addRuleToBC(bc:DB, rule:Rule):DB
Start
    If not isEmpty(premise(rule)) AND not isEmpty(conclusion(rule)) AND head(facts(rule)) = head(facts(bc)) Then
        newl:ElmOfDB <- createElmOfBC()
        rule(newl) <- rule
        next(rule) <- UNDEFINED
        If head(bc) = tail(bc) Then 
            head(bc) <- newl
            tail(bc) <- newl
        Else
            next(tail(bc)) <- newl
            tail(bc) <- newl
        EndIf
    EndIf
    addRuleToBC <- bc 
End
```

---
### `copyOfBC`
Cette fonction permet de réaliser une copie d'une base de connaissance.
* `bc` est la base de connaissance que l'on souhaite copier.
* `point` est un pointeur pour parcourir la base de connaissance `bc`.
* `new_rule` est l'ensemble de nouvelles règles que l'on ajoute à `bc`.
* `premise` est l'ensemble des premise des règles de `bc`.
>La fonction revoit la copie de la bc.
````
function copyOfBC(bc:DB):DB
Start 
    new_bc:DB <- createBC(facts(bc))
    point:ElmOfDB <- head(bc)
    While not isEmpty(point) Do
        new_rule:Rule <- createRule(facts(bc))
        conclusion(new_rule) <- conclusion(rule(point))
        premise:ElmOfPremise <- head(premise(rule(point)))
        While not isEmpty(premise) Do
            new_rule <- addPremise(new_rule, premise(premise))
            premise <- next(premise)
        Done
        new_bc <- addRuleToBC(new_bc, new_rule)
        point <- next(point)
    Done
    copyOfBC <- new_bc
End
````

---
### `freeBC`
Cette fonction permet de libérer la mémoire utilisée par une base de connaissance en cas de besoin, par exemple en cas d'erreur ou à la fin du programme.
* `bc` est la base de connaissance que l'on souhaite vider.
* `point` est un pointeur pour parcourir la base de connaissance `bc`.
* `rule` est un pointeur pour parcourir les règles de `bc`.
> La fonction renvoie la liste de fait (`FactList`) associée.

````
function freeBC(bc:DB):DB
Start
    If not isEmpty(bc) AND not isEmpty(head(bc)) Then
        point:ElmOfDB <- head(bc)
        While not isEmpty(point) Do
            temp:ElmOfDB <- point
            freeRule(rule(temp))
            point <- next(point)
            free(temp)
        Done
        rtn:FactList <- fact(bc)
        free(bc)
        freeBC <- rtn
End
````