#include <bits/stdc++.h>
using namespace std;

class LookupLTABLE
{
public:
        void insert(const string &key, const string &value)
        {
                LTABLE_[key] = value;
        }
        void remove(const string &key)
        {
                LTABLE_.erase(key);
        }
        void update(const string &key, const string &value)
        {
                LTABLE_[key] = value;
        }
        string search(const string &key)
        {
                if (LTABLE_.count(key) == 0)
                {
                        return "";
                }
                return LTABLE_[key];
        }

        void display()
        {
                for (const auto &entry : LTABLE_)
                {
                        cout << entry.first << ": " << entry.second << endl;
                }
        }

private:
        map<string, string> LTABLE_;
};

int main()
{
        LookupLTABLE LTABLE;
        LTABLE.insert("DOG", "ANIMAL");
        LTABLE.insert("YAMAHA", "BIKE");
        LTABLE.insert("TAJ MAHAL", "MONUMENT");
        LTABLE.display();
        cout << LTABLE.search("DOG") << endl;
        LTABLE.update("YAMAHA", "VEHICLE");
        LTABLE.remove("DOG");
        LTABLE.display();
}
