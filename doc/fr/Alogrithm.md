# Algorithmes des sous programmes

---
Dans cette section, vous pouvez retrouver tous les algorithmes des sous programmes en fonctions des données qu'ils traitent.

>[!NOTE]
>
>Avant de commencer la fonction `isEmpty(elm:type)` permet de savoir si un élément est vide (`UNDEFINED` ou `NULL` en C) peu importe le type `type`. Cette fonction est utilisée dans tous les algorithmes pour vérifier que les éléments passés en paramètres sont bien définis.`
> 
> `Type` servira à identifier le type d'un **fait**.

>[!WARNING]
>
>Les fonctions de bases ont changé de nom pour correspondre à leur nom de champs. Certaines peuvent exister en C. Pour vérifier cela merci de vous référer au [guide des fonctions](Function.md).


## isEmpty
Dans cette section, nous allons vous exposer quand la fonction `isEmpty` renvoie `True` ou `False` en fonction du type de l'élément passé en paramètre :
* `Propertie` : cela est définie par l'utilisateur avec la fonction du champ `isEmpty` de la liste de fait (`FactList`).
* `FactList` : est vide si `head` est `UNDEFINED`.
* `Rule` : est vide si `premise` est `UNDEFINED` et `conclusion` est `UNDEFINED`.
* `DB` : est vide si `head` est `UNDEFINED`.

>[!NOTE]
> 
>La `isEmpty` vérifie si un type est définie avant de tester ces champs. Si le type n'est pas définie alors la fonction renvoie `False`.

## Les algorithmes avec des `FactList`

---
### Les fonctions de bases
* `createFactList(cmpValue(Type, Type):Boolean, isEmpty(Type):Boolean, freeValue(Type):UNDEFINED)` renvoie une liste de fait (`FactList`) vide avec la méthode de comparaison (`cmpValue`), la méthode pour savoir si un élément est vide (`isEmpty`) et la méthode pour libérer la mémoire utilisée par un élément (`freeValue`).
* `createElmOfFact()` renvoie un élément vide d'une liste de fait (`FactList`).
* `head(elm:FactList)` permet l'accès au premier élément de la liste.
* `last_id(elm:FactList)` permet l'accès au dernier `id` donné de type `LongInteger`.
* `cmpValue()` permet l'accès à la méthode de comparaison de la liste de fait.
* `isEmpty()` permet l'accès à la méthode pour savoir si un élément est vide.
* `freeValue()` permet l'accès à la méthode pour libérer la mémoire utilisée par un élément.
* `fact(elm:ElmOfFact)` permet l'accession au champ `fact` de `elm`.
* `id(elm:ElmOfFact)` permet l'accès à l'`id` de l'élément.
* `next(elm:ElmOfFact)` permet l'accession au suivant de `elm`.

---
### `isAlreadyInFactList`
Cette fonction permet de savoir si un élément appartient à une liste de fait (`FactList`) récursivement en fonction de sa valeur.
* `list` est la liste de fait ou l'on cherche notre fait.
* `fact` est le fait que l'on cherche.
>La fonction renvoie un `Boolean`
````
function isAlreadyInFactList(list:FactList, fact:Type):Boolean
Start
    If isEmpty(list) OR isUndefined(fact) Then
        isAlreadyInFactList <- False
    EndIf
    If cmpValuelist(fact(head(list)),fact) Then
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
>La fonction renvoie un `Boolean`
````
function isPresentInFactList(list:FactList, fact:Type):Boolean
Start
    If isEmpty(list) OR isUndefined(fact) Then
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
### `addFact`
Cette fonction sert à ajouter un élément dans une `FactList`.
* `list` est la liste de fait où on veut ajouter l'élément.
* `fact` est le fait que l'on souhaite ajouter.
* `newl` est le nouvel élément de la `FactList` `list`.
>La fonction renvoie la liste de fait modifiée.
````
function addFact(list:FactList, fact:Type):FactList
Start
    if not isEmpty(fact) AND not isUndefined(list) AND not isInFactlist(list, fact) Then
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
### `removeAFact`
Cette fonction permet de retirer un élément d'une `FactList`.
* `list` est la liste de fait où on veut retirer l'élément.
* `fact` est le fait que l'on souhaite retirer.
* `point` est l'élément que l'on compare actuellement (sauf pour la tete de liste).
>La fonction renvoie la liste de fait modifiée.
````
function removeAFact(list:FactList, fact:Type):FactList
Start
    If not isEmpty(list) AND not isUndefined(fact) Then
        If fact(head(list)) = fact Then
            point:ElmOfFact <- head(list)
            head(list) <- next(head(list))
            free(fact(point))
            free(point)
        Else
            prev:ElmOfFact <- head(list)
            point:ElmOfFact <- next(prev)
            While not isEmpty(point) Do
                If fact(point) = fact Then
                    next(prev) <- next(point)
                    free(fact(point))
                    free(point)
                EndIf
                prev <- point
                point <- next(point)
            Done
        EndIf
    EndIf
    removeAFact <- list
End
````

---
### `removeAFactAndFree`
Cette fonction permet de retirer un élément d'une `FactList` et de libérer la mémoire utilisée par cet élément.
* `list` est la liste de fait où on veut retirer l'élément.
* `fact` est le fait que l'on souhaite retirer.
* `point` est l'élément que l'on compare actuellement (sauf pour la tete de liste).
>La fonction renvoie la liste de fait modifiée.
````
function removeAFactAndFree(list:FactList, fact:Type):FactList
Start
    If not isEmpty(list) AND not isUndefined(fact) Then
        If fact(head(list)) = fact Then
            point:ElmOfFact <- head(list)
            head(list) <- next(head(list))
            free(fact(point))
            free(point)
        Else
            prev:ElmOfFact <- head(list)
            point:ElmOfFact <- next(prev)
            While not isEmpty(point) Do
                If fact(point) = fact Then
                    next(prev) <- next(point)
                    free(fact(point))
                    free(point)
                EndIf
                prev <- point
                point <- next(point)
            Done
        EndIf
    EndIf
    removeAFactAndFree <- list
End
````

---
### `removeAFactsById`
Cette fonction permet de retirer un élément d'une `FactList` en fonction de son `id`.
* `list` est la liste de fait où on veut retirer l'élément.
* `id` est l'identifiant unique de l'élément que l'on souhaite retirer.
* `point` est l'élément que l'on compare actuellement (sauf pour la tete de liste).
>La fonction renvoie la liste de fait modifiée.
````
function removeAFactsById(list:FactList, id:LongInteger):FactList
Start
    If not isEmpty(list) AND id >= AND id <= last_id(list) Then
        If id(head(list)) = id Then
            point:ElmOfFact <- head(list)
            head(list) <- next(head(list))
            free(fact(point))
            free(point)
        Else
            prev:ElmOfFact <- head(list)
            point:ElmOfFact <- next(prev)
            While not isEmpty(point) Do
                If id(point) = id Then
                    next(prev) <- next(point)
                    free(fact(point))
                    free(point)
                EndIf
                prev <- point
                point <- next(point)
            Done
        EndIf
    EndIf
    removeAFactsById <- list
End
````

---
### `removeAFactsByIdAndFree`
Cette fonction permet de retirer un élément d'une `FactList` en fonction de son `id` et de libérer la mémoire utilisée par cet élément.
* `list` est la liste de fait où on veut retirer l'élément.
* `id` est l'identifiant unique de l'élément que l'on souhaite retirer.
* `point` est l'élément que l'on compare actuellement (sauf pour la tete de liste).
>La fonction renvoie la liste de fait modifiée.
````
function removeAFactsByIdAndFree(list:FactList, id:LongInteger):FactList
Start
    If not isEmpty(list) AND id >= AND id <= last_id(list) Then
        If id(head(list)) = id Then
            point:ElmOfFact <- head(list)
            head(list) <- next(head(list))
            free(fact(point))
            free(point)
        Else
            prev:ElmOfFact <- head(list)
            point:ElmOfFact <- next(prev)
            While not isEmpty(point) Do
                If id(point) = id Then
                    next(prev) <- next(point)
                    free(fact(point))
                    free(point)
                EndIf
                prev <- point
                point <- next(point)
            Done
        EndIf
    EndIf
    removeAFactsByIdAndFree <- list
End
````

---
### `removeAllFacts`
Cette fonction permet de retirer tous les éléments d'une `FactList`.
* `list` est la liste de fait que l'on souhaite vider.
* `point` est l'élément que l'on compare actuellement (sauf pour la tete de liste).
>La fonction renvoie la liste de fait modifiée.
````
function removeAllFacts(list:FactList):FactList
Start
    If not isEmpty(list) AND not isUndefined(fact) Then
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
### `removeAllFactsAndFree`
Cette fonction permet de libérer la mémoire utilisée par une `FactList` en cas de besoin, par exemple en cas d'erreur.
* `list` est la liste que l'on souhaite vider.
>La fonction renvoie la liste de fait modifiée.
````
function removeAllFactsAndFree(list:FactList):FactList
Start
    If not isEmpty(list) AND not isUndefined(fact) Then
    point:ElmOfFact <- head(list)
    While not isEmpty(point) Do
        head(list) <- point
        point <- next(point)
        free(fact(head(list)))
        free(head(list))
    Done
    head(list) = UNDEFINED
    last_id(list) = -1
    removeAllFactsAndFree <- point
End
````

---
### `getFactById`
Cette fonction permet de récupérer un élément d'une liste de fait en fonction de son `id`.
* `list` est la liste de fait dont on souhaite extraire un élément.
* `id` est l'identifiant unique dont on veut la structure associée.
* `point` est un pointeur pour parcourir la list.
>La fonction renvoie un fait de type `Type`.
````
function getFactById(list:FactList, id:LongInteger):Type
Start
    If not isEmpty(head(list)) AND id <= last_id(list) AND id >= 0 Then
        point:ElmOfFact <- head(list)
        While not isEmpty(point) Do
            If id(point) = id Then
                getFactById <- fact(point)*
            EndIf
        Done
    EndIf
    getFactById <- UNDEFINED
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
        list <- removeAllFactsAndFree(list)
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
* `id(elm:ElmOfPremise)` permet l'accès à l'`id` de l'élément.
* `next(elm:ElmOfPremise)` permet l'accession au suivant de `elm`.
* `createRule()` Renvoie un élément vide d'une règle (`Rule`).
* `premise(elm:Rule)` permet l'accession au champ `premise` de `elm`.
* `conclusion(elm:Rule)` permet l'accession au champ `conclusion` de `elm`.
* `facts(elm:Rule)` permet l'accession à la liste de fait qui a permis de construire la règle. 

---
### `isEqualsRule`
Cette fonction permet de savoir si deux règles sont égales en comparants leurs champs de valeurs.
* `rule1` est la première règle que l'on souhaite comparer.
* `rule2` est la seconde règle que l'on souhaite comparer.
* `point1` est un pointeur pour parcourir la prémisse de `rule1`.
* `point2` est un pointeur pour parcourir la prémisse de `rule2`.
>La fonction renvoie `True` si les règles sont égales, `False` sinon.
````
function isEqualsRule(rule1:Rule, rule2:Rule):Boolean
Start
    If not isEmpty(rule1) ANS not isEmpty(rule2) && head(facts(rule1)) = head(facts(rule2)) AND conclusion(rule1) = conclusion(rule2) Then
        point1:ElmOfPremise <- head(premise(rule1))
        While not isEmpty(point1) Do
            If not factInPremise(rule2, premise(point1)) Then
                isEqualsRule <- False
            EndIf
            point1 <- next(point1)
        Done
        point2:ElmOfPremise <- head(premise(rule2))
        While not isEmpty(point2) Do
            If not factInPremise(rule1, premise(point2)) Then
                isEqualsRule <- False
            EndIf
            point2 <- next(point2)
        Done
        isEqualsRule <- True
    EndIf
    isEqualsRule <- False
End
````

---
### `factInPremise`
Cette fonction sert à définir récursivement si un fait est dans une prémisse de règle.
* `rule` est la règle dont on veut savoir si le fait y est contenu dans la prémisse.
* `prop` est le fait que l'on cherche.
>La fonction renvoie `True` si la propriété est comprise, `False` sinon.
````
function factInPremise(premise:Rule, prop:Type):Boolean
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
### `addFactInPremise`
Cette fonction permet d'ajouter un élément à la prémisse d'une règle.
* `rule` est la règle à laquelle on veut modifier la prémisse.
* `premise` est un fait qui provient d'une liste de fait (`FactList`) et que l'on souhaite ajouter à la prémisse de la règle.
* `newl` est le nouvel élément de la prémisse.
>La fonction renvoie la règle modifiée.
````
function addFactInPremise(rule:Rule, premise:Type):Rule
Stat
    If not isUndefined(premise) AND not isUndefined(rule) AND isPresentInFactList(facts(rule),premise) AND not factInPremise(rule, premise) AND not conclusion(rule) = premise Then
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
    addFactInPremise <- rule
End
````

---
### `removeFromPremise`
Cette fonction permet de retirer un fait de la prémisse.
* `rule` est la règle à laquelle on veut modifier la prémisse.
* `premise` est un fait qui provient d'une liste de fait (`FactList`) et que l'on souhaite retirer à la prémisse de la règle.
* `now` est l'élément que l'on compare actuellement (sauf pour la tete de liste).
>La fonction renvoie la règle modifiée.
````
function removeFromPremise(rule:Rule, premise:Type):Rule
Start
    If not isUndefined(rule) AND not isUndefined(premise) Then
    If not isUndefined(head(premise(rule))) Then
        point:ElmOfPremise <- head(premise(rule))
        If premise(point) = premise Then
            head(premise(rule)) <- next(point)
            free(point)
        Else
            While not isUndefined(next(point)) AND not premise(next(point)) = premise Do
                point <- next(point)
            Done
            If not isUndefined(next(point)) Then
                If next(point) = tail(premise(rule)) Then
                    tail(premise(rule)) <- point
                EndIf
                temp:ElmOfPremise <- next(point)
                next(point) <- next(next(point))
                free(temp)
            EndIf
        EndIf
    EndIf
    removeFromPremise <- rule
End
````

---
### `removeFromPremiseById`
Cette fonction permet de retirer un fait de la prémisse en fonction de son `id`.
* `rule` est la règle à laquelle on veut modifier la prémisse.
* `id` est l'identifiant unique de l'élément que l'on souhaite retirer.
* `point` est l'élément que l'on compare actuellement (sauf pour la tete de liste).
>La fonction renvoie la règle modifiée.
````
function removeFromPremise(rule:Rule, id:LongInteger):Rule
Start
    If not isUndefined(rule) AND not isUndefined(premise) Then
    If not isUndefined(head(premise(rule))) Then
        point:ElmOfPremise <- head(premise(rule))
        If id(point) = id Then
            head(premise(rule)) <- next(point)
            free(point)
        Else
            While not isUndefined(next(point)) AND not id(next(point)) = id Do
                point <- next(point)
            Done
            If not isUndefined(next(point)) Then
                If next(point) = tail(premise(rule)) Then
                    tail(premise(rule)) <- point
                EndIf
                temp:ElmOfPremise <- next(point)
                next(point) <- next(next(point))
                free(temp)
            EndIf
        EndIf
    EndIf
    removeFromPremise <- rule
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
### `renmoveConclusion`
Cette fonction permet de retirer la conclusion d'une règle.
* `rule` est la règle à laquelle on veut modifier la conclusion.
>La fonction renvoie la règle modifiée.
````
function renmoveConclusion(rule:Rule):Rule
Start
    If not isUndefined(rule) Then
        conclusion(rule) <- UNDEFINED
    EndIf
    renmoveConclusion <- rule
End
````

---
### `getPremiseById`
Cette fonction permet de récupérer un élément d'une prémisse en fonction de son `id`.
* `rule` est la règle dont on souhaite extraire un élément.
* `id` est l'identifiant unique dont on veut la structure associée.
* `point` est un pointeur pour parcourir la prémisse.
>La fonction renvoie un fait de type `Type`.
````
function getPremiseById(rule:Rule, id:LongInteger):Type
Start
    If not isEmpty(rule) AND id <= last_id(rule) AND id >= 0 Then
        point:ElmOfPremise <- head(premise(rule))
        While not isEmpty(point) Do
            If id(point) = id Then
                getPremiseById <- premise(point)
            EndIf
        Done
    EndIf
    getPremiseById <- UNDEFINED
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
    If not isEmpty(rule) Then
        If not isEmpty(head(premise(rule))) Then
            point:ElmOfPremise <- head(premise(rule))
            While not isEmpty(point) Do
                temp:ElmOfPremise <- point
                point <- next(point)
                free(temp)
            Done
        Done
        rtn:FactList <- facts(rule)
        free(rule)
        freeRule <- rtn
    EndIf
    freeRule <- UNDEFINED
End
````
## Les algorithmes avec des `DB`

---
### Les fonctions de bases
* `createDB(facts:FactList)` renvoie une base de connaissance avec `facts` comme liste de faits associée.
* `head(elm:DB)` permet l'accès au premier élément de la liste.
* `tail(elm:DB)` permet l'accès au dernier élément de la liste.
* `last_id(elm:DB)` permet l'accès au dernier `id` donné de type `LongInteger`.
* `fact(elm:DB)` permet d'accès à la liste de fait qui a servi à construire la base de connaissance.
* `createElmOfDB()` Renvoie un élément vide d'une base de connaissance (`DB`).
* `rule(elm:ElmOfDB)` permet l'accession au champ `rule` de `elm`.
* `id(elm:ElmOfDB)` permet l'accès à l'`id` de l'élément.
* `next(elm:ElmOfDB)` permet l'accession au suivant de `elm`.

---
### `isRuleAddable`
Cette fonction permet de savoir si une règle est **addable** à une base de connaissance (`DB`).
* `rule` est la règle que l'on souhaite ajouter.
>La fonction renvoie un `Boolean` qui vaut `True` si la règle est **addable**, `False` sinon.
````
function isRuleAddable(rule:Rule):Boolean
Start
    isRuleAddable <- not isEmpty(rule) AND not isUndefined(fact(rule))
End
````

---
### `isPresentInDB`
Cette fonction permet de savoir si une règle appartient à une base de connaissance (`DB`) récursivement en fonction de son adresse mémoire.
* `db` est la base de connaissance où l'on cherche notre règle.
* `rule` est la règle que l'on cherche.
* `point` est un pointeur pour parcourir la base de connaissance `db`.
>La fonction renvoie un `Boolean` qui vaut `True` si la règle est déjà présente, `False` sinon.
````
function isPresentInDB(db:DB, rule:Rule):Boolean
Start
    If not isUndefined(rule) AND not isEmpty(db) Then
        point:ElmOfDB <- head(db)
        While not isEmpty(point) Do
            If rule(point) = rule Then
                isPresentInDB <- True
            EndIf
            point <- next(point)
        Done
    EndIf
    isPresentInDB <- False
End
````

---
### `isAlreadyInDB`
Cette fonction permet de savoir si une règle appartient à une base de connaissance (`DB`) récursivement en fonction de ses champs de valeurs.
* `db` est la base de connaissance où l'on cherche notre règle.
* `rule` est la règle que l'on cherche.
* `point` est un pointeur pour parcourir la base de connaissance `db`.
>La fonction renvoie un `Boolean` qui vaut `True` si la règle est déjà présente, `False` sinon.
````
function isAlreadyInDB(db:DB, rule:Rule):Boolean
Start
    If not not isUndefined(rule) AND not isEmpty(db) Then
        point:ElmOfDB <- head(db)
        While not isEmpty(point) Do
            If isEqualsRule(rule(point), rule) Then
                isAlreadyInDB <- True
            EndIf
            point <- next(point)
        Done
    EndIf
    isAlreadyInDB <- False
End
````

---
### `addRuleToDB`
Cette fonction permet d'ajouter une règle à une base de connaissance.
* `db` est la base de connaissance à laquelle on veut ajouter une règle.
* `rule` est une règle que l'on souhaite ajouter.
* `newl` est le nouvel élément de la base de connaissance.
>La fonction renvoie la base de connaissance modifiée.
```
function addRuleToDB(db:DB, rule:Rule):DB
Start
    If not isUndefined(db) AND isRuleAddable(rule) AND head(fact(rule)) = head(fact(db)) AND not isPresentInDB(db,rule) Then
        newl:ElmOfDB <- createElmOfDB()
        rule(newl) <- rule
        next(rule) <- UNDEFINED
        id(newl) <- last_id(db) + 1
        If head(db) = tail(db) Then 
            head(db) <- newl
            tail(db) <- newl
        Else
            next(tail(db)) <- newl
            tail(db) <- newl
        EndIf
        last_id(db) <- last_id(db) + 1
    EndIf
    addRuleToDB <- db 
End
```

---
### `addRuleToDB_Strict`
Cette fonction permet d'ajouter une règle à une base de connaissance en vérifiant que la règle n'est pas déjà présente par valeur de ses champs.
* `db` est la base de connaissance à laquelle on veut ajouter une règle.
* `rule` est une règle que l'on souhaite ajouter.
* `newl` est le nouvel élément de la base de connaissance.
>La fonction renvoie la base de connaissance modifiée.
```
function addRuleToDB_Strict(db:DB, rule:Rule):DB
Start
    If not isUndefined(db) AND isRuleAddable(rule) AND head(fact(rule)) = head(fact(db)) AND not isAlreadyInDB(db,rule) Then
        newl:ElmOfDB <- createElmOfDB()
        rule(newl) <- rule
        next(rule) <- UNDEFINED
        id(newl) <- last_id(db) + 1
        If head(db) = tail(db) Then 
            head(db) <- newl
            tail(db) <- newl
        Else
            next(tail(db)) <- newl
            tail(db) <- newl
        EndIf
        last_id(db) <- last_id(db) + 1
    EndIf
    addRuleToDB_Strict <- db 
End
```

---
### `removeARule`
Cette fonction permet de retirer une règle d'une base de connaissance.
* `db` est la base de connaissance à laquelle on veut retirer une règle.
* `rule` est une règle que l'on souhaite retirer.
* `now` est l'élément que l'on compare actuellement.
* `prev` est l'élément avant `now`. et est indéfinie au début
>La fonction renvoie la base de connaissance modifiée.
````
function removeARule(db:DB, rule:Rule):DB
Start
    If not isEmpty(db) AND not isUndefined(rule) Then
        prev:ElmOfDB <- UNDEFINED
        now:ElmOfDB <- head(db)
        While not isEmpty(now) Do
            If rule(now) = rule Then
                If prev = UNDEFINED Then
                    head(db) <- next(now)
                    If head(db) = UNDEFINED Then
                        tail(db) <- UNDEFINED
                    EndIf
                Else
                    next(prev) <- next(now)
                    If isUndefined(next(now)) Then
                        tail(db) <- prev
                    EndIf
                EndIf
                free(now)
                removeARule <- db
            EndIf
            prev <- now
            now <- next(now)
        Done
    removeARule <- db
End
````

---
### `removeARuleAndFree`
Cette fonction permet de retirer une règle d'une base de connaissance et de libérer la mémoire utilisée par cet élément.
* `db` est la base de connaissance à laquelle on veut retirer une règle.
* `rule` est une règle que l'on souhaite retirer.
* `point` est l'élément que l'on compare actuellement.
* `prev` est l'élément avant `now`. et est indéfinie au début
>La fonction renvoie la base de connaissance modifiée.
````
function removeARuleAndFree(db:DB, rule:Rule):DB
Start
    If not isEmpty(db) AND not isUndefined(rule) Then
        prev:ElmOfDB <- UNDEFINED
        now:ElmOfDB <- head(db)
        While not isEmpty(now) Do
            If rule(now) = rule Then
                If prev = UNDEFINED Then
                    head(db) <- next(now)
                    If head(db) = UNDEFINED Then
                        tail(db) <- UNDEFINED
                    EndIf
                Else
                    next(prev) <- next(now)
                    If isUndefined(next(point)) Then
                        tail(db) <- prev
                    EndIf
                EndIf
                freeRule(rule(point))
                free(point)
                removeARuleAndFree <- db
            EndIf
            prev <- now
            now <- next(now)
        Done
    removeARuleAndFree <- db
End
````

---
### `removeARulesById`
Cette fonction permet de retirer une règle d'une base de connaissance en fonction de son `id`.
* `db` est la base de connaissance à laquelle on veut retirer une règle.
* `id` est l'identifiant unique de l'élément que l'on souhaite retirer.
* `point` est l'élément que l'on compare actuellement.
* `prev` est l'élément avant `now`. et est indéfinie au début
>La fonction renvoie la base de connaissance modifiée.
````
function removeARulesById(db:DB, id:LongInteger):DB
Start
    If not isEmpty(db) AND not isEmpty(head(db)) Then
        prev:ElmOfDB <- UNDEFINED
        now:ElmOfDB <- head(db)
        While not isEmpty(now) Do
            If id(now) = id Then
                If prev = UNDEFINED Then
                    head(db) <- next(now)
                    If head(db) = UNDEFINED Then
                        tail(db) <- UNDEFINED
                    EndIf
                Else
                    next(prev) <- next(now)
                    If isUndefined(next(now)) Then
                        tail(db) <- prev
                    EndIf
                EndIf
                free(now)
                removeARulesById <- db
            EndIf
            prev <- now
            now <- next(now)
        Done
    removeARulesById <- db
End
````

---
### `removeARulesByIdAndFree`
Cette fonction permet de retirer une règle d'une base de connaissance en fonction de son `id` et de libérer la mémoire utilisée par cet élément.
* `db` est la base de connaissance à laquelle on veut retirer une règle.
* `id` est l'identifiant unique de l'élément que l'on souhaite retirer.
* `point` est l'élément que l'on compare actuellement.
* `prev` est l'élément avant `now`. et est indéfinie au début
>La fonction renvoie la base de connaissance modifiée.
````
function removeARulesByIdAndFree(db:DB, id:LongInteger):DB
Start
    If not isEmpty(db) AND not isEmpty(head(db)) Then
        prev:ElmOfDB <- UNDEFINED
        now:ElmOfDB <- head(db)
        While not isEmpty(now) Do
            If id(now) = id Then
                If prev = UNDEFINED Then
                    head(db) <- next(now)
                    If head(db) = UNDEFINED Then
                        tail(db) <- UNDEFINED
                    EndIf
                Else
                    next(prev) <- next(now)
                    If isUndefined(next(now)) Then
                        tail(db) <- prev
                    EndIf
                EndIf
                freeRule(rule(now))
                free(now)
                removeARulesByIdAndFree <- db
            EndIf
            prev <- now
            now <- next(now)
        Done
    removeARulesByIdAndFree <- db
End
````

---
### `removeAllRules`
Cette fonction permet de retirer toutes les règles d'une base de connaissance.
* `db` est la base de connaissance que l'on souhaite vider.
* `point` est un pointeur pour parcourir la base de connaissance `db`.
>La fonction renvoie la base de connaissance modifiée.
````
function removeAllRules(db:DB):DB
Start
    If not isUndefined(db)  Then
        point:ElmOfDB <- head(db)
        While not isEmpty(point) Do
            head(db) <- point
            point <- next(point)
            free(head(db))
        Done
        head(db) <- UNDEFINED
        tail(db) <- UNDEFINED
        last_id(db) <- -1
    EndIf
    removeAllRules <- db
End
````

---
### `removeAllRulesAndFree`
Cette fonction permet de retirer toutes les règles d'une base de connaissance et de libérer la mémoire utilisée par cet élément.
* `db` est la base de connaissance que l'on souhaite vider.
* `point` est un pointeur pour parcourir la base de connaissance `db`.
>La fonction renvoie la base de connaissance modifiée.
````
function removeAllRulesAndFree(db:DB):DB
Start
    If not isEmpty(db)  Then
        point:ElmOfDB <- head(db)
        While not isEmpty(point) Do
            head(db) <- point
            point <- next(point)
            freeRule(rule(temp))
            free(head(db))
        Done
    EndIf
    head(db) <- UNDEFINED
    tail(db) <- UNDEFINED
    last_id(db) <- -1
    removeAllRulesAndFree <- db
End
````

---
### `getRuleById`
Cette fonction permet de récupérer une règle d'une base de connaissance en fonction de son `id`.
* `db` est la base de connaissance dont on souhaite extraire une règle.
* `id` est l'identifiant unique dont on veut la structure associée.
* `point` est un pointeur pour parcourir la base de connaissance `db`.
>La fonction renvoie une règle de type `Rule`.
````
function getRuleById(db:DB, id:LongInteger):Rule
Start
    If not isEmpty(db) AND id <= last_id(db) AND id >= 0 Then
        point:ElmOfDB <- head(db)
        While not isEmpty(point) Do
            If id(point) = id Then
                getRuleById <- rule(point)
            EndIf
            point <- next(point)
        Done
    EndIf
    getRuleById <- UNDEFINED
End
````

---
### `copyOfDB`
Cette fonction permet de réaliser une copie d'une base de connaissance.
* `db` est la base de connaissance que l'on souhaite copier.
* `point` est un pointeur pour parcourir la base de connaissance `db`.
* `new_rule` est l'ensemble de nouvelles règles que l'on ajoute à `db`.
* `premise` est l'ensemble des prémisses des règles de `db`.
>La fonction revoit la copie de la db.
````
function copyOfDB(db:DB):DB
Start
    if isUndefined(db) OR isEpty(fact(db)) Then
        copyOfDB <- UNDEFINED
    EndIf
    new_db:DB <- createDB(facts(db))
    point:ElmOfDB <- head(db)
    While not isEmpty(point) Do
        new_rule:Rule <- createRule(facts(db))
        conclusion(new_rule) <- conclusion(rule(point))
        premise:ElmOfPremise <- head(premise(rule(point)))
        While not isEmpty(premise) Do
            new_rule <- addFactInPremise(new_rule, premise(premise))
            premise <- next(premise)
        Done
        new_db <- addRuleToDB(new_db, new_rule)
        point <- next(point)
    Done
    copyOfDB <- new_db
End
````

---
### `freeDB`
Cette fonction permet de libérer la mémoire utilisée par une base de connaissance en cas de besoin, par exemple en cas d'erreur ou à la fin du programme.
* `db` est la base de connaissance que l'on souhaite vider.
* `point` est un pointeur pour parcourir la base de connaissance `db`.
* `rule` est un pointeur pour parcourir les règles de `db`.
> La fonction renvoie la liste de fait (`FactList`) associée.

````
function freeDB(db:DB):DB
Start
    If not isEmpty(db) Then
        If not isEmpty(head(db)) Then
            point:ElmOfDB <- head(db)
            While not isEmpty(point) Do
                temp:ElmOfDB <- point
                freeRule(rule(temp))
                point <- next(point)
                free(temp)
            Done
        Done
        rtn:FactList <- fact(bd)
        free(db)
        freeDB <- rtn
    EndIf
    freeDB <- UNDEFINED
End
````

## Le système expert

---
### `expertSystem`
Cette fonction permet de réaliser un système expert.
* `factsToTset` est la liste de fait à tester.
* `resultFacts` est la liste de fait résultat.
* `db` est la base de connaissance.
* `current_elm_of_db` est l'élément de `db` que l'ont vérifié.
* `current_premise` est l'élément de la prémisse que l'on teste actuellement.
* `previous_premise` est l'élément de la prémisse avant `current_premise`
* `current_fact` est le fait que l'on compare actuellement.
* ``
* 
>La fonction revoit un entier en fonction de sa réussite ou échec.
````
function expertSystem(factsToTest:FactList, resultFacts:FactList, db:DB):Integer
Start
    If isEmpty(db) Then
        expertSystem <- 1
    EndIf
    If isEmpty(factsToTest) Then
        expertSystem <- 2
    EndIf
    If isEmpty(resultFacts) Then
        expertSystem <- 3
    EndIf
    
    While not isEmpty(factToTest) AND isUndefined(fact(head(factToTest))) Do
        Type current_fact <- fact(head(factToTest))
        current_elm_of_db:ElmOfDB <- head(db)
        
        While not isUndefined(current_elm_of_db) Do
            is_rule_find:Boolean <- False
            current_rule:Rule <- rule(current_elm_of_db)
            current_node:ElmOfPremise <- head(premise(current_rule))
            previous_node:ElmOfPremise <- UNDEFINED
            
            While not isUndefined(current_node) Do
                If preöise(current_node) = current_fact Then
                    If previous_node = UNDEFINED Then
                        head(premise(current_rule)) <- next(current_node)
                    Else
                        next(previous_node) <- next(current_node)
                        If isUndefined(next(current_node)) Then
                            tail(premise(current_rule)) <- previous_node
                            next(previous_node) <- UNDEFINED
                        EndIf
                    EndIf
                    current_node <- next(current_node)
                    is_rule_find <- True
                    free(current_node)
                    current_node <- NULL
                    If isPremiseEmpty(current_rule) Then
                        resultFacts <- addFact(resultFacts, conclusion(current_fact))
                        factsToTest <- addFact(factsToTest, conclusion(current_fact))
                        db <- removeARuleAndFree(db, current_rule)
                    EndIf
                Else
                    previous_node <- current_node
                    current_elm_of_db <- next(current_elm_of_db)
                EndIf
            Done
            If not is_rule_find Then
                current_elm_of_db <- next(current_elm_of_db)
            EndIf
        Done
    factsToTest <- removeAFacts(factsToTest, current_fact)    
    Done
    expertSystem <- 0
End
````

---
C'est tout pour cette section, vous pouvez passer à la section suivante : [Fonction de test et commentaires)](Test.md).