#include <iostream>
#include <set>
#include <string_view>
#include <unordered_map>
#include <map>
#include <regex>
#include <string>
using namespace std;



auto force_input (string& input, regex reg)
{
    while (not std::regex_match (input, reg))
    {
        cout << "wrong input, try again\n>> ";
        cin >> input;
    }
}





struct User
{
    string first_name;
    string last_name;
    string email;
    string password;
};





auto get_users () -> map <string, User>
{
    
}


struct Users
{
    map <string/*email*/, int/*user id*/> emails;
    map <string/*first name*/, int/*user id*/> first_names;
    map <string/*last name*/, int/*user id*/> last_names;
    map <int/*user id*/, string/*password*/> passwords;
};



auto main () -> int
{
    
    auto users = Users
    {
        .emails =
        {
            pair {"philip@hotmail.com", 0},
            pair {"adam@gmail.com", 1}
        },
        
        .first_names =
        {
            pair {"philip", 0},
            pair {"adam", 1}
        },
        
        .last_names =
        {
            pair {"wenkel", 0},
            pair {"andersson", 1}
        },
        
        .passwords =
        {
            pair {0, "hej123"},
            pair {1, "adam1212"}
        }
    };
    
    
    
    
    
    auto input = std::string {};
    
    auto start_menu = [&input] (auto&&... menus) -> void
    {
        cout << "system login\n 1. log in\n 2. new user\n\n>> ";
        cin >> input;

        force_input (input, regex {"[1-2]"});
        
        (([&input] (auto&& menu)
        {
            if (regex_match (input, menu.first))
            {
                menu.second ();
            }

        } (menus)), ...);
    };
    
    
   
    
    
    auto get_user = [&users] () -> int
    {
        auto email_input = string {};
        
        cout << "email >> ";
        cin >> email_input;
        
        auto email_match = users.emails.find (email_input);
        
        while (email_match == users.emails.end ())
        {
            cout << "email not found, please try again\nemail>> ";
            cin >> email_input;
            email_match = users.emails.find (email_input);
        }
        
        int user_id = email_match -> second;
        
        auto password = users.passwords.find (user_id)->second;
        auto password_input = string {};
        
        cout << "password >> ";
        cin >> password_input;

        while (password_input != password)
        {
            cout << "wrong password, please try again\npassword >> ";
            cin >> password_input;
        }
        
        return user_id;
    };
    
    auto new_user_menu = [&input] (auto&&... a)
    {
        
    };
    
    
//    get_username ();
    
    start_menu
    (
     pair {regex {"[1]"}, get_user},
         pair {regex {"[2]"}, new_user_menu}
     );
    
    
    
    
    
    
    
    
    
    
    
    
    
        
    
    
    
    
    
    
    
    
        //    auto bag = std::map <std::string_view> {};
    
    
    return 0;
}

