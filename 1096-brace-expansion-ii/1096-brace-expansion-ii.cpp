class Solution {
public:
    string expr;   // input expression store karne ke liye
    int idx = 0;    // current parsing position (pointer)

    // ---------------------------------------------------------
    // parseFactor(): ek "unit" parse karta hai
    // Ya to '{...}' group hoga (parseUnion call karo)
    // Ya phir consecutive lowercase letters (ek literal word)
    // ---------------------------------------------------------
    set<string> parseFactor() {
        if (expr[idx] == '{') {
            return parseUnion();   // nested group hai, union parse karo
        } else {
            // consecutive letters ko ek saath ek string bana lo
            // (efficiency ke liye — har letter alag parse karne ki zaroorat nahi)
            int start = idx;
            while (idx < (int)expr.size() && islower(expr[idx])) idx++;
            return { expr.substr(start, idx - start) };
        }
    }

    // ---------------------------------------------------------
    // parseConcat(): jab tak ',' ya '}' na mile (ya string khatam na ho),
    // consecutive factors ko concatenate (cartesian product) karta hai
    // ---------------------------------------------------------
    set<string> parseConcat() {
        vector<set<string>> factors;   // har factor ka apna set

        while (idx < (int)expr.size() && expr[idx] != ',' && expr[idx] != '}') {
            factors.push_back(parseFactor());
        }

        // ab in sab factors ka cartesian-product concatenation karo
        set<string> result = {""};     // empty string se start (identity element)
        for (auto &f : factors) {
            set<string> newResult;
            for (const string &prefix : result)
                for (const string &word : f)
                    newResult.insert(prefix + word);   // concatenation
            result = move(newResult);
        }
        return result;
    }

    // ---------------------------------------------------------
    // parseUnion(): '{' se shuru hoke, comma-separated concat-results
    // ka union leta hai, jab tak matching '}' na mile
    // ---------------------------------------------------------
    set<string> parseUnion() {
        idx++; // '{' skip karo
        set<string> result;

        while (true) {
            set<string> part = parseConcat();          // ek comma-part parse karo
            result.insert(part.begin(), part.end());   // union mein daalo

            if (expr[idx] == ',') {
                idx++;       // comma skip karke next part parse karo
            } else {         // matlab '}' mila
                idx++;       // '}' skip karo
                break;
            }
        }
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        expr = expression;
        idx = 0;
        // top level pe direct parseConcat call karo
        // (top level braces mandatory nahi hote, jaise "a{b,c}d")
        set<string> result = parseConcat();
        return vector<string>(result.begin(), result.end());  // set already sorted hai
    }
};