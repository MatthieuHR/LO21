# Algorithm des sous programmes

---
Dans cette sections vous pouvez retrouver tous les algorithmes des sous programmes en fonctions des données qu'ils traites.

## Les algorithmes avec des `FactList`

---
### `addFact`
Cette fonction sert a ajouter un élément dans une `FactList`.
````
function addFact(list:FactList, fact:Property):FactList
Start
    newl:ElmOfFact
    fact(newl) <- affectfiel(fact)
    If isEmpty(fact(newl)) Then
        addFact <- EMTPY
    EndIf
    next(newl) = EMPTY
    If not isEmpty(list) Then
        next(newl) <- list
    EndIf
    addFact <- newl
End
````

---
### `remouveAllFacts`
Cette fonction permet de libérer la mémoire utilisée par une `FactList` en cas de besoin, par exemple en cas d'erreur.
````
function remouveAllFacts(list:FactList):FactList
Start
    point:ElmOfFact <- head(list)
    While not isNull(point) Do
        head(list) <- point
        point <- next(point)
        free(point)
    Done
    remouveAllFacts <- point
End
````
## Les algorithmes avec des `Rule`

---
### `addPremise`
````
function addPremise(rule:Rule, premise:Property):Rule
Stat
    If not isEmpty(premise) Then
        newl:ElmOfPremise
        premise(newl) <- premise
        next(newl) <- INDEFINE
        If isEmpty(rule) Then
            rule <- createEmptyRule()
        EndIf
        If isEmpty(premise(rule)) Then
            premise(rule) <- newl
        Else
            point:ElmOfPremise <- head(premise(rule))
            While nnot isEmpty(ext(point)) Do
                point <- next(point)
            Done
            next(point) <- newl
        EndIf
    EndIf
    addPremise <- rule
End
````

---
### `createConclusion`
````
function createConclusion(rule:Rule, conclusion:Property):Rule
Start
    If not isEmpty(conclusion) Then
        If not isEmpty(conclusion(rule)) Then
            free(conclusion(rule))
        EndIf
        conclusion(rule) <- conclusion
    EndIf
    createConclusion <- rule
End
````

---
### `PropertiesInPremise`
````
function PropertiesInPremise(premise:Premise, prop:Property):Bool
Start
    If isEmpty(premise) Then
        PropertiesInPremise <- False
    EndIf
    If premise(head(premise)) = prop Then
        PropertiesInPremise <- True
    Endif
    PropertiesInPremise <- PropertiesInPremise(rest(premise), prop)
End
````

---
### `remouvePremise`
````
function remouvePremise(rule:Rule, premise:Property):Rule
Start
    If not isEmpty(premise(Rule)) Then
        point:ElmOfPremise <- head(premise(rule))
        If premise(point) = premise Then
            head(premise(rule)) <- next(point)
            free(point)
        Else
            If not isEmpty(next(point)) Then
                While not isEmpty(next(point)) Do
                    If premise(next(point)) = premise Then
                        tmp:ElmOfPremise <- next(point)
                        next(point) <- next(next(point))
                        free(tmp)
                        remouvePremise <- rule
                    EndIf
                    point <- next(point)
                Done
            EndIf
        EndIf
    EndIf
    remouvePremise <- rule
End
````

## Les algorithmes avec des `BC`

---
### `addRuleToBC`
```
function addRuleToBC(bc:BC, rule:Rule):BC
Start
    newl:ElmOfBC
    rule(newl) <- rule
    next(newl) <- INDEFINE
    If not isEmpty(bc) Then
        point:ElmOfBC <- head(bc)
        While not isEmpty(next(point)) Do
            point <- next(point)
        Done
        next(point) <- newl
        addRuleToBC <- bc
    Else
        head(bc) <- newl
        addRuleToBC <- bc
    EndIf
End
```