
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;
class Dictionary
{
public:
        Dictionary(const string &filename) : filename_(filename)
        {
                log_.open(filename, ios::app);
        }
        void insert(const string &key, const string &value)
        {
                log_ << "i " << key << " " << value << endl;
                entries_[key] = value;
        }
        void remove(const string &key)
        {
                log_ << "d " << key << endl;
                entries_.erase(key);
        }
        void update(const string &key, const string &value)
        {
                log_ << "u " << key << " " << value << endl;
                entries_[key] = value;
        }
        bool search(const string &key) const
        {
                return entries_.count(key) > 0;
        }
        void display() const
        {
                for (const auto &entry : entries_)
                {
                        cout << entry.first << ": " << entry.second << endl;
                }
        }

private:
        string filename_;

        ofstream log_;
        unordered_map<string, string> entries_;
};

int main()
{
        Dictionary dict("dictionary.log");

        dict.insert("apple", "a fruit");
        dict.insert("banana", "another fruit");
        dict.insert("car", "a vehicle");

        dict.display();

        dict.remove("apple");

        dict.display();

        dict.update("car", "a mode of transportation");

        dict.display();

        cout << dict.search("apple") << endl;
        cout << dict.search("banana") << endl;
        cout << dict.search("car") << endl;

        return 0;
}
