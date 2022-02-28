#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Knowledge_base {
   public:
    // all possible conclusions for our program

    vector<string> conclusions = {"Stingray venom Poisoning",
                                  "Alcohol Poisoning",
                                  "Venomous ticks Poisoning",
                                  "Psilocybin mushroom Poisoning",
                                  "Carbon monoxide Poisoning",
                                  "Radiation Poisoning"};

    // variables_list is the list of all symptoms

    vector<string> variables_list = {"Nausea",
                                     "Vomiting",
                                     "Dizziness",
                                     "Hallucinations",
                                     "Blurred vision",
                                     "Headache",
                                     "Abdominal pain",
                                     "Restlessness",
                                     "Shortness of breath",
                                     "Drowsiness",
                                     "Weakness",
                                     "Diarrhea",
                                     "Confusion",
                                     "Muscular paralysis",
                                     "Jaw stiffness",
                                     "Seizures",
                                     "Loss of memory",
                                     "Euphoria",
                                     "Loss of sense of distance and size",
                                     "Intense pain",
                                     "Muscle cramps"};

    /*
 list of all possible symptoms combination that leads to a diagnosis

  */

    vector<vector<int>> symptoms_combination = {
        {0, 1, 6},
        {0, 12},
        {0, 20},
        {0, 10},
        {0, 11},
        {0, 18},
        {0, 19},
        {1, 2, 6},
        {1, 2, 7},
        {1, 2, 8},
        {1, 2, 9},
        {1, 10},
        {1, 11},
        {1, 13},
        {1, 14},
        {1, 15},
        {1, 18},
        {1, 19},
        {1, 3, 7},
        {1, 3, 8},
        {1, 20},
        {1, 5, 6},
        {1, 5, 7},
        {1, 5, 9},
        {1, 12},
        {1, 6, 9},
        {1, 6, 7},
        {1, 6, 8},
        {1, 7},
        {1, 8, 9},
        {0, 16},
        {0, 17},
        {0, 7},
        {0, 8, 9},
        {1, 4, 7},
        {1, 4, 9}};

    // clauses for diseases, numerical value represents
    // index in the variables list

    vector<int> stingray_venom_clause = {0, 1, 3, 4, 6, 8, 9, 12, 20};

    vector<int> alcohol_clause = {0, 1, 2, 3, 5, 9, 10, 11};

    vector<int> venomous_ticks_clause = {1, 2, 3, 4, 5, 6, 7, 13, 14, 15};

    vector<int> mushroom_clause = {0, 2, 3, 6, 7, 16, 17};

    vector<int> carbon_clause = {0, 1, 2, 4, 5};

    vector<int> radiation_clause = {0, 1, 2, 4, 5, 8, 18, 19};

    //pushing all clauses in the clause index vector for easy retrieval later

    vector<vector<int>> clause_index = {stingray_venom_clause, alcohol_clause, venomous_ticks_clause, mushroom_clause, carbon_clause, radiation_clause};

    map<string, int> variable_initialized = variable_list_initializer(variables_list);

    vector<int> clause_variable_list = initialize_clause_variable_list(20, clause_index);

    /*
 the variable list initializer function returns a map of variable and their initialization status, -1 means the variable has not been initialized, 0 means the variable is false and 1 means the variable is true

*/

    map<string, int> variable_list_initializer(vector<string> variables_list) {
        map<string, int> initialized;

        for (string variable : variables_list) {
            pair<string, int> key_value;
            key_value = make_pair(variable, -1);
            initialized.insert(key_value);
        }

        return initialized;
    }

    vector<int> initialize_clause_variable_list(int numRules, vector<vector<int>> clause_index) {
        vector<int> clause_variable_list(numRules * clause_index.size());

        for (int i = 0; i < clause_index.size(); i++) {
            int begin_at = i * numRules;
            for (auto variable_index : clause_index[i]) {
                clause_variable_list[begin_at + variable_index] = 1;
            }
        }
        return clause_variable_list;
    }
};
