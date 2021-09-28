class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> u_email;
        string mail_id = "";
        bool present = false;
        for(int i=0; i<emails.size(); i++){
            int x = 0;
            while(emails[i][x]!='@'){
                if(emails[i][x] == '.'){
                    x++;
                    continue;
                }
                if(emails[i][x] == '+'){
                    while(emails[i][x]!='@'){x++;}
                    break;
                }
                mail_id+=emails[i][x];
                x++;
            }
            mail_id.insert(mail_id.end(), emails[i].begin()+x, emails[i].end());
            
            u_email.insert(mail_id);
            mail_id = "";
        }
        return u_email.size();
    }
};