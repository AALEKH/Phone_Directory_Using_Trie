#ifndef phonenumber 
#define phonenumber

#include "all_includes.h"
#include "utilities.h"

using namespace std;
 
class PhoneNumber {

    private:
        /**
         * @brief Essentially this program uses Trie for implementing PhoneNumber Search
         *
         * In this part, I have used Trie struct using unordered map for storing permissible character denoted in 
         * utitilies p_elements.h, here "last" denoted if the complete word has been formed (for true) or not (for false)
         * Further, relevantList Clubbed with doesExist is used for search by surname feature. Here doesExist is marked true
         * only when complete name s present with it's first name.
         */
        struct TrieNode
        {
            unordered_map<char,TrieNode*> child;
            map<string, bool> relevantList; 
            bool last;
            bool doesExist;
            
            TrieNode()
            {
                for (auto element: p_elements)
                    child[element] = NULL;
                last = false;
                doesExist = false;
            }
        };

        // Just to initialize the root element
        TrieNode *root = new TrieNode();

    public:

        /**
         * @brief Simply to insert new word to trie
         *
        */
        void insert(string);

        /**
         * @brief To iterate over all the elements of prefix
         *
        */
        void contactsUtils(TrieNode *curNode, string, map<string, bool> &checkMap);

        /**
         * @brief To return the map elements of trie for a given prefix
         *
        */
        map<string, bool> display(string);

        /**
         * @brief To console log (or should I say cout) all the elements received from display elements
         *
        */
        void displayContent(string);

        /**
         * @brief For barebone processing, just to check if the operation requested is search or insert or none of the two
         *
        */
        void processing(int , string);
        // void sortVector(vector<string> &arr);
        // bool operator() (string i,string j) { return (i.size()<j.size());}
};

#endif