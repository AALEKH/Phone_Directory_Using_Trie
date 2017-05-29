#include "phonenumber.h" 
#include <string>

using namespace std;
 
void PhoneNumber::insert(string s)
{

    vector<string> v;

    split(s, v, ' ');

    for(int j = 0;  j < v.size(); j++){
        int len = v[j].length();
 
        TrieNode *itr = root;
        for (int i = 0; i < len; i++)
        {

            TrieNode *nextNode = itr->child[v[j][i]];
            if (nextNode == NULL)
            {
                nextNode = new TrieNode();
     
                itr->child[v[j][i]] = nextNode;
            }
     
            itr = nextNode;

            if(i == len-2) {
                if(j ==0) itr->doesExist = true;
            }

            if (i == len - 1){
                itr->last = true;
                itr->relevantList[s] = true;
            }
        }
    }

}
 
void PhoneNumber::contactsUtils(TrieNode *curNode, string prefix, map<string, bool> &checkMap) {
    map<string, bool>::iterator it;
    if (curNode->last){
        // if(curNode) && 
        if(curNode->doesExist) checkMap[prefix] = true;
        for (it=curNode->relevantList.begin(); it!=curNode->relevantList.end(); ++it)
            checkMap[it->first] = true;
    }
 
    for (auto i: p_elements) {
        TrieNode *nextNode = curNode->child[i];
        if (nextNode != NULL)
            contactsUtils(nextNode, prefix + (char)i, checkMap);        
    }
}
 
map<string, bool> PhoneNumber::display(string str) {
    TrieNode *prevNode = root;
    map<string, bool> contactMap;
    string prefix = "";
    int len = str.length();
 
    int i;
    for (i=0; i<len; i++)
    {
        prefix += (char)str[i];
 
        char lastChar = prefix[i];
 
        TrieNode *curNode = prevNode->child[lastChar];
        if (curNode == NULL) {
            cout << "No Results Found for '" << prefix << "'\n";
            i++;
            break;
        }

        contactMap.clear();
        contactsUtils(curNode, prefix, contactMap);
 
        prevNode = curNode;
    }
    // cout << 'Contact Map here !!!';
    return contactMap;
}
 
void PhoneNumber::displayContent(string str){
    map<string, bool>::iterator it;
    map<string, bool> mapper = display(str);

    // cout << mapper.size() << endl;

    if(mapper.size() != 0){

        // Below if condition is used to check if the exact match condition can be found.
        if (mapper.count(str)>0){
            cout << str << "\n";
            it=mapper.find(str);
            mapper.erase(it);
        }
        for (it=mapper.begin(); it!=mapper.end(); ++it)
            cout << it->first << " " << "\n";
    }
}

void PhoneNumber::processing(int selection, string name) {
    switch(selection) {
        case 1: 
                insert(name);
                break;
        case 2:
                displayContent(name);
                break;
        default:
                cout << " \n Wrong details Selected" << endl;
                break;
    }
}

int main()
{ 
    string name;
    PhoneNumber phn;

    while(1){
        int selection;
        cout << "1) Add contact 2) Search 3) Exit \n";
        cin >> selection;
        if(selection < 1) {  cout << "Incorrect option selected "; break;}
        if(selection >= 3) {cout << "Happy Searching "; break;}
        cout << "Enter Name: ";

        // Since I used cin before getline, I had to use cin.ignore()

        cin.ignore();

        // Used getline instead of cin, so as to accomodate whitespace that might be found
        getline(cin, name);
        if(checkPermissibleEle(name)) {
            phn.processing(selection, name);
        } else {
            cout << "You entered unpermitted character in you string\n";
        }
    }
 
    return 0;
}