typedef enum {
    True, False
}Bool;

typedef struct {
    char* name;
    char* desc;
}Properties;

typedef struct elm1{
    Properties value;
    struct elm1* next;
}ElmOfProperties;

typedef ElmOfProperties * ListOfProperties;

typedef struct elm2{
    ListOfProperties premise;
    Properties* conclusion;
    Bool is_true;
}Rules;


Rules* createEmptyRule();
Rules* addPremise(Rules* rules,Properties premise);
Rules* createConclusion(Rules* rule, Properties* conclusion);
Bool PropertiesInPremise(ListOfProperties premise, Properties prop);
Rules* remouvePremise(Rules* rule,Properties premise);
Bool isPremiseEmpty(Rules* rule);
ElmOfProperties* getHeadOfPremise(Rules* rule);
Properties* getConclusion(Rules* rule);
void printPremise(Rules* rule);
void printRule(Rules* rule);
void printProperties(Properties* p);