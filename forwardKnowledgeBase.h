#ifndef forwardChain_h
#define forwardChain_h

#endif /* forward_chain_h */

#include <string>
#include <vector>

using namespace std;

class ForwardChain {
   public:
    vector<string> clause_variable_list = {"Unconsciousness",
                                           "Infection",
                                           "Inflammation",
                                           "Low O2 Level",
                                           "Dehydration",
                                           "Restlessness",
                                           "Hallucinations",
                                           "Intense Pain",
                                           "Internal Inflammation"};

    vector<string> treatment_list = {
        "Perform cardiopulmonary resuscitation (CPR) if necessary",
        "Oral antibiotics are usually recommended for infection",
        "Washing wound with cold water."
        "IV fluids, Oxygen, Stomach pumping, Blood filtration",
        "Intravenous fluids (if severely dehydrated) "
        "Sedation",
        "Benzodiazepines may be used for panic attacks, hallucinations, and seizures",
        "Pain Killers"
        "Potassium iodide, Prussian blue can be used "};

    vector<string> diagnosis_list = {"Stingray venom Poisoning",
                                     "Alcohol Poisoning",
                                     "Venomous ticks Poisoning",
                                     "Psilocybin mushroom Poisoning",
                                     "Carbon monoxide Poisoning",
                                     "Radiation Poisoning"};

    vector<pair<string, string>> variable_initialized_list = variable_initializer(clause_variable_list);

    vector<pair<string, string>> variable_initializer(vector<string> variable_list) {
        vector<pair<string, string>> temp_var_initializer;

        for (string variable : variable_list) {
            pair<string, string> temp_pair = make_pair(variable, "");
            temp_var_initializer.push_back(temp_pair);
        }

        return temp_var_initializer;
    }

    //

    vector<pair<int, vector<int>>> diagnosis_ailment = {
        {0, {0, 1}}, {1, {2, 3}}, {2, {4, 5, 6}}, {3, {0, 6}}, {4, {6, 7}}, {7, {7, 8}}};

    vector<vector<string>> ailment_condition = {{"UNCONSCIOUS", "INFECTED"},
                                                {"O2LEVEL", "PAIN"},
                                                {"DEHYDRATED", "RESTLESS", "INFLAMED"},
                                                {"HALLUCINATE", "RESTLESS"},
                                                {"O2LEVEL", "UNCONSCIOUS"},
                                                {"IINFLAMED", "UNCONSCIOUS"}};

    vector<pair<vector<string>, string>> ailment_condition_treatment = {
        {{clause_variable_list[0], "UNCONSCIOUS"}, "Perform cardiopulmonary resuscitation (CPR) if necessary "},
        {{clause_variable_list[1], "INFECTED"}, "Oral antibiotics are usually recommended for infection "},
        {{clause_variable_list[2], "O2LEVEL"}, "IV fluids, Oxygen, Stomach pumping, Blood filtration "},
        {{clause_variable_list[3], "PAIN"}, "Stomach pumping, Blood filtration"},
        {{clause_variable_list[4], "DEHYDRATED"}, "Intravenous fluids (if severely dehydrated)"},
        {{clause_variable_list[5], "RESTLESS"}, "Sedation (to keep calm)"},
        {{clause_variable_list[6], "INFLAMED"}, "Potassium iodide, Prussian blue can be used "},
        {{clause_variable_list[7], "HALLUCINATE"}, "Benzodiazepines may be used for panic attacks, hallucinations, and seizures "}};
};
