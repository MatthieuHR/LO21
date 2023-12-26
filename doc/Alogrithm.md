# Algorithm des sous programmes

---
Dans cette sections vous pouvez retrouver tous les algorithmes des sous programmes en fonctions des données qu'ils traites.

## Les algorithmes avec des `FactList`

---
### `addFact`
Cette fonction sert a ajouter un élément dans une `FactList`.
````
function addFact(list:FactList, fact:Properties):FactList
Start
    newl:ElmOfFact
    fact(newl) <- affectfiel(fact)
    If isEmpty(fact(newl)) SO
        addFact <- EMTPY
    EndIf
    next(newl) = EMPTY
    If not isEmpty(list) SO
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
## Les algorithmes avec des `Rules`

---
### `addPremise`
````
function addPremise(rule:Rules, premise:Properties):Rules
Stat
    If not isEmpty(premise) So
        newl:ElmOfPremise
        value(newl) <- premise
        next(newl) <- INDEFINE
        If isEmpty(rule) So
            rule <- createEmptyRule()
        EndIf
        If isEmpty(premise(rule)) So
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
function createConclusion(rule:Rules, conclusion:Properties):Rules
Start
    If not isEmpty(conclusion) So
        If not isEmpty(conclusion(rule)) So
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
function PropertiesInPremise(premise:Premise, prop:Properties):Bool
Start
    If isEmpty(premise) So
        PropertiesInPremise <- False
    EndIf
    If value(head(premise)) = prop So
        PropertiesInPremise <- True
    Endif
    PropertiesInPremise <- PropertiesInPremise(rest(premise), prop)
End
````

---
### `remouvePremise`
````
function remouvePremise(rule:Rules, premise:Properties):Rules
Start
    If not isEmpty(premise(Rule)) So
        point:ElmOfPremise <- head(premise(rule))
        If value(point) = premise So
            head(premise(rule)) <- next(point)
            free(point)
        Else
            If not isEmpty(next(point)) So
                While not isEmpty(next(point)) Do
                    If value(next(point)) = premise So
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
function addRuleToBC(bc:BC, rule:Rules):BC
Start
    newl:ElmBC
    rule(newl) <- rule
    next(newl) <- INDEFINE
    If not isEmpty(bc) So
        point:ElmBC <- head(bc)
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