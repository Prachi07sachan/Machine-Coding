#include<bits/stdc++.h>
using namespace std;

class Database {

private:
    // arrays 
    string shortUrl[100];
    string longUrl[100];

    int count;  

public:


    Database() {
        count = 0;
    }

    // function to store short and long URL
    void store(string s, string l) {
        shortUrl[count] = s;   
        longUrl[count] = l;    
        count++;               
    }

    // function to get original URL from short code
    string get(string s) {

        for(int i=0; i<count; i++) {
            if(shortUrl[i] == s) {
                return longUrl[i];  
            }
        }

        return ""; // else empty not found
    }
};

class UrlShortener {

private:
    Database db; 

    int id;     

public:

    
    UrlShortener() {
        id = 1;
    }

    // function to create short code
    string shorten(string longUrl) {

        // convert number to string -> "1","2"......
        string code = to_string(id);

        id++;  

        // store mapping in database
        db.store(code, longUrl);

        return code;
    }

    // function to get original URL
    string getOriginal(string code) {

        string ans = db.get(code);

        if(ans == "") {
            return "Not found";
        }

        return ans; 
    }
};
